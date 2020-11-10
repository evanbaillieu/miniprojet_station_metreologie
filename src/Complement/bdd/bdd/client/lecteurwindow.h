#ifndef LECTEURWINDOW_H
#define LECTEURWINDOW_H

#include <QMainWindow>
#include "physique/servicesql.h"
#include "metier/lecteurrfidservice.h"
#include "metier/metierfactory.h"
#include "QString"
#include "QList"

namespace Ui {
class LecteurWindow;
}

class LecteurWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit LecteurWindow(QWidget *parent = 0);
    ~LecteurWindow();
    
private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonGetById_clicked();
    void on_pushButtonRemove_clicked();
    void on_pushButtonUpdate_clicked();
    void on_pushButtonGetAll_clicked();
    void on_pushButtongetCount_clicked();
    void on_pushButtonGetByModele_clicked();
    void on_pushButtonGetCountByModele_clicked();
    void on_pushButtonGetByIp_clicked();
    void on_pushButtonGetByEtatOn_clicked();
    void on_pushButtonGetCountByEtatOn_clicked();
    void on_pushButtonGetListIp_clicked();
    void on_pushButtonGetCountListIp_clicked();
    void on_pushButtonGetListModele_clicked();
    void on_pushButtonGetCountListModele_clicked();
    void closeEvent(QCloseEvent *ev);

private:
    Ui::LecteurWindow *ui;
    Metier::LecteurRFIDService* lecteurRFIDSrv;

signals:
    void fin(QObject*);

};

#endif // LECTEURWINDOW_H
