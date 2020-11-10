#include "batimentwindow.h"
#include "ui_batimentwindow.h"
#include <QCloseEvent>

BatimentWindow::BatimentWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BatimentWindow)
{
    ui->setupUi(this);
    batimentSrv = MetierFactory::getBatimentServiceImpl();
    salleSrv = MetierFactory::getSalleServiceImpl();
    QList<int> numSalles = salleSrv->getListNumSalle(0, salleSrv->getCountListNumSalle());
    foreach(int numSalle, numSalles){
        ui->comboBoxSalle->addItem(QString::number(numSalle)); // Remplis la combobox du numéro de toutes les salles existantes
    }
}

BatimentWindow::~BatimentWindow()
{
    delete ui;
}

void BatimentWindow::on_pushButtonAdd_clicked()
{
    QString text;
    QString nomBatiment = ui->lineEditNomBatiment->text();
    QString plan = ui->lineEditPlan->text();
    QList<Salle> salles;
    int count = ui->listWidget->count();
    for(int i = 0; i < count; i++){ // Réccupère toutes les salles passé dans la liste
        salles.append(salleSrv->getByNumSalle(ui->listWidget->item(i)->text().toInt()));
    }
    Batiment batiment_temp = Batiment(nomBatiment, salles, plan);
    Batiment batiment = batimentSrv->add(batiment_temp);
    foreach(Salle salle, batiment.getSalles()){ // Permet de creer la chaine de caractères contenant toutes les salles. Non utilisation de append car fait un saut de ligne automatiquement
        text += " "+QString::number(salle.getNumSalle());
    }
    ui->textEdit->setText("id: "+QString::number(batiment.getId())+"\nnomBatiment: "+batiment.getNomBatiment()+"\nsalles:"+text+"\nplan:"+batiment.getPlan()); // Affiche les informations en suprimant ce qu'il y avait précédement
}

void BatimentWindow::on_pushButtonGetById_clicked()
{
    QString text;
    long id = ui->lineEditId->text().toLong();
    Batiment batiment = batimentSrv->getById(id);
    foreach(Salle salle, batiment.getSalles()){
        text += " "+QString::number(salle.getNumSalle());
    }
    ui->textEdit->setText("id: "+QString::number(batiment.getId())+"\nnomBatiment: "+batiment.getNomBatiment()+"\nsalles:"+text+"\nplan:"+batiment.getPlan());
}

void BatimentWindow::on_pushButtonRemove_clicked()
{
    QString text;
    long id = ui->lineEditId->text().toLong();
    Batiment batiment = batimentSrv->getById(id);
    foreach(Salle salle, batiment.getSalles()){
        text += " "+QString::number(salle.getNumSalle());
    }
    ui->textEdit->setText("id: "+QString::number(batiment.getId())+"\nnomBatiment: "+batiment.getNomBatiment()+"\nsalles:"+text+"\nplan:"+batiment.getPlan());
    bool execute = batimentSrv->remove(batiment);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
}

void BatimentWindow::on_pushButtonUpdate_clicked()
{
    QString text;
    long id = ui->lineEditId->text().toLong();
    QList<Salle> salles;
    int count = ui->listWidget->count();
    for(int i = 0; i < count; i++){
        salles.append(salleSrv->getByNumSalle(ui->listWidget->item(i)->text().toInt()));
    }
    QString nomBatiment = ui->lineEditNomBatiment->text();
    QString plan = ui->lineEditPlan->text();
    Batiment batiment = batimentSrv->getById(id);
    foreach(Salle salle, batiment.getSalles()){
        text += " "+QString::number(salle.getNumSalle());
    }
    ui->textEdit->setText("id: "+QString::number(batiment.getId())+"\nnomBatiment: "+batiment.getNomBatiment()+"\nsalles:"+text+"\nplan:"+batiment.getPlan());
    text.clear();
    if(!nomBatiment.isEmpty()){ // Modifie seulement la colonne liée au champs lorsque le champs n'est pas vide
        batiment.setNomBatiment(nomBatiment);
    }
    if(!plan.isEmpty()){
        batiment.setPlan(plan);
    }
    if(!salles.isEmpty()){
        batiment.setSalles(salles);
    }
    bool execute = batimentSrv->update(batiment);
    batiment = batimentSrv->getById(id);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
    ui->textEdit->append("--------------------");
    foreach(Salle salle, batiment.getSalles()){
        text += " "+QString::number(salle.getNumSalle());
    }
    ui->textEdit->append("id: "+QString::number(batiment.getId())+"\nnomBatiment: "+batiment.getNomBatiment()+"\nsalles:"+text+"\nplan:"+batiment.getPlan());
}

void BatimentWindow::on_pushButtonGetAll_clicked()
{
    QString text;
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Batiment> batiments = batimentSrv->getAll(page, parPage);
    ui->textEdit->clear();
    foreach(Batiment batiment, batiments){
        foreach(Salle salle, batiment.getSalles()){
            text += " "+QString::number(salle.getNumSalle());
        }
        ui->textEdit->append("id: "+QString::number(batiment.getId())+"\nnomBatiment: "+batiment.getNomBatiment()+"\nsalles:"+text+"\nplan:"+batiment.getPlan());
        ui->textEdit->append("--------------------");
        text.clear();
    }
}

