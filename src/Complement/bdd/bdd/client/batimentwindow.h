#ifndef BATIMENTWINDOW_H
#define BATIMENTWINDOW_H

#include <QMainWindow>
#include "physique/servicesql.h"
#include "metier/batimentservice.h"
#include "metier/metierfactory.h"
#include "QString"
#include "QList"
#include "QModelIndex"

namespace Ui {
class BatimentWindow;
}

class BatimentWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit BatimentWindow(QWidget *parent = 0);
    ~BatimentWindow();
    
private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonGetById_clicked();
    void on_pushButtonRemove_clicked();
    void on_pushButtonUpdate_clicked();
    void on_pushButtonGetAll_clicked();
    void on_pushButtonGetCount_clicked();
    void on_pushButtonGetByNomBatiment_clicked();
    void on_pushButtonGetBySalle_clicked();
    void on_pushButtonGetByPlan_clicked();
    void on_pushButtonAjouter_clicked();
    void on_listWidget_doubleClicked(const QModelIndex &index);
    void on_pushButtonGetListNomBatiment_clicked();
    void on_pushButtonGetCountListBatiment_clicked();
    void on_pushButtonGetListSalle_clicked();
    void on_pushButtonGetCountListSalle_clicked();
    void on_pushButtonGetListPlan_clicked();
    void on_pushButtonGetCountListPlan_clicked();
    void on_pushButtonSallesBatiment_clicked();
    void closeEvent(QCloseEvent *ev);

private:
    Ui::BatimentWindow *ui;
    Metier::BatimentService* batimentSrv;
    Metier::SalleService* salleSrv;

signals:
    void fin(QObject*);
};

#endif // BATIMENTWINDOW_H
