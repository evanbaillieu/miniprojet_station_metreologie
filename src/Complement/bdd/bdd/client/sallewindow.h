#ifndef SALLEWINDOW_H
#define SALLEWINDOW_H

#include <QMainWindow>
#include "physique/servicesql.h"
#include "metier/salleservice.h"
#include "metier/metierfactory.h"
#include "QString"
#include "QList"

namespace Ui {
class SalleWindow;
}

class SalleWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SalleWindow(QWidget *parent = 0);
    ~SalleWindow();
    
private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonGetById_clicked();
    void on_pushButtonRemove_clicked();
    void on_pushButtonUpdate_clicked();
    void on_pushButtonGetAll_clicked();
    void on_pushButtonGetCount_clicked();
    void on_pushButtonGetByNumSalle_clicked();
    void on_pushButtonGetByNomSalle_clicked();
    void on_pushButtonGetCountByNomSalle_clicked();
    void on_pushButtonGetByNomAtelier_clicked();
    void on_getCountByNomAtelier_clicked();
    void on_pushButtonGetListNumSalle_clicked();
    void on_pushButtonGetCountListNumSalle_clicked();
    void on_pushButtonGetListNomSalle_clicked();
    void on_pushButtonGetCountListNomSalle_clicked();
    void on_pushButtonGetListNomAtelier_clicked();
    void on_pushButtonGetCountListNomAtelier_clicked();
    void closeEvent(QCloseEvent *ev);

private:
    Ui::SalleWindow *ui;
    Metier::SalleService* salleSrv;

signals:
    void fin(QObject*);
};

#endif // SALLEWINDOW_H
