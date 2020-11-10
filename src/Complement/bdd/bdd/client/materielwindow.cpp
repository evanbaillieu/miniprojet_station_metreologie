#include "materielwindow.h"
#include "ui_materielwindow.h"
#include <QCloseEvent>

MaterielWindow::MaterielWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MaterielWindow)
{
    ui->setupUi(this);
    materielSrv = MetierFactory::getMaterielServiceImpl();
    typeSrv = MetierFactory::getTypeServiceImpl();
    QList<QString> nomTypes = typeSrv->getListNomType(0, typeSrv->getCountListNomType());
    ui->comboBoxType->addItem("");
    foreach(QString nomType, nomTypes){
        ui->comboBoxType->addItem(nomType);
    }
}

MaterielWindow::~MaterielWindow()
{
    delete ui;
}

void MaterielWindow::on_pushButtonAdd_clicked()
{
    QString idBadge = ui->lineEditIdBadge->text();
    QDate dateControle = QDate::fromString(ui->lineEditDateControle->text(), "dd/MM/yyyy");
    QDate newDateControle = QDate::fromString(ui->lineEditNewDateControle->text(), "dd/MM/yyyy");
    QString nomMateriel = ui->lineEditNomMateriel->text();
    Type type = typeSrv->getByNomType(ui->comboBoxType->currentText());
    Materiel materiel_temp = Materiel(idBadge, dateControle, newDateControle, nomMateriel, type);
    Materiel materiel = materielSrv->add(materiel_temp);
    ui->textEdit->setText("id: "+QString::number(materiel.getId())+"\nidBadge: "+materiel.getIdBadge()+"\ndateControle: "+materiel.getDateControle().toString("dd/MM/yyyy")+"\nnewDateControle: "+materiel.getNewDateControle().toString("dd/MM/yyyy")+"\nnomMateriel: "+materiel.getNomMateriel()+"\ntype: "+materiel.getType().getNomType());
}

void MaterielWindow::on_pushButtonGetById_clicked()
{
    long id = ui->lineEditId->text().toLong();
    Materiel materiel = materielSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(materiel.getId())+"\nidBadge: "+materiel.getIdBadge()+"\ndateControle: "+materiel.getDateControle().toString("dd/MM/yyyy")+"\nnewDateControle: "+materiel.getNewDateControle().toString("dd/MM/yyyy")+"\nnomMateriel: "+materiel.getNomMateriel()+"\ntype: "+materiel.getType().getNomType());
}

void MaterielWindow::on_pushButtonRemove_clicked()
{
    long id = ui->lineEditId->text().toLong();
    Materiel materiel = materielSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(materiel.getId())+"\nidBadge: "+materiel.getIdBadge()+"\ndateControle: "+materiel.getDateControle().toString("dd/MM/yyyy")+"\nnewDateControle: "+materiel.getNewDateControle().toString("dd/MM/yyyy")+"\nnomMateriel: "+materiel.getNomMateriel()+"\ntype: "+materiel.getType().getNomType());
    bool execute = materielSrv->remove(materiel);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
}

void MaterielWindow::on_pushButtonUpdate_clicked()
{
    long id = ui->lineEditId->text().toLong();
    QString idBadge = ui->lineEditIdBadge->text();
    QDate dateControle = QDate::fromString(ui->lineEditDateControle->text(), "dd/MM/yyyy");
    QDate newDateControle = QDate::fromString(ui->lineEditNewDateControle->text(), "dd/MM/yyyy");
    QString nomMateriel = ui->lineEditNomMateriel->text();
    Type type = typeSrv->getByNomType(ui->comboBoxType->currentText());
    Materiel materiel = materielSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(materiel.getId())+"\nidBadge: "+materiel.getIdBadge()+"\ndateControle: "+materiel.getDateControle().toString("dd/MM/yyyy")+"\nnewDateControle: "+materiel.getNewDateControle().toString("dd/MM/yyyy")+"\nnomMateriel: "+materiel.getNomMateriel()+"\ntype: "+materiel.getType().getNomType());
    if(idBadge != 0){
        materiel.setIdBadge(idBadge);
    }
    if(dateControle.isValid()){
        materiel.setDateControle(dateControle);
    }
    if(newDateControle.isValid()){
        materiel.setNewDateControle(newDateControle);
    }
    if(!nomMateriel.isEmpty()){
        materiel.setNomMateriel(nomMateriel);
    }
    if(type.getId() > 0){
        materiel.setType(type);
    }
    bool execute = materielSrv->update(materiel);
    materiel = materielSrv->getById(id);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
    ui->textEdit->append("--------------------");
    ui->textEdit->append("id: "+QString::number(materiel.getId())+"\nidBadge: "+materiel.getIdBadge()+"\ndateControle: "+materiel.getDateControle().toString("dd/MM/yyyy")+"\nnewDateControle: "+materiel.getNewDateControle().toString("dd/MM/yyyy")+"\nnomMateriel: "+materiel.getNomMateriel()+"\ntype: "+materiel.getType().getNomType());
}

