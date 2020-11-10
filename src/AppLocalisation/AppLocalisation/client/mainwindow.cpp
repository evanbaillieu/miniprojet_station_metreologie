#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "metier/type.h"
#include "metier/metierfactory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    typeSrv = MetierFactory::getTypeServiceImpl();
    localisationSrv = MetierFactory::getLocalisationServiceImpl();
    salleSrv = MetierFactory::getSalleServiceImpl();
    metrologueSrv = MetierFactory::getMetrologueServiceImpl();
    materielSrv = MetierFactory::getMaterielServiceImpl();
    batimentSvr =MetierFactory::getBatimentServiceImpl();
    lecteurRFIDSvr =MetierFactory::getLecteurRFIDServiceImpl();
    portiqueSvr =MetierFactory::getPortiqueServiceImpl();

    this->x_ini = 0;
    this->y_ini = 0;
    this->x_fin = 0;
    this->y_fin = 0;

    this->x_curseur = 0;
    this->y_curseur = 0;

    this->boolCoordonneesSalle = false;
    this->boolCoordonneesPortique = false;
    this->boolDoubleClick = false;
    this->boolLabelListeMaterielDansSalle = false;

    this->timerActualisationPlan = new QTimer();
    connect(this->timerActualisationPlan,SIGNAL(timeout()),this,SLOT(resultatVoir()));

    // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8")); // selon la version de QT < 5

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    // lorsque je double clique
    if(this->boolDoubleClick == true){
        // recuperation des coordonnées de la souris
        this->x_curseur = event->x();
        this->y_curseur = event->y();
        // affiche la liste de materiel de la salle d'ou se trouve la souris
        affichageListeMaterielDansSalle();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint coor;
    QString stringCoor;


    if(this->boolCoordonneesSalle){
        QSize sizeLabelPlan = labelPlan->size();
        coor = labelPlan->mapFrom(this,coor);
        // recupere les coordonnées
        this->x_fin = event->x() - abs(coor.x());
        this->y_fin = event->y() - abs(coor.y());
        // converti en pourcentage
        this->x_fin_pourcentage = 100.0*( (float) this->x_fin/sizeLabelPlan.width());
        this->y_fin_pourcentage = 100.0*( (float) this->y_fin/sizeLabelPlan.height());

        // remet les coordonnées dans le bon sens
        if(this->x_ini_pourcentage > this->x_fin_pourcentage){
            float a = this->x_ini_pourcentage;
            this->x_ini_pourcentage = this->x_fin_pourcentage;
            this->x_fin_pourcentage = a;
        }
        if(this->y_ini_pourcentage > this->y_fin_pourcentage){
            float b = this->y_ini_pourcentage;
            this->y_ini_pourcentage = this->y_fin_pourcentage;
            this->y_fin_pourcentage = b;
        }
        stringCoor ="{";
        stringCoor +=QString::number(this->x_ini);
        stringCoor +=";";
        stringCoor +=QString::number(this->y_ini);
        stringCoor +="},{";
        stringCoor +=QString::number(this->x_fin);
        stringCoor +=";";
        stringCoor +=QString::number(this->y_fin);
        stringCoor +="}";
        lineEditCoordonneesSalle->setText(stringCoor);
        this->boolCoordonneesSalle = false;
        this->boolCoordonneesPortique = false;
    }

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // meme principe que mouseReleaseEvent
    QPoint coor;
    QString stringCoor;

    if(this->boolCoordonneesSalle){
        QSize sizeLabelPlan = labelPlan->size();
        coor = labelPlan->mapFrom(this,coor);
        this->x_ini = event->x() - abs(coor.x());
        this->y_ini = event->y() - abs(coor.y());
        this->x_fin = 0;
        this->y_fin = 0;
        this->x_ini_pourcentage = 100.0*( (float) this->x_ini/sizeLabelPlan.width());
        this->y_ini_pourcentage = 100.0*( (float) this->y_ini/sizeLabelPlan.height());
        stringCoor ="{";
        stringCoor +=QString::number(this->x_ini);
        stringCoor +=";";
        stringCoor +=QString::number(this->y_ini);
        stringCoor +="},{";
        stringCoor +=QString::number(this->x_fin);
        stringCoor +=";";
        stringCoor +=QString::number(this->y_fin);
        stringCoor +="}";
        lineEditCoordonneesSalle->setText(stringCoor);
    }

    // clique pour placer le portique
    if(this->boolCoordonneesPortique){
        QSize sizeLabelPlan = labelPlan->size();
        coor = labelPlan->mapFrom(this,coor);
        this->x_ini = event->x() - abs(coor.x());
        this->y_ini = event->y() - abs(coor.y());
        this->x_fin = 0;
        this->y_fin = 0;
        this->x_ini_pourcentage = 100.0*( (float) this->x_ini/sizeLabelPlan.width());
        this->y_ini_pourcentage = 100.0*( (float) this->y_ini/sizeLabelPlan.height());
        stringCoor ="{";
        stringCoor +=QString::number(this->x_ini);
        stringCoor +=";";
        stringCoor +=QString::number(this->y_ini);
        stringCoor +="}";
        lineEditCoordonneesPortique->setText(stringCoor);
        this->boolCoordonneesPortique = false;
    }


}

void MainWindow::rechercheParType()
{
    QStandardItem *item;
    QCheckBox *checkbox;

    QList<Materiel> listMateriel;
    Materiel materiel;
    int nb;
    Type type;

    this->monModel = new QStandardItemModel();
    this->maTable = new QTableView(this);

    viderLayout(ui->layoutDroit);
    viderLabelPlan();

    // verification si les checkBox sont coché
    for(int i = 0 ; i < (ui->layoutGauche->count()-2) ; i++){
        checkbox = (QCheckBox *) ui->layoutGauche->itemAt(i+1)->widget();
        if( checkbox->isChecked()){
            type = typeSrv->getByNomType(checkbox->text());
            nb = materielSrv->getCountByType(type);
            listMateriel.append(materielSrv->getByType(type,0,nb));
        }
    }

    // affiche le materiel ligne par ligne
    for (int i=0;i<listMateriel.count();++i){ // Pour les colonnes
        materiel = listMateriel.at(i);

        item = new QStandardItem();
        item->setText(materiel.getIdBadge());
        this->monModel->setItem(i,0,item);

        item = new QStandardItem();
        item->setText(materiel.getNomMateriel());
        this->monModel->setItem(i,1,item);

        item = new QStandardItem();
        item->setText(materiel.getDateControle().toString());
        this->monModel->setItem(i,2,item);


        item = new QStandardItem();
        item->setText(materiel.getNewDateControle().toString());
        this->monModel->setItem(i,3,item);

        item = new QStandardItem();
        item->setText(materiel.getType().getNomType());
        this->monModel->setItem(i,4,item);

    }

    // nom des colonnes du tableau
    this->monModel->setHeaderData(0,Qt::Horizontal, "Id du badge :");
    this->monModel->setHeaderData(1,Qt::Horizontal, "Nom du materiel :");
    this->monModel->setHeaderData(2,Qt::Horizontal, "Date de controle :");
    this->monModel->setHeaderData(3,Qt::Horizontal, "Prochaine date de controle :");
    this->monModel->setHeaderData(4,Qt::Horizontal, "Type du materiel :");

    // affiche le tableau
    this->maTable->setModel(this->monModel);
    this->maTable->resizeColumnsToContents();
    // evennement lorsque je clique sur une ligne du tableau
    connect(this->maTable, SIGNAL(clicked(QModelIndex)), this,SLOT(clickTable(QModelIndex)));
    ui->layoutDroit->addRow(this->maTable);
}

void MainWindow::rechercheParNom()
{
    // meme principe que rechercheParType
    QStandardItem *item;

    QList<Materiel> listMateriel;
    Materiel materiel;

    this->monModel = new QStandardItemModel();
    this->maTable = new QTableView(this);

    viderLayout(ui->layoutDroit);
    viderLabelPlan();

    listMateriel = materielSrv->getByNomMateriel(lineEditNomMateriel->text(),0,materielSrv->getCountByNomMateriel(lineEditNomMateriel->text()));

    for (int i=0;i<listMateriel.count();++i){ // Pour les colonnes
        materiel = listMateriel.at(i);

        item = new QStandardItem();
        item->setText(materiel.getIdBadge());
        this->monModel->setItem(i,0,item);

        item = new QStandardItem();
        item->setText(materiel.getNomMateriel());
        this->monModel->setItem(i,1,item);

        item = new QStandardItem();
        item->setText(materiel.getDateControle().toString());
        this->monModel->setItem(i,2,item);

        item = new QStandardItem();
        item->setText(materiel.getNewDateControle().toString());
        this->monModel->setItem(i,3,item);

        item = new QStandardItem();
        item->setText(materiel.getType().getNomType());
        this->monModel->setItem(i,4,item);
    }

    this->monModel->setHeaderData(0,Qt::Horizontal, "Id du badge :");
    this->monModel->setHeaderData(1,Qt::Horizontal, "Nom du materiel :");
    this->monModel->setHeaderData(2,Qt::Horizontal, "Date de controle :");
    this->monModel->setHeaderData(3,Qt::Horizontal, "Prochaine date de controle :");
    this->monModel->setHeaderData(4,Qt::Horizontal, "Type du materiel :");

    this->maTable->setModel(this->monModel);
    this->maTable->resizeColumnsToContents();
    connect(this->maTable, SIGNAL(clicked(QModelIndex)), this,SLOT(clickTable(QModelIndex)));
    ui->layoutDroit->addRow(this->maTable);
}

void MainWindow::rechercheParBadge()
{
    // meme principe que rechercheParType
    QStandardItem *item;
    int i = 0;
    Materiel materiel;

    this->monModel = new QStandardItemModel();
    this->maTable = new QTableView(this);

    viderLayout(ui->layoutDroit);
    viderLabelPlan();

    materiel = materielSrv->getByIdBadge(lineEditIdBadge->text());

    item = new QStandardItem();
    item->setText(materiel.getIdBadge());
    this->monModel->setItem(i,0,item);

    item = new QStandardItem();
    item->setText(materiel.getNomMateriel());
    this->monModel->setItem(i,1,item);

    item = new QStandardItem();
    item->setText(materiel.getDateControle().toString());
    this->monModel->setItem(i,2,item);

    item = new QStandardItem();
    item->setText(materiel.getNewDateControle().toString());
    this->monModel->setItem(i,3,item);

    item = new QStandardItem();
    item->setText(materiel.getType().getNomType());
    this->monModel->setItem(i,4,item);

    this->monModel->setHeaderData(0,Qt::Horizontal, "Id du badge :");
    this->monModel->setHeaderData(1,Qt::Horizontal, "Nom du materiel :");
    this->monModel->setHeaderData(2,Qt::Horizontal, "Date de controle :");
    this->monModel->setHeaderData(3,Qt::Horizontal, "Prochaine date de controle :");
    this->monModel->setHeaderData(4,Qt::Horizontal, "Type du materiel :");

    this->maTable->setModel(this->monModel);
    this->maTable->resizeColumnsToContents();
    connect(this->maTable, SIGNAL(clicked(QModelIndex)), this,SLOT(clickTable(QModelIndex)));
    ui->layoutDroit->addRow(this->maTable);
}

