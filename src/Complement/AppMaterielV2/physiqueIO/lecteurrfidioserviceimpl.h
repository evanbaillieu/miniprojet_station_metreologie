#ifndef LECTEURRFIDIOSERVICEIMPL_H
#define LECTEURRFIDIOSERVICEIMPL_H

#include "lecteurrfidioservice.h"
#include <QString>
#include <QByteArray>
#include <QTcpSocket>
#include <QObject>
#include <QStringList>
#include "metier/typeservice.h"
#include "metier/metierfactory.h"
#include <QEventLoop>

#define STX 0x02
#define ETX 0x03
#define SYN 0x16
#define ACK 0x06
#define NAK 0x15

namespace PhysiqueIO {
class LecteurRFIDIOServiceImpl : public LecteurRFIDIOService
{
    Q_OBJECT
public:
    LecteurRFIDIOServiceImpl();
    ~LecteurRFIDIOServiceImpl();
    Materiel lireBadge();
    bool ecrireBadge(Materiel materiel);
    void connexion(QString, int);
    void deconnexion();
    void construireLigne(QString noFonc, QString param);
    void envoiTrame(QByteArray cmd);
    void lireTrame();
    QByteArray getCmdRecu();
    void convertData32to16();

public slots:
    void deconnexionOK();
    void connexionOK();
    void readDatagram();
    void detectErreur();

signals:
    void dataOk(bool);

private:
    Metier::TypeService* typeSrv;
    QString ip;
    int port;
    QString fctLire;
    QString fctEcrire;
    QString msg;
    QString msgErreur;
    QTcpSocket tcpSocket;
    QByteArray trameMsg;
    bool connexionEtat;
    QByteArray cmdRecu;
    QStringList contenuBadge;
    QEventLoop loop;
};
}


#endif // LECTEURRFIDIOSERVICEIMPL_H
