#ifndef HELPER_H
#define HELPER_H

#include <QString>
#include <QTextCodec>
#include <QCryptographicHash>
#include <QDebug>
#include <iostream>

#include <assert.h>

#pragma GCC diagnostic ignored "-Wunused-function"
#include "secp256k1/include/secp256k1.h"
#pragma GCC diagnostic warning "-Wunused-function"
#include "digest.h"

#include "common_defs.h"

#define QT_STRING  helper::convertStdStringToQString
#define STD_STRING helper::convertQStringToStdString


namespace helper {

    std::string convertQStringToStdString(
            __IN    const   QString &str);
    QString convertStdStringToQString(
            __IN    const   std::string &str);

    QString encodeBase58(
            __IN    const   QByteArray  &Data);
    QString encodeBase58(
            __IN    const   QString &str);
    QString decodeBase58(
            __IN    const   QString &str);

    QByteArray CalcHash(
            __IN    const   void                    *Data,
            __IN    const   size_t                  DataSize,
            __IN    const   CDigest::DIGEST_TYPE    DigestType);
    QByteArray CalcHash(
            __IN    const   QByteArray              &Data,
            __IN    const   CDigest::DIGEST_TYPE    DigestType);

    /// Calculates a hash recursively
    /// Each next iteration of digesting is being
    /// done on the result from the prior iteration.
    QByteArray CalcHashN(
            __IN    const   void                                *Data,
            __IN    const   size_t                              DataSize,
            __IN    const   std::vector<CDigest::DIGEST_TYPE>   &DigestTypes);
    QByteArray CalcHashN(
            __IN    const   QByteArray                          &Data,
            __IN    const   std::vector<CDigest::DIGEST_TYPE>   &DigestTypes);

    QString getQtHashSha256(
            __IN    const   QString &str);
    QByteArray getQtHexHashSha256(
            __IN    const   QByteArray  &ba);
    QString getQtHexHashSha256(
            __IN    const   QString &str);
    QString getQtHexHashSha256FromHexString(
            __IN    const   QString &str);

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
    QString getPublicPrivateKeysMultiplication(const QString &publicKey, const QString &privateKey, bool compressedFlag = false);

    QString getWIFFromPublicKey(const QString &key, QString MainNet = "0");
    QString getWIFFromPrivateKey(const QString &key, QString prefix = "80");

    QString GetRandomString();
    QString generateWIF();
    //bool testWIF(char *);  no need yet
    QString makeWIFCheckSum(QString WIF);

    QString getStringFromDouble(double val);

    void updateContextWithBasePointFromPubkey(secp256k1_context* orig_ctx, const secp256k1_pubkey &pubkey);
    QString getPublicFromModfiedBasePoint(const QString &publicKey, const QString &privateKey);

    bool DecodeHexString(
            __IN    const   QString     &String,
            __OUT           QByteArray  &ByteArray);
}

#endif // HELPER_H
