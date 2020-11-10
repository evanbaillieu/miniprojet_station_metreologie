#include "servicesql.h"
#include <QStringList>
//#include <QMessageBox>
#include <QDebug>
#include <QSqlDriver>

ServiceSQL::ServiceSQL() {
    db = QSqlDatabase::addDatabase("QMYSQL"); // Type de base de donnée
    db.setDatabaseName("localisationmateriel"); // Nom de la base de donnée
    db.setUserName( "userbdd" ); // Nom d'utilisateur
    db.setPassword( "mysqlpass" ); // Mot de passe
    db.setHostName("localhost"); // Nom du domaine
    db.setPort(3306); // Port (par défault: 3306)
    if (db.open()) {
//        qWarning("Connexion Database OK");
        messageErreur= "Connexion Database OK";
    }else{
//        QMessageBox::critical(0, QObject::tr("Database Error"), db.lastError().text());
        messageErreur= db.lastError().text();
    }
}

ServiceSQL::~ServiceSQL() {
    if(db.isOpen()){
        db.commit(); // Valide la transition pour etre sûr que toutes les modifications sur la bdd seront prise en compte avant la fermeture de la connexion
        db.close();
    }
    qWarning("Fermeture et destruction du service SQL\n");
}

bool ServiceSQL::databaseIsOpen() // Permet de verifier depuis une autres classe si la base de donnée est ouverte
{
    return db.isOpen();
}

QString ServiceSQL::getMessageErreur(){
    return messageErreur;
}
