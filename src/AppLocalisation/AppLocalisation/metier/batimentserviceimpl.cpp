#include "batimentserviceimpl.h"

Metier::BatimentServiceImpl::BatimentServiceImpl()
{
    batimentDataSrv = PhysiqueFactory::getBatimentDataServiceImpl();
    salleSrv = MetierFactory::getSalleServiceImpl();
}

    Batiment Metier::BatimentServiceImpl::add(Batiment batiment)
    {
        // vérification si le "nomBatiment" et le "plan" n'est pas vide
        if(!batiment.getNomBatiment().isEmpty() && !batiment.getPlan().isEmpty()){
            // vérification si le batiment n'existe pas déjà
            Batiment batimentVerif = batimentDataSrv->getByNomBatiment(batiment.getNomBatiment());
            if(batimentVerif.getId() < 1){
                // appel de la couche physique pour l'ajout à la base de données
                batiment = batimentDataSrv->add(batiment);
            }
        }
        return batiment;
    }

bool Metier::BatimentServiceImpl::remove(Batiment batiment)
{
    // verification si le batiment est dans la base avec l'id
    if(batiment.getId() > 0){
        // supprime toute les salles du batiment passé en parametre
        for( int i = 0 ; i < batiment.getSalles().count() ; i++ ){
            salleSrv->remove(batiment.getSalles().at(i));
        }
        // supprime le batiment
        return batimentDataSrv->remove(batiment);
    }
    return false;
}

bool Metier::BatimentServiceImpl::update(Batiment batiment)
{
    // vérification des valeurs
    if(!batiment.getNomBatiment().isEmpty() && !batiment.getPlan().isEmpty()){
        //vérifie si le nom du batiment est deja urilisé
        Batiment batimentVerif = batimentDataSrv->getByNomBatiment(batiment.getNomBatiment());
        if(batimentVerif.getId() < 1 || batimentVerif.getId() == batiment.getId()){
            return batimentDataSrv->update(batiment);
        }
    }
    return false;
}

QList<Batiment> Metier::BatimentServiceImpl::getAll(int debut, int parPage)
{
    QList<Batiment> listeBatiments;
    if(debut >= 0 && parPage > 0 ){
        listeBatiments = batimentDataSrv->getAll(debut, parPage);
    }
    return listeBatiments;
}

int Metier::BatimentServiceImpl::getCount()
{
    return batimentDataSrv->getCount();
}

Batiment Metier::BatimentServiceImpl::getById(long id)
{
    Batiment batiment;
    if(id > 0){
        batiment = batimentDataSrv->getById(id);
    }
    return batiment;
}

Batiment Metier::BatimentServiceImpl::getByNomBatiment(QString nomBatiment)
{
    Batiment batiment;
    if(!nomBatiment.isEmpty()){
        batiment = batimentDataSrv->getByNomBatiment(nomBatiment);
    }
    return batiment;
}

QList<QString> Metier::BatimentServiceImpl::getListNomBatiment(int debut, int parPage)
{
    QList<QString> liste;
    if(debut >= 0 && parPage > 0 ){
        liste = batimentDataSrv->getListNomBatiment(debut, parPage);
    }
    return liste;
}

int Metier::BatimentServiceImpl::getCountListNomBatiment()
{
    return batimentDataSrv->getCountListSalle();
}

Batiment Metier::BatimentServiceImpl::getBySalle(Salle salle)
{
    Batiment batiment;
    if(salle.getId() > 0){
        batiment = batimentDataSrv->getBySalle(salle);
    }
    return batiment;
}

QList<Salle> Metier::BatimentServiceImpl::getListSalle(int debut, int parPage)
{
    QList<Salle> listeSalles;
    if(debut >= 0 && parPage > 0 ){
        listeSalles = batimentDataSrv->getListSalle(debut, parPage);
    }
    return listeSalles;
}

int Metier::BatimentServiceImpl::getCountListSalle()
{
    return batimentDataSrv->getCountListSalle();
}

Batiment Metier::BatimentServiceImpl::getByPlan(QString plan)
{
    Batiment batiment;
    if(!plan.isEmpty()){
        batiment = batimentDataSrv->getByPlan(plan);
    }
    return batiment;
}

QList<QString> Metier::BatimentServiceImpl::getListPlan(int debut, int parPage)
{
    QList<QString> liste;
    if(debut >= 0 && parPage > 0 ){
        liste = batimentDataSrv->getListPlan(debut, parPage);
    }
    return liste;
}

int Metier::BatimentServiceImpl::getCountListPlan()
{
    return batimentDataSrv->getCountListPlan();
}
