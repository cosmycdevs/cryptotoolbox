QT -= gui

CONFIG += console c++14
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS+= -fsanitize=address -fsanitize=undefined -fsanitize=leak
QMAKE_CFLAGS+= -fsanitize=address -fsanitize=undefined -fsanitize=leak
QMAKE_LFLAGS+= -fsanitize=address -fsanitize=undefined -fsanitize=leak

INCLUDEPATH += ../../boost_1_65_1 \
              /usr/local/ssl/include/openssl

LIBS += -lssl -lcrypto

SOURCES += main.cpp \
    base58.cpp \
    VanityAddressTest.cpp \
    BitcoinAddressTest.cpp \
    PrivateKeyTest.cpp \
    utils.cpp

HEADERS += \
    VanityAddressTest.hpp \
    BitcoinAddressTest.hpp \
    PrivateKeyTest.hpp \
    utils.hpp \
    base58.hpp