void MainWindow::rechercheParBatiment()
{
    // meme principe que rechercheParType
    QStandardItem *item;

    Materiel materiel;
    Batiment batiment;
    Localisation localisation;
    Salle salle;
    QList<Salle> listeSalle;
    QList<Localisation> listeLocalisation;
    int nbLigne=0;

    this->monModel = new QStandardItemModel();
    this->maTable = new QTableView(this);

    viderLayout(ui->layoutDroit);
    viderLabelPlan();

    batiment = batimentSvr->getByNomBatiment(lineEditNomBatiment->text());
    listeSalle = batiment.getSalles();

    for( int i = 0 ; i < listeSalle.count(); i ++){
        salle = listeSalle.at(i);
        listeLocalisation = localisationSrv->getBySalle(salle,0,localisationSrv->getCountBySalle(salle));

        for( int j = 0 ; j < listeLocalisation.count() ; j++ ){

            localisation = listeLocalisation.at(j);
            materiel = localisation.getMateriel();

            item = new QStandardItem();
            item->setText(materiel.getIdBadge());
            this->monModel->setItem(nbLigne,0,item);

            item = new QStandardItem();
            item->setText(materiel.getNomMateriel());
            this->monModel->setItem(nbLigne,1,item);

            item = new QStandardItem();
            item->setText(materiel.getDateControle().toString());
            this->monModel->setItem(nbLigne,2,item);

            item = new QStandardItem();
            item->setText(materiel.getNewDateControle().toString());
            this->monModel->setItem(nbLigne,3,item);

            item = new QStandardItem();
            item->setText(materiel.getType().getNomType());
            this->monModel->setItem(nbLigne,4,item);

            nbLigne++;
        }
    }

    this->monModel->setHeaderData(0,Qt::Horizontal, "Id du badge :");
    this->monModel->setHeaderData(1,Qt::Horizontal, "Nom du materiel :");
    this->monModel->setHeaderData(2,Qt::Horizontal, "Date de controle :");
    this->monModel->setHeaderData(3,Qt::Horizontal, "Prochaine date de controle :");
    this->monModel->setHeaderData(4,Qt::Horizontal, "Type du materiel :");

    this->maTable->setModel(this->monModel);
    this->maTable->resizeColumnsToContents();
    connect(this->maTable, SIGNAL(clicked(QModelIndex)), this,SLOT(clickTable(QModelIndex)));
    ui->layoutDroit->addRow(this->maTable);
}

void MainWindow::rechercheParSalle()
{
    // meme principe que rechercheParType
    QStandardItem *item;

    Materiel materiel;
    Localisation localisation;
    Salle salle;
    QList<Localisation> listeLocalisation;
    int nbLigne=0;

    this->monModel = new QStandardItemModel();
    this->maTable = new QTableView(this);

    viderLayout(ui->layoutDroit);
    viderLabelPlan();

    salle = salleSrv->getByNumSalle(lineEditNumSalle->text().toInt());

    listeLocalisation = localisationSrv->getBySalle(salle,0,localisationSrv->getCountBySalle(salle));

    for( int j = 0 ; j < listeLocalisation.count() ; j++ ){

        localisation = listeLocalisation.at(j);
        materiel = localisation.getMateriel();

        item = new QStandardItem();
        item->setText(materiel.getIdBadge());
        this->monModel->setItem(nbLigne,0,item);

        item = new QStandardItem();
        item->setText(materiel.getNomMateriel());
        this->monModel->setItem(nbLigne,1,item);

        item = new QStandardItem();
        item->setText(materiel.getDateControle().toString());
        this->monModel->setItem(nbLigne,2,item);

        item = new QStandardItem();
        item->setText(materiel.getNewDateControle().toString());
        this->monModel->setItem(nbLigne,3,item);

        item = new QStandardItem();
        item->setText(materiel.getType().getNomType());
        this->monModel->setItem(nbLigne,4,item);

        nbLigne++;
    }

    this->monModel->setHeaderData(0,Qt::Horizontal, "Id du badge :");
    this->monModel->setHeaderData(1,Qt::Horizontal, "Nom du materiel :");
    this->monModel->setHeaderData(2,Qt::Horizontal, "Date de controle :");
    this->monModel->setHeaderData(3,Qt::Horizontal, "Prochaine date de controle :");
    this->monModel->setHeaderData(4,Qt::Horizontal, "Type du materiel :");

    this->maTable->setModel(this->monModel);
    this->maTable->resizeColumnsToContents();
    connect(this->maTable, SIGNAL(clicked(QModelIndex)), this,SLOT(clickTable(QModelIndex)));
    ui->layoutDroit->addRow(this->maTable);
}

void MainWindow::rechercheParControleValide()
{
    // meme principe que rechercheParType
    QStandardItem *item;

    Materiel materiel;
    Salle salle;
    QList<Materiel> listeMateriels;
    QDate dateAujourdHuit = QDate::currentDate();
    int nbLigne=0;

    this->monModel = new QStandardItemModel();
    this->maTable = new QTableView(this);

    viderLayout(ui->layoutDroit);
    viderLabelPlan();

    listeMateriels = materielSrv->getByPeriode(dateAujourdHuit,true,0,materielSrv->getCountByPeriode(dateAujourdHuit,true));

    for( int j = 0 ; j < listeMateriels.count() ; j++ ){

        materiel = listeMateriels.at(j);

        item = new QStandardItem();
        item->setText(materiel.getIdBadge());
        this->monModel->setItem(nbLigne,0,item);

        item = new QStandardItem();
        item->setText(materiel.getNomMateriel());
        this->monModel->setItem(nbLigne,1,item);

        item = new QStandardItem();
        item->setText(materiel.getDateControle().toString());
        this->monModel->setItem(nbLigne,2,item);

        item = new QStandardItem();
        item->setText(materiel.getNewDateControle().toString());
        this->monModel->setItem(nbLigne,3,item);

        item = new QStandardItem();
        item->setText(materiel.getType().getNomType());
        this->monModel->setItem(nbLigne,4,item);

        nbLigne++;
    }

    this->monModel->setHeaderData(0,Qt::Horizontal, "Id du badge :");
    this->monModel->setHeaderData(1,Qt::Horizontal, "Nom du materiel :");
    this->monModel->setHeaderData(2,Qt::Horizontal, "Date de controle :");
    this->monModel->setHeaderData(3,Qt::Horizontal, "Prochaine date de controle :");
    this->monModel->setHeaderData(4,Qt::Horizontal, "Type du materiel :");

    this->maTable->setModel(this->monModel);
    this->maTable->resizeColumnsToContents();
    connect(this->maTable, SIGNAL(clicked(QModelIndex)), this,SLOT(clickTable(QModelIndex)));
    ui->layoutDroit->addRow(this->maTable);
}

void MainWindow::rechercheParControleNonValide()
{
    // meme principe que rechercheParType
    QStandardItem *item;

    Materiel materiel;
//    Salle salle;
    QList<Materiel> listeMateriels;
    QDate dateAujourdHuit = QDate::currentDate();
    int nbLigne=0;

    this->monModel = new QStandardItemModel();
    this->maTable = new QTableView(this);

    viderLayout(ui->layoutDroit);
    viderLabelPlan();

    listeMateriels = materielSrv->getByPeriode(dateAujourdHuit, false, 0, materielSrv->getCountByPeriode(dateAujourdHuit,false));

    for( int j = 0 ; j < listeMateriels.count() ; j++ ){

        materiel = listeMateriels.at(j);

        item = new QStandardItem();
        item->setText(materiel.getIdBadge());
        this->monModel->setItem(nbLigne,0,item);

        item = new QStandardItem();
        item->setText(materiel.getNomMateriel());
        this->monModel->setItem(nbLigne,1,item);

        item = new QStandardItem();
        item->setText(materiel.getDateControle().toString());
        this->monModel->setItem(nbLigne,2,item);

        item = new QStandardItem();
        item->setText(materiel.getNewDateControle().toString());
        this->monModel->setItem(nbLigne,3,item);

        item = new QStandardItem();
        item->setText(materiel.getType().getNomType());
        this->monModel->setItem(nbLigne,4,item);

        nbLigne++;
    }

    this->monModel->setHeaderData(0,Qt::Horizontal, "Id du badge :");
    this->monModel->setHeaderData(1,Qt::Horizontal, "Nom du materiel :");
    this->monModel->setHeaderData(2,Qt::Horizontal, "Date de controle :");
    this->monModel->setHeaderData(3,Qt::Horizontal, "Prochaine date de controle :");
    this->monModel->setHeaderData(4,Qt::Horizontal, "Type du materiel :");

    this->maTable->setModel(this->monModel);
    this->maTable->resizeColumnsToContents();
    connect(this->maTable, SIGNAL(clicked(QModelIndex)), this,SLOT(clickTable(QModelIndex)));
    ui->layoutDroit->addRow(this->maTable);
}

void MainWindow::rechercheCheminPlan()
{
    // va chercher le plan sur le disque et l'affiche
    viderLayout(ui->layoutDroit);
    QString adresse = QFileDialog::getOpenFileName(this, "Ouvrir", ":/images/image", "Fichier image (*.bmp *.gif *.jpg *.jpeg *.png)");
    lineEditCheminPlan->setText(adresse);

    viderLayout(ui->layoutDroit);
    viderLabelPlan();

    labelPlan = new QLabel();
    labelPlan->setPixmap(QPixmap(adresse));
    labelPlan->adjustSize();
    labelPlan->setScaledContents(true);
    labelPlan->resize(785,571);
    ui->layoutDroit->addWidget(labelPlan);
}

void MainWindow::recupererPlan(QString nomBatiment)
{
    // affiche le plan en fonction du nom de batiment
    if(comboBoxNomBatiment->currentIndex()>0){
        affichePlanComplet(nomBatiment);
    }else{
        viderLabelPlan();
        viderLayout(ui->layoutDroit);
    }
}

void MainWindow::prendreCoordonneesSalle()
{
    // preparation pour la recuperation de coordonnées
    if(comboBoxNomBatiment->currentIndex()!=0){
        QMessageBox::information(this,"","1) Clic droit pour prendre les coordonnées en haut a gauche de la salle,\n2) Relachez pour prendre les coordonnées en bas a droite");
        this->boolCoordonneesSalle = true;
    }else
        QMessageBox::critical(this,"","Veuillez sélectionner un batiment");
}

void MainWindow::prendreCoordonneesPortique()
{
    // preparation pour la recuperation de coordonnées
    if(comboBoxNomBatiment->currentIndex()!=0){
        QMessageBox::information(this,"","1) Clic gauche pour prendre les coordonnées du portique");
        this->boolCoordonneesPortique = true;
    }else
        QMessageBox::critical(this,"","Veuillez sélectionner un batiment");
}

void MainWindow::creerBatiment()
{
    // récupère les valeurs que j'ai saisi
    QString nomBatiment = lineEditNomBatiment->text();
    QString nomPlan = lineEditCheminPlan->text();
    // vérification des valeurs
    if( nomBatiment == "" || nomPlan == ""){
        QMessageBox::critical(this,"Erreur","Veuillez saisir tous les champs");
    }else{
        // vérification par le nom du batiment s'il n'est pas déjà dans la base de données
        if(batimentSvr->getByNomBatiment(nomBatiment).getId()>0){
            QMessageBox::critical(this,"Erreur","Nom de batiment déjà utilisé");
        }else{
            // sinon je crée une liste de salles vides, et je crée l'objet batiment
            QList<Salle> listeSalles;
            Batiment batiment = Batiment(nomBatiment, listeSalles, nomPlan);
            // si l'id retourné est 0 alors la sauvegarde n'a pas été faite
            if(batimentSvr->add(batiment).getId() > 0){
                QMessageBox::information(this,"Validation","Le batiment a été sauvegardé");
                on_actionCreerBatiment_triggered();
            }else{
                QMessageBox::critical(this,"Erreur","Le batiment n'a pas été sauvegardé");
            }
        }
    }
}

