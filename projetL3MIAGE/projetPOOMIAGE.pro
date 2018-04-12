TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    userinterface.cpp \
    agence.cpp \
    acheteur.cpp \
    client.cpp \
    appartement.cpp \
    maison.cpp \
    terrain.cpp \
    visite.cpp \
    vendeur.cpp \
    bienimmobilier.cpp \
    localprofessionnel.cpp

HEADERS += \
    userinterface.h \
    agence.h \
    acheteur.h \
    client.h \
    appartement.h \
    maison.h \
    terrain.h \
    localprofessionnel.h \
    bienimmobilier.h \
    vendeur.h \
    visite.h

DISTFILES += \
    ../save/buyers.txt \
    ../save/realEstates.txt \
    ../save/sellers.txt