void MaterielWindow::on_pushButtonGetAll_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Materiel> materiels = materielSrv->getAll(page, parPage);
    ui->textEdit->clear();
    foreach(Materiel materiel, materiels){
        ui->textEdit->append("id: "+QString::number(materiel.getId())+"\nidBadge: "+materiel.getIdBadge()+"\ndateControle: "+materiel.getDateControle().toString("dd/MM/yyyy")+"\nnewDateControle: "+materiel.getNewDateControle().toString("dd/MM/yyyy")+"\nnomMateriel: "+materiel.getNomMateriel()+"\ntype: "+materiel.getType().getNomType());
        ui->textEdit->append("--------------------");
    }
}

void MaterielWindow::on_pushButtongetCount_clicked()
{
    int count = materielSrv->getCount();
    ui->textEdit->setText("count = "+QString::number(count));
}

void MaterielWindow::on_pushButtonGetByIdBadge_clicked()
{
    QString idBadge = ui->lineEditIdBadge->text();
    Materiel materiel = materielSrv->getByIdBadge(idBadge);
    ui->textEdit->setText("id: "+QString::number(materiel.getId())+"\nidBadge: "+materiel.getIdBadge()+"\ndateControle: "+materiel.getDateControle().toString("dd/MM/yyyy")+"\nnewDateControle: "+materiel.getNewDateControle().toString("dd/MM/yyyy")+"\nnomMateriel: "+materiel.getNomMateriel()+"\ntype: "+materiel.getType().getNomType());
}

void MaterielWindow::on_pushButtonGetByDateControle_clicked()
{
    QDate dateControle = QDate::fromString(ui->lineEditDateControle->text(), "dd/MM/yyyy");
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Materiel> materiels = materielSrv->getByDateControle(dateControle, page, parPage);
    ui->textEdit->clear();
    foreach(Materiel materiel, materiels){
        ui->textEdit->append("id: "+QString::number(materiel.getId())+"\nidBadge: "+materiel.getIdBadge()+"\ndateControle: "+materiel.getDateControle().toString("dd/MM/yyyy")+"\nnewDateControle: "+materiel.getNewDateControle().toString("dd/MM/yyyy")+"\nnomMateriel: "+materiel.getNomMateriel()+"\ntype: "+materiel.getType().getNomType());
        ui->textEdit->append("--------------------");
    }
}

void MaterielWindow::on_pushButtonGetCountByDateControle_clicked()
{
    QDate dateControle = QDate::fromString(ui->lineEditDateControle->text(), "dd/MM/yyyy");
    int count = materielSrv->getCountByDateControle(dateControle);
    ui->textEdit->setText("count = "+QString::number(count));
}

void MaterielWindow::on_pushButtonGetByNewDateControle_clicked()
{
    QDate newDateControle = QDate::fromString(ui->lineEditNewDateControle->text(), "dd/MM/yyyy");
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Materiel> materiels = materielSrv->getByNewDateControle(newDateControle, page, parPage);
    ui->textEdit->clear();
    foreach(Materiel materiel, materiels){
        ui->textEdit->append("id: "+QString::number(materiel.getId())+"\nidBadge: "+materiel.getIdBadge()+"\ndateControle: "+materiel.getDateControle().toString("dd/MM/yyyy")+"\nnewDateControle: "+materiel.getNewDateControle().toString("dd/MM/yyyy")+"\nnomMateriel: "+materiel.getNomMateriel()+"\ntype: "+materiel.getType().getNomType());
        ui->textEdit->append("--------------------");
    }
}

void MaterielWindow::on_pushButtonGetCountByNewDateControle_clicked()
{
    QDate newDateControle = QDate::fromString(ui->lineEditNewDateControle->text(), "dd/MM/yyyy");
    int count = materielSrv->getCountByNewDateControle(newDateControle);
    ui->textEdit->setText("count = "+QString::number(count));
}

void MaterielWindow::on_pushButtonGetByPeriode_clicked()
{
    QDate date = QDate::fromString(ui->lineEditDateControle->text(), "dd/MM/yyyy");
    bool avant = ui->checkBoxAvant->isChecked();
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Materiel> materiels = materielSrv->getByPeriode(date, avant, page, parPage);
    ui->textEdit->clear();
    foreach(Materiel materiel, materiels){
        ui->textEdit->append("id: "+QString::number(materiel.getId())+"\nidBadge: "+materiel.getIdBadge()+"\ndateControle: "+materiel.getDateControle().toString("dd/MM/yyyy")+"\nnewDateControle: "+materiel.getNewDateControle().toString("dd/MM/yyyy")+"\nnomMateriel: "+materiel.getNomMateriel()+"\ntype: "+materiel.getType().getNomType());
        ui->textEdit->append("--------------------");
    }
}

void MaterielWindow::on_pushButtonGetCountByPeriode_clicked()
{
    QDate date = QDate::fromString(ui->lineEditDateControle->text(), "dd/MM/yyyy");
    bool avant = ui->checkBoxAvant->isChecked();
    int count = materielSrv->getCountByPeriode(date, avant);
    ui->textEdit->setText("count = "+QString::number(count));
}