void MainWindow::modifierBatiment()
{
    // modification de batiment
    QString nomBatiment = lineEditNomBatiment->text();
    QString nomPlan = lineEditCheminPlan->text();
    Batiment batimentAModifier = batimentSvr->getByNomBatiment(comboBoxNomBatiment->currentText());
    batimentAModifier.setNomBatiment(nomBatiment);
    batimentAModifier.setPlan(nomPlan);

    if( nomBatiment == "" || nomPlan == ""){
        QMessageBox::critical(this,"Erreur","Veuillez saisir tous les champs");
    }else{
        if(batimentSvr->update(batimentAModifier)){
            QMessageBox::information(this,"Validation","Le batiment a été modifié");
            on_actionModifierBatiment_triggered();
        }else{
            QMessageBox::critical(this,"Erreur","Le batiment n'a été pas modifié");
        }
    }
    viderLabelPlan();
    viderLayout(ui->layoutDroit);
    affichePlanComplet(nomBatiment);
}

void MainWindow::supprimerBatiment()
{
    // suppression de batiment
    QString nomBatiment = lineEditNomBatiment->text();
    Batiment batiment = batimentSvr->getByNomBatiment(nomBatiment);

    if(!batimentSvr->getByNomBatiment(nomBatiment).getId()>0){
        QMessageBox::critical(this,"Erreur","Le batiment n'existe pas");
    }else{
        if(batimentSvr->remove(batiment)){
            QMessageBox::information(this,"Validation","Le batiment a été supprimé");
            on_actionSupprimerBatiment_triggered();
        }else{
            QMessageBox::critical(this,"Erreur","Le batiment n'a été pas supprimé");
        }
    }
    viderLabelPlan();
    viderLayout(ui->layoutDroit);
}

void MainWindow::creerSalle()
{
    // création de la salle
    Batiment batiment = batimentSvr->getByNomBatiment(comboBoxNomBatiment->currentText());
    Salle salle;
    QList<Salle> listeSalles;
    int numSalle = lineEditNumSalle->text().toInt();
    QString nomSalle = lineEditNomSalle->text();
    QString nomAtelier = lineEditNomAtelier->text();
    QString coor = lineEditCoordonneesSalle->text();

    if(comboBoxNomBatiment->currentIndex()>0){
        if( numSalle<=0 || nomSalle == "" || nomAtelier == "" || coor == "" ){
            QMessageBox::critical(this,"Erreur","Veuillez saisir tous les champs");
        }else{
            salle = salleSrv->getByNumSalle(numSalle);
            if(salle.getId() > 0){
                QMessageBox::critical(this,"Erreur","La salle est déjà existante");
            }else{
                QSize sizeLabelPlan = labelPlan->size();
                if(     this->x_fin > sizeLabelPlan.width() || this->x_fin < 0 ||
                        this->y_fin > sizeLabelPlan.height() || this->y_fin < 0 ||
                        this->x_ini > sizeLabelPlan.width() || this->x_ini < 0 ||
                        this->y_ini > sizeLabelPlan.height() || this->y_ini < 0 ){
                    QMessageBox::critical(this,"Erreur","Les coordonnées ne sont pas correctes");
                }else{
                    salle = Salle(this->x_ini_pourcentage,this->y_ini_pourcentage,this->x_fin_pourcentage,this->y_fin_pourcentage,numSalle,nomSalle,nomAtelier);
                    salle = salleSrv->add(salle);
                    if(salle.getId()>0){
                        listeSalles =  batiment.getSalles();
                        listeSalles.append(salle);
                        batiment.setSalles(listeSalles);
                        if(batimentSvr->update(batiment)){
                            lineEditNumSalle->setText("");
                            lineEditNomSalle->setText("");
                            lineEditNomAtelier->setText("");
                            lineEditCoordonneesSalle->setText("");
                            viderLabelPlan();
                            viderLayout(ui->layoutDroit);
                            affichePlanComplet(batiment.getNomBatiment());
                            QMessageBox::information(this,"Validation","La salle a été sauvegardée");
                        }else{
                            salleSrv->remove(salle);
                            QMessageBox::critical(this,"Erreur","La salle n'a pas été sauvegardée");
                        }
                    }else{
                        QMessageBox::critical(this,"Erreur","La salle n'a pas été sauvegardée");
                    }

                }
            }
        }
    }else{
        QMessageBox::critical(this,"Erreur","Veuillez sélectionner un batiment");
    }
}

void MainWindow::modifierSalle()
{
    // modification de la salle
    QString nomSalle = lineEditNomSalle->text();
    QString nomAtelier = lineEditNomAtelier->text();
    Salle salleAModifier;

    if( !comboBoxNumSalle->currentText().toInt() > 0){
        QMessageBox::critical(this,"Erreur","Veuillez sélectionner une salle ");
    }else{
        if(     this->x_fin_pourcentage > 100.0 || this->x_fin_pourcentage < 0 ||
                this->y_fin_pourcentage > 100.0 || this->y_fin_pourcentage < 0 ||
                this->x_ini_pourcentage > 100.0 || this->x_ini_pourcentage < 0 ||
                this->y_ini_pourcentage > 100.0 || this->y_ini_pourcentage < 0 ){
            QMessageBox::critical(this,"Erreur","Les coordonnées ne sont pas correctes");
        }else{
            if( !lineEditNumSalle->text().toInt() > 0 || !nomSalle.compare("") || !nomAtelier.compare("") ){
                QMessageBox::critical(this,"Erreur","Veuillez saisir tous les champs");
            }else{
                salleAModifier = salleSrv->getByNumSalle(comboBoxNumSalle->currentText().toInt());
                salleAModifier.setNumSalle(lineEditNumSalle->text().toInt());
                salleAModifier.setNomSalle(nomSalle);
                salleAModifier.setNomAtelier(nomAtelier);
                salleAModifier.setX_ini(this->x_ini_pourcentage);
                salleAModifier.setY_ini(this->y_ini_pourcentage);
                salleAModifier.setX_fin(this->x_fin_pourcentage);
                salleAModifier.setY_fin(this->y_fin_pourcentage);

                if(salleSrv->update(salleAModifier)){
                    viderLabelPlan();
                    viderLayout(ui->layoutDroit);
                    affichePlanComplet(comboBoxNomBatiment->currentText());
                    QMessageBox::information(this,"Validation","La salle a été sauvegardée");
                    on_actionModifierSalle_triggered();
                }else{
                    QMessageBox::critical(this,"Erreur","La salle n'a pas été sauvegardée");
                }
            }
        }
    }
}

void MainWindow::supprimerSalle()
{
    // suppression de la salle
    Salle salle;
    if( !lineEditNumSalle->text().toInt() > 0){
        QMessageBox::critical(this,"Erreur","Veuillez saisir une salle");
    }else{
        if(!salleSrv->getByNumSalle(lineEditNumSalle->text().toInt()).getId()>0){
            QMessageBox::critical(this,"Erreur","Le batiment n'existe pas");
        }else{
            salle = salleSrv->getByNumSalle(lineEditNumSalle->text().toInt());
            if(salleSrv->remove(salle)){
                QMessageBox::information(this,"Validation","La salle a été supprimé");
                viderLabelPlan();
                viderLayout(ui->layoutDroit);
                affichePlanComplet(comboBoxNomBatiment->currentText());
                on_actionSupprimerSalle_triggered();
            }else{
                QMessageBox::critical(this,"Erreur","La salle n'a été pas supprimé");
            }
        }
    }
}

void MainWindow::creerPortique()
{
    // créarion de portique
    QString ipLecteur = lineEditIpLecteur->text();
    QString coor = lineEditCoordonneesPortique->text();
    Salle salle1;
    Salle salle2;
    Portique portique;
    LecteurRFID lecteurRFID;

    if( ipLecteur == "" || !lineEditNumSallePortique1->text().toInt() > 0 || coor == ""){
        QMessageBox::critical(this,"Erreur","Veuillez saisir tous les champs");
    }else{
        if(
                this->x_ini_pourcentage > 100.0 || this->x_ini_pourcentage < 0 ||
                this->y_ini_pourcentage > 100.0 || this->y_ini_pourcentage < 0 ){
            QMessageBox::critical(this,"Erreur","Les coordonnées ne sont pas correctes");
        }else{
            salle1 = salleSrv->getByNumSalle(lineEditNumSallePortique1->text().toInt());
            if(salle1.getId()>0){
                lecteurRFID = lecteurRFIDSvr->getByIp(ipLecteur);

                if(lecteurRFID.getId() > 0){
                    portique = Portique(this->x_ini_pourcentage,this->y_ini_pourcentage,salle1,salle2,lecteurRFID);

                    if(lineEditNumSallePortique2->text().toInt() > 0 && lineEditNumSallePortique2->text().toInt() != lineEditNumSallePortique1->text().toInt()){

                        salle2 = salleSrv->getByNumSalle(lineEditNumSallePortique2->text().toInt());
                        if(salle2.getId()>0){
                            portique.setSalle2(salle2);
                            portique = portiqueSvr->add(portique);
                            if(portique.getId() > 0){
                                QMessageBox::information(this,"Validation","Le portique a été sauvegargé");
                                on_actionCreerPortique_triggered();
                            }else{
                                QMessageBox::critical(this,"Erreur","Le portique n'a pas été sauvegargé");
                            }
                        }else{
                            QMessageBox::critical(this,"Erreur","La salle n°2 est incorecte");
                        }

                    }else{
                        portique = portiqueSvr->add(portique);
                        if(portique.getId() > 0){
                            QMessageBox::information(this,"Validation","Le portique a été sauvegargé");
                            on_actionCreerPortique_triggered();
                        }else{
                            QMessageBox::critical(this,"Erreur","Le portique n'a pas été sauvegargé");
                        }
                    }
                }else{
                    QMessageBox::critical(this,"Erreur","Le lecteur est incorecte");
                }
            }else{
                QMessageBox::critical(this,"Erreur","La salle n°1 est incorecte");
            }
        }
    }
}

void MainWindow::modifierPortique()
{
    QMessageBox::information(this, "Info", "Partie non gérée !");
}

void MainWindow::supprimerPortique()
{
    // suppression du portique
    Portique portique;
    LecteurRFID lecteurRFID;

    if(comboBoxNomBatiment->currentText().compare(" ")){
        if( !lineEditIpLecteur->text().compare("")){
            QMessageBox::critical(this,"Erreur","Veuillez sélectionner l'@ip du portique");
        }else{
            lecteurRFID = lecteurRFIDSvr->getByIp(lineEditIpLecteur->text());
            portique = portiqueSvr->getByLecteurRFID(lecteurRFID);
            if( portique.getId() < 1 ){
                QMessageBox::critical(this,"Erreur","Le portique n'existe pas");
            }else{
                if(portiqueSvr->remove(portique)){
                    QMessageBox::information(this,"Validation","Le portique a été supprimé");
                    viderLabelPlan();
                    viderLayout(ui->layoutDroit);
                    affichePlanComplet(comboBoxNomBatiment->currentText());
                    on_actionSupprimerPortique_triggered();
                }else{
                    QMessageBox::critical(this,"Erreur","Le portique n'a été pas supprimé");
                }
            }
        }
    }else{
        QMessageBox::critical(this,"Erreur","Veuillez sélectionner un batiment");
    }
}

