#ifndef TYPEWINDOW_H
#define TYPEWINDOW_H

#include <QMainWindow>
#include "physique/servicesql.h"
#include "metier/typeservice.h"
#include "metier/metierfactory.h"
#include "QString"
#include "QList"

namespace Ui {
class TypeWindow;
}

class TypeWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TypeWindow(QWidget *parent = 0);
    ~TypeWindow();
    
private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonGetById_clicked();
    void on_pushButtonRemove_clicked();
    void on_pushButtonUpdate_clicked();
    void on_pushButtonGetAll_clicked();
    void on_pushButtongetCount_clicked();
    void on_pushButtonGetByNomType_clicked();
    void on_pushButtonGetListNomType_clicked();
    void on_pushButtonGetCountListNomType_clicked();
    void on_pushButtonGetByNomImage_clicked();
    void on_pushButtonGetListNomImage_clicked();
    void on_pushButtonGetCountListNomImage_clicked();
    void closeEvent(QCloseEvent *ev);

private:
    Ui::TypeWindow *ui;
    Metier::TypeService* typeSrv;

signals:
    void fin(QObject*);
};

#endif // TYPEWINDOW_H
