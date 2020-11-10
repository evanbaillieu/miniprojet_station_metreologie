#include "materielserviceimpl.h"

Metier::MaterielServiceImpl::MaterielServiceImpl()
{
    materielDataSrv = PhysiqueFactory::getMaterielDataServiceImpl();
    localisationDataSrv = PhysiqueFactory::getLocalisationDataServiceImpl();
}

Materiel Metier::MaterielServiceImpl::add(Materiel materiel)
{
    // verification des valeurs
    if(!materiel.getNomMateriel().isEmpty() && !materiel.getIdBadge().isEmpty() && materiel.getDateControle().isValid() && materiel.getType().getId() > 0){
        Materiel materielVerif = materielDataSrv->getByIdBadge(materiel.getIdBadge());
        if(materielVerif.getId() < 1){
            // ajout
            materiel = materielDataSrv->add(materiel);
        }
    }
    return materiel;
}

bool Metier::MaterielServiceImpl::remove(Materiel materiel)
{
    // verification de la présence dans la base
    if(materiel.getId() > 0){
        Localisation localisation = localisationDataSrv->getByMateriel(materiel);
        //suppression de la localisation concernant le materiel
        localisationDataSrv->remove(localisation);
        // suppression du materiel
        return materielDataSrv->remove(materiel);
    }
    return false;
}

bool Metier::MaterielServiceImpl::update(Materiel materiel)
{
    // verification des valeurs
    if(!materiel.getNomMateriel().isEmpty() && !materiel.getIdBadge().isEmpty() && materiel.getDateControle().isValid() && materiel.getType().getId() > 0){
        Materiel materielVerif = materielDataSrv->getByIdBadge(materiel.getIdBadge());
        if(materielVerif.getId() < 1 || materielVerif.getId() == materiel.getId()){
            // modification
            return materielDataSrv->update(materiel);
        }
    }
    return false;
}

QList<Materiel> Metier::MaterielServiceImpl::getAll(int debut, int parPage)
{
    QList<Materiel> listeMateriels;
    if(debut >= 0 && parPage > 0 ){
        listeMateriels = materielDataSrv->getAll(debut, parPage);
    }
    return listeMateriels;
}

int Metier::MaterielServiceImpl::getCount()
{
    return materielDataSrv->getCount();
}

Materiel Metier::MaterielServiceImpl::getById(long id)
{
    Materiel materiel;
    if(id > 0){
        materiel = materielDataSrv->getById(id);
    }
    return materiel;
}

Materiel Metier::MaterielServiceImpl::getByIdBadge(QString idBadge)
{
    Materiel materiel;
    if(!idBadge.isEmpty()){
        materiel = materielDataSrv->getByIdBadge(idBadge);
    }
    return materiel;
}

QList<QString> Metier::MaterielServiceImpl::getListIdBadge(int debut, int parPage)
{
    QList<QString> liste;
    if(debut >= 0 && parPage > 0 ){
        liste = materielDataSrv->getListIdBadge(debut, parPage);
    }
    return liste;
}

int Metier::MaterielServiceImpl::getCountListIdBadge()
{
    return materielDataSrv->getCountListIdBadge();
}

QList<Materiel> Metier::MaterielServiceImpl::getByDateControle(QDate dateControle, int debut, int parPage)
{
    QList<Materiel> materiel;
    if(dateControle.isValid()){
        materiel = materielDataSrv->getByDateControle(dateControle, debut, parPage);
    }
    return materiel;
}

int Metier::MaterielServiceImpl::getCountByDateControle(QDate dateControle)
{
    int count = 0;
    if(dateControle.isValid()){
        count = materielDataSrv->getCountByDateControle(dateControle);
    }
    return count;
}

QList<QDate> Metier::MaterielServiceImpl::getListDateControle(int debut, int parPage)
{
    QList<QDate> listeDates;
    if(debut >= 0 && parPage > 0 ){
        listeDates = materielDataSrv->getListDateControle(debut, parPage);
    }
    return listeDates;
}

