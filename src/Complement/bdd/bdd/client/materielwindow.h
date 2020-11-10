#ifndef MATERIELWINDOW_H
#define MATERIELWINDOW_H

#include <QMainWindow>
#include "physique/servicesql.h"
#include "metier/materielservice.h"
#include "metier/typeservice.h"
#include "metier/metierfactory.h"
#include "QString"
#include "QList"
#include "QDate"

namespace Ui {
class MaterielWindow;
}

class MaterielWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MaterielWindow(QWidget *parent = 0);
    ~MaterielWindow();
    
private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonGetById_clicked();
    void on_pushButtonRemove_clicked();
    void on_pushButtonUpdate_clicked();
    void on_pushButtonGetAll_clicked();
    void on_pushButtongetCount_clicked();
    void on_pushButtonGetByIdBadge_clicked();
    void on_pushButtonGetByDateControle_clicked();
    void on_pushButtonGetCountByDateControle_clicked();
    void on_pushButtonGetByNomMateriel_clicked();
    void on_pushButtonGetCountByNomMateriel_clicked();
    void on_pushButtonGetByType_clicked();
    void on_pushButtonGetCountByType_clicked();
    void on_pushButtonGetListIdBadge_clicked();
    void on_pushButtonGetCountListIdBadge_clicked();
    void on_pushButtonGetListDateControle_clicked();
    void on_pushButtonGetCountListDateControle_clicked();
    void on_pushButtonGetListNomMateriel_clicked();
    void on_pushButtonGetCountListNomMateriel_clicked();
    void on_pushButtonGetListType_clicked();
    void on_pushButtonGetCountListType_clicked();
    void on_pushButtonGetCountListNewDateControle_clicked();
    void on_pushButtonGetListNewDateControle_clicked();
    void on_pushButtonGetCountByNewDateControle_clicked();
    void on_pushButtonGetByNewDateControle_clicked();
    void on_pushButtonGetByPeriode_clicked();
    void on_pushButtonGetCountByPeriode_clicked();
    void closeEvent(QCloseEvent *ev);

private:
    Ui::MaterielWindow *ui;
    Metier::MaterielService* materielSrv;
    Metier::TypeService* typeSrv;

signals:
    void fin(QObject*);
};

#endif // MATERIELWINDOW_H
