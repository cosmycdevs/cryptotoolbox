#ifndef HELPER_H
#define HELPER_H

#include <QString>
#include <QTextCodec>
#include <QCryptographicHash>
#include <QDebug>
#include <iostream>

#include <assert.h>
#include "secp256k1/include/secp256k1.h"

#define QT_STRING  helper::convertStdStringToQString
#define STD_STRING helper::convertQStringToStdString

namespace helper {

    std::string convertQStringToStdString(const QString &str);
    QString convertStdStringToQString(const std::string &str);

    QString encodeBase58(const QString &str);
    QString decodeBase58(const QString &str);

    QString     getQtHashSha256(const QString &str);
    QByteArray  getQtHexHashSha256(const QByteArray &ba);
    QString     getQtHexHashSha256(const QString &str);
    QString     getQtHexHashSha256FromHexString(const QString &str);

    QByteArray encodeRipemd160(const QByteArray &ba);
    QString getHexHashRipemd160FromHexString(const QString &str);
    QString getHexHashRipemd160FromString(const QString &str);

    QByteArray encodeSha256(const QByteArray &ba);
    QString getHexHashSha256FromHexString(const QString &str);
    QString getHexHashSha256FromString(const QString &str);

    QString getPublicECDSAKey(const QString &privKey, bool compressedFlag = false);

    QString getPrivateKeysSum(const QString &key1, const QString &key2);

    int qt_secp256k1_ec_privkey_tweak_mul(const secp256k1_context* ctx, unsigned char *seckey, const unsigned char *tweak);
    QString getPrivateKeysMultiplication(const QString &key1, const QString &key2);

    QString getPublicKeysSum(const QString &key1, const QString &key2, bool compressedFlag = false);

    QString GetRandomString();
    QString generateWIF();
}

#endif // HELPER_H