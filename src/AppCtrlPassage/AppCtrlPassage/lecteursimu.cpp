#include "lecteursimu.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

LecteurSimu::LecteurSimu(){
    cout << "Simu tag: 1 à 9 ou autre=SORTIE" << endl;
    trameRecu[0]= '\0';
    idMateriel[0]= '\0';
    isValideIdMateriel= true;
    codeErreur= 0;
}

LecteurSimu::~LecteurSimu(){
}

void LecteurSimu::setDevice(char *s){
    // rien à faire
}

int LecteurSimu::initLecteur(){
    return 0;
}

int LecteurSimu::scanGrandTag(){
	return scan();
}

int LecteurSimu::scanPetitTag(){
	return scan();
}

int LecteurSimu::scanAllTag(){
	return scan();
}

int LecteurSimu::scan(){
    switch(getcar()){
    case '1': strcpy(idMateriel, "12345678"); break;
    case '2': strcpy(idMateriel, "23456789"); break;
    case '3': strcpy(idMateriel, "34567890"); break;
    case '4': strcpy(idMateriel, "4567890A"); break;
    case '5': strcpy(idMateriel, "AD813077"); break;
    case '6': strcpy(idMateriel, "49823077"); break;
    case '7': strcpy(idMateriel, "2A823077"); break;
    case '8': strcpy(idMateriel, "48823077"); break;
    case '9': strcpy(idMateriel, "2B823077"); break;
    default : strcpy(idMateriel, "SORTIE"); break;
    }
    return 8;
}

char *LecteurSimu::getIdMateriel() {
    return this->idMateriel;
}

void LecteurSimu::cligno(){
    // rien à faire
}

char LecteurSimu::getcar(){
    struct termios saveClavier, workClavier;
    char c;

    tcgetattr(0, &workClavier);
    saveClavier= workClavier;
    workClavier.c_cflag= CLOCAL|CREAD;
    workClavier.c_iflag= 0;
    workClavier.c_oflag= 0;
    workClavier.c_lflag= ISIG;
    workClavier.c_cc[VMIN]= 1;	// sortie sur 1 caractere présent
    workClavier.c_cc[VTIME]= 1;	// fréquence de scrutation du clavier: 10ms
    tcsetattr(0, TCSANOW, &workClavier);
    c= getchar();
    tcsetattr(0, TCSANOW, &saveClavier);
    return(c);
}