void MainWindow::recupererInfoBatiment(QString contenu)
{
    // affiche les info dans les lineEdit
    Batiment batiment;
    viderLayout(ui->layoutDroit);
    viderLabelPlan();
    batiment = batimentSvr->getByNomBatiment(contenu);
    if(!contenu.compare(" ")){
        lineEditNomBatiment->setText("");
        lineEditCheminPlan->setText("");
    }else{
        lineEditNomBatiment->setText(batiment.getNomBatiment());
        lineEditCheminPlan->setText(batiment.getPlan());
        affichePlanComplet(batiment.getNomBatiment());
    }
}

void MainWindow::recupererInfoSalle(QString contenu)
{
    // affiche les info dans les lineEdit
    Salle salle;
    QString stringCoor;
    QLabel *label;
    QSize size;
    QPoint coordonneesLabelPlan;
    float intToFloat;
    int x,y;
    viderLayout(ui->layoutDroit);
    viderLabelPlan();
    affichePlanComplet(comboBoxNomBatiment->currentText());

    if(contenu.compare(" ") && comboBoxNumSalle->currentText().toInt()>0 ){
        salle = salleSrv->getByNumSalle(comboBoxNumSalle->currentText().toInt());
        lineEditNumSalle->setText(QString::number(salle.getNumSalle()));
        lineEditNomSalle->setText(salle.getNomSalle());
        lineEditNomAtelier->setText(salle.getNomAtelier());
        stringCoor ="{";
        stringCoor +=QString::number(salle.getX_ini());
        stringCoor +=";";
        stringCoor +=QString::number(salle.getY_ini());
        stringCoor +="},{";
        stringCoor +=QString::number(salle.getX_fin());
        stringCoor +=";";
        stringCoor +=QString::number(salle.getY_fin());
        stringCoor +="}";
        lineEditCoordonneesSalle->setText(stringCoor);
        this->x_ini_pourcentage = salle.getX_ini();
        this->y_ini_pourcentage = salle.getY_ini();
        this->x_fin_pourcentage = salle.getX_fin();
        this->y_fin_pourcentage = salle.getY_fin();

        coordonneesLabelPlan = labelPlan->mapFrom(this,coordonneesLabelPlan);

        label = new QLabel(this);
        label->setPixmap(QPixmap(":/images/image/logo.png"));
        label->adjustSize();
        size = label->size();

        intToFloat = (labelPlan->width()*salle.getX_fin()/100);
        x = (int)intToFloat;
        x += abs(coordonneesLabelPlan.x()) + 5 - size.width();

        intToFloat = (labelPlan->height()*salle.getY_ini()/100);
        y = (int)intToFloat;
        y += abs(coordonneesLabelPlan.y());

        label->move(x, y);
        label->show();
        this->listLabelPlan.append(label);

    }else{
        lineEditNumSalle->setText("");
        lineEditNomSalle->setText("");
        lineEditNomAtelier->setText("");
        lineEditCoordonneesSalle->setText("");
    }
}

void MainWindow::recupererInfoPortique(QString contenu)
{
    // affiche les info dans les lineEdit
    disconnect(lineEditIpLecteur, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditIpLecteur(QString)));    
    disconnect(lineEditNumSallePortique1, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNumSallePortique1(QString)));
    disconnect(lineEditNumSallePortique2, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNumSallePortique2(QString)));

    viderLayout(ui->layoutDroit);
    viderLabelPlan();
    affichePlanComplet(comboBoxNomBatiment->currentText());

    QString stringCoor;
    QLabel *label;
    QSize size;
    QPoint coordonneesLabelPlan;
    float intToFloat;
    int x,y;
    LecteurRFID lecteurRFID = lecteurRFIDSvr->getByIp(contenu);
    Portique portique = portiqueSvr->getByLecteurRFID(lecteurRFID);

    if(contenu.compare(" ")){
        lineEditIpLecteur->setText(contenu);
        lineEditNumSallePortique1->setText(QString::number(portique.getSalle1().getNumSalle()));
        lineEditNumSallePortique2->setText(QString::number(portique.getSalle2().getNumSalle()));
        stringCoor = "{";
        stringCoor += QString::number(portique.getX());
        stringCoor += ";";
        stringCoor += QString::number(portique.getY());
        stringCoor += "}";
        lineEditCoordonneesPortique->setText(stringCoor);

        coordonneesLabelPlan = labelPlan->mapFrom(this,coordonneesLabelPlan);

        label = new QLabel(this);
        label->setPixmap(QPixmap(":/images/image/croix.jpg"));
        label->adjustSize();
        size = label->size();

        intToFloat = (labelPlan->width()*portique.getX()/100);
        x = (int)intToFloat - size.width()/2;
        x += abs(coordonneesLabelPlan.x()) + 5;

        intToFloat = (labelPlan->height()*portique.getY()/100);
        y = (int)intToFloat - size.height()/2;
        y += abs(coordonneesLabelPlan.y());

        label->move(x, y);
        label->show();
        this->listLabelPlan.append(label);
    }else{
        lineEditIpLecteur->setText(" ");
        lineEditNumSallePortique1->setText(" ");
        lineEditNumSallePortique2->setText(" ");
        lineEditCoordonneesPortique->setText(" ");
    }
    connect(lineEditIpLecteur, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditIpLecteur(QString)));
    connect(lineEditNumSallePortique1, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNumSallePortique1(QString)));
    connect(lineEditNumSallePortique2, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNumSallePortique2(QString)));

}

void MainWindow::resultatVoir()
{
    affichePlanComplet(lineEditNomBatiment->text());
//    qWarning("actualisation plan");
}

void MainWindow::resultatVoirEtTimer()
{
    // active le timer
    this->boolDoubleClick = true;
    this->timerActualisationPlan->start(2000);
    affichePlanComplet(lineEditNomBatiment->text());
}

void MainWindow::affichageListeMaterielDansSalle()
{
    // récupere le nom du batiment
    Batiment batiment = batimentSvr->getByNomBatiment(comboBoxNomBatiment->currentText());
    QList<Salle> listeSalles = batiment.getSalles();
    QList<Localisation> listeLocalisations;
    Salle salle;
    Localisation localisation;
    QString phrase;
    // vide la liste s'il y en a déjà une
    viderLabelListeMaterielDansSalle();
    // recupere les coordonnées du plan et sa taille
    QPoint coordonneesLabelPlan;
    coordonneesLabelPlan = labelPlan->mapFrom(this,coordonneesLabelPlan);
    QSize sizeLabelPlan = labelPlan->size();
    // soustrait les coordonnées du plan à la position du double click de ma souris
    this->x_curseur = this->x_curseur - abs(coordonneesLabelPlan.x());
    this->y_curseur = this->y_curseur - abs(coordonneesLabelPlan.y());
    // pour chaque salle du plan concerné
    for(int i = 0 ; i < listeSalles.count() ; i++ ){
        salle = listeSalles.at(i);
        // reconverti le poucentage dans la base en nombre de pixel
        this->x_ini = (int) (sizeLabelPlan.width() * salle.getX_ini()) / 100;
        this->y_ini = (int) (sizeLabelPlan.height() * salle.getY_ini() / 100);
        this->x_fin = (int) (sizeLabelPlan.width() * salle.getX_fin() / 100);
        this->y_fin = (int) (sizeLabelPlan.height() * salle.getY_fin() / 100);
        // vérifie si le double clic est contenu dans les coordonnées d'une salle
        if(     this->x_curseur > this->x_ini && this->x_curseur < this->x_fin &&
                this->y_curseur > this->y_ini && this->y_curseur < this->y_fin ){
            // si oui j'affiche ce label
            this->labelListeMaterielDansSalle = new QLabel(this);
            phrase = "-> Dans la salle n° ";
            phrase += QString::number(salle.getNumSalle());
            phrase += " :\n\n";
            //je récupere la liste de localisation concernant cette salle
            listeLocalisations = localisationSrv->getBySalle(salle, 0 , localisationSrv->getCountBySalle(salle));
            // pour chaque localisation
            for(int j = 0 ; j < listeLocalisations.count() ; j++ ){
                localisation = listeLocalisations.at(j);
                if(localisation.getSortie() == false){
                    // j'affiche le nom du materiel avec son type
                    phrase += localisation.getMateriel().getNomMateriel();
                    phrase += ", ";
                    phrase += localisation.getMateriel().getType().getNomType();
                    phrase += "\n";
                }
            }

            // je positionne le label
            this->labelListeMaterielDansSalle->setText(phrase);
            this->labelListeMaterielDansSalle->adjustSize();
            this->labelListeMaterielDansSalle->move(10, 150);
            this->labelListeMaterielDansSalle->show();
            this->boolLabelListeMaterielDansSalle = true;
            break;
        }
    }
}

void MainWindow::clickTable(QModelIndex modelIndex)
{
    // lorsque je clique sur une ligne du tableau et gere l'affichage en dessous du tableau
    QLabel *label = new QLabel();
    Localisation localisation;
    Batiment batiment;
    QString idBadge;

    viderLayoutExFirst(ui->layoutDroit);

    int row = modelIndex.row();

    idBadge = this->monModel->item(row,0)->data(2).toString();
    localisation = localisationSrv->getByMateriel(materielSrv->getByIdBadge(idBadge));

    ui->layoutDroit->addRow(" ", label);
    ui->layoutDroit->addRow("Informations sur le materiel :", label);

    label = new QLabel(idBadge);
    ui->layoutDroit->addRow("-> Id du badge :", label);

    label = new QLabel(this->monModel->item(row,1)->data(2).toString());
    ui->layoutDroit->addRow("-> Nom du materiel :", label);

    label = new QLabel(this->monModel->item(row,2)->data(2).toString());
    ui->layoutDroit->addRow("-> Date de controle :", label);

    label = new QLabel(this->monModel->item(row,3)->data(2).toString());
    ui->layoutDroit->addRow("-> Prochaine date de controle :", label);

    label = new QLabel(this->monModel->item(row,4)->data(2).toString());
    ui->layoutDroit->addRow("-> Type du materiel :", label);

    label = new QLabel();
    ui->layoutDroit->addRow(" ", label);

    label = new QLabel();
    if(localisation.getSortie()){
        ui->layoutDroit->addRow("Sortie de la salle :", label);
    }else
        ui->layoutDroit->addRow("Actuellement dans la salle :", label);

    label = new QLabel(QString::number(localisation.getSalle().getNumSalle()));
    ui->layoutDroit->addRow("-> Numero de la salle :", label);


    label = new QLabel(localisation.getSalle().getNomSalle());
    ui->layoutDroit->addRow("-> Nom de la salle :", label );


    label = new QLabel(localisation.getSalle().getNomAtelier());
    ui->layoutDroit->addRow("-> Nom de l'atelier :", label);

    batiment = batimentSvr->getBySalle(localisation.getSalle());
    label = new QLabel(batiment.getNomBatiment());
    ui->layoutDroit->addRow("-> Nom du batiment :", label);

    label = new QLabel();
    ui->layoutDroit->addRow(" ", label);

    salleSituer = salleSrv->getByNumSalle(localisation.getSalle().getNumSalle());

    QPushButton *pushButton = new QPushButton("Situer sur le plan", this);
    ui->layoutDroit->addRow(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(situerSurLePlan()));

}

