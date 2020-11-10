#ifndef LECTEURSEMTEC_H
#define LECTEURSEMTEC_H

#include "lecteurrfid.h"
#include "liaisonrs232.h"

#define STX 2   //
#define ETX 3   //
#define ACK 6   //
#define NAK 21  //
#define SYN 22  // Erreur
#define ESC 27  // Interrupt

class LecteurSemtec : public LecteurRFID
{
private:
    LiaisonRS232 com;

public:
    LecteurSemtec();
    ~LecteurSemtec();

    virtual void setDevice(char *);
    virtual int initLecteur();
    virtual int scanGrandTag();
    virtual int scanPetitTag();
	virtual int scanAllTag();
    virtual void cligno();
    virtual char* getIdMateriel();

private:
    int scan(int typeTag);
    int lectureTrame();
    int ecritureTrame( char* trame);
    char calculChecksum(const char *repOUreq);
};

#endif // LECTEURSEMTEC_H
