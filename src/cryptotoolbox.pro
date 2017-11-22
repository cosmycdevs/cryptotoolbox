QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cryptotoolbox
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    helper.cpp \
    bitcointests.cpp \
    main.cpp \
    libs/bitcoin/base58.cpp \
    libs/bitcoin/crypto/ripemd160.cpp \
    libs/bitcoin/crypto/sha256.cpp \
    libs/bitcoin/uint256.cpp \
    vanity.cpp \
    digest.cpp \
    digest_ripemd160.cpp \
    digest_sha256.cpp \
    digest_sha512.cpp \
    libs/bitcoin/crypto/sha512.cpp \
    libs/bitcoin/uint256.cpp \
    libs/bitcoin/utilstrencodings.cpp
HEADERS += \
    helper.h \
    bitcointests.h \
    libs/bitcoin/base58.h \
    libs/bitcoin/crypto/ripemd160.h \
    libs/bitcoin/crypto/sha256.h \
    libs/bitcoin/uint256.h \
    libs/bitcoin/tinyformat.h \
    libs/bitcoin/utilstrencodings.h \
    libs/bitcoin/arith_uint256.h \
    vanity.h \
    digest.h \
    digest_ripemd160.h \
    digest_sha256.h \
    digest_sha512.h \
    libs/bitcoin/crypto/sha512.h \
    libs/bitcoin/arith_uint256.h \
    libs/bitcoin/tinyformat.h \
    libs/bitcoin/uint256.h \
    libs/bitcoin/utilstrencodings.h
FORMS += \
    bitcointests.ui

INCLUDEPATH += $$PWD/libs/bitcoin
#INCLUDEPATH += c:/boost-1-65-1/include/boost-1_65_1
#LIBS += "-Lc:/boost-1-65-1/lib" -llibboost_locale-mgw53-mt-1_65_1

### from secp256k1/src/basic-config.h

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


### from configure.ac
#DEFINES -= _CLIENT_VERSION_MAJOR
#DEFINES -= _CLIENT_VERSION_MINOR
#DEFINES -= _CLIENT_VERSION_REVISION
#DEFINES -= _CLIENT_VERSION_BUILD
#DEFINES -= _CLIENT_VERSION_IS_RELEASE
#DEFINES -= _COPYRIGHT_YEAR

#DEFINES += "_CLIENT_VERSION_MAJOR=0"
#DEFINES += "_CLIENT_VERSION_MINOR=15"
#DEFINES += "_CLIENT_VERSION_REVISION=99"
#DEFINES += "_CLIENT_VERSION_BUILD=0"
#DEFINES += "_CLIENT_VERSION_IS_RELEASE=false"
#DEFINES += "_COPYRIGHT_YEAR=2017"

#DEFINES -= COVERAGE
#DEFINES += "COVERAGE=1"