void MainWindow::situerSurLePlan()
{
    // affiche la croix sur le plan
    viderLayout(ui->layoutDroit);
    Batiment batiment = batimentSvr->getBySalle(this->salleSituer);

    float intToFloat;
    int x,y;
    QLabel *label;
    QSize size;
    affichePlanComplet(batiment.getNomBatiment());
    QPoint coordonneesLabelPlan;
    coordonneesLabelPlan = labelPlan->mapFrom(this,coordonneesLabelPlan);

    label = new QLabel(this);
    label->setPixmap(QPixmap(":/images/image/logo.png")); //croix.jpg
    label->adjustSize();
    size = label->size();

    intToFloat = (labelPlan->width()*this->salleSituer.getX_fin()/100);
    x = (int)intToFloat;
    x += abs(coordonneesLabelPlan.x()) + 5 - size.width();

    intToFloat = (labelPlan->height()*this->salleSituer.getY_ini()/100);
    y = (int)intToFloat;
    y += abs(coordonneesLabelPlan.y());

    label->move(x, y);
    label->show();

    this->listLabelPlan.append(label);
}

void MainWindow::indexChangedComboBoxNomMateriel(QString contenu)
{
    // lorsque je selectionne une ligne dans mon comboBox
    disconnect(lineEditNomMateriel, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNomMateriel(QString)));
    lineEditNomMateriel->setText(QString(contenu));
    connect(lineEditNomMateriel, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNomMateriel(QString)));
}

void MainWindow::textChangedLineEditNomMateriel(QString contenu)
{
    // réduit la liste du comboBox selon le contenu du lineEdit
    QString mot;
    for(int i = 1 ; i<comboBoxNomMateriel->count() ;){
        comboBoxNomMateriel->removeItem(i);
    }
    for(int i = 0 ; i<listStringNomMateriel.count() ; i++){
        mot = listStringNomMateriel.at(i);
        if(mot.contains(contenu,Qt::CaseInsensitive)){
            comboBoxNomMateriel->addItem(mot);
        }
    }
}

void MainWindow::indexChangedComboBoxIdBadge(QString contenu)
{
    disconnect(lineEditIdBadge, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditIdBadge(QString)));
    lineEditIdBadge->setText(QString(contenu));
    connect(lineEditIdBadge, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditIdBadge(QString)));
}

void MainWindow::textChangedLineEditIdBadge(QString contenu)
{
    QString mot;
    for(int i = 1 ; i<comboBoxIdBadge->count() ;){
        comboBoxIdBadge->removeItem(i);
    }
    for(int i = 0 ; i<listStringIdBadge.count() ; i++){
        mot = listStringIdBadge.at(i);
        if(mot.contains(contenu,Qt::CaseInsensitive)){
            comboBoxIdBadge->addItem(mot);
        }
    }
}

void MainWindow::indexChangedComboBoxNomBatimentSalle(QString contenu)
{
    Batiment batiment;
    Salle salle;
    QList<Salle> listeSalle;
    disconnect(lineEditNomBatiment, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNomBatiment(QString)));

    if(!contenu.compare(" ")){
        comboBoxNumSalle->clear();
        comboBoxNumSalle->addItem(" ");
        viderLabelPlan();
        viderLayout(ui->layoutDroit);
    }else{
        lineEditNomBatiment->setText(QString(contenu));
        batiment = batimentSvr->getByNomBatiment(contenu);
        listeSalle = batiment.getSalles();
        comboBoxNumSalle->clear();
        comboBoxNumSalle->addItem(" ");
        for( int i = 0 ; i < listeSalle.count() ; i++ ){
            salle = listeSalle.at(i);
            comboBoxNumSalle->addItem(QString::number(salle.getNumSalle()));
            listStringNumSalle.append(QString::number(salle.getNumSalle()));
        }
    }
    connect(lineEditNomBatiment, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNomBatiment(QString)));

}

void MainWindow::indexChangedComboBoxNomBatimentCreerPortique(QString contenu)
{
    Batiment batiment;
    Salle salle;
    QList<Salle> listeSalle;
    disconnect(lineEditNomBatiment, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNomBatiment(QString)));

    if(!contenu.compare(" ")){
        comboBoxNumSallePortique1->clear();
        comboBoxNumSallePortique1->addItem(" ");
        comboBoxNumSallePortique2->clear();
        comboBoxNumSallePortique2->addItem(" ");
        viderLabelPlan();
        viderLayout(ui->layoutDroit);
    }else{
        lineEditNomBatiment->setText(QString(contenu));
        batiment = batimentSvr->getByNomBatiment(contenu);
        listeSalle = batiment.getSalles();
        comboBoxNumSallePortique1->clear();
        comboBoxNumSallePortique1->addItem(" ");
        comboBoxNumSallePortique2->clear();
        comboBoxNumSallePortique2->addItem(" ");
        for( int i = 0 ; i < listeSalle.count() ; i++ ){
            salle = listeSalle.at(i);
            comboBoxNumSallePortique1->addItem(QString::number(salle.getNumSalle()));
            listStringNumSallePortique1.append(QString::number(salle.getNumSalle()));
            comboBoxNumSallePortique2->addItem(QString::number(salle.getNumSalle()));
            listStringNumSallePortique2.append(QString::number(salle.getNumSalle()));
        }
        affichePlanComplet(contenu);
    }
    connect(lineEditNomBatiment, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNomBatiment(QString)));
}

void MainWindow::indexChangedComboBoxNomBatimentSupprimerPortique(QString contenu)
{
    QList<Portique> listePortique;
    Batiment batiment;
    Portique portique;
    Salle salle;
    QList<Salle> listeSalle;
    listStringIpLecteur.clear();

    if(!contenu.compare(" ")){
        comboBoxIpLecteur->clear();
        comboBoxIpLecteur->addItem(" ");
        lineEditNumSallePortique1->clear();
        lineEditNumSallePortique2->clear();
        lineEditCoordonneesPortique->clear();
        viderLabelPlan();
        viderLayout(ui->layoutDroit);
    }else{
        batiment = batimentSvr->getByNomBatiment(contenu);
        listeSalle = batiment.getSalles();

        for( int i = 0 ; i < listeSalle.count() ; i++ ){
            salle = listeSalle.at(i);
            listePortique = portiqueSvr->getBySalle(salle,0,portiqueSvr->getCountBySalle(salle));

            for(int j = 0 ; j < listePortique.count() ; j++){

                portique = listePortique.at(j);
                listStringIpLecteur.append(portique.getLecteurRFID().getIp());
            }
        }

        listStringIpLecteur = getDifferent(listStringIpLecteur);

        comboBoxIpLecteur->addItems(listStringIpLecteur);
        lineEditNumSallePortique1->clear();
        lineEditNumSallePortique2->clear();
        lineEditCoordonneesPortique->clear();
        affichePlanComplet(contenu);
    }
}

void MainWindow::textChangedLineEditNomBatiment(QString contenu)
{
    QString mot;
    for(int i = 1 ; i<comboBoxNomBatiment->count() ;){
        comboBoxNomBatiment->removeItem(i);
    }
    for(int i = 0 ; i<listStringNomBatiment.count() ; i++){
        mot = listStringNomBatiment.at(i);
        if(mot.contains(contenu,Qt::CaseInsensitive)){
            comboBoxNomBatiment->addItem(mot);
        }
    }
}

void MainWindow::indexChangedComboBoxNumSalle(QString contenu)
{
    disconnect(lineEditNumSalle, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNumSalle(QString)));
    lineEditNumSalle->setText(QString(contenu));
    connect(lineEditNumSalle, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNumSalle(QString)));
}

void MainWindow::textChangedLineEditNumSalle(QString contenu)
{
    QString mot;
    for(int i = 1 ; i<comboBoxNumSalle->count() ;){
        comboBoxNumSalle->removeItem(i);
    }
    for(int i = 0 ; i<listStringNumSalle.count() ; i++){
        mot = listStringNumSalle.at(i);
        if(mot.contains(contenu,Qt::CaseInsensitive)){
            comboBoxNumSalle->addItem(mot);
        }
    }
}

void MainWindow::indexChangedComboBoxNumSallePortique1(QString contenu)
{
    disconnect(lineEditNumSallePortique1, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNumSallePortique1(QString)));
    lineEditNumSallePortique1->setText(QString(contenu));
    if(contenu.compare(" ")){
        lineEditNumSallePortique2->setEnabled(true);
        comboBoxNumSallePortique2->setEnabled(true);
    }else{
        comboBoxNumSallePortique2->setCurrentIndex(0);
        lineEditNumSallePortique2->setEnabled(false);
        comboBoxNumSallePortique2->setEnabled(false);
    }
    connect(lineEditNumSallePortique1, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNumSallePortique1(QString)));
}

void MainWindow::textChangedLineEditNumSallePortique1(QString contenu )
{
    QString mot;
    if(contenu.compare("")){
        for(int i = 1 ; i<comboBoxNumSallePortique1->count() ;){
            comboBoxNumSallePortique1->removeItem(i);
        }
        for(int i = 0 ; i<listStringNumSallePortique1.count() ; i++){
            mot = listStringNumSallePortique1.at(i);
            if(mot.contains(contenu,Qt::CaseInsensitive)){
                comboBoxNumSallePortique1->addItem(mot);
            }
        }
        lineEditNumSallePortique2->setEnabled(true);
        comboBoxNumSallePortique2->setEnabled(true);
    }else{
        comboBoxNumSallePortique2->setCurrentIndex(0);
        lineEditNumSallePortique2->setEnabled(false);
        comboBoxNumSallePortique2->setEnabled(false);
    }
}

void MainWindow::indexChangedComboBoxNumSallePortique2(QString contenu)
{
    disconnect(lineEditNumSallePortique2, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNumSallePortique2(QString)));
    lineEditNumSallePortique2->setText(QString(contenu));
    connect(lineEditNumSallePortique2, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNumSallePortique2(QString)));
}

void MainWindow::textChangedLineEditNumSallePortique2(QString contenu)
{
    QString mot;
    for(int i = 1 ; i<comboBoxNumSallePortique2->count() ;){
        comboBoxNumSallePortique2->removeItem(i);
    }
    for(int i = 0 ; i<listStringNumSallePortique2.count() ; i++){
        mot = listStringNumSallePortique2.at(i);
        if(mot.contains(contenu,Qt::CaseInsensitive)){
            comboBoxNumSallePortique2->addItem(mot);
        }
    }
}

void MainWindow::indexChangedComboBoxIpLecteur(QString contenu)
{
    disconnect(lineEditIpLecteur, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditIpLecteur(QString)));
    lineEditIpLecteur->setText(QString(contenu));
    connect(lineEditIpLecteur, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditIpLecteur(QString)));
}

