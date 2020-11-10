#ifndef PORTIQUEWINDOW_H
#define PORTIQUEWINDOW_H

#include <QMainWindow>
#include "physique/servicesql.h"
#include "metier/portiqueservice.h"
#include "metier/metierfactory.h"
#include "QString"
#include "QList"

namespace Ui {
class PortiqueWindow;
}

class PortiqueWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit PortiqueWindow(QWidget *parent = 0);
    ~PortiqueWindow();
    
private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonGetById_clicked();
    void on_pushButtonRemove_clicked();
    void on_pushButtonUpdate_clicked();
    void on_pushButtonGetAll_clicked();
    void on_pushButtonGetCount_clicked();
    void on_pushButtonGetBySalle_clicked();
    void on_pushButtonGetCountBySalle_clicked();
    void on_pushButtonGetByLecteur_clicked();
    void on_comboBoxSalle1_currentIndexChanged(const QString &arg1);
    void on_pushButtonGetListSalle_clicked();
    void on_pushButtonGetCountListSalle_clicked();
    void on_pushButtonGetListLecteur_clicked();
    void on_pushButtonGetCountListLecteur_clicked();
    void closeEvent(QCloseEvent *ev);

private:
    Ui::PortiqueWindow *ui;
    Metier::PortiqueService* portiqueSrv;
    Metier::SalleService* salleSrv;
    Metier::LecteurRFIDService* lecteurSrv;
    QString comboBox;

signals:
    void fin(QObject*);
};

#endif // PORTIQUEWINDOW_H
