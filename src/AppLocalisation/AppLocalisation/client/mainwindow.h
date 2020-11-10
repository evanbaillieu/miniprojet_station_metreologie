#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QStandardItemModel>
#include <QTableView>
#include <QPixmap>
#include <QPainter>
#include <QList>
#include <QFormLayout>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <physique/servicesql.h>
// #include <QTextCodec> // selon la version de Qt < 5

#include "metier/typeservice.h"
#include "metier/localisationservice.h"
#include "metier/salleservice.h"
#include "metier/metrologueservice.h"
#include "metier/materielservice.h"
#include "metier/batimentservice.h"
#include "metier/lecteurrfidservice.h"
#include "metier/portiqueservice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected :
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void rechercheParType();
    void rechercheParNom();
    void rechercheParBadge();
    void rechercheParBatiment();
    void rechercheParSalle();
    void rechercheParControleValide();
    void rechercheParControleNonValide();

    void rechercheCheminPlan();
    void recupererPlan(QString nomBatiment);
    void prendreCoordonneesSalle();
    void prendreCoordonneesPortique();

    void creerBatiment();
    void modifierBatiment();
    void supprimerBatiment();

    void creerSalle();
    void modifierSalle();
    void supprimerSalle();

    void creerPortique();
    void modifierPortique();
    void supprimerPortique();

    void recupererInfoBatiment(QString contenu);
    void recupererInfoSalle(QString contenu);
    void recupererInfoPortique(QString contenu);

    void resultatVoir();
    void resultatVoirEtTimer();
    void affichageListeMaterielDansSalle();

    void indexChangedComboBoxNomMateriel(QString contenu);
    void textChangedLineEditNomMateriel(QString);
    void indexChangedComboBoxIdBadge(QString contenu);
    void textChangedLineEditIdBadge(QString);
    void indexChangedComboBoxNomBatimentSalle(QString contenu);
    void indexChangedComboBoxNomBatimentCreerPortique(QString contenu);
    void indexChangedComboBoxNomBatimentSupprimerPortique(QString contenu);
    void textChangedLineEditNomBatiment(QString);
    void indexChangedComboBoxNumSalle(QString contenu);
    void textChangedLineEditNumSalle(QString);
    void indexChangedComboBoxNumSallePortique1(QString contenu);
    void textChangedLineEditNumSallePortique1(QString);
    void indexChangedComboBoxNumSallePortique2(QString contenu);
    void textChangedLineEditNumSallePortique2(QString);
    void indexChangedComboBoxIpLecteur(QString contenu);
    void textChangedLineEditIpLecteur(QString);

    void clickTable(QModelIndex);
    void situerSurLePlan();

    void on_actionPar_type_triggered();
    void on_actionPar_nom_triggered();
    void on_actionPar_badge_triggered();
    void on_actionPar_lieu_triggered();
    void on_actionPar_Controle_triggered();

    void on_actionCreerBatiment_triggered();
    void on_actionCreerSalle_triggered();
    void on_actionCreerPortique_triggered();

    void on_actionModifierBatiment_triggered();
    void on_actionModifierSalle_triggered();
    void on_actionModifierPortique_triggered();

    void on_actionSupprimerBatiment_triggered();
    void on_actionSupprimerSalle_triggered();
    void on_actionSupprimerPortique_triggered();

    void on_actionVoir_triggered();

private:
    void viderLayout(QFormLayout *layout);
    void viderLayoutExFirst(QFormLayout *layout);
    void viderLabelPlan();
    void viderLabelListeMaterielDansSalle();
    void affichePlanComplet(QString nomBatiment);
    void initLayout(void);
    QList<QString> getDifferent(QList<QString> list);

    Ui::MainWindow *ui;
    Metier::TypeService *typeSrv;
    Metier::LocalisationService *localisationSrv;
    Metier::SalleService *salleSrv;
    Metier::MetrologueService *metrologueSrv;
    Metier::MaterielService *materielSrv;
    Metier::BatimentService *batimentSvr;
    Metier::LecteurRFIDService *lecteurRFIDSvr;
    Metier::PortiqueService *portiqueSvr;

    QLineEdit *lineEditNomMateriel;
    QLineEdit *lineEditIdBadge;
    QLineEdit *lineEditNomBatiment;
    QLineEdit *lineEditNumSalle;
    QLineEdit *lineEditCheminPlan;
    QLineEdit *lineEditNomSalle;
    QLineEdit *lineEditNomAtelier;
    QLineEdit *lineEditCoordonneesSalle;

    QLineEdit *lineEditCoordonneesPortique;
    QLineEdit *lineEditNumSallePortique1;
    QLineEdit *lineEditNumSallePortique2;
    QLineEdit *lineEditIpLecteur;

    QComboBox *comboBoxNomMateriel;
    QComboBox *comboBoxIdBadge;
    QComboBox *comboBoxNomBatiment;
    QComboBox *comboBoxNumSalle;

    QComboBox *comboBoxNumSallePortique1;
    QComboBox *comboBoxNumSallePortique2;
    QComboBox *comboBoxIpLecteur;

    QList<QString> listStringNomMateriel;
    QList<QString> listStringIdBadge;
    QList<QString> listStringNomBatiment;
    QList<QString> listStringNumSalle;
    QList<QString> listStringNumSallePortique1;
    QList<QString> listStringNumSallePortique2;
    QList<QString> listStringIpLecteur;

    QLabel *labelPlan;
    QList<QLabel *> listLabelPlan;
    QLabel *labelListeMaterielDansSalle;
    Salle salleSituer;

    bool boolCoordonneesSalle;
    bool boolCoordonneesPortique;
    bool boolDoubleClick;
    bool boolLabelListeMaterielDansSalle;

    QTimer *timerActualisationPlan;

    int x_ini;
    int y_ini;
    int x_fin;
    int y_fin;

    int x_curseur;
    int y_curseur;

    float x_ini_pourcentage;
    float y_ini_pourcentage;
    float x_fin_pourcentage;
    float y_fin_pourcentage;

    QTableView *maTable;
    QStandardItemModel *monModel;

    //pour la connexion pour la BDD
    ServiceSQL sql;
};

#endif // MAINWINDOW_H