void MainWindow::textChangedLineEditIpLecteur(QString contenu)
{
    QString mot;
    for(int i = 1 ; i<comboBoxIpLecteur->count() ;){
        comboBoxIpLecteur->removeItem(i);
    }
    for(int i = 0 ; i<listStringIpLecteur.count() ; i++){
        mot = listStringIpLecteur.at(i);
        if(mot.contains(contenu,Qt::CaseInsensitive)){
            comboBoxIpLecteur->addItem(mot);
        }
    }
}

void MainWindow::on_actionPar_type_triggered()
{
    // gere l'affichage
    initLayout();

    Type type = Type();
    QString nomType;
    QList<Type> listType;
    listType = typeSrv->getAll(0,typeSrv->getCount());
    QLabel *label = new QLabel("Cocher le/les type(s) a \nrechercher :", this,0);
    ui->layoutGauche->addWidget(label);
    for(int i = 0 ; i < typeSrv->getCount() ; i++ ){
        type = listType.at(i);
        nomType = type.getNomType();
        QCheckBox *checkbox = new QCheckBox(nomType, this);
        ui->layoutGauche->addWidget(checkbox);
    }
    QPushButton *pushButton = new QPushButton("Rechercher par type", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(rechercheParType()));
}

void MainWindow::on_actionPar_nom_triggered()
{
    // gere l 'affichage
    initLayout();

    QLabel *label = new QLabel("Sélectionner le nom \ndu materiel à rechercher :", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNomMateriel = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNomMateriel);

    comboBoxNomMateriel = new QComboBox(this);
    ui->layoutGauche->addWidget(comboBoxNomMateriel);

    listStringNomMateriel = materielSrv->getListNomMateriel(0,materielSrv->getCountListNomMateriel());
    comboBoxNomMateriel->addItem("");
    comboBoxNomMateriel->addItems(listStringNomMateriel);

    QPushButton *pushButton = new QPushButton("Rechercher par le nom", this);
    ui->layoutGauche->addWidget(pushButton);

    connect(lineEditNomMateriel, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNomMateriel(QString)));
    connect(pushButton, SIGNAL(released()), this,SLOT(rechercheParNom()));
    connect(comboBoxNomMateriel, SIGNAL(currentIndexChanged(QString)), this,SLOT(indexChangedComboBoxNomMateriel(QString)));
}

void MainWindow::on_actionPar_badge_triggered()
{
    // gere l 'affichage
    initLayout();

    QLabel *label = new QLabel("Sélectionner le badge \ndu materiel à rechercher :", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditIdBadge = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditIdBadge);

    comboBoxIdBadge = new QComboBox(this);
    ui->layoutGauche->addWidget(comboBoxIdBadge);

    listStringIdBadge = materielSrv->getListIdBadge(0,materielSrv->getCountListIdBadge());
    comboBoxIdBadge->addItem("");
    comboBoxIdBadge->addItems(listStringIdBadge);

    QPushButton *pushButton = new QPushButton("Rechercher par le badge", this);
    ui->layoutGauche->addWidget(pushButton);

    connect(lineEditIdBadge, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditIdBadge(QString)));
    connect(pushButton, SIGNAL(released()), this,SLOT(rechercheParBadge()));
    connect(comboBoxIdBadge, SIGNAL(currentIndexChanged(QString)), this,SLOT(indexChangedComboBoxIdBadge(QString)));

}

void MainWindow::on_actionPar_lieu_triggered()
{
    // gere l'affichage
    initLayout();

    QLabel *label = new QLabel("-> Sélectionner le \nbatiment :", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNomBatiment = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNomBatiment);

    comboBoxNomBatiment = new QComboBox(this);
    ui->layoutGauche->addWidget(comboBoxNomBatiment);

    listStringNomBatiment = batimentSvr->getListNomBatiment(0,batimentSvr->getCountListNomBatiment());
    comboBoxNomBatiment->addItem("");
    comboBoxNomBatiment->addItems(listStringNomBatiment);

    QPushButton *pushButton = new QPushButton("Rechercher par batiment", this);
    ui->layoutGauche->addWidget(pushButton);

    connect(lineEditNomBatiment, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNomBatiment(QString)));
    connect(pushButton, SIGNAL(released()), this,SLOT(rechercheParBatiment()));
    connect(comboBoxNomBatiment, SIGNAL(currentIndexChanged(QString)), this,SLOT(indexChangedComboBoxNomBatimentSalle(QString)));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("-> Sélectionner la salle :", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNumSalle = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNumSalle);

    comboBoxNumSalle = new QComboBox(this);
    ui->layoutGauche->addWidget(comboBoxNumSalle);

    comboBoxNumSalle->addItem("");
    comboBoxNumSalle->addItems(listStringNumSalle);

    pushButton = new QPushButton("Rechercher par salle", this);
    ui->layoutGauche->addWidget(pushButton);

    connect(lineEditNumSalle, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNumSalle(QString)));
    connect(pushButton, SIGNAL(released()), this,SLOT(rechercheParSalle()));
    connect(comboBoxNumSalle, SIGNAL(currentIndexChanged(QString)), this,SLOT(indexChangedComboBoxNumSalle(QString)));
}

void MainWindow::on_actionPar_Controle_triggered()
{
    // gere l 'affichage
    initLayout();

    QLabel *label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Voir la liste du matériel\ncontrolé :", this,0);
    ui->layoutGauche->addWidget(label);

    QPushButton *pushButton = new QPushButton("Matériel controlé", this);
    ui->layoutGauche->addWidget(pushButton);

    connect(pushButton, SIGNAL(released()), this,SLOT(rechercheParControleValide()));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Voir la liste du matériel\nnon controlé :", this,0);
    ui->layoutGauche->addWidget(label);

    pushButton = new QPushButton("Matériel à controler", this);
    ui->layoutGauche->addWidget(pushButton);

    connect(pushButton, SIGNAL(released()), this,SLOT(rechercheParControleNonValide()));
}

void MainWindow::on_actionCreerBatiment_triggered()
{
    // gere l'affichage
    initLayout();

    QLabel *label = new QLabel("Entrer le nom du batiment :", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNomBatiment = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNomBatiment);

    label = new QLabel("", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Entrer le chemin du plan :", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditCheminPlan = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditCheminPlan);

    QPushButton *pushButton = new QPushButton("Rechercher le plan", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(rechercheCheminPlan()));

    label = new QLabel("", this,0);
    ui->layoutGauche->addWidget(label);

    pushButton = new QPushButton("Ajouter le batiment", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(creerBatiment()));
}

void MainWindow::on_actionCreerSalle_triggered()
{
    // gere l'affichage
    initLayout();

//    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0, batimentSvr->getCountListNomBatiment());
    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0, batimentSvr->getCount());

    QLabel *label = new QLabel("Choisir le batiment :", this,0);
    ui->layoutGauche->addWidget(label);

    comboBoxNomBatiment = new QComboBox(this);
    comboBoxNomBatiment->addItem(" ");
    comboBoxNomBatiment->addItems(listeNomBatiments);
    ui->layoutGauche->addWidget(comboBoxNomBatiment);
    connect(comboBoxNomBatiment, SIGNAL(currentIndexChanged(QString)),this, SLOT(recupererPlan(QString)));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Entrez le n° de la salle", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNumSalle = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNumSalle);

    label = new QLabel("Entrez le nom de la salle", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNomSalle = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNomSalle);

    label = new QLabel("Entrez le nom de l'atelier", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNomAtelier = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNomAtelier);

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    QPushButton *pushButton = new QPushButton("Prendre les coordonnées", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(prendreCoordonneesSalle()));

    lineEditCoordonneesSalle = new QLineEdit();
    lineEditCoordonneesSalle->setEnabled(false);
    ui->layoutGauche->addWidget(lineEditCoordonneesSalle);

    label = new QLabel("", this,0);
    ui->layoutGauche->addWidget(label);

    pushButton = new QPushButton("Créer une salle", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(creerSalle()));
}

void MainWindow::on_actionCreerPortique_triggered()
{
    // gere l 'affichage
    initLayout();

    QLabel *label = new QLabel("Choisir le batiment :", this, 0);
    ui->layoutGauche->addWidget(label);

//    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0,batimentSvr->getCountListNomBatiment());
    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0, batimentSvr->getCount());
    comboBoxNomBatiment = new QComboBox(this);
    comboBoxNomBatiment->addItem(" ");
    comboBoxNomBatiment->addItems(listeNomBatiments);
    ui->layoutGauche->addWidget(comboBoxNomBatiment);
    connect(comboBoxNomBatiment, SIGNAL(currentIndexChanged(QString)),this, SLOT(indexChangedComboBoxNomBatimentCreerPortique(QString)));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Sélectionner l'@ip \ndu lecteur", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditIpLecteur = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditIpLecteur);
    connect(lineEditIpLecteur,SIGNAL(textChanged(QString)),this,SLOT(textChangedLineEditIpLecteur(QString)));

//    QList<QString> listeLecteurRFID = lecteurRFIDSvr->getListIp(0,lecteurRFIDSvr->getCountListIp());
    QList<QString> listeLecteurRFID = lecteurRFIDSvr->getListIp(0,lecteurRFIDSvr->getCount());
    Portique portique;
    LecteurRFID lecteurRFID;

    this->listStringIpLecteur.clear();
    for(int i = 0 ; i < listeLecteurRFID.count() ; i++ ){
        lecteurRFID = lecteurRFIDSvr->getByIp(listeLecteurRFID.at(i));
        portique = portiqueSvr->getByLecteurRFID(lecteurRFID);
        if(portique.getId() < 1){
            this->listStringIpLecteur.append(listeLecteurRFID.at(i));
        }
    }
    comboBoxIpLecteur = new QComboBox(this);
    comboBoxIpLecteur->addItem(" ");
    comboBoxIpLecteur->addItems(this->listStringIpLecteur);
    ui->layoutGauche->addWidget(comboBoxIpLecteur);
    connect(comboBoxIpLecteur, SIGNAL(currentIndexChanged(QString)),this, SLOT(indexChangedComboBoxIpLecteur(QString)));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Sélectionner salle n°1", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNumSallePortique1 = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNumSallePortique1);
    connect(lineEditNumSallePortique1,SIGNAL(textChanged(QString)),this,SLOT(textChangedLineEditNumSallePortique1(QString)));

    comboBoxNumSallePortique1 = new QComboBox(this);
    ui->layoutGauche->addWidget(comboBoxNumSallePortique1);
    connect(comboBoxNumSallePortique1, SIGNAL(currentIndexChanged(QString)),this, SLOT(indexChangedComboBoxNumSallePortique1(QString)));


    label = new QLabel("Sélectionner salle n°2\nPeut être null", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNumSallePortique2 = new QLineEdit();
    lineEditNumSallePortique2->setEnabled(false);
    ui->layoutGauche->addWidget(lineEditNumSallePortique2);
    connect(lineEditNumSallePortique2,SIGNAL(textChanged(QString)),this,SLOT(textChangedLineEditNumSallePortique2(QString)));

    comboBoxNumSallePortique2 = new QComboBox(this);
    comboBoxNumSallePortique2->setEnabled(false);
    ui->layoutGauche->addWidget(comboBoxNumSallePortique2);
    connect(comboBoxNumSallePortique2, SIGNAL(currentIndexChanged(QString)),this, SLOT(indexChangedComboBoxNumSallePortique2(QString)));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    QPushButton *pushButton = new QPushButton("Prendre les coordonnées", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(prendreCoordonneesPortique()));

    lineEditCoordonneesPortique = new QLineEdit();
    lineEditCoordonneesPortique->setEnabled(false);
    ui->layoutGauche->addWidget(lineEditCoordonneesPortique);

    label = new QLabel("", this,0);
    ui->layoutGauche->addWidget(label);

    pushButton = new QPushButton("Créer un portique", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(creerPortique()));


    lineEditNomBatiment = new QLineEdit();
    lineEditNomBatiment->setVisible(false);
    ui->layoutGauche->addWidget(lineEditNomBatiment);
}


