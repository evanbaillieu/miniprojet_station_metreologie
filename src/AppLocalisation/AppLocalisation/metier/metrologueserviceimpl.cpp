#include "metrologueserviceimpl.h"

Metier::MetrologueServiceImpl::MetrologueServiceImpl()
{
    metrologueDataSrv = PhysiqueFactory::getMetrologueDataServiceImpl();
}

Metrologue Metier::MetrologueServiceImpl::add(Metrologue metrologue)
{
    // verification des valeurs
    if(!metrologue.getLogin().isEmpty() && !metrologue.getPassword().isEmpty()){
        Metrologue metrologueVerif = metrologueDataSrv->getByLogin(metrologue.getLogin());
        if(metrologueVerif.getId() < 1){
            // ajout
            metrologue = metrologueDataSrv->add(metrologue);
        }
    }
    return metrologue;
}

bool Metier::MetrologueServiceImpl::remove(Metrologue metrologue)
{
    // verification de la presence dans la base
    if(metrologue.getId() > 0){
        // suppression
        return metrologueDataSrv->remove(metrologue);
    }
    return false;
}

bool Metier::MetrologueServiceImpl::update(Metrologue metrologue)
{
    // verification des valeurs
    if(!metrologue.getLogin().isEmpty() && !metrologue.getPassword().isEmpty()){
        Metrologue metrologueVerif = metrologueDataSrv->getByLogin(metrologue.getLogin());
        if(metrologueVerif.getId() < 1 || metrologueVerif.getId() == metrologue.getId()){
            return metrologueDataSrv->update(metrologue);
        }

    }
    return false;
}

QList<Metrologue> Metier::MetrologueServiceImpl::getAll(int debut, int parPage)
{
    QList<Metrologue> listeMetrologues;
    if(debut >= 0 && parPage > 0 ){
        listeMetrologues = metrologueDataSrv->getAll(debut, parPage);
    }
    return listeMetrologues;
}

int Metier::MetrologueServiceImpl::getCount()
{
    return metrologueDataSrv->getCount();
}

Metrologue Metier::MetrologueServiceImpl::getById(long id)
{
    Metrologue metrologue;
    if(id > 0){
        metrologue = metrologueDataSrv->getById(id);
    }
    return metrologue;
}

Metrologue Metier::MetrologueServiceImpl::getByLogin(QString login)
{
    Metrologue metrologue;
    if(!login.isEmpty()){
        metrologue = metrologueDataSrv->getByLogin(login);
    }
    return metrologue;
}

QList<QString> Metier::MetrologueServiceImpl::getListLogin(int debut, int parPage)
{
    QList<QString> listeMetrologues;
    if(debut >= 0 && parPage > 0 ){
        listeMetrologues = metrologueDataSrv->getListLogin(debut, parPage);
    }
    return listeMetrologues;
}

int Metier::MetrologueServiceImpl::getCountListLogin()
{
    return metrologueDataSrv->getCountListLogin();
}
