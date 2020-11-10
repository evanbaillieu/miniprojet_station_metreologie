#ifndef LIAISONRS232_H
#define LIAISONRS232_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string>
#include <termios.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/ioctl.h>

enum mode_com {raw, canonique, trame};

class LiaisonRS232 {

private:
    char nomCom[32];        // nom du port Serie (ttyS0, ttyUSB0,...)
    struct termios worktty;
    struct termios oldtty;
    int canal;
    mode_com mode;          // 0=raw 1=canonique 2=trame
    bool status;            // port série ouvert ou non
    int numErreur;    //0: Pas d'erreur, 13:Erreur ouverture, 14:Erreur ecriture,
    //15:Erreur lecture, 16:COM déjà ouvert, 17:COM non ouvert

public:
    LiaisonRS232();
    ~LiaisonRS232();
    int initCom();
    void fermer(void);

    int ecrire(char *t, int n); // Ecrire n caractères pointé par t
    int lectureCar(char *car);  // Lire un caractère
    int lectureTrameArduino();  // Lecture d'une trame lecteur RFID sur arduino
    int activeRTS(bool);
    int activeDTR(bool);
    bool getStatus();
    char* getNomCom();
    void setNomCom(char *);
    mode_com getMode();
    void setMode(mode_com);
    int getNumErreur();
};

#endif // LIAISONRS232_H
