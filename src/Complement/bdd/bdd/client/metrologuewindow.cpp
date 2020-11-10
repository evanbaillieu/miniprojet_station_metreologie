#include "metrologuewindow.h"
#include "ui_metrologuewindow.h"
#include <QCloseEvent>

MetrologueWindow::MetrologueWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MetrologueWindow)
{
    ui->setupUi(this);
    metrologueSrv = MetierFactory::getMetrologueServiceImpl();
}

MetrologueWindow::~MetrologueWindow()
{
    delete ui;
}

void MetrologueWindow::on_pushButtonAdd_clicked()
{
    QString login = ui->lineEditLogin->text();
    QString password = ui->lineEditPassword->text();
    Metrologue metrologue_temp = Metrologue(login, password);
    Metrologue metrologue = metrologueSrv->add(metrologue_temp);
    ui->textEdit->setText("id: "+QString::number(metrologue.getId())+"\nlogin: "+metrologue.getLogin()+"\npassword: "+metrologue.getPassword());
}

void MetrologueWindow::on_pushButtonGetById_clicked()
{
    long id = ui->lineEditId->text().toLong();
    Metrologue metrologue = metrologueSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(metrologue.getId())+"\nlogin: "+metrologue.getLogin()+"\npassword: "+metrologue.getPassword());
}

void MetrologueWindow::on_pushButtonRemove_clicked()
{
    long id = ui->lineEditId->text().toLong();
    Metrologue metrologue = metrologueSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(metrologue.getId())+"\nlogin: "+metrologue.getLogin()+"\npassword: "+metrologue.getPassword());
    bool execute = metrologueSrv->remove(metrologue);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
}

void MetrologueWindow::on_pushButtonUpdate_clicked()
{
    long id = ui->lineEditId->text().toLong();
    QString login = ui->lineEditLogin->text();
    QString password = ui->lineEditPassword->text();
    Metrologue metrologue = metrologueSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(metrologue.getId())+"\nlogin: "+metrologue.getLogin()+"\npassword: "+metrologue.getPassword());
    if(!login.isEmpty()){
        metrologue.setLogin(login);
    }
    if(!password.isEmpty()){
        metrologue.setPassword(password);
    }
    bool execute = metrologueSrv->update(metrologue);
    metrologue = metrologueSrv->getById(id);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
    ui->textEdit->append("--------------------");
    ui->textEdit->append("id: "+QString::number(metrologue.getId())+"\nlogin: "+metrologue.getLogin()+"\npassword: "+metrologue.getPassword());
}

void MetrologueWindow::on_pushButtonGetAll_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Metrologue> metrologues = metrologueSrv->getAll(page, parPage);
    ui->textEdit->clear();
    foreach(Metrologue metrologue, metrologues){
        ui->textEdit->append("id: "+QString::number(metrologue.getId())+"\nlogin: "+metrologue.getLogin()+"\npassword: "+metrologue.getPassword());
        ui->textEdit->append("--------------------");
    }
}

void MetrologueWindow::on_pushButtongetCount_clicked()
{
    int count = metrologueSrv->getCount();
    ui->textEdit->setText("count = "+QString::number(count));
}

void MetrologueWindow::on_pushButtonGetByLogin_clicked()
{
    QString login = ui->lineEditLogin->text();
    Metrologue metrologue = metrologueSrv->getByLogin(login);
    ui->textEdit->setText("id: "+QString::number(metrologue.getId())+"\nlogin: "+metrologue.getLogin()+"\npassword: "+metrologue.getPassword());
}

void MetrologueWindow::on_pushButtonGetListLogin_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<QString> listLogin = metrologueSrv->getListLogin(page, parPage);
    ui->textEdit->clear();
    foreach(QString login, listLogin){
        ui->textEdit->append(login);
    }
}

void MetrologueWindow::on_pushButtonGetCountListLogin_clicked()
{
    int count = metrologueSrv->getCountListLogin();
    ui->textEdit->setText("count = "+QString::number(count));
}

void MetrologueWindow::closeEvent(QCloseEvent *ev){
    ev->accept();
    emit fin(this);
}
