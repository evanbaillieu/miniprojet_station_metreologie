#ifndef SERVICESQL_H
#define SERVICESQL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlError>

class ServiceSQL
{
public:
    ServiceSQL();
    ~ServiceSQL();
    bool databaseIsOpen();
    QString getMessageErreur();

private:
    QSqlDatabase db;	// référence sur base
    QString messageErreur;
};

#endif
