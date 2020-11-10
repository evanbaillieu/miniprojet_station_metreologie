#include "typewindow.h"
#include "ui_typewindow.h"
#include <QCloseEvent>

TypeWindow::TypeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TypeWindow)
{
    ui->setupUi(this);
    typeSrv = MetierFactory::getTypeServiceImpl();
}

TypeWindow::~TypeWindow(){
    delete ui;
}

void TypeWindow::on_pushButtonAdd_clicked() {
    QString nomType = ui->lineEditNomType->text();
    QString nomImage = ui->lineEditNomImage->text();
    Type type_temp = Type(nomType, nomImage);
    Type type = typeSrv->add(type_temp);
    ui->textEdit->setText("id: "+QString::number(type.getId())+"\nnomType: "+type.getNomType()+"\nnomImage: "+type.getNomImage());
}

void TypeWindow::on_pushButtonGetById_clicked() {
    long id = ui->lineEditId->text().toLong();
    Type type = typeSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(type.getId())+"\nnomType: "+type.getNomType()+"\nnomImage: "+type.getNomImage());
}

void TypeWindow::on_pushButtonRemove_clicked() {
    long id = ui->lineEditId->text().toLong();
    Type type = typeSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(type.getId())+"\nnomType: "+type.getNomType()+"\nnomImage: "+type.getNomImage());
    bool execute = typeSrv->remove(type);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
}

void TypeWindow::on_pushButtonUpdate_clicked() {
    long id = ui->lineEditId->text().toLong();
    QString nomType = ui->lineEditNomType->text();
    QString nomImage = ui->lineEditNomImage->text();
    Type type = typeSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(type.getId())+"\nnomType: "+type.getNomType()+"\nnomImage: "+type.getNomImage());
    if(!nomType.isEmpty()){
        type.setNomType(nomType);
    }
    if(!nomImage.isEmpty()){
        type.setNomImage(nomImage);
    }
    bool execute = typeSrv->update(type);
    type = typeSrv->getById(id);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
    ui->textEdit->append("--------------------");
    ui->textEdit->append("id: "+QString::number(type.getId())+"\nnomType: "+type.getNomType()+"\nnomImage: "+type.getNomImage());
}

void TypeWindow::on_pushButtonGetAll_clicked() {
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Type> types = typeSrv->getAll(page, parPage);
    ui->textEdit->clear();
    foreach(Type type, types){
        ui->textEdit->append("id: "+QString::number(type.getId())+"\nnomType: "+type.getNomType()+"\nnomImage: "+type.getNomImage());
        ui->textEdit->append("--------------------");
    }
}

void TypeWindow::on_pushButtongetCount_clicked() {
    int count = typeSrv->getCount();
    ui->textEdit->setText("count = "+QString::number(count));
}

void TypeWindow::on_pushButtonGetByNomType_clicked() {
    QString nomType = ui->lineEditNomType->text();
    Type type = typeSrv->getByNomType(nomType);
    ui->textEdit->setText("id: "+QString::number(type.getId())+"\nnomType: "+type.getNomType()+"\nnomImage: "+type.getNomImage());
}

void TypeWindow::on_pushButtonGetListNomType_clicked() {
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<QString> listNomType = typeSrv->getListNomType(page, parPage);
    ui->textEdit->clear();
    foreach(QString nomType, listNomType){
        ui->textEdit->append(nomType);
    }
}

void TypeWindow::on_pushButtonGetCountListNomType_clicked() {
    int count = typeSrv->getCountListNomType();
    ui->textEdit->setText("count = "+QString::number(count));
}

void TypeWindow::on_pushButtonGetByNomImage_clicked() {
    QString nomImage = ui->lineEditNomImage->text();
    Type type = typeSrv->getByNomImage(nomImage);
    ui->textEdit->setText("id: "+QString::number(type.getId())+"\nnomType: "+type.getNomType()+"\nnomImage: "+type.getNomImage());
}

void TypeWindow::on_pushButtonGetListNomImage_clicked() {
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<QString> listNomImage = typeSrv->getListNomImage(page, parPage);
    ui->textEdit->clear();
    foreach(QString nomImage, listNomImage){
        ui->textEdit->append(nomImage);
    }
}

void TypeWindow::on_pushButtonGetCountListNomImage_clicked() {
    int count = typeSrv->getCountListNomImage();
    ui->textEdit->setText("count = "+QString::number(count));
}

void TypeWindow::closeEvent(QCloseEvent *ev){
    ev->accept();
    emit fin(this);
}
