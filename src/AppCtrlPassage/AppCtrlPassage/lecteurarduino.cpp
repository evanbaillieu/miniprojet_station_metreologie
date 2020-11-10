#include "lecteurarduino.h"

LecteurArduino::LecteurArduino(){
    trameRecu[0]= '\0';
    idMateriel[0]= '\0';
    codeErreur= 0;
}

LecteurArduino::~LecteurArduino(){
    if(com.getStatus() == true)
        com.fermer();
}

void LecteurArduino::setDevice(char *device) {
    com.setNomCom(device);
}

int LecteurArduino::initLecteur(){
    int erreur= -1;

    erreur= com.initCom();
    if(erreur != -1)
        com.activeRTS(false);
    else
        codeErreur= com.getNumErreur();
    return erreur; // retourne 0:OK sinon -1:Erreur
}

int LecteurArduino::scanGrandTag(){
    return lectureTrame();
}

int LecteurArduino::scanPetitTag(){
    return lectureTrame();
}

int LecteurArduino::scanAllTag(){
    return lectureTrame();
}

char *LecteurArduino::getIdMateriel() {
    int i, j, debutID=0, sizeID;

    for(i= 0, j=0; (i < (int)strlen(trameRecu)) && (j!=2); i++){
        if(trameRecu[i] == ':')
            j++;
        if(j == 2){
            debutID= i; // On regarde où se trouve l'id en prenant le tokenizer ":"
        }
    }
    debutID += 3; //On met le curseur à l'id
    sizeID= 8;
    memset(idMateriel, 0, sizeof(idMateriel)); // RAZ zone mem idmateriel
    for( i = 0; i < sizeID ; i++, debutID++){
        idMateriel[i]= trameRecu[debutID];
    }
    return this->idMateriel;
}

void LecteurArduino::cligno(){
    // Rien à faire
}

int LecteurArduino::lectureTrame() {
    int n=0;
    int r; // Validité de la reception

    isValideIdMateriel= false;
    memset(trameRecu, 0, sizeof(trameRecu)); // RAZ zone mem trameRecu

    do {    // sort sur une '{' ou Erreur de lecture
        r= com.lectureCar(&trameRecu[n]);
    } while((r != -1) && (trameRecu[n] != '{'));
    n++;
    if(r > 0) {
        do { // Lire jusqu'à un '\n'
            com.lectureCar(&trameRecu[n]);
            if(trameRecu[n] != '\0')
                n++;
        } while((r!= -1) && (trameRecu[n-1] != '\n'));

        if(r != -1){
            trameRecu[n]= '\0';
            if(r > 0){
                r= n;
                isValideIdMateriel = true;
            }
        }
    }
    codeErreur= com.getNumErreur();
    return r; // si ok retourne la longueur trame sinon -1
}

