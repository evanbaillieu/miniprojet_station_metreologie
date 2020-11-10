#include "portiqueserviceimpl.h"

Metier::PortiqueServiceImpl::PortiqueServiceImpl()
{
    portiqueDataSrv = PhysiqueFactory::getPortiqueDataServiceImpl();
}

Portique Metier::PortiqueServiceImpl::add(Portique portique)
{
    // verification des valeurs
    if(portique.getLecteurRFID().getId() > 0 ){
        Portique portiqueVerif = portiqueDataSrv->getByLecteurRFID(portique.getLecteurRFID());
        if(portiqueVerif.getId() < 1 && portique.getSalle1().getId() > 0 && portique.getSalle2().getId() >= 0 ){
            // ajout
            portique = portiqueDataSrv->add(portique);
        }
    }
    return portique;
}

bool Metier::PortiqueServiceImpl::remove(Portique portique)
{
    if(portique.getId() > 0){
        // suppression
        return portiqueDataSrv->remove(portique);
    }
    return false;
}

bool Metier::PortiqueServiceImpl::update(Portique portique)
{
    // verification des valeurs
    if(portique.getLecteurRFID().getId() > 0){
        Portique portiqueVerif = portiqueDataSrv->getByLecteurRFID(portique.getLecteurRFID());
        if( portiqueVerif.getId() < 1 || portiqueVerif.getId()==portique.getId()){
            // suppression
            return portiqueDataSrv->update(portique);
        }
    }
    return false;
}

QList<Portique> Metier::PortiqueServiceImpl::getAll(int debut, int parPage)
{
    QList<Portique> listePortiques;
    if(debut >= 0 && parPage > 0 ){
        listePortiques = portiqueDataSrv->getAll(debut, parPage);
    }
    return listePortiques;
}

int Metier::PortiqueServiceImpl::getCount()
{
    return portiqueDataSrv->getCount();
}

Portique Metier::PortiqueServiceImpl::getById(long id)
{
    Portique portique;
    if(id > 0){
        portique = portiqueDataSrv->getById(id);
    }
    return portique;
}

Portique Metier::PortiqueServiceImpl::getByLecteurRFID(LecteurRFID lecteur)
{
    Portique portique;
    if(lecteur.getId() > 0){
        portique = portiqueDataSrv->getByLecteurRFID(lecteur);
    }
    return portique;
}

QList<LecteurRFID> Metier::PortiqueServiceImpl::getListLecteurRFID(int debut, int parPage)
{
    QList<LecteurRFID> listeLecteurRFIDs;
    if(debut >= 0 && parPage > 0 ){
        listeLecteurRFIDs = portiqueDataSrv->getListLecteurRFID(debut, parPage);
    }
    return listeLecteurRFIDs;

}

int Metier::PortiqueServiceImpl::getCountListLecteurRFID()
{
    return portiqueDataSrv->getCountListLecteurRFID();
}

QList<Portique> Metier::PortiqueServiceImpl::getBySalle(Salle salle, int debut, int parPage)
{
    QList<Portique> listePortiques;
    if(debut >= 0 && parPage > 0 && salle.getId() > 0){
        listePortiques = portiqueDataSrv->getBySalle(salle, debut, parPage);
    }
    return listePortiques;

}

int Metier::PortiqueServiceImpl::getCountBySalle(Salle salle)
{
    int count = 0;
    if(salle.getId() > 0){
        count = portiqueDataSrv->getCountBySalle(salle);
    }
    return count;
}

QList<Salle> Metier::PortiqueServiceImpl::getListSalle(int debut, int parPage)
{
    QList<Salle> listeSalles;
    if(debut >= 0 && parPage > 0){
        listeSalles = portiqueDataSrv->getListSalle(debut, parPage);
    }
    return listeSalles;

}

int Metier::PortiqueServiceImpl::getCountListSalle()
{
    return portiqueDataSrv->getCountListSalle();
}
