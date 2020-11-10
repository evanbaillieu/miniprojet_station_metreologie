#ifndef SERVERTCP_H
#define SERVERTCP_H

#include <stdio.h>
#include <stdlib.h>
#include <QString>
#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include <QList>
#include <QDate>
#include "physique/servicesql.h"
#include <metier/materielservice.h>
#include <metier/materielserviceimpl.h>
#include <metier/localisationserviceimpl.h>
#include <metier/localisationservice.h>

class ServerTCP: public QObject
{
Q_OBJECT
public :
    ServerTCP(QObject * parent = 0);
    ~ServerTCP();
    void lancement();
    int compteur;
    int longueurRequete;
    char requete[1024];

private slots:
    void deconnexion();
    void connexion();
    void readClient();

private:
    QTcpServer serverTCP;
    QList<QTcpSocket*> listClient;
    QString addrIp;
    bool etatServeur;

    void writeClient(QTcpSocket* client);
    void gestionTrame(QTcpSocket* client);

    Metier::MaterielService *materielSrv;
    Metier::LocalisationService *localisationSrv;
    Metier::SalleService* salleSrv;
    Metier::LecteurRFIDService* lecteurRFIDSrv;
    Metier::PortiqueService* portiqueSrv;
    ServiceSQL sql;
signals:
    void fin();
};

#endif // SERVERTCP_H
