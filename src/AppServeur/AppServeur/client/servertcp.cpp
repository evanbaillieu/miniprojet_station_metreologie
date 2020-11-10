#include "servertcp.h"

ServerTCP::ServerTCP(QObject *parent): QObject(parent) {
    materielSrv = MetierFactory::getMaterielServiceImpl();
    localisationSrv = MetierFactory::getLocalisationServiceImpl();
    salleSrv = MetierFactory::getSalleServiceImpl();
    lecteurRFIDSrv = MetierFactory::getLecteurRFIDServiceImpl();
    portiqueSrv = MetierFactory::getPortiqueServiceImpl();
    etatServeur= false;
}

ServerTCP::~ServerTCP() {
    serverTCP.close();
}

void ServerTCP::lancement(){
    if(! serverTCP.listen(QHostAddress::Any, 8888)){ // 8888
        qWarning("Erreur serveur : %s", serverTCP.errorString().toLatin1().data());
        exit(1);
    }
    else {
        qWarning("-> Serveur actif sur port 8888\n");
        connect(&serverTCP, SIGNAL(newConnection()), this, SLOT(connexion()));
        etatServeur= true;
    }
    if(sql.databaseIsOpen() == false) {
        qWarning("-> %s\n", sql.getMessageErreur().toLatin1().data());
        exit(2);
    }
}

void ServerTCP::connexion(){
    LecteurRFID lecteur;
    QTcpSocket *client = serverTCP.nextPendingConnection();
    addrIp = client->peerAddress().toString();
    qWarning("-> Connexion du portique d'@ IP : %s", addrIp.toLatin1().data());
    listClient.append(client);
    connect(client, SIGNAL(readyRead()), this, SLOT(readClient()));
    connect(client, SIGNAL(disconnected()), this, SLOT(deconnexion()));
    qWarning("Il y a %d portique(s) actif(s)\n", listClient.length());
    lecteur= lecteurRFIDSrv->getByIp(addrIp);
    lecteur.setEtatOn(true);
    qWarning("update ON= %d", lecteurRFIDSrv->update(lecteur));
}

void ServerTCP::deconnexion(){
    LecteurRFID lecteur;
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
    if(!client)
        return;
    addrIp = client->peerAddress().toString();
    qWarning("-> Deconnexion du portique d'@ip : %s\n", addrIp.toLatin1().data());
    client->deleteLater();
    listClient.removeAll(client);
    qWarning("Reste %d portique(s) actif(s)", listClient.length());
    lecteur= lecteurRFIDSrv->getByIp(addrIp);
    lecteur.setEtatOn(false);
    lecteurRFIDSrv->update(lecteur);
    qWarning("update OFF= %d", lecteurRFIDSrv->update(lecteur));
}

void ServerTCP::readClient(){
    for(int i = 0 ; i<listClient.count() ; i++ ){
        QTcpSocket* client = listClient.at(i);
        if(client->bytesAvailable() > 0)
            gestionTrame(client);
    }
}

void ServerTCP::writeClient(QTcpSocket* client){
    client->write(this->requete);
}

void ServerTCP::gestionTrame(QTcpSocket *client){
    QString idBadge= NULL;
    Materiel materiel;
    Localisation localisation;
    LecteurRFID lecteur;
    Salle oldSalle;
    Portique portique;

    addrIp= client->peerAddress().toString();
    qWarning("Trame recue de : %s", addrIp.toLatin1().data());
    this->longueurRequete = client->read(this->requete, client->bytesAvailable());
    for(int i =0 ; i < longueurRequete ; i++)
        idBadge.append(this->requete[i]);
    qWarning("Id Tag: %s", idBadge.toLatin1().data());
    materiel = materielSrv->getByIdBadge(idBadge);
    qWarning("Id materiel correspondant au tag: %ld", materiel.getId());
    if(materiel.getId() > 0 ){
        lecteur = lecteurRFIDSrv->getByIp(addrIp);
        qWarning("Ip lecteur: %s - Id materiel: %ld - Id lecteur: %ld", lecteur.getIp().toLatin1().data(), materiel.getId(), lecteur.getId());
        localisation = localisationSrv->getByMateriel(materiel);
        qWarning("Ancienne localisation du materiel de id: %ld = salle %d (%d)",\
                 materiel.getId(), localisation.getSalle().getNumSalle(), localisation.getSortie());
        oldSalle = salleSrv->getByNumSalle(localisation.getSalle().getNumSalle());
        portique = portiqueSrv->getByLecteurRFID(lecteur);
        qWarning("Id portique: %ld salle1=%d", portique.getId(), portique.getSalle1().getNumSalle());
        if(portique.getSalle2().getNumSalle() != 0) { // portique entre 2 salles
            qWarning("portique entre 2 salles");
            if((oldSalle.getNumSalle()== portique.getSalle1().getNumSalle()) && (localisation.getSortie()==false))
                localisation.setSalle(portique.getSalle2());
            else if((oldSalle.getNumSalle()== portique.getSalle1().getNumSalle()) && (localisation.getSortie()==true))
                localisation.setSalle(portique.getSalle1());
            else if((oldSalle.getNumSalle()== portique.getSalle2().getNumSalle()) && (localisation.getSortie()==false))
                localisation.setSalle(portique.getSalle1());
            else if((oldSalle.getNumSalle()== portique.getSalle2().getNumSalle()) && (localisation.getSortie()==true))
                localisation.setSalle(portique.getSalle2());
            else
                localisation.setSalle(portique.getSalle1());
            localisation.setSortie(false);
        }
        else { // portique entre une salle et un couloir
            qWarning("portique entre une salle et un couloir");
            if((oldSalle.getNumSalle()== portique.getSalle1().getNumSalle()) && (localisation.getSortie()==false)){
                localisation.setSortie(true);
            }
            else {
                localisation.setSortie(false);
            }
            localisation.setSalle(portique.getSalle1());
        }
        localisationSrv->update(localisation);
        qWarning("Nouvelle localisation du materiel de id: %ld = salle %d (%d)",\
                 localisation.getMateriel().getId(), localisation.getSalle().getNumSalle(), localisation.getSortie());
    }else {
        qWarning("Id:%s inconnu dans BdD !!", idBadge.toLatin1().data());
    }
}