void MaterielWindow::on_pushButtonGetByNomMateriel_clicked()
{
    QString nomMateriel = ui->lineEditNomMateriel->text();
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Materiel> materiels = materielSrv->getByNomMateriel(nomMateriel, page, parPage);
    ui->textEdit->clear();
    foreach(Materiel materiel, materiels){
        ui->textEdit->append("id: "+QString::number(materiel.getId())+"\nidBadge: "+materiel.getIdBadge()+"\ndateControle: "+materiel.getDateControle().toString("dd/MM/yyyy")+"\nnewDateControle: "+materiel.getNewDateControle().toString("dd/MM/yyyy")+"\nnomMateriel: "+materiel.getNomMateriel()+"\ntype: "+materiel.getType().getNomType());
        ui->textEdit->append("--------------------");
    }
}

void MaterielWindow::on_pushButtonGetCountByNomMateriel_clicked()
{
    QString nomMateriel = ui->lineEditNomMateriel->text();
    int count = materielSrv->getCountByNomMateriel(nomMateriel);
    ui->textEdit->setText("count = "+QString::number(count));
}

void MaterielWindow::on_pushButtonGetByType_clicked()
{
    Type type = typeSrv->getByNomType(ui->comboBoxType->currentText());
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Materiel> materiels = materielSrv->getByType(type, page, parPage);
    ui->textEdit->clear();
    foreach(Materiel materiel, materiels){
        ui->textEdit->append("id: "+QString::number(materiel.getId())+"\nidBadge: "+materiel.getIdBadge()+"\ndateControle: "+materiel.getDateControle().toString("dd/MM/yyyy")+"\nnewDateControle: "+materiel.getNewDateControle().toString("dd/MM/yyyy")+"\nnomMateriel: "+materiel.getNomMateriel()+"\ntype: "+materiel.getType().getNomType());
        ui->textEdit->append("--------------------");
    }
}

void MaterielWindow::on_pushButtonGetCountByType_clicked()
{
    Type type = typeSrv->getByNomType(ui->comboBoxType->currentText());
    int count = materielSrv->getCountByType(type);
    ui->textEdit->setText("count = "+QString::number(count));
}

void MaterielWindow::on_pushButtonGetListIdBadge_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<QString> listIdBadge = materielSrv->getListIdBadge(page, parPage);
    ui->textEdit->clear();
    foreach(QString idBadge, listIdBadge){
        ui->textEdit->append(idBadge);
    }
}

void MaterielWindow::on_pushButtonGetCountListIdBadge_clicked()
{
    int count = materielSrv->getCountListIdBadge();
    ui->textEdit->setText("count = "+QString::number(count));
}

void MaterielWindow::on_pushButtonGetListDateControle_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<QDate> listDateControle = materielSrv->getListDateControle(page, parPage);
    ui->textEdit->clear();
    foreach(QDate dateCotrole, listDateControle){
        ui->textEdit->append(dateCotrole.toString("dd/MM/yyyy"));
    }
}

void MaterielWindow::on_pushButtonGetCountListDateControle_clicked()
{
    int count = materielSrv->getCountListDateControle();
    ui->textEdit->setText("count = "+QString::number(count));
}

void MaterielWindow::on_pushButtonGetListNomMateriel_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<QString> listNomMateriel = materielSrv->getListNomMateriel(page, parPage);
    ui->textEdit->clear();
    foreach(QString nomMateriel, listNomMateriel){
        ui->textEdit->append(nomMateriel);
    }
}

void MaterielWindow::on_pushButtonGetCountListNomMateriel_clicked()
{
    int count = materielSrv->getCountListNomMateriel();
    ui->textEdit->setText("count = "+QString::number(count));
}

void MaterielWindow::on_pushButtonGetListType_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Type> types = materielSrv->getListType(page, parPage);
    ui->textEdit->clear();
    foreach(Type type, types){
        ui->textEdit->append("id: "+QString::number(type.getId())+"\nnomType: "+type.getNomType()+"\nnomImage: "+type.getNomImage());
        ui->textEdit->append("--------------------");
    }
}

void MaterielWindow::on_pushButtonGetCountListType_clicked()
{
    int count = materielSrv->getCountListType();
    ui->textEdit->setText("count = "+QString::number(count));
}

void MaterielWindow::on_pushButtonGetListNewDateControle_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<QDate> listNewDateControle = materielSrv->getListNewDateControle(page, parPage);
    ui->textEdit->clear();
    foreach(QDate newDateControle, listNewDateControle){
        ui->textEdit->append(newDateControle.toString("dd/MM/yyyy"));
    }
}

void MaterielWindow::on_pushButtonGetCountListNewDateControle_clicked()
{
    int count = materielSrv->getCountListNewDateControle();
    ui->textEdit->setText("count = "+QString::number(count));
}

void MaterielWindow::closeEvent(QCloseEvent *ev){
    ev->accept();
    emit fin(this);
}
