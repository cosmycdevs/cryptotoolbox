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
#    libs/bitcoin/secp256k1/src/secp256k1.c
HEADERS += \
        bitcointests.h \
    libs/bitcoin/base58.h \
    helper.h
# \
#    libs/bitcoin/secp256k1/src/basic-config.h

FORMS += \
        bitcointests.ui

INCLUDEPATH += $$PWD/libs/bitcoin
INCLUDEPATH += $$PWD/libs/bitcoin/secp256k1
#INCLUDEPATH += $$PWD/libs/bitcoin/secp256k1/src

# from secp256k1/src/basic-config.h

DEFINES -= USE_ASM_X86_64
DEFINES -= USE_ENDOMORPHISM
DEFINES -= USE_FIELD_10X26
DEFINES -= USE_FIELD_5X52
DEFINES -= USE_FIELD_INV_BUILTIN
DEFINES -= USE_FIELD_INV_NUM
DEFINES -= USE_NUM_GMP
DEFINES -= USE_NUM_NONE
DEFINES -= USE_SCALAR_4X64
DEFINES -= USE_SCALAR_8X32
DEFINES -= USE_SCALAR_INV_BUILTIN
DEFINES -= USE_SCALAR_INV_NUM

DEFINES += "USE_NUM_NONE=1"
DEFINES += "USE_FIELD_INV_BUILTIN=1"
DEFINES += "USE_SCALAR_INV_BUILTIN=1"
DEFINES += "USE_FIELD_10X26=1"
DEFINES += "USE_SCALAR_8X32=1"
