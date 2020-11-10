#ifndef LECTEURSIMU_H
#define LECTEURSIMU_H

#include "lecteurrfid.h"
#include <termios.h>

class LecteurSimu : public LecteurRFID
{
private:
    char getcar();
	int scan();

public:
    LecteurSimu();
    ~LecteurSimu();

    virtual void setDevice(char *);
    virtual int initLecteur();
    virtual int scanGrandTag();
    virtual int scanPetitTag();
	virtual int scanAllTag();
    virtual char* getIdMateriel();
    virtual void cligno();
};

#endif // LECTEURSIMU_H
