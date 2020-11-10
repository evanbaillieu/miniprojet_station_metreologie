#include "salleserviceimpl.h"

Metier::SalleServiceImpl::SalleServiceImpl()
{
    salleDataSrv = PhysiqueFactory::getSalleDataServiceImpl();
    localisationSrv = MetierFactory::getLocalisationServiceImpl();
    portiqueSrv = MetierFactory::getPortiqueServiceImpl();
}

    Salle Metier::SalleServiceImpl::add(Salle salle)
    {
        // verification des valeurs
        if(salle.getNumSalle() >= 0 && !salle.getNomSalle().isEmpty() && !salle.getNomAtelier().isEmpty() && salle.getX_fin() >= 0 && salle.getX_ini() >= 0 && salle.getY_fin() >= 0 && salle.getY_ini() >= 0){
            Salle salleVerif = salleDataSrv->getByNumSalle(salle.getNumSalle());
            if(salleVerif.getId() == 0){
                // ajout
                salle = salleDataSrv->add(salle);
            }
        }else
            salle.setId(0);
        return salle;
    }

bool Metier::SalleServiceImpl::remove(Salle salle)
{
    QList<Localisation> listeLocalisations = localisationSrv->getBySalle(salle,0,localisationSrv->getCountBySalle(salle));
    QList<Portique> listePortiques = portiqueSrv->getBySalle(salle,0,portiqueSrv->getCountBySalle(salle));

    if(salle.getId() > 0){
        for( int i = 0 ; i < listeLocalisations.count() ; i++ ){
            // suppresion de toute les localisation concernant cette salle
            localisationSrv->remove(listeLocalisations.at(i));
        }
        Portique portique;

        for( int i = 0 ; i < listePortiques.count() ; i++){
            // suppression des portiques si ils ont que cette salle ou déplacement de la 2de salle si elle est a salle2
            portique = listePortiques.at(i);
            if(portique.getSalle2().getId() == 0){
                portiqueSrv->remove(portique);
            }else{
                if(portique.getSalle2().getId() == salle.getId()){
                    Salle salle;
                    portique.setSalle2(salle);
                    portiqueSrv->update(portique);
                }else{
                    portique.getSalle1() = portique.getSalle2();
                    portiqueSrv->update(portique);
                }
            }
        }
        // suppression de la salle
        return salleDataSrv->remove(salle);
    }
    return false;
}

    bool Metier::SalleServiceImpl::update(Salle salle)
    {
        // verification des valeurs
        if( !salle.getNomAtelier().isEmpty() && !salle.getNomSalle().isEmpty() && salle.getId() > 0 && salle.getNumSalle() >= 0 && salle.getX_fin() >= 0 && salle.getX_ini() >= 0 && salle.getY_fin() >= 0 && salle.getY_ini() >= 0){
            Salle salleVerif = salleDataSrv->getByNumSalle(salle.getNumSalle());
            if( salleVerif.getId() < 1 || salleVerif.getId()==salle.getId()){
                // modification
                return salleDataSrv->update(salle);
            }
        }
        return false;
    }

QList<Salle> Metier::SalleServiceImpl::getAll(int debut, int parPage)
{
    QList<Salle> listeSalles;
    if(debut >= 0 && parPage > 0 ){
        listeSalles = salleDataSrv->getAll(debut, parPage);
    }
    return listeSalles;
}

int Metier::SalleServiceImpl::getCount()
{
    return salleDataSrv->getCount();
}

Salle Metier::SalleServiceImpl::getById(long id)
{
    Salle salle;
    if(id > 0){
        salle = salleDataSrv->getById(id);
    }
    return salle;
}

QList<Salle> Metier::SalleServiceImpl::getByNomSalle(QString nomSalle, int debut, int parPage)
{
    QList<Salle> listeSalles;
    if(!nomSalle.isEmpty() && debut >= 0 && parPage > 0 ){
        listeSalles = salleDataSrv->getByNomSalle(nomSalle, debut, parPage);
    }
    return listeSalles;
}

int Metier::SalleServiceImpl::getCountByNomSalle(QString nomSalle)
{
    int count = 0;
    if(!nomSalle.isEmpty()){
        count = salleDataSrv->getCountByNomSalle(nomSalle);
    }
    return count;
}

QList<QString> Metier::SalleServiceImpl::getListNomSalle(int debut, int parPage)
{
    QList<QString> listeNomSalle;
    if(debut >= 0 && parPage > 0 ){
        listeNomSalle = salleDataSrv->getListNomSalle(debut, parPage);
    }
    return listeNomSalle;
}

int Metier::SalleServiceImpl::getCountListNomSalle()
{
    return salleDataSrv->getCountListNomSalle();
}

Salle Metier::SalleServiceImpl::getByNumSalle(int numSalle)
{
    Salle salle;
    if(numSalle >= 0){
        salle = salleDataSrv->getByNumSalle(numSalle);
    }
    return salle;
}

QList<int> Metier::SalleServiceImpl::getListNumSalle(int debut, int parPage)
{
    QList<int> listeNumSalle;
    if(debut >= 0 && parPage > 0 ){
        listeNumSalle = salleDataSrv->getListNumSalle(debut, parPage);
    }
    return listeNumSalle;
}

int Metier::SalleServiceImpl::getCountListNumSalle()
{
    return salleDataSrv->getCountListNumSalle();
}

QList<Salle> Metier::SalleServiceImpl::getByNomAtelier(QString nomAtelier, int debut, int parPage)
{
    QList<Salle> salle;
    if(!nomAtelier.isEmpty() && debut >= 0 && parPage > 0){
        salle = salleDataSrv->getByNomAtelier(nomAtelier, debut, parPage);
    }
    return salle;
}

int Metier::SalleServiceImpl::getCountByNomAtelier(QString nomAtelier)
{
    int count = 0;
    if(!nomAtelier.isEmpty()){
        count = salleDataSrv->getCountByNomAtelier(nomAtelier);
    }
    return count;
}

QList<QString> Metier::SalleServiceImpl::getListNomAtelier(int debut, int parPage)
{
    QList<QString> listeNomAtelier;
    if(debut >= 0 && parPage > 0 ){
        listeNomAtelier = salleDataSrv->getListNomAtelier(debut, parPage);
    }
    return listeNomAtelier;
}

int Metier::SalleServiceImpl::getCountListNomAtelier()
{
    return salleDataSrv->getCountListNomAtelier();
}
