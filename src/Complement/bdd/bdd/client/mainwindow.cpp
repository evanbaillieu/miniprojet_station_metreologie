#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map["MetrologueWindow"]= NULL;
    map["LecteurWindow"]= NULL;
    map["SalleWindow"]= NULL;
    map["BatimentWindow"]= NULL;
    map["PortiqueWindow"]= NULL;
    map["TypeWindow"]= NULL;
    map["MaterielWindow"]= NULL;
    map["LocalisationWindow"]= NULL;
    ui->textEdit->setText("Création de l'objet serviceSql");
    if(servSQL.databaseIsOpen()){
        ui->textEdit->append("Base de Données ouverte avec succès");
        initDialog(true);
    }else{
        ui->textEdit->append("La connexion à la base a échoué !");
        initDialog(false);
    }
}

void MainWindow::initDialog(bool flag) {
    ui->pushButtonBatiment->setEnabled(flag);
    ui->pushButtonLecteurRFID->setEnabled(flag);
    ui->pushButtonLocalisation->setEnabled(flag);
    ui->pushButtonMateriel->setEnabled(flag);
    ui->pushButtonMetrologue->setEnabled(flag);
    ui->pushButtonPortique->setEnabled(flag);
    ui->pushButtonSalle->setEnabled(flag);
    ui->pushButtonType->setEnabled(flag);
}

MainWindow::~MainWindow(){
    qWarning("Destructeur MainWindow");
    delete ui;
}

void MainWindow::on_pushButtonMetrologue_clicked() {
    if(map["MetrologueWindow"] == NULL) {
        metrologueWindow = new MetrologueWindow;
        map["MetrologueWindow"]= metrologueWindow;
        connect(metrologueWindow, SIGNAL(fin(QObject*)), SLOT(closeWindow(QObject*)));
        metrologueWindow->show(); // mode non modal
    }
    metrologueWindow->activateWindow();
}

void MainWindow::on_pushButtonLecteurRFID_clicked() {
    if(map["LecteurWindow"] == NULL) {
        lecteurWindow = new LecteurWindow;
        map["LecteurWindow"]= lecteurWindow;
        connect(lecteurWindow, SIGNAL(fin(QObject*)), SLOT(closeWindow(QObject*)));
        lecteurWindow->show();
    }
    lecteurWindow->activateWindow();
}

void MainWindow::on_pushButtonSalle_clicked() {
    if( map["SalleWindow"] == NULL) {
        salleWindow = new SalleWindow;
        map["SalleWindow"]= salleWindow;
        connect(salleWindow, SIGNAL(fin(QObject*)), SLOT(closeWindow(QObject*)));
        salleWindow->show();
    }
    salleWindow->activateWindow();
}

void MainWindow::on_pushButtonBatiment_clicked() {
    if(map["BatimentWindow"] == NULL) {
        batimentWindow = new BatimentWindow;
        map["BatimentWindow"]= batimentWindow;
        connect(batimentWindow, SIGNAL(fin(QObject*)), SLOT(closeWindow(QObject*)));
        batimentWindow->show();
    }
    batimentWindow->activateWindow();
}

void MainWindow::on_pushButtonPortique_clicked() {
    if(map["PortiqueWindow"] == NULL) {
        portiqueWindow = new PortiqueWindow;
        map["PortiqueWindow"]= portiqueWindow;
        connect(portiqueWindow, SIGNAL(fin(QObject*)), SLOT(closeWindow(QObject*)));
        portiqueWindow->show();
    }
    portiqueWindow->activateWindow();
}

void MainWindow::on_pushButtonType_clicked() {
    if(map["TypeWindow"] == NULL) {
        typeWindow = new TypeWindow;
        map["TypeWindow"]= typeWindow;
        connect(typeWindow, SIGNAL(fin(QObject*)), SLOT(closeWindow(QObject*)));
        typeWindow->show();
    }
    typeWindow->activateWindow();
}

void MainWindow::on_pushButtonMateriel_clicked() {
    if(map["MaterielWindow"] == NULL) {
        materielWindow = new MaterielWindow;
        map["MaterielWindow"]= materielWindow;
        connect(materielWindow, SIGNAL(fin(QObject*)), SLOT(closeWindow(QObject*)));
        materielWindow->activateWindow();
    }
    materielWindow->activateWindow();
}

void MainWindow::on_pushButtonLocalisation_clicked() {
    if(map["LocalisationWindow"] == NULL) {
        localisationWindow = new LocalisationWindow;
        map["LocalisationWindow"]= localisationWindow;
        connect(localisationWindow, SIGNAL(fin(QObject*)), SLOT(closeWindow(QObject*)));
        localisationWindow->show();
    }
    localisationWindow->activateWindow();
}

void MainWindow::closeWindow(QObject *obj) {
    QString s= obj->objectName();
    if(map.contains(s)){
        qWarning("delete objet %s", s.toLatin1().data());
        delete map.value(s);
    }
    else
        qWarning("Objet non défini !");
    map[s]= NULL;
}

