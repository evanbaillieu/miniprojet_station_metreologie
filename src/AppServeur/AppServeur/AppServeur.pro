#-------------------------------------------------
#
# Project created by QtCreator 2015-01-29T11:11:27
#
#-------------------------------------------------

QT       += core sql network

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AppServeur
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += client/main.cpp \
    client/servertcp.cpp \
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
    metier/lecteurrfidserviceimpl.cpp \
    metier/lecteurrfid.cpp \
    metier/batimentserviceimpl.cpp \
    metier/batiment.cpp \
    physique/typedataserviceimpl.cpp \
    physique/servicesql.cpp \
    physique/salledataserviceimpl.cpp \
    physique/portiquedataserviceimpl.cpp \
    physique/physiquefactory.cpp \
    physique/metrologuedataserviceimpl.cpp \
    physique/materieldataserviceimpl.cpp \
    physique/localisationdataserviceimpl.cpp \
    physique/lecteurrfiddataserviceimpl.cpp \
    physique/batimentdataserviceimpl.cpp

HEADERS += \
		client/servertcp.h \
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
    metier/lecteurrfidserviceimpl.h \
    metier/lecteurrfidservice.h \
    metier/lecteurrfid.h \
    metier/batimentserviceimpl.h \
    metier/batimentservice.h \
    metier/batiment.h \
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
    physique/lecteurrfiddataserviceimpl.h \
    physique/lecteurrfiddataservice.h \
    physique/batimentdataserviceimpl.h \
    physique/batimentdataservice.h
