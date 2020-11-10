#include "lecteursemtec.h"

LecteurSemtec::LecteurSemtec(){
    trameRecu[0]= '\0';
    idMateriel[0]= '\0';
    codeErreur= 0;
}

LecteurSemtec::~LecteurSemtec(){
    if(com.getStatus() == true)
        com.fermer();
}

void LecteurSemtec::setDevice(char *device){
    com.setNomCom(device);
}

int LecteurSemtec::initLecteur(){
    int erreur;
    
    erreur= com.initCom();
    codeErreur= com.getNumErreur();
    return erreur; // retourne 0:OK sinon -1:Erreur
}

int LecteurSemtec::scanAllTag(){
	int sizeId;
    if( (sizeId= scan(0)) > 0 )
		return sizeId;
	if((codeErreur >=13) && (codeErreur <=15))
                return -1;
	return scan(1);
}

int LecteurSemtec::scanGrandTag(){
    return scan(1);
}

int LecteurSemtec::scanPetitTag(){
    return scan(0);
}

char *LecteurSemtec::getIdMateriel() {
    memset(idMateriel, 0, sizeof(idMateriel)); // RAZ zone mem idmateriel
    for( int i= 0, debutID= 6, sizeID= 8; i < sizeID ; i++, debutID++){
        idMateriel[i]= trameRecu[debutID];
    }
    return this->idMateriel;
}

void LecteurSemtec::cligno(){
    const char *cmd[]={"\002200300\003", "\002200301\003"}; // LED OFF / LED ON
    char req[20];

    strcpy(req, cmd[1]);
    ecritureTrame(req);
    lectureTrame();
    usleep(300000);
    strcpy(req, cmd[0]);
    ecritureTrame(req);
    lectureTrame();
}

int LecteurSemtec::scan(int typeTag){
    const char *cmd[]={"\0026200\x3", "\0024301S\003"}; //
    char req[20];
    int erreur;

    strcpy(req, cmd[typeTag]);
    if((erreur= ecritureTrame(req)) > 0 )
        erreur= lectureTrame();
    return erreur; // retourne -1 en cas d'erreur avec maj numErreur
}

int LecteurSemtec::lectureTrame() {
    int r; // Validité de la reception
    int n= 0; // Indice carac de la trame recue
    char checkRecu, checkCalcul;

    isValideIdMateriel= false;
    memset(trameRecu, 0, sizeof(trameRecu)); // RAZ zone mem trameRecu
//    printf("lectureTrame: ");fflush(stdout);
    do {    // sort sur un ACK NAK SYN ou Erreur de lecture
        r= com.lectureCar(&trameRecu[n]);
    } while((r != -1) && (trameRecu[n] != ACK) && (trameRecu[n] != SYN) && (trameRecu[n] != NAK));
    if( r > 0 ){
        switch(trameRecu[n]) {
        case ACK:
            n++;
            do {    // Lire jusqu'a un ETX
                com.lectureCar(&trameRecu[n]);
//                printf("%02x ", trameRecu[n]);
            } while((r!= -1) && (trameRecu[n++] !=  ETX));
//            putchar('\n');
            trameRecu[n]= '\0';
            if((r>0) && (com.lectureCar(&checkRecu)>0) && (n>12)) { // si lecture precedente ok et lecture checksum ok et rep trame id
                checkCalcul= calculChecksum(trameRecu);
                if(checkRecu == checkCalcul ) { // test du checksum
                    r= n;
                    isValideIdMateriel= true;
                }
                else {
                    r= -1;
                    codeErreur= 18;
                }
            }
            printf("ACK\n");
            break;

        case SYN:   // Erreur
        // Lire le code d'erreur SYN STX <ffff> <ee> ETX cheksum => 7e et 8e carac
            char code[3];
            code[0]= trameRecu[6];
            code[1]= trameRecu[7];
            code[2]= '\0';
            codeErreur= atoi(code);
            r= -1;
//            printf("SYN\n");
            break;

        case NAK: // Requete invalide
            codeErreur= 12;
            r= -1;
//            printf("NAK\n");
            break;
        }
    }
    else
        codeErreur= com.getNumErreur();
    return r; // si ok retourne longueur trame sinon -1: Erreur
}

int LecteurSemtec::ecritureTrame(char *trame){
    int lg, erreur;

    lg= strlen(trame);
    trame[lg++]= calculChecksum(trame);
/*    printf("ecritureTrame: ");fflush(stdout);
    for(int i=0; i<lg; i++)
        printf("%02x ", trame[i]);
    putchar('\n');*/
    erreur= com.ecrire(trame, lg);
    codeErreur= com.getNumErreur();
    return erreur; // si ok retourne lg trame ecrite sinon -1: Erreur
}

char LecteurSemtec::calculChecksum(const char* repOUreq){
    int i, lg;
    char checksum;

    lg= strlen(repOUreq);
//    printf("%s : %d", repOUreq, lg);
    for(checksum= '\0', i= 0; i < lg; i++)
        checksum ^= repOUreq[i]; //Calcul du checksum avec un XOR
    return checksum;
}
