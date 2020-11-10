#ifndef METROLOGUEWINDOW_H
#define METROLOGUEWINDOW_H

#include <QMainWindow>
#include "physique/servicesql.h"
#include "metier/metrologueservice.h"
#include "metier/metierfactory.h"
#include "QString"
#include "QList"

namespace Ui {
class MetrologueWindow;
}

class MetrologueWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MetrologueWindow(QWidget *parent = 0);
    ~MetrologueWindow();
    
private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonGetById_clicked();
    void on_pushButtonRemove_clicked();
    void on_pushButtonUpdate_clicked();
    void on_pushButtonGetAll_clicked();
    void on_pushButtongetCount_clicked();
    void on_pushButtonGetByLogin_clicked();
    void on_pushButtonGetListLogin_clicked();
    void on_pushButtonGetCountListLogin_clicked();
    void closeEvent(QCloseEvent *ev);

private:
    Ui::MetrologueWindow *ui;
    Metier::MetrologueService* metrologueSrv;

signals:
    void fin(QObject*);
};

#endif // METROLOGUEWINDOW_H
