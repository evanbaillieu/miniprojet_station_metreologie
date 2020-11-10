#include "localisationwindow.h"
#include "ui_localisationwindow.h"
#include <QCloseEvent>

LocalisationWindow::LocalisationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LocalisationWindow)
{
    ui->setupUi(this);
    localisationSrv = MetierFactory::getLocalisationServiceImpl();
    materielSrv = MetierFactory::getMaterielServiceImpl();
    salleSrv = MetierFactory::getSalleServiceImpl();
    ui->comboBoxIdMateriel->addItem("");
    QList<QString> idBadgeMateriels = materielSrv->getListIdBadge(0, materielSrv->getCountListIdBadge());
    foreach(QString idBadgeMateriel, idBadgeMateriels){
        ui->comboBoxIdMateriel->addItem(idBadgeMateriel);
    }
    QList<int> numSalles = salleSrv->getListNumSalle(0, salleSrv->getCountListNumSalle());
    ui->comboBoxIdSalle->addItem("");
    foreach(int numSalle, numSalles){
        ui->comboBoxIdSalle->addItem(QString::number(numSalle));
    }
}

LocalisationWindow::~LocalisationWindow()
{
    delete ui;
}

void LocalisationWindow::on_pushButtonAdd_clicked()
{
    Materiel materiel = materielSrv->getByIdBadge(ui->comboBoxIdMateriel->currentText());
    Salle salle = salleSrv->getByNumSalle(ui->comboBoxIdSalle->currentText().toInt());
    bool sortie = ui->checkBoxSortie->isChecked();
    Localisation localisation_temp = Localisation(materiel, salle, sortie);
    Localisation localisation = localisationSrv->add(localisation_temp);
    ui->textEdit->setText("id: "+QString::number(localisation.getId())+"\nidMateriel: "+QString::number(localisation.getMateriel().getId())+"\nidSalle: "+QString::number(localisation.getSalle().getId())+"\nsortie: "+QString::number(localisation.getSortie()));
}

void LocalisationWindow::on_pushButtonGetById_clicked()
{
    long id = ui->lineEditId->text().toLong();
    Localisation localisation = localisationSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(localisation.getId())+"\nidMateriel: "+QString::number(localisation.getMateriel().getId())+"\nidSalle: "+QString::number(localisation.getSalle().getId())+"\nsortie: "+QString::number(localisation.getSortie()));
}

void LocalisationWindow::on_pushButtonRemove_clicked()
{
    long id = ui->lineEditId->text().toLong();
    Localisation localisation = localisationSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(localisation.getId())+"\nidMateriel: "+QString::number(localisation.getMateriel().getId())+"\nidSalle: "+QString::number(localisation.getSalle().getId())+"\nsortie: "+QString::number(localisation.getSortie()));
    bool execute = localisationSrv->remove(localisation);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
}

void LocalisationWindow::on_pushButtonUpdate_clicked()
{
    long id = ui->lineEditId->text().toLong();
    Materiel materiel = materielSrv->getByIdBadge(ui->comboBoxIdMateriel->currentText());
    Salle salle = salleSrv->getByNumSalle(ui->comboBoxIdSalle->currentText().toInt());
    bool sortie = ui->checkBoxSortie->isChecked();
    Localisation localisation = localisationSrv->getById(id);
    ui->textEdit->setText("id: "+QString::number(localisation.getId())+"\nidMateriel: "+QString::number(localisation.getMateriel().getId())+"\nidSalle: "+QString::number(localisation.getSalle().getId())+"\nsortie: "+QString::number(localisation.getSortie()));
    if(materiel.getId() > 0){
        localisation.setMateriel(materiel);
    }
    if(salle.getId() > 0){
        localisation.setSalle(salle);
    }
    localisation.setSortie(sortie);
    bool execute = localisationSrv->update(localisation);
    localisation = localisationSrv->getById(id);
    ui->textEdit->append("--------------------");
    ui->textEdit->append("resultat de l'operation: "+QString::number(execute));
    ui->textEdit->append("--------------------");
    ui->textEdit->append("id: "+QString::number(localisation.getId())+"\nidMateriel: "+QString::number(localisation.getMateriel().getId())+"\nidSalle: "+QString::number(localisation.getSalle().getId())+"\nsortie: "+QString::number(localisation.getSortie()));
}

void LocalisationWindow::on_pushButtonGetAll_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Localisation> localisations = localisationSrv->getAll(page, parPage);
    ui->textEdit->clear();
    foreach(Localisation localisation, localisations){
        ui->textEdit->append("id: "+QString::number(localisation.getId())+"\nidMateriel: "+QString::number(localisation.getMateriel().getId())+"\nidSalle: "+QString::number(localisation.getSalle().getId())+"\nsortie: "+QString::number(localisation.getSortie()));
        ui->textEdit->append("--------------------");
    }
}

