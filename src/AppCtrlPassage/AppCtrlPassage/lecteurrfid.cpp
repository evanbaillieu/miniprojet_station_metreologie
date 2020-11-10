#include "lecteurrfid.h"

const char *LecteurRFID::msgErreur[]= {"0: Succes",\
    "1:Common system error.","2:Invalid function number.", "3:Function not supported.",\
    "4:Syntax error in parameter.", "5:Invalid parameter value.", "6:No log data available.",\
    "7:Device not ready.", "8:Buffer overflow.", "9:TAG write/read error.",\
    "10:Password error.", "11:Error executing function.", "12:Error structure request",\
    "13:Erreur ouverture COM", "14:Erreur ecriture COM", "15:Erreur lecture COM",\
    "16:COM déjà ouvert !", "17:COM non ouvert", "18:Checksum Erreur"};

LecteurRFID::LecteurRFID(){
}

LecteurRFID::~LecteurRFID(){
}

bool LecteurRFID::getIsValideIdMateriel(){
    return this->isValideIdMateriel;
}

int LecteurRFID::getCodeErreur(){
    return codeErreur;
}

const char *LecteurRFID::getMsgErreur(){
    return(msgErreur[codeErreur]);
}

char *LecteurRFID::getTrameRecu(){
    return trameRecu;
}
