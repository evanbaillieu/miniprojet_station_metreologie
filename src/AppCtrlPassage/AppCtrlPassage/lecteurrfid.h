#ifndef LECTEURRFID_H
#define LECTEURRFID_H

class LecteurRFID {
protected:
    char trameRecu[80];
    char idMateriel[20];    // Identifiant du tag
    bool isValideIdMateriel;    // Indicateur de validité de l'identifiant reçu
    int codeErreur;
    static const char* msgErreur[];

public:
    LecteurRFID();
    virtual ~LecteurRFID();
    char* getTrameRecu();
    bool getIsValideIdMateriel();
    int getCodeErreur();
    const char* getMsgErreur();

    virtual void setDevice(char *)=0;
    virtual int initLecteur()=0;
    virtual int scanGrandTag()=0;
    virtual int scanPetitTag()=0;
	virtual int scanAllTag()=0;
    virtual char* getIdMateriel()=0;
    virtual void cligno()=0;
};

#endif // LECTEURRFID_H
