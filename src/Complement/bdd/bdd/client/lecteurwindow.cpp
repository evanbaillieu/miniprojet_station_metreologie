#include "lecteurwindow.h"
#include "ui_lecteurwindow.h"
#include <QCloseEvent>

LecteurWindow::LecteurWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LecteurWindow)
{
    ui->setupUi(this);
    lecteurRFIDSrv = MetierFactory::getLecteurRFIDServiceImpl();
}

LecteurWindow::~LecteurWindow()
{
    delete ui;
}

void LecteurWindow::on_pushButtonAdd_clicked()
{
    QString ip = ui->lineEditIp->text();
    QString modele = ui->lineEditModele->text();
    bool etatOn = ui->checkBoxEtatOn->isChecked();
    LecteurRFID lecteur_temp = LecteurRFID(ip, modele, etatOn);
    LecteurRFID lecteur = lecteurRFIDSrv->add(lecteur_temp);
    ui->textEdit->setText("id: "+QString::number(lecteur.getId())+"\nip: "+lecteur.getIp()+"\nmodele: "+lecteur.getModele()+"\netatOn: "+QString::number(lecteur.getEtatOn()));
}

void LecteurWindow::on_pushButtonGetById_clicked()
{
    long id = ui->lineEditId->text().toLong();
    LecteurRFID lecteur = lecteurRFIDSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(lecteur.getId())+"\nip: "+lecteur.getIp()+"\nmodele: "+lecteur.getModele()+"\netatOn: "+QString::number(lecteur.getEtatOn()));
}

void LecteurWindow::on_pushButtonRemove_clicked()
{
    long id = ui->lineEditId->text().toLong();
    LecteurRFID lecteur = lecteurRFIDSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(lecteur.getId())+"\nip: "+lecteur.getIp()+"\nmodele: "+lecteur.getModele()+"\netatOn: "+QString::number(lecteur.getEtatOn()));
    bool execute = lecteurRFIDSrv->remove(lecteur);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
}

void LecteurWindow::on_pushButtonUpdate_clicked()
{
    long id = ui->lineEditId->text().toLong();
    QString ip = ui->lineEditIp->text();
    QString modele = ui->lineEditModele->text();
    bool etatOn = ui->checkBoxEtatOn->isChecked();
    LecteurRFID lecteur = lecteurRFIDSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(lecteur.getId())+"\nip: "+lecteur.getIp()+"\nmodele: "+lecteur.getModele()+"\netatOn: "+QString::number(lecteur.getEtatOn()));
    if(!ip.isEmpty()){
        lecteur.setIp(ip);
    }
    if(!modele.isEmpty()){
        lecteur.setModele(modele);
    }
    lecteur.setEtatOn(etatOn);
    bool execute = lecteurRFIDSrv->update(lecteur);
    lecteur = lecteurRFIDSrv->getById(id);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
    ui->textEdit->append("--------------------");
    ui->textEdit->append("id: "+QString::number(lecteur.getId())+"\nip: "+lecteur.getIp()+"\nmodele: "+lecteur.getModele()+"\netatOn: "+QString::number(lecteur.getEtatOn()));
}

void LecteurWindow::on_pushButtonGetAll_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<LecteurRFID> lecteurs = lecteurRFIDSrv->getAll(page, parPage);
    ui->textEdit->clear();
    foreach(LecteurRFID lecteur, lecteurs){
        ui->textEdit->append("id: "+QString::number(lecteur.getId())+"\nip: "+lecteur.getIp()+"\nmodele: "+lecteur.getModele()+"\netatOn: "+QString::number(lecteur.getEtatOn()));
        ui->textEdit->append("--------------------");
    }
}

void LecteurWindow::on_pushButtongetCount_clicked()
{
    int count = lecteurRFIDSrv->getCount();
    ui->textEdit->setText("count = "+QString::number(count));
}

void LecteurWindow::on_pushButtonGetByIp_clicked()
{
    QString ip = ui->lineEditIp->text();
    LecteurRFID lecteur = lecteurRFIDSrv->getByIp(ip);
    ui->textEdit->setText("id: "+QString::number(lecteur.getId())+"\nip: "+lecteur.getIp()+"\nmodele: "+lecteur.getModele()+"\netatOn: "+QString::number(lecteur.getEtatOn()));
}

void LecteurWindow::on_pushButtonGetByModele_clicked()
{
    QString modele = ui->lineEditModele->text();
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<LecteurRFID> lecteurs = lecteurRFIDSrv->getByModele(modele, page, parPage);
    ui->textEdit->clear();
    foreach(LecteurRFID lecteur, lecteurs){
        ui->textEdit->append("id: "+QString::number(lecteur.getId())+"\nip: "+lecteur.getIp()+"\nmodele: "+lecteur.getModele()+"\netatOn: "+QString::number(lecteur.getEtatOn()));
        ui->textEdit->append("--------------------");
    }
}

void LecteurWindow::on_pushButtonGetCountByModele_clicked()
{
    QString modele = ui->lineEditModele->text();
    int count = lecteurRFIDSrv->getCountByModele(modele);
    ui->textEdit->setText("count = "+QString::number(count));
}

void LecteurWindow::on_pushButtonGetByEtatOn_clicked()
{
    bool etatOn = ui->checkBoxEtatOn->isChecked();
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<LecteurRFID> lecteurs = lecteurRFIDSrv->getByEtatOn(etatOn, page, parPage);
    ui->textEdit->clear();
    foreach(LecteurRFID lecteur, lecteurs){
        ui->textEdit->append("id: "+QString::number(lecteur.getId())+"\nip: "+lecteur.getIp()+"\nmodele: "+lecteur.getModele()+"\netatOn: "+QString::number(lecteur.getEtatOn()));
        ui->textEdit->append("--------------------");
    }
}

void LecteurWindow::on_pushButtonGetCountByEtatOn_clicked()
{
    bool etatOn = ui->checkBoxEtatOn->isChecked();
    int count = lecteurRFIDSrv->getCountByEtatOn(etatOn);
    ui->textEdit->setText("count = "+QString::number(count));
}

void LecteurWindow::on_pushButtonGetListIp_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<QString> listIp = lecteurRFIDSrv->getListIp(page, parPage);
    ui->textEdit->clear();
    foreach(QString ip, listIp){
        ui->textEdit->append(ip);
    }
}

void LecteurWindow::on_pushButtonGetCountListIp_clicked()
{
    int count = lecteurRFIDSrv->getCountListIp();
    ui->textEdit->setText("count = "+QString::number(count));
}

void LecteurWindow::on_pushButtonGetListModele_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<QString> listModele = lecteurRFIDSrv->getListModele(page, parPage);
    ui->textEdit->clear();
    foreach(QString modele, listModele){
        ui->textEdit->append(modele);
    }
}

void LecteurWindow::on_pushButtonGetCountListModele_clicked()
{
    int count = lecteurRFIDSrv->getCountListModele();
    ui->textEdit->setText("count = "+QString::number(count));
}

void LecteurWindow::closeEvent(QCloseEvent *ev){
    ev->accept();
    emit fin(this);
}
