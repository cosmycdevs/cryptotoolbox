#include "helper.h"

#include "base58.h"
#include "secp256k1/src/secp256k1.c"
#include "crypto/ripemd160.h"
#include "crypto/sha256.h"

std::string helper::convertQStringToStdString(const QString &str)
{
    return str.toLocal8Bit().constData();
}

QString helper::convertStdStringToQString(const std::string &str)
{
    return QTextCodec::codecForName("UTF8")->toUnicode(QByteArray(str.c_str()));
}

QString helper::encodeBase58(const QString &str)
{
    QByteArray hexBeforeBase58 = QByteArray::fromHex(str.toUtf8().data());
    std::vector<unsigned char> beforeBase58Vector;
    for (int i = 0; i < hexBeforeBase58.size(); i++) {
        beforeBase58Vector.push_back(hexBeforeBase58.at(i));
    }
    std::string afterBase58Std = EncodeBase58(beforeBase58Vector);
    return QT_STRING(afterBase58Std);
}

QByteArray helper::getQtHexHashSha256(const QByteArray &ba)
{
    return QCryptographicHash::hash(ba, QCryptographicHash::Sha256).toHex();
}

QString helper::getQtHexHashSha256(const QString &str)
{
    return QString(getQtHexHashSha256(str.toUtf8()));
}

QString helper::getQtHexHashSha256FromHexString(const QString &str)
{
    return QString(helper::getQtHexHashSha256(QByteArray::fromHex(str.toUtf8().data())));
}

QString helper::getQtHashSha256(const QString &str)
{
    return QCryptographicHash::hash(str.toUtf8(), QCryptographicHash::Sha256).toHex();
}

QByteArray helper::encodeRipemd160(const QByteArray &ba)
{
    unsigned char hash[CRIPEMD160::OUTPUT_SIZE];
    CRIPEMD160().Write(reinterpret_cast<const unsigned char *>(ba.data()), ba.size()).Finalize(hash);
    return QByteArray(reinterpret_cast<const char*>(hash), CRIPEMD160::OUTPUT_SIZE);
}

QString helper::getHexHashRipemd160FromHexString(const QString &str)
{
    return encodeRipemd160(QByteArray::fromHex(str.toUtf8().data())).toHex();
}

QString helper::getHexHashRipemd160FromString(const QString &str)
{
    return encodeRipemd160(str.toUtf8().data()).toHex();
}

QByteArray helper::encodeSha256(const QByteArray &ba)
{
    unsigned char hash[CSHA256::OUTPUT_SIZE];
    CSHA256().Write(reinterpret_cast<const unsigned char *>(ba.data()), ba.size()).Finalize(hash);
    return QByteArray(reinterpret_cast<const char*>(hash), CSHA256::OUTPUT_SIZE);
}

QString helper::getHexHashSha256FromHexString(const QString &str)
{
    return encodeSha256(QByteArray::fromHex(str.toUtf8().data())).toHex();
}

QString helper::getHexHashSha256FromString(const QString &str)
{
    return encodeSha256(str.toUtf8().data()).toHex();
}

QString helper::getPublicECDSAKey(const QString &privKeyQString, bool compressedFlag)
{

    QByteArray ba = QByteArray::fromHex(privKeyQString.toUtf8().data());
    const unsigned char *seckey = reinterpret_cast<const unsigned char *>(ba.data());
    const secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
    secp256k1_pubkey pubkey;

    int ret = secp256k1_ec_pubkey_create(ctx, &pubkey, seckey);
    assert(ret);

    size_t clen = compressedFlag ? 33 : 65;
    unsigned char result[clen];
    ret = secp256k1_ec_pubkey_serialize(ctx, result, &clen, &pubkey, compressedFlag ? SECP256K1_EC_COMPRESSED : SECP256K1_EC_UNCOMPRESSED);
    assert(ret);

    QByteArray baRes = QByteArray(reinterpret_cast<const char*>(result), clen).toHex();
    qDebug() << "baRes == " << QString(baRes);
    return QString(baRes);
}
