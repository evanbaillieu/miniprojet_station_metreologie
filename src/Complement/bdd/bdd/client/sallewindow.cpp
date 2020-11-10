#include "sallewindow.h"
#include "ui_sallewindow.h"
#include <QCloseEvent>

SalleWindow::SalleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SalleWindow)
{
    ui->setupUi(this);
    salleSrv = MetierFactory::getSalleServiceImpl();
}

SalleWindow::~SalleWindow()
{
    delete ui;
}

void SalleWindow::on_pushButtonAdd_clicked()
{
    float x_ini = ui->lineEditX_ini->text().toFloat();
    float y_ini = ui->lineEditY_ini->text().toFloat();
    float x_fin = ui->lineEditX_fin->text().toFloat();
    float y_fin = ui->lineEditY_fin->text().toFloat();
    int numSalle = ui->lineEditNumSalle->text().toInt();
    QString nomSalle = ui->lineEditNomSalle->text();
    QString nomAtelier = ui->lineEditNomAtelier->text();
    Salle salle_temp = Salle(x_ini, y_ini, x_fin, y_fin, numSalle, nomSalle, nomAtelier);
    Salle salle = salleSrv->add(salle_temp);
    ui->textEdit->setText("id: "+QString::number(salle.getId())+"\nx_ini: "+QString::number(salle.getX_ini())+"\ny_ini: "+QString::number(salle.getY_ini())+"\nx_fin: "+QString::number(salle.getX_fin())+"\ny_fin: "+QString::number(salle.getY_fin())+"\nnumSalle: "+QString::number(salle.getNumSalle())+"\nnomSalle: "+salle.getNomSalle()+"\nnomAtelier: "+salle.getNomAtelier());
}

void SalleWindow::on_pushButtonGetById_clicked()
{
    long id = ui->lineEditId->text().toLong();
    Salle salle = salleSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(salle.getId())+"\nx_ini: "+QString::number(salle.getX_ini())+"\ny_ini: "+QString::number(salle.getY_ini())+"\nx_fin: "+QString::number(salle.getX_fin())+"\ny_fin: "+QString::number(salle.getY_fin())+"\nnumSalle: "+QString::number(salle.getNumSalle())+"\nnomSalle: "+salle.getNomSalle()+"\nnomAtelier: "+salle.getNomAtelier());
}

void SalleWindow::on_pushButtonRemove_clicked()
{
    long id = ui->lineEditId->text().toLong();
    Salle salle = salleSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(salle.getId())+"\nx_ini: "+QString::number(salle.getX_ini())+"\ny_ini: "+QString::number(salle.getY_ini())+"\nx_fin: "+QString::number(salle.getX_fin())+"\ny_fin: "+QString::number(salle.getY_fin())+"\nnumSalle: "+QString::number(salle.getNumSalle())+"\nnomSalle: "+salle.getNomSalle()+"\nnomAtelier: "+salle.getNomAtelier());
    bool execute = salleSrv->remove(salle);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
}

void SalleWindow::on_pushButtonUpdate_clicked()
{
    long id = ui->lineEditId->text().toLong();
    QString x_ini = ui->lineEditX_ini->text();
    QString y_ini = ui->lineEditY_ini->text();
    QString x_fin = ui->lineEditX_fin->text();
    QString y_fin = ui->lineEditY_fin->text();
    QString numSalle = ui->lineEditNumSalle->text();
    QString nomSalle = ui->lineEditNomSalle->text();
    QString nomAtelier = ui->lineEditNomAtelier->text();
    Salle salle = salleSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(salle.getId())+"\nx_ini: "+QString::number(salle.getX_ini())+"\ny_ini: "+QString::number(salle.getY_ini())+"\nx_fin: "+QString::number(salle.getX_fin())+"\ny_fin: "+QString::number(salle.getY_fin())+"\nnumSalle: "+QString::number(salle.getNumSalle())+"\nnomSalle: "+salle.getNomSalle()+"\nnomAtelier: "+salle.getNomAtelier());
    if(!x_ini.isEmpty()){
        salle.setX_ini(x_ini.toFloat());
    }
    if(!y_ini.isEmpty()){
        salle.setY_ini(y_ini.toFloat());
    }
    if(!x_fin.isEmpty()){
        salle.setX_fin(x_fin.toFloat());
    }
    if(!y_fin.isEmpty()){
        salle.setY_fin(y_fin.toFloat());
    }
    if(!numSalle.isEmpty()){
        salle.setNumSalle(numSalle.toInt());
    }
    if(!nomSalle.isEmpty()){
        salle.setNomSalle(nomSalle);
    }
    if(!nomAtelier.isEmpty()){
        salle.setNomAtelier(nomAtelier);
    }
    bool execute = salleSrv->update(salle);
    salle = salleSrv->getById(id);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
    ui->textEdit->append("--------------------");
    ui->textEdit->append("id: "+QString::number(salle.getId())+"\nx_ini: "+QString::number(salle.getX_ini())+"\ny_ini: "+QString::number(salle.getY_ini())+"\nx_fin: "+QString::number(salle.getX_fin())+"\ny_fin: "+QString::number(salle.getY_fin())+"\nnumSalle: "+QString::number(salle.getNumSalle())+"\nnomSalle: "+salle.getNomSalle()+"\nnomAtelier: "+salle.getNomAtelier());
}