void LocalisationWindow::on_pushButtongetCount_clicked()
{
    int count = localisationSrv->getCount();
    ui->textEdit->setText("count = "+QString::number(count));
}

void LocalisationWindow::on_pushButtonGetByMateriel_clicked()
{
    Materiel materiel = materielSrv->getByIdBadge(ui->comboBoxIdMateriel->currentText());
    Localisation localisation = localisationSrv->getByMateriel(materiel);
    ui->textEdit->setText("id: "+QString::number(localisation.getId())+"\nidMateriel: "+QString::number(localisation.getMateriel().getId())+"\nidSalle: "+QString::number(localisation.getSalle().getId())+"\nsortie: "+QString::number(localisation.getSortie()));
}

void LocalisationWindow::on_pushButtonGetBySalle_clicked()
{
    Salle salle = salleSrv->getByNumSalle(ui->comboBoxIdSalle->currentText().toInt());
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Localisation> localisations = localisationSrv->getBySalle(salle, page, parPage);
    ui->textEdit->clear();
    foreach(Localisation localisation, localisations){
        ui->textEdit->append("id: "+QString::number(localisation.getId())+"\nidMateriel: "+QString::number(localisation.getMateriel().getId())+"\nidSalle: "+QString::number(localisation.getSalle().getId())+"\nsortie: "+QString::number(localisation.getSortie()));
        ui->textEdit->append("--------------------");
    }
}

void LocalisationWindow::on_pushButtonGetCountBySalle_clicked()
{
    Salle salle = salleSrv->getByNumSalle(ui->comboBoxIdSalle->currentText().toInt());
    int count = localisationSrv->getCountBySalle(salle);
    ui->textEdit->setText("count = "+QString::number(count));
}

void LocalisationWindow::on_pushButtonGetBySortie_clicked()
{
    bool sortie = ui->checkBoxSortie->isChecked();
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Localisation> localisations = localisationSrv->getBySortie(sortie, page, parPage);
    ui->textEdit->clear();
    foreach(Localisation localisation, localisations){
        ui->textEdit->append("id: "+QString::number(localisation.getId())+"\nidMateriel: "+QString::number(localisation.getMateriel().getId())+"\nidSalle: "+QString::number(localisation.getSalle().getId())+"\nsortie: "+QString::number(localisation.getSortie()));
        ui->textEdit->append("--------------------");
    }
}

void LocalisationWindow::on_pushButtonGetCountBySortie_clicked()
{
    bool sortie = ui->checkBoxSortie->isChecked();
    int count = localisationSrv->getCountBySortie(sortie);
    ui->textEdit->setText("count = "+QString::number(count));
}

void LocalisationWindow::on_pushButtonGetListMateriel_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Materiel> materiels = localisationSrv->getListMateriel(page, parPage);
    ui->textEdit->clear();
    foreach(Materiel materiel, materiels){
        ui->textEdit->append("id: "+QString::number(materiel.getId())+"\nidBadge: "+materiel.getIdBadge()+"\ndateControle: "+materiel.getDateControle().toString("dd/MM/yyyy")+"\nnomMateriel: "+materiel.getNomMateriel()+"\ntype: "+materiel.getType().getNomType());
        ui->textEdit->append("--------------------");
    }
}

void LocalisationWindow::on_pushButtonGetCountListMateriel_clicked()
{
    int count = localisationSrv->getCountListMateriel();
    ui->textEdit->setText("count = "+QString::number(count));
}

void LocalisationWindow::on_pushButtonGetListSalle_clicked()
{
    int parPage = ui->spinBoxParPage->value();
    int page = (ui->spinBoxPage->value()-1)*parPage;
    QList<Salle> salles = localisationSrv->getListSalle(page, parPage);
    ui->textEdit->clear();
    foreach(Salle salle, salles){
        ui->textEdit->append("id: "+QString::number(salle.getId())+"\nx_ini: "+salle.getX_ini()+"\ny_ini: "+salle.getY_ini()+"\nx_fin: "+salle.getX_fin()+"\ny_fin: "+salle.getY_fin()+"\nnumSalle: "+QString::number(salle.getNumSalle())+"\nnomSalle: "+salle.getNomSalle()+"\nnomAtelier: "+salle.getNomAtelier());
        ui->textEdit->append("--------------------");
    }
}

void LocalisationWindow::on_pushButtonGetCountListSalle_clicked()
{
    int count = localisationSrv->getCountListSalle();
    ui->textEdit->setText("count = "+QString::number(count));
}

void LocalisationWindow::closeEvent(QCloseEvent *ev){
    ev->accept();
    emit fin(this);
}
