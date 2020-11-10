#ifndef LIAISONTCP_H
#define LIAISONTCP_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

class LiaisonTCP{

private:
    char messageErreur[120];
    char requete[80];
    char reponse[80];
    struct hostent *server;
    struct sockaddr_in adServeurTCP;
    struct sockaddr_in adClientTCP; // pour choisir son @IP ou n° de port
    int sockClient;

public:
    LiaisonTCP();
    ~LiaisonTCP();
    int creerSocket(int type, char *numMachine);
    int connexionSrv(int port, char *nomMachine);
    int ecrireSocket(char *requete);
    char *lireSocket();
    void fermer();
    char* getMessageErreur(void);
};

#endif // LIAISONTCP_H
