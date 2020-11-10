#ifndef LECTEURARDUINO_H
#define LECTEURARDUINO_H

#include "liaisonrs232.h"
#include "lecteurrfid.h"

class LecteurArduino : public LecteurRFID
{
private:
    LiaisonRS232 com;

public:
    LecteurArduino();
    virtual ~LecteurArduino();

    virtual void setDevice(char *);
    virtual int initLecteur();
    virtual int scanGrandTag();
    virtual int scanPetitTag();
	virtual int scanAllTag();
    virtual char* getIdMateriel();
    virtual void cligno();

private:
    int lectureTrame();
};

#endif // LECTEURARDUINO_H
