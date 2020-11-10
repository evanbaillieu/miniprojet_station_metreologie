#ifndef METROLOGUEDATASERVICE_H
#define METROLOGUEDATASERVICE_H
#include "metier/metrologue.h"

namespace Physique {
class MetrologueDataService
{
public:
    virtual Metrologue add(Metrologue metrologue) = 0;
    virtual bool remove(Metrologue metrologue) = 0;
    virtual bool update(Metrologue metrologue) = 0;
    virtual QList<Metrologue> getAll(int debut, int parPage) = 0;
    virtual int getCount() = 0;
    virtual Metrologue getById(long id) = 0;
    virtual Metrologue getByLogin(QString login) = 0;
    virtual QList<QString> getListLogin(int debut, int parPage) = 0;
    virtual int getCountListLogin() = 0;
};
}

#endif // METROLOGUEDATASERVICE_H
