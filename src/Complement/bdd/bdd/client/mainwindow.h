#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include "physique/servicesql.h"
#include "metrologuewindow.h"
#include "lecteurwindow.h"
#include "sallewindow.h"
#include "batimentwindow.h"
#include "portiquewindow.h"
#include "localisationwindow.h"
#include "materielwindow.h"
#include "typewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ServiceSQL servSQL;
    
private slots:
    void on_pushButtonMetrologue_clicked();
    void on_pushButtonLecteurRFID_clicked();
    void on_pushButtonSalle_clicked();
    void on_pushButtonBatiment_clicked();
    void on_pushButtonPortique_clicked();
    void on_pushButtonType_clicked();
    void on_pushButtonMateriel_clicked();
    void on_pushButtonLocalisation_clicked();
    void closeWindow(QObject*);

private:
    Ui::MainWindow *ui;
    MetrologueWindow* metrologueWindow;
    LecteurWindow* lecteurWindow;
    SalleWindow* salleWindow;
    BatimentWindow* batimentWindow;
    PortiqueWindow* portiqueWindow;
    TypeWindow* typeWindow;
    MaterielWindow* materielWindow;
    LocalisationWindow* localisationWindow;
    QMap<QString, QObject*> map;

    void initDialog(bool flag);
};

#endif // MAINWINDOW_H
