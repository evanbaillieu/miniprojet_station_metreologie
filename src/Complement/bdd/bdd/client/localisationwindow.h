#ifndef LOCALISATIONWINDOW_H
#define LOCALISATIONWINDOW_H

#include <QMainWindow>
#include "physique/servicesql.h"
#include "metier/localisationservice.h"
#include "metier/materielservice.h"
#include "metier/salleservice.h"
#include "metier/metierfactory.h"
#include "QString"
#include "QList"

namespace Ui {
class LocalisationWindow;
}

class LocalisationWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit LocalisationWindow(QWidget *parent = 0);
    ~LocalisationWindow();
    
private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonGetById_clicked();
    void on_pushButtonRemove_clicked();
    void on_pushButtonUpdate_clicked();
    void on_pushButtonGetAll_clicked();
    void on_pushButtongetCount_clicked();
    void on_pushButtonGetByMateriel_clicked();
    void on_pushButtonGetBySalle_clicked();
    void on_pushButtonGetCountBySalle_clicked();
    void on_pushButtonGetBySortie_clicked();
    void on_pushButtonGetCountBySortie_clicked();
    void on_pushButtonGetListMateriel_clicked();
    void on_pushButtonGetCountListMateriel_clicked();
    void on_pushButtonGetListSalle_clicked();
    void on_pushButtonGetCountListSalle_clicked();
    void closeEvent(QCloseEvent *ev);

private:
    Ui::LocalisationWindow *ui;
    Metier::LocalisationService* localisationSrv;
    Metier::MaterielService* materielSrv;
    Metier::SalleService* salleSrv;

signals:
    void fin(QObject*);
};

#endif // LOCALISATIONWINDOW_H
