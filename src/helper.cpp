#include "helper.h"

//#include "secp256k1.c" //secp256k1/src/
//#include "include/secp256k1.h" //secp256k1/
#include "base58.h"
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

QString helper::getPublicECDSAKey(const QString &privKeyQString)
{
    qDebug() << "privKeyQString == " << privKeyQString;
/*
    QByteArray baFromHexString = QByteArray::fromHex(privKeyQString.toUtf8().data());

//    std::string stdPrivKey = STD_STRING(QString(baFromHexString));
//    std::cout << "stdPrivKey == " << stdPrivKey << std::endl;
    unsigned char privkey[baFromHexString.size()];
    for (int i = 0; i < baFromHexString.size(); i++) {
        privkey[i] = baFromHexString.at(i);
    }

//    const char* charPtrPrivKey = stdPrivKey.c_str();
//    std::cout << "charPtrPrivKey == " << charPtrPrivKey << std::endl;
//    const unsigned char* privkey = reinterpret_cast<const unsigned char *>(charPtrPrivKey);

//    const unsigned char* privkey = (const unsigned char*) stdPrivKey.c_str();
//    std::cout << "privkey    == " << privkey << std::endl;

    //master
    secp256k1_context *secp256k1_context_sign = nullptr;
    secp256k1_context_sign = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
    assert(secp256k1_context_sign != nullptr);

    int ret = secp256k1_ec_seckey_verify(secp256k1_context_sign, privkey);
    std::cout << "secp256k1_ec_seckey_verify() == " << ret << std::endl;
    if (!ret) {
        std::cout << "Error in secp256k1_ec_seckey_verify()" << std::endl;
        return "";
    }
    assert(ret);

    std::cout << "secp256k1_context_sign->ecmult_gen_ctx.prec == " << secp256k1_context_sign->ecmult_gen_ctx.prec << std::endl;

    secp256k1_pubkey pubkey;
    ret = secp256k1_ec_pubkey_create(secp256k1_context_sign, &pubkey, privkey);
    assert(ret);

    std::cout << "secp256k1_ec_pubkey_create() == " << ret  << std::endl;

    size_t clen = 65;
    unsigned char pub[65];
    size_t publen = 65;
    secp256k1_ec_pubkey_serialize(secp256k1_context_sign, pub, &publen, &pubkey, SECP256K1_EC_UNCOMPRESSED);
    //assert(result.size() == clen);
    std::cout << "pub == " << pub << std::endl;
*/
    return "";
}