void BatimentWindow::on_pushButtonGetCount_clicked()
{
    int count = batimentSrv->getCount();
    ui->textEdit->setText("count = "+QString::number(count));
}

void BatimentWindow::on_pushButtonGetByNomBatiment_clicked()
{
    QString text;
    QString nomBatiment = ui->lineEditNomBatiment->text();
    Batiment batiment = batimentSrv->getByNomBatiment(nomBatiment);
    foreach(Salle salle, batiment.getSalles()){
        text += " "+QString::number(salle.getNumSalle());
    }
    ui->textEdit->setText("id: "+QString::number(batiment.getId())+"\nnomBatiment: "+batiment.getNomBatiment()+"\nsalles:"+text+"\nplan:"+batiment.getPlan());
}

void BatimentWindow::on_pushButtonGetBySalle_clicked()
{
    QString text;
    Batiment batiment;
    QListWidgetItem* element = ui->listWidget->item(0);
    if(element != 0){
        int numSalle = element->text().toInt();
        batiment = batimentSrv->getBySalle(salleSrv->getByNumSalle(numSalle));
    }
    foreach(Salle salle, batiment.getSalles()){
        text += " "+QString::number(salle.getNumSalle());
    }
    ui->textEdit->setText("id: "+QString::number(batiment.getId())+"\nnomBatiment: "+batiment.getNomBatiment()+"\nsalles:"+text+"\nplan:"+batiment.getPlan());
}

void BatimentWindow::on_pushButtonGetByPlan_clicked()
{
    QString text;
    QString plan = ui->lineEditPlan->text();
    Batiment batiment = batimentSrv->getByPlan(plan);
    foreach(Salle salle, batiment.getSalles()){
        text += " "+QString::number(salle.getNumSalle());
    }
    ui->textEdit->setText("id: "+QString::number(batiment.getId())+"\nnomBatiment: "+batiment.getNomBatiment()+"\nsalles:"+text+"\nplan:"+batiment.getPlan());
}

void BatimentWindow::on_pushButtonGetListNomBatiment_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<QString> listNomBatiment = batimentSrv->getListNomBatiment(page, parPage);
    ui->textEdit->clear();
    foreach(QString nomBatiment, listNomBatiment){
        ui->textEdit->append(nomBatiment);
    }
}

void BatimentWindow::on_pushButtonGetCountListBatiment_clicked()
{
    int count = batimentSrv->getCountListNomBatiment();
    ui->textEdit->setText("count = "+QString::number(count));
}

void BatimentWindow::on_pushButtonGetListSalle_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Salle> salles = batimentSrv->getListSalle(page, parPage);
    ui->textEdit->clear();
    foreach(Salle salle, salles){
        ui->textEdit->append("id: "+QString::number(salle.getId())+"\nx_ini: "+QString::number(salle.getX_ini())+"\ny_ini: "+QString::number(salle.getY_ini())+"\nx_fin: "+QString::number(salle.getX_fin())+"\ny_fin: "+QString::number(salle.getY_fin())+"\nnumSalle: "+QString::number(salle.getNumSalle())+"\nnomSalle: "+salle.getNomSalle()+"\nnomAtelier: "+salle.getNomAtelier());
        ui->textEdit->append("--------------------");
    }
}

void BatimentWindow::on_pushButtonGetCountListSalle_clicked()
{
    int count = batimentSrv->getCountListSalle();
    ui->textEdit->setText("count = "+QString::number(count));
}

void BatimentWindow::on_pushButtonGetListPlan_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<QString> listPlan = batimentSrv->getListPlan(page, parPage);
    ui->textEdit->clear();
    foreach(QString plan, listPlan){
        ui->textEdit->append(plan);
    }
}

void BatimentWindow::on_pushButtonGetCountListPlan_clicked()
{
    int count = batimentSrv->getCountListPlan();
    ui->textEdit->setText("count = "+QString::number(count));
}

void BatimentWindow::on_pushButtonAjouter_clicked() // Ajoute un numéro de salle à la liste
{
    QString text = ui->comboBoxSalle->currentText();
    QList<QListWidgetItem*> items = ui->listWidget->findItems(text, Qt::MatchExactly); // réccupère l'index correspondant exactement à la chaine de caractère affiché dans la combobox
    if(items.size() == 0){ // Si la liste ne contient pas déjà cet item, on l'ajoute
        ui->listWidget->addItem(text);
    }
}

void BatimentWindow::on_listWidget_doubleClicked(const QModelIndex &index) // Supprime de la liste l'item qui a subbit un double click
{
    delete ui->listWidget->item(index.row());
}

void BatimentWindow::on_pushButtonSallesBatiment_clicked() // Permet de réccupérer toutes les salles du batiment
{
    long id = ui->lineEditId->text().toLong();
    Batiment batiment = batimentSrv->getById(id);
    QList<Salle> salles = batiment.getSalles();
    foreach(Salle salle, salles){
        ui->listWidget->addItem(QString::number(salle.getNumSalle())); // number permet de convertir un nombre en string
    }
}

void BatimentWindow::closeEvent(QCloseEvent *ev){
    ev->accept();
    emit fin(this);
}
