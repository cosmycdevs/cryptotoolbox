QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cryptotoolbox
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        bitcointests.cpp \
    libs/bitcoin/base58.cpp \
    helper.cpp

HEADERS += \
        bitcointests.h \
    libs/bitcoin/base58.h \
    helper.h

FORMS += \
        bitcointests.ui

INCLUDEPATH += $$PWD/libs/bitcoin
