#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include "liaisonrs232.h"

LiaisonRS232::LiaisonRS232(){
    numErreur= 0;
    status= false;
    strcpy(nomCom, "/dev/ttyUSB0"); // valeur par defaut
    mode= trame;                    // valeur par defaut
}

LiaisonRS232::~LiaisonRS232(){
    if(status == true)
        fermer();
}

int LiaisonRS232::initCom() { // retourne -1 ou le n° de canal
    if(status == true){
        numErreur= 16;
        return -1;
    }
    if ((canal = open(nomCom, O_RDWR)) < 0 )  {    //| O_NONBLOCK
        numErreur= 13;
        status= false;
    }
    else {
        tcgetattr(canal, &oldtty);
        tcgetattr(canal, &worktty);

        cfsetispeed(&worktty, B9600); // B9600 dans c_cflag non operationel
        cfsetospeed(&worktty, B9600);
        worktty.c_cflag |= CS8 | CREAD | CLOCAL; // voir doc termios
        worktty.c_cflag &= ~ (PARENB | CRTSCTS);
        worktty.c_iflag |= IGNBRK ;
        worktty.c_iflag &= ~(IXON | IXOFF | IXANY);
        worktty.c_oflag = OPOST;
        if((mode == raw) || (mode == trame)) {
            worktty.c_lflag = 0; // &= ~(ECHO | ICANON);
            worktty.c_cc[VMIN]= 0;  // Nombre min de carac pour terminer un appel read
            worktty.c_cc[VTIME]= 10; // Duree maxi d'attente du read en 1/10s
        }
        else
            worktty.c_lflag |= ICANON;

        if(tcsetattr(canal, TCSANOW, &worktty) == 0){
            printf("Configuration du port série\n");
            status = true;
            numErreur= 0;
            tcflush(canal, TCIOFLUSH); // Vide le buffer de lecture et d'ecriture
        }
        else {
            close(canal);
            status= false;
            numErreur= 13;
        }
    }
    return canal;
}

int LiaisonRS232::activeRTS(bool niveau) {
    int flags;
    ioctl(canal, TIOCMGET, &flags);
    if(niveau == true)
        flags |= TIOCM_RTS; // Active RTS
    else
        flags &= ~TIOCM_RTS;    // Desactive RTS
    return ioctl(canal, TIOCMSET, &flags);
}

int LiaisonRS232::activeDTR(bool niveau) {
    int flags;
    ioctl(canal, TIOCMGET, &flags);
    if(niveau == true)
        flags |= TIOCM_DTR; // Active DTR
    else
        flags &= ~TIOCM_DTR;    // Desactive DTR
    return ioctl(canal, TIOCMSET, &flags);
}

void LiaisonRS232::fermer() {
    printf("Restauration et fermeture du port série\n");
    tcsetattr(canal, TCSANOW, &oldtty); // Restauration du port
    if(status == true)
        close(canal);
    status= false;
    numErreur= 0;
}

int LiaisonRS232::ecrire(char *t, int n) {
    int i=0, etat=1;
//    printf("Passage status=%d\n", status);
    if (status == true){
        for(i=0; (i < n) && (etat > 0); i++) {
//            printf("Canal=%d Envoi de %02x\n", canal, t[i]);
            etat= write(canal, &t[i], 1);   // Envoi de la trame carac/carac
        }
        if(etat > 0){
            etat= i;
            numErreur= 0;
        }
        else
            numErreur= 14;
    }
    else
        numErreur= 17;
    return etat; // retourne nb octets ecrits ou -1
}

int LiaisonRS232::lectureCar(char *car) {
    int nb= -1;
    if (status == true) {
        nb= read(canal, car, 1);
        if((nb == -1) && (errno == EAGAIN)) {
            nb= 0; // pas de donnée
            numErreur= 0;
        }
        else if (nb > 0)
            numErreur= 0;
        else
            numErreur= 15;
    }
    else
        numErreur= 17;
    return nb;  // retourne 0:pas de donnée ou 1:carac lu ou -1:Erreur
}

bool LiaisonRS232::getStatus() {
    return status;
}

mode_com LiaisonRS232::getMode() {
    return mode;
}

void LiaisonRS232::setMode(mode_com m) {
    mode= m;
}

int LiaisonRS232::getNumErreur(){
    return numErreur;
}

void LiaisonRS232::setNomCom(char* nomPort) {
    strcpy(nomCom, nomPort);
}

char* LiaisonRS232::getNomCom() {
    return nomCom;
}