void MainWindow::on_actionModifierBatiment_triggered()
{
    // gere l'affichage
    initLayout();

//    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0,batimentSvr->getCountListNomBatiment());
    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0,batimentSvr->getCount());

    QLabel *label = new QLabel("Choisir le batiment :", this,0);
    ui->layoutGauche->addWidget(label);

    comboBoxNomBatiment = new QComboBox(this);
    comboBoxNomBatiment->addItem(" ");
    comboBoxNomBatiment->addItems(listeNomBatiments);
    ui->layoutGauche->addWidget(comboBoxNomBatiment);
    connect(comboBoxNomBatiment, SIGNAL(currentIndexChanged(QString)),this, SLOT(recupererInfoBatiment(QString)));

    label = new QLabel("", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Modifier le nom du batiment :", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNomBatiment = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNomBatiment);

    label = new QLabel("", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Modifier le chemin du plan :", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditCheminPlan = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditCheminPlan);

    QPushButton *pushButton = new QPushButton("Modifier le plan", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(rechercheCheminPlan()));

    label = new QLabel("", this,0);
    ui->layoutGauche->addWidget(label);

    pushButton = new QPushButton("Modifier le batiment", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(modifierBatiment()));
}

void MainWindow::on_actionModifierSalle_triggered()
{
    // gere l 'affichage
    initLayout();

//    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0,batimentSvr->getCountListNomBatiment());
    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0,batimentSvr->getCount());

    QLabel *label = new QLabel("Choisir le batiment :", this,0);
    ui->layoutGauche->addWidget(label);

    comboBoxNomBatiment = new QComboBox(this);
    comboBoxNomBatiment->addItem(" ");
    comboBoxNomBatiment->addItems(listeNomBatiments);
    ui->layoutGauche->addWidget(comboBoxNomBatiment);
    connect(comboBoxNomBatiment, SIGNAL(currentIndexChanged(QString)),this, SLOT(indexChangedComboBoxNomBatimentSalle(QString)));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Sélectionner la salle :", this,0);
    ui->layoutGauche->addWidget(label);

    comboBoxNumSalle = new QComboBox(this);
    ui->layoutGauche->addWidget(comboBoxNumSalle);
    connect(comboBoxNumSalle, SIGNAL(currentIndexChanged(QString)),this, SLOT(recupererInfoSalle(QString)));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Modifier le n° de la salle", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNumSalle = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNumSalle);

    label = new QLabel("Modifier le nom de la salle", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNomSalle = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNomSalle);

    label = new QLabel("Modifier le nom de l'atelier", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNomAtelier = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNomAtelier);

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    QPushButton *pushButton = new QPushButton("Prendre les coordonnées", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(prendreCoordonneesSalle()));

    lineEditCoordonneesSalle = new QLineEdit();
    lineEditCoordonneesSalle->setEnabled(false);
    ui->layoutGauche->addWidget(lineEditCoordonneesSalle);

    label = new QLabel("", this,0);
    ui->layoutGauche->addWidget(label);

    pushButton = new QPushButton("Modifier la salle", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(modifierSalle()));

    lineEditNomBatiment = new QLineEdit();
    lineEditNomBatiment->setVisible(false);
    ui->layoutGauche->addWidget(lineEditNomBatiment);
}

void MainWindow::on_actionModifierPortique_triggered()
{
    // gere l'affichage
    initLayout();
    QList<LecteurRFID> listeLecteurRFID;

    QLabel *label = new QLabel("Sélectionner le batiment :", this, 0);
    ui->layoutGauche->addWidget(label);

//    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0,batimentSvr->getCountListNomBatiment());
    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0,batimentSvr->getCount());
    comboBoxNomBatiment = new QComboBox(this);
    comboBoxNomBatiment->addItem(" ");
    comboBoxNomBatiment->addItems(listeNomBatiments);
    ui->layoutGauche->addWidget(comboBoxNomBatiment);
    connect(comboBoxNomBatiment, SIGNAL(currentIndexChanged(QString)),this, SLOT(indexChangedComboBoxNomBatimentCreerPortique(QString)));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Sélectionner l'@ip \ndu lecteur", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditIpLecteur = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditIpLecteur);
    connect(lineEditIpLecteur,SIGNAL(textChanged(QString)),this,SLOT(textChangedLineEditIpLecteur(QString)));

    LecteurRFID lecteurRFID;

    this->listStringIpLecteur.clear();
    listeLecteurRFID = portiqueSvr->getListLecteurRFID(0,portiqueSvr->getCountListLecteurRFID());
    for(int i = 0 ; i < listeLecteurRFID.count() ; i++ ){
        lecteurRFID = listeLecteurRFID.at(i);
        this->listStringIpLecteur.append(lecteurRFID.getIp());
    }

    comboBoxIpLecteur = new QComboBox(this);
    comboBoxIpLecteur->addItem(" ");
    comboBoxIpLecteur->addItems(this->listStringIpLecteur);
    ui->layoutGauche->addWidget(comboBoxIpLecteur);
    connect(comboBoxIpLecteur, SIGNAL(currentIndexChanged(QString)),this, SLOT(recupererInfoPortique(QString)));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Sélectionner salle n°1", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNumSallePortique1 = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNumSallePortique1);
    connect(lineEditNumSallePortique1,SIGNAL(textChanged(QString)),this,SLOT(textChangedLineEditNumSallePortique1(QString)));

    comboBoxNumSallePortique1 = new QComboBox(this);
    ui->layoutGauche->addWidget(comboBoxNumSallePortique1);
    connect(comboBoxNumSallePortique1, SIGNAL(currentIndexChanged(QString)),this, SLOT(indexChangedComboBoxNumSallePortique1(QString)));

    label = new QLabel("Sélectionner salle n°2\nPeut être null", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNumSallePortique2 = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNumSallePortique2);
    connect(lineEditNumSallePortique2,SIGNAL(textChanged(QString)),this,SLOT(textChangedLineEditNumSallePortique2(QString)));

    comboBoxNumSallePortique2 = new QComboBox(this);
    ui->layoutGauche->addWidget(comboBoxNumSallePortique2);
    connect(comboBoxNumSallePortique2, SIGNAL(currentIndexChanged(QString)),this, SLOT(indexChangedComboBoxNumSallePortique2(QString)));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    QPushButton *pushButton = new QPushButton("Prendre les coordonnées", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(prendreCoordonneesPortique()));

    lineEditCoordonneesPortique = new QLineEdit();
    lineEditCoordonneesPortique->setEnabled(false);
    ui->layoutGauche->addWidget(lineEditCoordonneesPortique);

    label = new QLabel("", this,0);
    ui->layoutGauche->addWidget(label);

    pushButton = new QPushButton("Modifer le portique", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(modifierPortique()));

    lineEditNomBatiment = new QLineEdit();
    lineEditNomBatiment->setVisible(false);
    ui->layoutGauche->addWidget(lineEditNomBatiment);
}