int Metier::MaterielServiceImpl::getCountListDateControle()
{
    return materielDataSrv->getCountListDateControle();
}

QList<Materiel> Metier::MaterielServiceImpl::getByNewDateControle(QDate newDateControle, int debut, int parPage)
{
    QList<Materiel> listeMateriel;
    if(newDateControle.isValid() && debut >= 0 && parPage > 0 ){
        materielDataSrv->getByNewDateControle(newDateControle,debut,parPage);
    }
    return listeMateriel;
}

QList<Materiel> Metier::MaterielServiceImpl::getByType(Type type, int debut, int parPage)
{
    QList<Materiel> listeMateriels;
    if(type.getId() > 0 && debut >= 0 && parPage > 0 ){
        listeMateriels = materielDataSrv->getByType(type, debut, parPage);
    }
    return listeMateriels;
}

int Metier::MaterielServiceImpl::getCountByType(Type type)
{
    int count = 0;
    if(type.getId() > 0){
        count = materielDataSrv->getCountByType(type);
    }
    return count;
}

QList<Type> Metier::MaterielServiceImpl::getListType(int debut, int parPage)
{
    QList<Type> listeTypes;
    if( debut >= 0 && parPage > 0 ){
        listeTypes = materielDataSrv->getListType(debut, parPage);
    }
    return listeTypes;
}

int Metier::MaterielServiceImpl::getCountListType()
{
    return materielDataSrv->getCountListType();
}

QList<Materiel> Metier::MaterielServiceImpl::getByNomMateriel(QString nomMateriel, int debut, int parPage)
{
    QList<Materiel> listeMateriels;
    if(!nomMateriel.isEmpty() && debut >= 0 && parPage > 0 ){
        listeMateriels = materielDataSrv->getByNomMateriel(nomMateriel, debut, parPage);
    }
    return listeMateriels;
}

int Metier::MaterielServiceImpl::getCountByNomMateriel(QString nomMateriel)
{
    int count = 0;
    if(!nomMateriel.isEmpty()){
        count = materielDataSrv->getCountByNomMateriel(nomMateriel);
    }
    return count;
}

QList<QString> Metier::MaterielServiceImpl::getListNomMateriel(int debut, int parPage)
{
    QList<QString> listeStrings;
    if( debut >= 0 && parPage > 0 ){
        listeStrings = materielDataSrv->getListNomMateriel(debut, parPage);
    }
    return listeStrings;
}

int Metier::MaterielServiceImpl::getCountListNomMateriel()
{
    return materielDataSrv->getCountListNomMateriel();
}


int Metier::MaterielServiceImpl::getCountListNewDateControle()
{
    return materielDataSrv->getCountListNewDateControle();
}

QList<Materiel> Metier::MaterielServiceImpl::getByPeriode(QDate date, bool avant, int debut, int parPage)
{
    QList<Materiel> listeMateriels;
    if(date.isValid() && debut >= 0 && parPage > 0 ){
        return materielDataSrv->getByPeriode( date, avant, debut, parPage);
    }
    return listeMateriels;
}

int Metier::MaterielServiceImpl::getCountByPeriode(QDate date, bool avant)
{
    if(date.isValid()){
        return materielDataSrv->getCountByPeriode(date, avant);
    }
    return 0;
}


QList<QDate> Metier::MaterielServiceImpl::getListNewDateControle(int debut, int parPage)
{
    QList<QDate> listeDates;
    if(debut >= 0 && parPage > 0 ){
        materielDataSrv->getListNewDateControle(debut, parPage);
    }
    return listeDates;
}


int Metier::MaterielServiceImpl::getCountByNewDateControle(QDate newDateControle)
{
    if(newDateControle.isValid()){
        materielDataSrv->getCountByNewDateControle(newDateControle);
    }
    return 0;
}
