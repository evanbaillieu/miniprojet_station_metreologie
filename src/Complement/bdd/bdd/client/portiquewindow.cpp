#include "portiquewindow.h"
#include "ui_portiquewindow.h"
#include <QCloseEvent>

PortiqueWindow::PortiqueWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PortiqueWindow)
{
    ui->setupUi(this);
    portiqueSrv = MetierFactory::getPortiqueServiceImpl();
    salleSrv = MetierFactory::getSalleServiceImpl();
    lecteurSrv = MetierFactory::getLecteurRFIDServiceImpl();
    QList<int> numSalles = salleSrv->getListNumSalle(0, salleSrv->getCount());
    ui->comboBoxSalle1->addItem("");
    ui->comboBoxSalle2->addItem("");
    foreach(int numSalle, numSalles){
        ui->comboBoxSalle1->addItem(QString::number(numSalle));
        ui->comboBoxSalle2->addItem(QString::number(numSalle));
    }
    ui->comboBoxLecteur->addItem("");
    QList<QString> ipLecteurs = lecteurSrv->getListIp(0, lecteurSrv->getCountListIp());
    foreach(QString ipLecteur, ipLecteurs){
        ui->comboBoxLecteur->addItem(ipLecteur);
    }
    comboBox = "";
}

PortiqueWindow::~PortiqueWindow()
{
    delete ui;
}

void PortiqueWindow::on_pushButtonAdd_clicked()
{
    float x = ui->lineEditX->text().toFloat();
    float y = ui->lineEditY->text().toFloat();
    Salle salle1;
    Salle salle2;
    if(!ui->comboBoxSalle1->currentText().isEmpty()){
        salle1 = salleSrv->getByNumSalle(ui->comboBoxSalle1->currentText().toInt());
    }
    if(!ui->comboBoxSalle2->currentText().isEmpty()){
        salle2 = salleSrv->getByNumSalle(ui->comboBoxSalle2->currentText().toInt());
    }
    LecteurRFID lecteur = lecteurSrv->getByIp(ui->comboBoxLecteur->currentText());
    Portique portique_temp = Portique(x, y, salle1, salle2, lecteur);
    Portique portique = portiqueSrv->add(portique_temp);
    ui->textEdit->setText("id: "+QString::number(portique.getId())+"\nx: "+QString::number(portique.getX())+"\ny: "+QString::number(portique.getY())+"\nsalle 1: "+QString::number(portique.getSalle1().getNumSalle())+"\nsalle 2: "+QString::number(portique.getSalle2().getNumSalle())+"\nlecteur: "+portique.getLecteurRFID().getIp());
}

void PortiqueWindow::on_pushButtonGetById_clicked()
{
    long id = ui->lineEditId->text().toLong();
    Portique portique = portiqueSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(portique.getId())+"\nx: "+QString::number(portique.getX())+"\ny: "+QString::number(portique.getY())+"\nsalle 1: "+QString::number(portique.getSalle1().getNumSalle())+"\nsalle 2: "+QString::number(portique.getSalle2().getNumSalle())+"\nlecteur: "+portique.getLecteurRFID().getIp());
}

void PortiqueWindow::on_pushButtonRemove_clicked()
{
    long id = ui->lineEditId->text().toLong();
    Portique portique = portiqueSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(portique.getId())+"\nx: "+QString::number(portique.getX())+"\ny: "+QString::number(portique.getY())+"\nsalle 1: "+QString::number(portique.getSalle1().getNumSalle())+"\nsalle 2: "+QString::number(portique.getSalle2().getNumSalle())+"\nlecteur: "+portique.getLecteurRFID().getIp());
    bool execute = portiqueSrv->remove(portique);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
}

void PortiqueWindow::on_pushButtonUpdate_clicked()
{
    long id = ui->lineEditId->text().toLong();
    QString x = ui->lineEditX->text();
    QString y = ui->lineEditY->text();
    QString ip = ui->comboBoxLecteur->currentText();
    Salle salle1;
    Salle salle2;
    if(!ui->comboBoxSalle1->currentText().isEmpty()){
        salle1 = salleSrv->getByNumSalle(ui->comboBoxSalle1->currentText().toInt());
    }
    if(!ui->comboBoxSalle2->currentText().isEmpty()){
        salle2 = salleSrv->getByNumSalle(ui->comboBoxSalle2->currentText().toInt());
    }
    LecteurRFID lecteur = lecteurSrv->getByIp(ip);
    Portique portique = portiqueSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(portique.getId())+"\nx: "+QString::number(portique.getX())+"\ny: "+QString::number(portique.getY())+"\nsalle 1: "+QString::number(portique.getSalle1().getNumSalle())+"\nsalle 2: "+QString::number(portique.getSalle2().getNumSalle())+"\nlecteur: "+portique.getLecteurRFID().getIp());
    if(!x.isEmpty()){
        portique.setX(x.toFloat());
    }
    if(!y.isEmpty()){
        portique.setY(y.toFloat());
    }
    if(salle1.getId() > 0){
        portique.setSalle1(salle1);
    }
    if(salle2.getId() > 0){
        portique.setSalle2(salle2);
    }
    if(!ip.isEmpty()){
        portique.setLecteurRFID(lecteur);
    }
    bool execute = portiqueSrv->update(portique);
    portique = portiqueSrv->getById(id);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
    ui->textEdit->append("--------------------");
    ui->textEdit->append("id: "+QString::number(portique.getId())+"\nx: "+QString::number(portique.getX())+"\ny: "+QString::number(portique.getY())+"\nsalle 1: "+QString::number(portique.getSalle1().getNumSalle())+"\nsalle 2: "+QString::number(portique.getSalle2().getNumSalle())+"\nlecteur: "+portique.getLecteurRFID().getIp());
}