void MainWindow::on_actionSupprimerBatiment_triggered()
{
    // gere l 'affichage
    initLayout();

//    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0,batimentSvr->getCountListNomBatiment());
    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0,batimentSvr->getCount());
    QLabel *label = new QLabel("Sélectionner le batiment :", this,0);
    ui->layoutGauche->addWidget(label);

    comboBoxNomBatiment = new QComboBox(this);
    comboBoxNomBatiment->addItem(" ");
    comboBoxNomBatiment->addItems(listeNomBatiments);
    ui->layoutGauche->addWidget(comboBoxNomBatiment);
    connect(comboBoxNomBatiment, SIGNAL(currentIndexChanged(QString)),this, SLOT(recupererInfoBatiment(QString)));

    label = new QLabel("", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Nom du batiment :", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNomBatiment = new QLineEdit();
    lineEditNomBatiment->setEnabled(false);
    ui->layoutGauche->addWidget(lineEditNomBatiment);

    label = new QLabel("", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Chemin du plan :", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditCheminPlan = new QLineEdit();
    lineEditCheminPlan->setEnabled(false);
    ui->layoutGauche->addWidget(lineEditCheminPlan);

    label = new QLabel("", this,0);
    ui->layoutGauche->addWidget(label);

    QPushButton *pushButton = new QPushButton("Supprimer le batiment", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(supprimerBatiment()));

}

void MainWindow::on_actionSupprimerSalle_triggered()
{
    // gere l 'affichage
    initLayout();

//    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0,batimentSvr->getCountListNomBatiment());
    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0,batimentSvr->getCount());

    QLabel *label = new QLabel("Choisir le batiment :", this, 0);
    ui->layoutGauche->addWidget(label);

    comboBoxNomBatiment = new QComboBox(this);
    comboBoxNomBatiment->addItem(" ");
    comboBoxNomBatiment->addItems(listeNomBatiments);
    ui->layoutGauche->addWidget(comboBoxNomBatiment);
    connect(comboBoxNomBatiment, SIGNAL(currentIndexChanged(QString)),this, SLOT(indexChangedComboBoxNomBatimentSalle(QString)));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Sélectionner la salle :", this,0);
    ui->layoutGauche->addWidget(label);

    comboBoxNumSalle = new QComboBox(this);
    ui->layoutGauche->addWidget(comboBoxNumSalle);
    connect(comboBoxNumSalle, SIGNAL(currentIndexChanged(QString)),this, SLOT(recupererInfoSalle(QString)));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Numero de la salle", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNumSalle = new QLineEdit();
    lineEditNumSalle->setEnabled(false);
    ui->layoutGauche->addWidget(lineEditNumSalle);

    label = new QLabel("Nom de la salle", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNomSalle = new QLineEdit();
    lineEditNomSalle->setEnabled(false);
    ui->layoutGauche->addWidget(lineEditNomSalle);

    label = new QLabel("Nom de l'atelier", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNomAtelier = new QLineEdit();
    lineEditNomAtelier->setEnabled(false);
    ui->layoutGauche->addWidget(lineEditNomAtelier);

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Les coordonnées", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditCoordonneesSalle = new QLineEdit();
    lineEditCoordonneesSalle->setEnabled(false);
    ui->layoutGauche->addWidget(lineEditCoordonneesSalle);

    label = new QLabel("", this,0);
    ui->layoutGauche->addWidget(label);

    QPushButton *pushButton = new QPushButton("Supprimer la salle", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(supprimerSalle()));

    lineEditNomBatiment = new QLineEdit();
    lineEditNomBatiment->setVisible(false);
    ui->layoutGauche->addWidget(lineEditNomBatiment);
}

void MainWindow::on_actionSupprimerPortique_triggered()
{
    // gere l 'affichage
    initLayout();

    QLabel *label = new QLabel("Choisir le batiment :", this,0);
    ui->layoutGauche->addWidget(label);

//    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0,batimentSvr->getCountListNomBatiment());
    QList<QString> listeNomBatiments = batimentSvr->getListNomBatiment(0,batimentSvr->getCount());
    comboBoxNomBatiment = new QComboBox(this);
    comboBoxNomBatiment->addItem(" ");
    comboBoxNomBatiment->addItems(listeNomBatiments);
    ui->layoutGauche->addWidget(comboBoxNomBatiment);
    connect(comboBoxNomBatiment, SIGNAL(currentIndexChanged(QString)),this, SLOT(indexChangedComboBoxNomBatimentSupprimerPortique(QString)));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Sélectionner l'@ip \ndu portique", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditIpLecteur = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditIpLecteur);
    connect(lineEditIpLecteur,SIGNAL(textChanged(QString)),this,SLOT(textChangedLineEditIpLecteur(QString)));

    this->listStringIpLecteur.clear();
    comboBoxIpLecteur = new QComboBox(this);
    comboBoxIpLecteur->addItem(" ");
    comboBoxIpLecteur->addItems(this->listStringIpLecteur);
    ui->layoutGauche->addWidget(comboBoxIpLecteur);
    connect(comboBoxIpLecteur, SIGNAL(currentIndexChanged(QString)),this, SLOT(recupererInfoPortique(QString)));

    label = new QLabel(" ", this,0);
    ui->layoutGauche->addWidget(label);

    label = new QLabel("Salle n°1", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNumSallePortique1 = new QLineEdit();
    lineEditNumSallePortique1->setEnabled(false);
    ui->layoutGauche->addWidget(lineEditNumSallePortique1);

    label = new QLabel("Salle n°2", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditNumSallePortique2 = new QLineEdit();
    lineEditNumSallePortique2->setEnabled(false);
    ui->layoutGauche->addWidget(lineEditNumSallePortique2);

    label = new QLabel("Les coordonnées", this,0);
    ui->layoutGauche->addWidget(label);

    lineEditCoordonneesPortique = new QLineEdit();
    lineEditCoordonneesPortique->setEnabled(false);
    ui->layoutGauche->addWidget(lineEditCoordonneesPortique);

    label = new QLabel("", this,0);
    ui->layoutGauche->addWidget(label);

    QPushButton *pushButton = new QPushButton("Supprimer le portique", this);
    ui->layoutGauche->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this,SLOT(supprimerPortique()));
}

void MainWindow::on_actionVoir_triggered()
{
    // gere l'affichage
    initLayout();

    QLabel *label = new QLabel("-> Choisir le batiment :", this, 0);
    ui->layoutGauche->addWidget(label);

    lineEditNomBatiment = new QLineEdit();
    ui->layoutGauche->addWidget(lineEditNomBatiment);

    comboBoxNomBatiment = new QComboBox(this);
    ui->layoutGauche->addWidget(comboBoxNomBatiment);

//    listStringNomBatiment = batimentSvr->getListNomBatiment(0, batimentSvr->getCountListNomBatiment());
    listStringNomBatiment = batimentSvr->getListNomBatiment(0, batimentSvr->getCount());
    comboBoxNomBatiment->addItem("");
    comboBoxNomBatiment->addItems(listStringNomBatiment);

    QPushButton *pushButton = new QPushButton("Voir", this);
    ui->layoutGauche->addWidget(pushButton);

    comboBoxNumSalle = new QComboBox(this);
    comboBoxNumSalle->setVisible(false);
    ui->layoutGauche->addWidget(comboBoxNumSalle);

    connect(lineEditNomBatiment, SIGNAL(textChanged(QString)), this, SLOT(textChangedLineEditNomBatiment(QString)));
    connect(pushButton, SIGNAL(released()), this,SLOT(resultatVoirEtTimer()));
    connect(comboBoxNomBatiment, SIGNAL(currentIndexChanged(QString)), this,SLOT(indexChangedComboBoxNomBatimentSalle(QString)));
}

void MainWindow::initLayout()
{
    this->boolDoubleClick = false;
    this->timerActualisationPlan->stop();
    viderLayout(ui->layoutDroit);
    viderLayout(ui->layoutGauche);
    viderLabelPlan();
    viderLabelListeMaterielDansSalle();
}

void MainWindow::viderLayout(QFormLayout *layout)
{
    // vide le layout que je passe en parametre
    QWidget *w;
    while(0<layout->count()){
        w = layout->takeAt(0)->widget();
        w->close();
        delete w;
    }
}

void MainWindow::viderLayoutExFirst(QFormLayout *layout)
{
    // vide le layout que je passe en parametre, sauf le 1er
    QWidget *w;
    while(1<layout->count()){
        w = layout->takeAt(1)->widget();
        w->close();
        delete w;
    }
}

void MainWindow::viderLabelPlan()
{
    // supprime tous les composants graphiques
    QLabel *w;
    while(0< this->listLabelPlan.count()){
        w = this->listLabelPlan.at(0);
        this->listLabelPlan.removeAt(0);
        w->close();
        delete w;
    }
}

void MainWindow::viderLabelListeMaterielDansSalle()
{
    // supprime la liste de materiel concernant une salle
    if(this->boolLabelListeMaterielDansSalle){
        this->boolLabelListeMaterielDansSalle = false;

        this->labelListeMaterielDansSalle->close();
        delete this->labelListeMaterielDansSalle;
    }

}

void MainWindow::affichePlanComplet(QString nomBatiment)
{
    // vide les plan et les layouts
    viderLayout(ui->layoutDroit);
    viderLabelPlan();
    Batiment batiment;
    QList<Salle> listSalles;
    QList<Materiel> listMateriels;
    QList<QString> listTypes;
    Salle salle;
    QList<Localisation> listLocalisations;
    Localisation localisation;
    int y,x;
    //recupere la liste de salles dans le batiment conserné
    batiment = batimentSvr->getByNomBatiment(nomBatiment);
    listSalles = batiment.getSalles();
    // créé le label pour afficher mon plan
    labelPlan = new QLabel();
    labelPlan->setPixmap(QPixmap(batiment.getPlan()));
    labelPlan->adjustSize();
    labelPlan->setScaledContents(true);
    labelPlan->resize(785,571);
    //affichage du plan
    ui->layoutDroit->addWidget(labelPlan);
    QSize sizeLabelPlan = labelPlan->size(); // recupere la taille dans une valeur
    QPoint coordonneesLabelPlan;
    coordonneesLabelPlan = labelPlan->mapFrom(this, coordonneesLabelPlan); // recupere son origine
    // pour chaque salle qu'il y a dans le batiment
    for(int i = 0 ; i < listSalles.count() ; i++ ){
        salle = listSalles.at(i);
        listLocalisations = localisationSrv->getBySalle(salle, 0, localisationSrv->getCountBySalle(salle)); // recupere tous les localisation
        // supprime les localisations qui ne sont plus dans la salle
        for(int a = 0 ; a < listLocalisations.count() ; a++ ){
            localisation= listLocalisations.at(a);
            if(localisation.getSortie()){
                listLocalisations.removeAt(a);
                a--;
            }
        }
        // recupere la liste de materiel qui est dans la salle, et recupere les types
        listTypes.clear();
        for(int j = 0 ; j < listLocalisations.count() ; j++ ){
            localisation = listLocalisations.at(j);
            listMateriels.append(localisation.getMateriel());
            listTypes.append(localisation.getMateriel().getType().getNomType());
        }
//        listTypes = getDifferent(listTypes);// retourne la liste de types different

        //permet l'affichage du numero et du nom de la salle
        QLabel *label = new QLabel(this);
        label->setText(QString::number(salle.getNumSalle())+"\n"+ salle.getNomSalle());
        label->adjustSize();
        QSize size = label->size();

        //permet de faire la conversion entre le pourcentage mit dans la base et le nombre de pixel de mon labelPlan
        this->x_ini = (int) (sizeLabelPlan.width() * salle.getX_ini() /100);
        this->y_ini = (int) (sizeLabelPlan.height() * salle.getY_ini() /100);
        this->x_fin = (int) (sizeLabelPlan.width() * salle.getX_fin() /100);
        this->y_fin = (int) (sizeLabelPlan.height() * salle.getY_fin() /100);

        // Affichage Label du nom de la salle sur le plan
        x = 5 + abs(coordonneesLabelPlan.x()) + this->x_ini + ((this->x_fin - this->x_ini)/2) - ((size.width())/2);
        y = abs(coordonneesLabelPlan.y()) + this->y_ini;
        label->move(x, y);
        label->show();
        this->listLabelPlan.append(label);// rajoute le label dans une liste

        // Affichage des icones type (10 max)
        int nb= listTypes.count();
        if(nb > 10) //2
            nb = 10;
        for(int k= 0; k < nb ; k++ ){
            label = new QLabel(this);
            label->setPixmap(QPixmap(typeSrv->getByNomType(listTypes.at(k)).getNomImage()));
            label->adjustSize();
            size= label->size();

            // coord de base de la salle
            x = 5 + abs(coordonneesLabelPlan.x());
            y = abs(coordonneesLabelPlan.y());
//            qWarning("Coord salle: x=%d y=%d", x, y);
            int div= (this->x_fin - this->x_ini)/size.width();
            x += 5 + this->x_ini + ((k%div) * size.width());
            y += 30 + this->y_ini + ((k/div) * size.height());
            label->move(x, y);
            label->show();
            this->listLabelPlan.append(label);
        }

        //affichage des portiques
        Portique portique;
        QList<Portique> listePortique;
        listePortique = portiqueSvr->getBySalle(salle,0,portiqueSvr->getCountBySalle(salle));
        for(int p = 0 ; p < listePortique.count() ; p++ ){
            portique = listePortique.at(p);
            label = new QLabel(this);
            if(portique.getLecteurRFID().getEtatOn()){
                label->setPixmap(QPixmap(":/images/image/pointVert.jpg"));
            }else{
                label->setPixmap(QPixmap(":/images/image/pointRouge.jpg"));
            }
            label->adjustSize();
            size = label->size();

            //permet de faire la conversion entre le pourcentage mi dans la base et le nombre de pixel de mon labelPlan
            this->x_ini = (int) (sizeLabelPlan.width() * portique.getX() /100);
            this->y_ini = (int) (sizeLabelPlan.height() * portique.getY() /100);

            x = 5 + abs(coordonneesLabelPlan.x()) + this->x_ini - label->width()/2;
            y = abs(coordonneesLabelPlan.y()) + this->y_ini - label->height()/2;

            label->move(x, y);
            label->show();
            this->listLabelPlan.append(label);
        }
    }
}

QList<QString> MainWindow::getDifferent(QList<QString> list)
{
    // donne une liste avec plusieur fois la meme chaine de caractère , et me renvoie seulement les différents
    QString chaine1, chaine2;
    QList<QString> listDifferent;
    bool b = false;
    listDifferent.append(" ");
    for( int i = 0 ; i < list.count() ; i++ ){
        chaine1 = list.at(i);
        b = false;
        for( int j = 0 ; j < listDifferent.count() ; j++){
            chaine1 = list.at(i);
            chaine2 = listDifferent.at(j);
            if(!chaine1.compare(chaine2)){
                b = true;
            }
        }
        if(!b){
            listDifferent.append(chaine1);
        }
    }
    listDifferent.removeAt(0);
    return listDifferent;
}
