#-------------------------------------------------
#
# Project created by QtCreator 2015-01-21T15:33:29
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bdd
TEMPLATE = app


SOURCES += \
    metier/typeserviceimpl.cpp \
    metier/type.cpp \
    metier/salleserviceimpl.cpp \
    metier/salle.cpp \
    metier/portiqueserviceimpl.cpp \
    metier/portique.cpp \
    metier/metrologueserviceimpl.cpp \
    metier/metrologue.cpp \
    metier/metierfactory.cpp \
    metier/materielserviceimpl.cpp \
    metier/materiel.cpp \
    metier/localisationserviceimpl.cpp \
    metier/localisation.cpp \
    metier/batimentserviceimpl.cpp \
    metier/batiment.cpp \
    metier/lecteurrfid.cpp \
    metier/lecteurrfidserviceimpl.cpp \
    physique/typedataserviceimpl.cpp \
    physique/servicesql.cpp \
    physique/salledataserviceimpl.cpp \
    physique/portiquedataserviceimpl.cpp \
    physique/physiquefactory.cpp \
    physique/metrologuedataserviceimpl.cpp \
    physique/materieldataserviceimpl.cpp \
    physique/localisationdataserviceimpl.cpp \
    physique/batimentdataserviceimpl.cpp \
    physique/lecteurrfiddataserviceimpl.cpp \
    client/mainwindow.cpp \
		main.cpp \
    client/metrologuewindow.cpp \
    client/batimentwindow.cpp \
    client/lecteurwindow.cpp \
    client/sallewindow.cpp \
    client/portiquewindow.cpp \
    client/localisationwindow.cpp \
    client/materielwindow.cpp \
    client/typewindow.cpp

HEADERS  += \
    metier/typeserviceimpl.h \
    metier/typeservice.h \
    metier/type.h \
    metier/salleserviceimpl.h \
    metier/salleservice.h \
    metier/salle.h \
    metier/portiqueserviceimpl.h \
    metier/portiqueservice.h \
    metier/portique.h \
    metier/metrologueserviceimpl.h \
    metier/metrologueservice.h \
    metier/metrologue.h \
    metier/metierfactory.h \
    metier/materielserviceimpl.h \
    metier/materielservice.h \
    metier/materiel.h \
    metier/localisationserviceimpl.h \
    metier/localisationservice.h \
    metier/localisation.h \
    metier/batimentserviceimpl.h \
    metier/batimentservice.h \
    metier/batiment.h \
    metier/lecteurrfid.h \
    metier/lecteurrfidservice.h \
    metier/lecteurrfidserviceimpl.h \
    physique/typedataserviceimpl.h \
    physique/typedataservice.h \
    physique/servicesql.h \
    physique/salledataserviceimpl.h \
    physique/salledataservice.h \
    physique/portiquedataserviceimpl.h \
    physique/portiquedataservice.h \
    physique/physiquefactory.h \
    physique/metrologuedataserviceimpl.h \
    physique/metrologuedataservice.h \
    physique/materieldataserviceimpl.h \
    physique/materieldataservice.h \
    physique/localisationdataserviceimpl.h \
    physique/localisationdataservice.h \
    physique/batimentdataserviceimpl.h \
    physique/batimentdataservice.h \
    physique/lecteurrfiddataservice.h \
    physique/lecteurrfiddataserviceimpl.h \
    client/mainwindow.h \
    client/metrologuewindow.h \
    client/batimentwindow.h \
    client/lecteurwindow.h \
    client/sallewindow.h \
    client/portiquewindow.h \
    client/localisationwindow.h \
    client/materielwindow.h \
    client/typewindow.h

FORMS    += client/mainwindow.ui \
		client/metrologuewindow.ui \
		client/batimentwindow.ui \
		client/lecteurwindow.ui \
		client/sallewindow.ui \
		client/portiquewindow.ui \
		client/localisationwindow.ui \
		client/materielwindow.ui \
		client/typewindow.ui