void SalleWindow::on_pushButtonGetAll_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Salle> salles = salleSrv->getAll(page, parPage);
    ui->textEdit->clear();
    foreach(Salle salle, salles){
        ui->textEdit->append("id: "+QString::number(salle.getId())+"\nx_ini: "+QString::number(salle.getX_ini())+"\ny_ini: "+QString::number(salle.getY_ini())+"\nx_fin: "+QString::number(salle.getX_fin())+"\ny_fin: "+QString::number(salle.getY_fin())+"\nnumSalle: "+QString::number(salle.getNumSalle())+"\nnomSalle: "+salle.getNomSalle()+"\nnomAtelier: "+salle.getNomAtelier());
        ui->textEdit->append("--------------------");
    }
}

void SalleWindow::on_pushButtonGetCount_clicked()
{
    int count = salleSrv->getCount();
    ui->textEdit->setText("count = "+QString::number(count));
}

void SalleWindow::on_pushButtonGetByNumSalle_clicked()
{
    int numSalle = ui->lineEditNumSalle->text().toInt();
    Salle salle = salleSrv->getByNumSalle(numSalle);
    ui->textEdit->setText("id: "+QString::number(salle.getId())+"\nx_ini: "+QString::number(salle.getX_ini())+"\ny_ini: "+QString::number(salle.getY_ini())+"\nx_fin: "+QString::number(salle.getX_fin())+"\ny_fin: "+QString::number(salle.getY_fin())+"\nnumSalle: "+QString::number(salle.getNumSalle())+"\nnomSalle: "+salle.getNomSalle()+"\nnomAtelier: "+salle.getNomAtelier());
}

void SalleWindow::on_pushButtonGetByNomSalle_clicked()
{
    QString nomSalle = ui->lineEditNomSalle->text();
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Salle> salles = salleSrv->getByNomSalle(nomSalle, page, parPage);
    ui->textEdit->clear();
    foreach(Salle salle, salles){
        ui->textEdit->append("id: "+QString::number(salle.getId())+"\nx_ini: "+QString::number(salle.getX_ini())+"\ny_ini: "+QString::number(salle.getY_ini())+"\nx_fin: "+QString::number(salle.getX_fin())+"\ny_fin: "+QString::number(salle.getY_fin())+"\nnumSalle: "+QString::number(salle.getNumSalle())+"\nnomSalle: "+salle.getNomSalle()+"\nnomAtelier: "+salle.getNomAtelier());
        ui->textEdit->append("--------------------");
    }
}

void SalleWindow::on_pushButtonGetCountByNomSalle_clicked()
{
    QString nomSalle = ui->lineEditNomSalle->text();
    int count = salleSrv->getCountByNomSalle(nomSalle);
    ui->textEdit->setText("count = "+QString::number(count));
}

void SalleWindow::on_pushButtonGetByNomAtelier_clicked()
{
    QString nomAtelier = ui->lineEditNomAtelier->text();
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Salle> salles = salleSrv->getByNomAtelier(nomAtelier, page, parPage);
    ui->textEdit->clear();
    foreach(Salle salle, salles){
        ui->textEdit->append("id: "+QString::number(salle.getId())+"\nx_ini: "+QString::number(salle.getX_ini())+"\ny_ini: "+QString::number(salle.getY_ini())+"\nx_fin: "+QString::number(salle.getX_fin())+"\ny_fin: "+QString::number(salle.getY_fin())+"\nnumSalle: "+QString::number(salle.getNumSalle())+"\nnomSalle: "+salle.getNomSalle()+"\nnomAtelier: "+salle.getNomAtelier());
        ui->textEdit->append("--------------------");
    }
}

void SalleWindow::on_getCountByNomAtelier_clicked()
{
    QString nomAtelier = ui->lineEditNomAtelier->text();
    int count = salleSrv->getCountByNomAtelier(nomAtelier);
    ui->textEdit->setText("count = "+QString::number(count));
}

void SalleWindow::on_pushButtonGetListNumSalle_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<int> listNumSalle = salleSrv->getListNumSalle(page, parPage);
    ui->textEdit->clear();
    foreach(int numSalle, listNumSalle){
        ui->textEdit->append(QString::number(numSalle));
    }
}

void SalleWindow::on_pushButtonGetCountListNumSalle_clicked()
{
    int count = salleSrv->getCountListNumSalle();
    ui->textEdit->setText("count = "+QString::number(count));
}

void SalleWindow::on_pushButtonGetListNomSalle_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<QString> listNomSalle = salleSrv->getListNomSalle(page, parPage);
    ui->textEdit->clear();
    foreach(QString nomSalle, listNomSalle){
        ui->textEdit->append(nomSalle);
    }
}

void SalleWindow::on_pushButtonGetCountListNomSalle_clicked()
{
    int count = salleSrv->getCountListNomSalle();
    ui->textEdit->setText("count = "+QString::number(count));
}

void SalleWindow::on_pushButtonGetListNomAtelier_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<QString> listNomAtelier = salleSrv->getListNomAtelier(page, parPage);
    ui->textEdit->clear();
    foreach(QString nomAtelier, listNomAtelier){
        ui->textEdit->append(nomAtelier);
    }
}

void SalleWindow::on_pushButtonGetCountListNomAtelier_clicked()
{
    int count = salleSrv->getCountListNomAtelier();
    ui->textEdit->setText("count = "+QString::number(count));
}

void SalleWindow::closeEvent(QCloseEvent *ev){
    ev->accept();
    emit fin(this);
}
