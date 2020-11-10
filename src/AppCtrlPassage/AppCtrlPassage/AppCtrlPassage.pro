TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
	liaisontcp.cpp \
	lecteurrfid.cpp \
	lecteursimu.cpp \
	lecteurarduino.cpp \
	lecteursemtec.cpp \
	liaisonrs232.cpp

HEADERS += \
	liaisontcp.h \
	lecteurrfid.h \
	lecteursimu.h \
	lecteurarduino.h \
	lecteursemtec.h \
	liaisonrs232.h
