#include "localisationserviceimpl.h"

Metier::LocalisationServiceImpl::LocalisationServiceImpl()
{
    localisationDataSrv = PhysiqueFactory::getLocalisationDataServiceImpl();
    materielSrv = MetierFactory::getMaterielServiceImpl();
}

Localisation Metier::LocalisationServiceImpl::add(Localisation localisation)
{
    // vérification des valeurs
    if(localisation.getMateriel().getId() > 0 && localisation.getSalle().getId() > 0){
        Materiel materielVerif = materielSrv->getById(localisation.getMateriel().getId());
        if(materielVerif.getId() < 1){
            // ajout
            localisation = localisationDataSrv->add(localisation);
        }
    }
    return localisation;
}

bool Metier::LocalisationServiceImpl::remove(Localisation localisation)
{
    // verification de la présence dans la base
    if(localisation.getId() > 0){
        // suppression
        return localisationDataSrv->remove(localisation);
    }
    return false;
}

bool Metier::LocalisationServiceImpl::update(Localisation localisation)
{
    // vérification des valeurs
    if(localisation.getMateriel().getId() > 0 && localisation.getSalle().getId() > 0){
        Materiel materielVerif = materielSrv->getById(localisation.getMateriel().getId());
        if(materielVerif.getId() < 1 || localisation.getMateriel().getId() == materielVerif.getId() ){
            // modification
            return localisationDataSrv->update(localisation);
        }
    }
    return false;
}

QList<Localisation> Metier::LocalisationServiceImpl::getAll(int debut, int parPage)
{
    QList<Localisation> listeLocalisations;
    if(debut >= 0 && parPage > 0 ){
        listeLocalisations = localisationDataSrv->getAll(debut, parPage);
    }
    return listeLocalisations;
}

int Metier::LocalisationServiceImpl::getCount()
{
    return localisationDataSrv->getCount();
}

Localisation Metier::LocalisationServiceImpl::getById(long id)
{
    Localisation localisation;
    if(id > 0){
        localisation = localisationDataSrv->getById(id);
    }
    return localisation;
}

QList<Localisation> Metier::LocalisationServiceImpl::getBySalle(Salle salle, int debut, int parPage)
{
    QList<Localisation> listeLocalisations;
    if(salle.getId() > 0 && debut >= 0 && parPage > 0 ){
        listeLocalisations = localisationDataSrv->getBySalle(salle, debut, parPage);
    }
    return listeLocalisations;
}

int Metier::LocalisationServiceImpl::getCountBySalle(Salle salle)
{
    int count = 0;
    if(salle.getId() > 0){
        count = localisationDataSrv->getCountBySalle(salle);
    }
    return count;
}

QList<Salle> Metier::LocalisationServiceImpl::getListSalle(int debut, int parPage)
{
    QList<Salle> listeSalles;
    if(debut >= 0 && parPage > 0 ){
        listeSalles = localisationDataSrv->getListSalle(debut, parPage);
    }
    return listeSalles;
}

int Metier::LocalisationServiceImpl::getCountListSalle()
{
    return localisationDataSrv->getCountListSalle();
}

Localisation Metier::LocalisationServiceImpl::getByMateriel(Materiel materiel)
{
    Localisation localition;
    if(materiel.getId() > 0){
        localition = localisationDataSrv->getByMateriel(materiel);
    }
    return localition;
}

QList<Materiel> Metier::LocalisationServiceImpl::getListMateriel(int debut, int parPage)
{
    QList<Materiel> listeMateriels;
    if(debut >= 0 && parPage > 0 ){
        listeMateriels = localisationDataSrv->getListMateriel(debut, parPage);
    }
    return listeMateriels;
}

int Metier::LocalisationServiceImpl::getCountListMateriel()
{
    return localisationDataSrv->getCountListMateriel();
}

QList<Localisation> Metier::LocalisationServiceImpl::getBySortie(bool sortie, int debut, int parPage)
{
    QList<Localisation> listeLocalisations;
    if(debut >= 0 && parPage > 0 ){
        listeLocalisations = localisationDataSrv->getBySortie(sortie, debut, parPage);
    }
    return listeLocalisations;
}

int Metier::LocalisationServiceImpl::getCountBySortie(bool sortie)
{
    return localisationDataSrv->getCountBySortie(sortie);
}