void PortiqueWindow::on_pushButtonGetAll_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Portique> portiques = portiqueSrv->getAll(page, parPage);
    ui->textEdit->clear();
    foreach(Portique portique, portiques){
        ui->textEdit->append("id: "+QString::number(portique.getId())+"\nx: "+QString::number(portique.getX())+"\ny: "+QString::number(portique.getY())+"\nsalle 1: "+QString::number(portique.getSalle1().getNumSalle())+"\nsalle 2: "+QString::number(portique.getSalle2().getNumSalle())+"\nlecteur: "+portique.getLecteurRFID().getIp());
        ui->textEdit->append("--------------------");
    }
}

void PortiqueWindow::on_pushButtonGetCount_clicked()
{
    int count = portiqueSrv->getCount();
    ui->textEdit->setText("count = "+QString::number(count));
}

void PortiqueWindow::on_pushButtonGetBySalle_clicked()
{
    Salle salle;
    if(!ui->comboBoxSalle1->currentText().isEmpty()){
        salle = salleSrv->getByNumSalle(ui->comboBoxSalle1->currentText().toInt());
    }
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Portique> portiques = portiqueSrv->getBySalle(salle, page, parPage);
    ui->textEdit->clear();
    foreach(Portique portique, portiques){
        ui->textEdit->append("id: "+QString::number(portique.getId())+"\nx: "+QString::number(portique.getX())+"\ny: "+QString::number(portique.getY())+"\nsalle 1: "+QString::number(portique.getSalle1().getNumSalle())+"\nsalle 2: "+QString::number(portique.getSalle2().getNumSalle())+"\nlecteur: "+portique.getLecteurRFID().getIp());
        ui->textEdit->append("--------------------");
    }
}

void PortiqueWindow::on_pushButtonGetCountBySalle_clicked()
{
    Salle salle;
    if(!ui->comboBoxSalle1->currentText().isEmpty()){
        salle = salleSrv->getByNumSalle(ui->comboBoxSalle1->currentText().toInt());
    }
    int count = portiqueSrv->getCountBySalle(salle);
    ui->textEdit->setText("count = "+QString::number(count));
}

void PortiqueWindow::on_pushButtonGetByLecteur_clicked()
{
    LecteurRFID lecteur = lecteurSrv->getByIp(ui->comboBoxLecteur->currentText());
    Portique portique = portiqueSrv->getByLecteurRFID(lecteur);
    ui->textEdit->append("id: "+QString::number(portique.getId())+"\nx: "+QString::number(portique.getX())+"\ny: "+QString::number(portique.getY())+"\nsalle 1: "+QString::number(portique.getSalle1().getNumSalle())+"\nsalle 2: "+QString::number(portique.getSalle2().getNumSalle())+"\nlecteur: "+portique.getLecteurRFID().getIp());
}

void PortiqueWindow::on_comboBoxSalle1_currentIndexChanged(const QString &arg1) // Permet de retirer la proposition du numéro de salle 1 dans celle de salle 2
{
    ui->comboBoxSalle2->setCurrentIndex(0); // On remet la valeur par défault à la salle 2 si il y a eu un changement sur la salle 1
    if(arg1 != ""){ // Si l'item séléctionné n'est pas vide (celui de défault), on le supprime de la liste
        ui->comboBoxSalle2->removeItem(ui->comboBoxSalle2->findText(arg1, Qt::MatchExactly));
        if(comboBox != ""){ // Si un item à deja été précédement supprimé, on le remet dans la liste
            ui->comboBoxSalle2->addItem(comboBox);
            ui->comboBoxSalle2->model()->sort(0); // Permet de remettre dans l'ordre les éléments (ascendent par défault)
        }
        ui->comboBoxSalle2->setEnabled(true);
    }else{
        ui->comboBoxSalle2->setEnabled(false);
    }
    comboBox = arg1; // On garde en mémoire la proposition supprimé
}

void PortiqueWindow::on_pushButtonGetListSalle_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Salle> listSalle = portiqueSrv->getListSalle(page, parPage);
    ui->textEdit->clear();
    foreach(Salle salle, listSalle){
        ui->textEdit->append("id: "+QString::number(salle.getId())+"\nx_ini: "+salle.getX_ini()+"\ny_ini: "+salle.getY_ini()+"\nx_fin: "+salle.getX_fin()+"\ny_fin: "+salle.getY_fin()+"\nnumSalle: "+QString::number(salle.getNumSalle())+"\nnomSalle: "+salle.getNomSalle()+"\nnomAtelier: "+salle.getNomAtelier());
        ui->textEdit->append("--------------------");
    }
}

void PortiqueWindow::on_pushButtonGetCountListSalle_clicked()
{
    int count = portiqueSrv->getCountListSalle();
    ui->textEdit->setText("count = "+QString::number(count));
}

void PortiqueWindow::on_pushButtonGetListLecteur_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<LecteurRFID> listLecteur = portiqueSrv->getListLecteurRFID(page, parPage);
    ui->textEdit->clear();
    foreach(LecteurRFID lecteur, listLecteur){
        ui->textEdit->append("id: "+QString::number(lecteur.getId())+"\nip: "+lecteur.getIp()+"\nmodele: "+lecteur.getModele()+"\netatOn: "+QString::number(lecteur.getEtatOn()));
        ui->textEdit->append("--------------------");
    }
}

void PortiqueWindow::on_pushButtonGetCountListLecteur_clicked()
{
    int count = portiqueSrv->getCountListLecteurRFID();
    ui->textEdit->setText("count = "+QString::number(count));
}

void PortiqueWindow::closeEvent(QCloseEvent *ev){
    ev->accept();
    emit fin(this);
}
