#include "lecteurrfidserviceimpl.h"

Metier::LecteurRFIDServiceImpl::LecteurRFIDServiceImpl()
{
    lecteurRFIDDataSrv = PhysiqueFactory::getLecteurRFIDDataServiceImpl();
    portiqueSrv = MetierFactory::getPortiqueServiceImpl();
}

LecteurRFID Metier::LecteurRFIDServiceImpl::add(LecteurRFID lecteur)
{
    // vérification des valeurs
    if(!lecteur.getIp().isEmpty() && lecteur.getModele().isEmpty() ){
        LecteurRFID lecteurVerif = lecteurRFIDDataSrv->getById(lecteur.getId() );
        if(lecteurVerif.getId() < 1){
            // ajoute le lecteur
            lecteur = lecteurRFIDDataSrv->add(lecteur);
        }
    }
    return lecteur;
}

bool Metier::LecteurRFIDServiceImpl::remove(LecteurRFID lecteur)
{
    // verification de la présence dans la base
    if(lecteur.getId() > 0){
        Portique portique = portiqueSrv->getByLecteurRFID(lecteur);
        // suppression du portique
        portiqueSrv->remove(portique);
        // suppression du lecteur
        return lecteurRFIDDataSrv->remove(lecteur);
    }
    return false;
}

bool Metier::LecteurRFIDServiceImpl::update(LecteurRFID lecteur)
{
    // vérification des valeurs
    if(! lecteur.getIp().isEmpty()) { // && lecteur.getModele().isEmpty() ){
        LecteurRFID lecteurVerif = lecteurRFIDDataSrv->getById(lecteur.getId() );
        if(lecteurVerif.getId() < 1 || lecteur.getId() == lecteurVerif.getId()){
            // modification du lecteur
            return lecteurRFIDDataSrv->update(lecteur);
        }
    }
    return false;
}

QList<LecteurRFID> Metier::LecteurRFIDServiceImpl::getAll(int debut, int parPage)
{
    QList<LecteurRFID> listeLecteurRFIDs;
    if(debut >= 0 && parPage > 0 ){
        listeLecteurRFIDs = lecteurRFIDDataSrv->getAll(debut, parPage);
    }
    return listeLecteurRFIDs;
}

int Metier::LecteurRFIDServiceImpl::getCount()
{
    return lecteurRFIDDataSrv->getCount();
}

LecteurRFID Metier::LecteurRFIDServiceImpl::getById(long id)
{
    LecteurRFID lecteurRFID;
    if(id > 0){
        lecteurRFID = lecteurRFIDDataSrv->getById(id);
    }
    return lecteurRFID;
}

LecteurRFID Metier::LecteurRFIDServiceImpl::getByIp(QString ip)
{
    LecteurRFID lecteurRFID;
    if(!ip.isEmpty()){
        lecteurRFID = lecteurRFIDDataSrv->getByIp(ip);
    }
    return lecteurRFID;
}

QList<QString> Metier::LecteurRFIDServiceImpl::getListIp(int debut, int parPage)
{
    QList<QString> liste;
    if(debut >= 0 && parPage > 0 ){
        liste = lecteurRFIDDataSrv->getListIp(debut, parPage);
    }
    return liste;
}

int Metier::LecteurRFIDServiceImpl::getCountListIp()
{
    return lecteurRFIDDataSrv->getCountListIp();
}

QList<LecteurRFID> Metier::LecteurRFIDServiceImpl::getByModele(QString modele, int debut, int parPage)
{
    QList<LecteurRFID> listeLecteurRFIDs;
    if(!modele.isEmpty() &&debut >= 0 && parPage > 0 ){
        listeLecteurRFIDs = lecteurRFIDDataSrv->getByModele(modele, debut, parPage);
    }
    return listeLecteurRFIDs;
}

int Metier::LecteurRFIDServiceImpl::getCountByModele(QString modele)
{
    int count = 0;
    if(!modele.isEmpty()){
        count = lecteurRFIDDataSrv->getCountByModele(modele);
    }
    return count;
}

QList<QString> Metier::LecteurRFIDServiceImpl::getListModele(int debut, int parPage)
{
    QList<QString> liste;
    if(debut >= 0 && parPage > 0 ){
        liste = lecteurRFIDDataSrv->getListModele(debut, parPage);
    }
    return liste;
}

int Metier::LecteurRFIDServiceImpl::getCountListModele()
{
    return lecteurRFIDDataSrv->getCountListModele();
}

QList<LecteurRFID> Metier::LecteurRFIDServiceImpl::getByEtatOn(bool etatOn, int debut, int parPage)
{
    QList<LecteurRFID> listeLecteurRFID;
    if(debut >= 0 && parPage > 0 ){
        listeLecteurRFID = lecteurRFIDDataSrv->getByEtatOn(etatOn, debut, parPage);
    }
    return listeLecteurRFID;
}

int Metier::LecteurRFIDServiceImpl::getCountByEtatOn(bool etatOn)
{
    return lecteurRFIDDataSrv->getCountByEtatOn(etatOn);
}
