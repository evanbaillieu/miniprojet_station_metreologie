#include "typeserviceimpl.h"

Metier::TypeServiceImpl::TypeServiceImpl()
{
    typeDataSrv = PhysiqueFactory::getTypeDataServiceImpl();
}

Type Metier::TypeServiceImpl::add(Type type)
{
    if(!type.getNomType().isEmpty()){
        if(typeDataSrv->getByNomType(type.getNomType()).getId() == 0){
            type = typeDataSrv->add(type);
        }
    }
    return type;
}

bool Metier::TypeServiceImpl::remove(Type type)
{
    if( !type.getNomType().isEmpty() &&  type.getId() > 1 ){
        return typeDataSrv->remove(type);
    }else
        return false;
}

bool Metier::TypeServiceImpl::update(Type type)
{
    if( !type.getNomType().isEmpty() &&  type.getId() > 1 ){
        return typeDataSrv->update(type);
    }else
        return false;
}

QList<Type> Metier::TypeServiceImpl::getAll(int debut, int parPage)
{
    QList<Type> listType;
    if(debut >= 0 && parPage > 0 ){
        listType = typeDataSrv->getAll(debut, parPage);
    }
    return listType;
}

int Metier::TypeServiceImpl::getCount()
{
    return typeDataSrv->getCount();
}

Type Metier::TypeServiceImpl::getById(long id)
{
    Type type;
    if(id > 0){
        type = typeDataSrv->getById(id);
    }
    return type;
}

Type Metier::TypeServiceImpl::getByNomType(QString nomType)
{
    Type type;
    if(!nomType.isEmpty() ){
        type = typeDataSrv->getByNomType(nomType);
    }
    return type;
}

QList<QString> Metier::TypeServiceImpl::getListNomType(int debut, int parPage)
{
    QList<QString> listNomType;
    if(debut >= 0 && parPage > 0 ){
        listNomType = typeDataSrv->getListNomType(debut, parPage);
    }
    return listNomType;
}

int Metier::TypeServiceImpl::getCountListNomType()
{
    return typeDataSrv->getCountListNomType();
}

Type Metier::TypeServiceImpl::getByNomImage(QString nomImage)
{
    Type type;
    if(!nomImage.isEmpty() ){
        type = typeDataSrv->getByNomImage(nomImage);
    }
    return type;
}

QList<QString> Metier::TypeServiceImpl::getListNomImage(int debut, int parPage)
{
    QList<QString> listNomImage;
    if(debut >= 0 && parPage > 0 ){
        listNomImage = typeDataSrv->getListNomImage(debut, parPage);
    }
    return listNomImage;
}

int Metier::TypeServiceImpl::getCountListNomImage()
{
    return typeDataSrv->getCountListNomImage();
}
