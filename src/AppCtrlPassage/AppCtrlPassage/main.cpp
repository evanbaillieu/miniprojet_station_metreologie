#include <iostream>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "liaisontcp.h"
#include "lecteurrfid.h"
#include "lecteurarduino.h"
#include "lecteursemtec.h"
#include "lecteursimu.h"

enum TypeLecteur { simu, arduino, semtec };
const char *nomLecteur[]={"simu", "arduino", "semtec"};

using namespace std;

bool flagSortie;

void fct_interrupt(int n){
    flagSortie= true;
}

int main(int argc, char *argv[]){
    enum TypeLecteur typeLecteur;
    LiaisonTCP liaisonTCP;
    LecteurRFID *lecteur= NULL;
    int port, i;
    char ipServeur[16], ipClient[16], deviceName[80], *idNewMateriel, option;;

    printf("Usage: %s -t [simu/arduino/semtec] -s [ServeurName] -p [port] -h [HostName] -d [device]\n", argv[0]);
    printf("Par défaut: %s simu 127.0.0.1 8888 127.0.0.1 /dev/ttyUSB0 (sans effet en mode simu)\n", argv[0]);

    strcpy(ipClient, "127.0.0.1");
    port= 8888;
    strcpy(ipServeur, "127.0.0.1");
    strcpy(deviceName, "/dev/ttyUSB0");
    typeLecteur= simu;
    for(i=1; i < argc; i+=2) {
        option= *(argv[i]+1);
        printf("option= %c param=%s\n", option, argv[i+1]);
        switch(option) {
        case 'h':
            strcpy(ipClient, argv[i+1]);   //Initialisation de l'IP Client
            break;
        case 'p':
            port= atoi(argv[i+1]);       //Initialisation du port (Port serveur: 8888)
            break;
        case 's':
            strcpy(ipServeur, argv[i+1]);   //Initialisation de l'IP Serveur
            break;
        case 't':
            if(strcmp(argv[i+1], "arduino") == 0)
                typeLecteur= arduino;
            else if(strcmp(argv[i+1], "semtec") == 0)
                typeLecteur= semtec;
            break;
        case 'd':strcpy (deviceName, argv[i+1]);
            break;
        default: cout << "option inconnue !" << endl;
        }
    }
    printf("Choix: %s %s %s %d %s %s\n",\
           argv[0], nomLecteur[typeLecteur], ipServeur, port, ipClient, deviceName);

    printf("Config OK ? (o/n)\n");
    if(getchar() != 'o')
        exit(0);
    getchar();
    switch(typeLecteur){
    case simu:
        lecteur= new LecteurSimu();
        break;
    case arduino:
        lecteur= new LecteurArduino();
        break;
    case semtec:
        lecteur= new LecteurSemtec();
        break;
    }

    if((liaisonTCP.creerSocket(SOCK_STREAM, ipClient)) == -1){
        cout << "Creation socket impossible!" << endl;
        exit(1);
    }

    if(liaisonTCP.connexionSrv(port, ipServeur) == -1){
        cout << "Connexion impossible !\n" << endl;
        exit(1);
    }

    printf("Signal SIGINT(^C) pour Quitter\nou caractère différent d'un chiffre en simulation\nScan de TAG RFID\n");

    signal(SIGQUIT, fct_interrupt);

    if(typeLecteur != simu) {
        lecteur->setDevice(deviceName); // Choix du nom du port série
        if(access(deviceName, F_OK) != 0){
            printf("Port USB non detecte !\n");
            exit(2);
        }
        printf("Detection Port USB : OK!\n");
    }
    if(lecteur->initLecteur() < 0) {
        printf("%s", lecteur->getMsgErreur());
        exit(2);
    }
    if(typeLecteur != simu) {
        printf("Ouverture de %s a %d bauds\n", deviceName, 9600);
    }
    else
        printf("Lecteur initialisé\n");
    flagSortie= false;
    do {
        if(lecteur->scanAllTag() < 0){
//            printf("%s\n", lecteur->getMsgErreur());
            int codeErr= lecteur->getCodeErreur();
            if((codeErr >=13) && (codeErr <=15))
                flagSortie= true;
        }
        else {
            if(lecteur->getIsValideIdMateriel() == true) {
                idNewMateriel= lecteur->getIdMateriel();
                printf("id= %s\r\n", idNewMateriel);
                if(typeLecteur == semtec)
                    lecteur->cligno();
                liaisonTCP.ecrireSocket(idNewMateriel);
                sleep(1); // Pour eviter de lire plusieurs fois le meme tag pour 1 seul passage
                if(strcmp(idNewMateriel, "SORTIE") == 0)
                    flagSortie= true;
            }
            else {
                printf("%s\n", lecteur->getMsgErreur());
            }
        }
    }
    while(flagSortie == false);
    liaisonTCP.fermer();
    printf("Fermeture de l'application\n");
    return 0;
}

