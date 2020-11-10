#include "liaisontcp.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

LiaisonTCP::LiaisonTCP(){
    sockClient= -1;
}

LiaisonTCP::~LiaisonTCP(){
    if(sockClient >= 0)
        fermer();
}

int LiaisonTCP::creerSocket(int type, char *numMachine ){
    //creation de la socket
    if((this->sockClient= socket(AF_INET, type, 0)) == -1)
        strcpy(messageErreur, "ERREUR socket !");
    else {
        adClientTCP.sin_family= AF_INET;
        adClientTCP.sin_port= 0;
        adClientTCP.sin_addr.s_addr= inet_addr(numMachine);
        if(bind(sockClient, (struct sockaddr*)&adClientTCP, sizeof(struct sockaddr))<0){
            this->sockClient= -1;
            strcpy(messageErreur, "ERREUR bind !");
        }
    }
    return this->sockClient;
}

int LiaisonTCP::connexionSrv(int port, char *nomMachine){
    if((server= gethostbyname(nomMachine)) == NULL)    {
        strcpy(messageErreur, strerror(errno));
        return(-1);
    }
    adServeurTCP.sin_family = AF_INET;
    adServeurTCP.sin_port = htons(port);
    memcpy((char *) &adServeurTCP.sin_addr.s_addr, (char *) server->h_addr, server->h_length);                                                            
    if(connect(sockClient, (struct sockaddr*)&adServeurTCP, sizeof(adServeurTCP)) == -1)
        return -1;                                                  //demande de connexion
    return 0;
}

void LiaisonTCP::fermer(){
    close(sockClient);
}

char *LiaisonTCP::getMessageErreur(){
    return messageErreur;
}

int LiaisonTCP::ecrireSocket(char *requete){
    if(write(sockClient, requete, strlen(requete)) < 0)
        return -1;
    return 0;
}

char *LiaisonTCP::lireSocket(){
    if(read(sockClient, reponse, sizeof(reponse)) < 0)
        return NULL;
    return reponse;
}

