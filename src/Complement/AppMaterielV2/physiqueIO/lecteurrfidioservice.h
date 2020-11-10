#ifndef LECTEURRFIDIOSERVICE_H
#define LECTEURRFIDIOSERVICE_H
#include <QString>
#include <QObject>
#include <metier/materiel.h>

namespace PhysiqueIO {
class LecteurRFIDIOService : public QObject
{

public:
    virtual Materiel lireBadge() = 0;
    virtual bool ecrireBadge(Materiel materiel) = 0;
};
}

#endif // LECTEURRFIDIOSERVICE_H
