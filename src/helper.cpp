#include "helper.h"

#include "base58.h"

#include "secp256k1/src/secp256k1.c"
#include "secp256k1/include/secp256k1.h"

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
    QString afterBase58 = helper::convertStdStringToQString(afterBase58Std);

    return afterBase58;
}

QByteArray helper::getQtHexHashSha256(const QByteArray &ba)
{
    QByteArray hashSha256 = QCryptographicHash::hash(ba, QCryptographicHash::Sha256);
    return hashSha256.toHex();
}

QString helper::getQtHexHashSha256(const QString &str)
{
    return QString(getQtHexHashSha256(str.toUtf8()));
}

QString helper::getQtHexHashSha256FromHexString(const QString &str)
{
    QByteArray baFromHexString = QByteArray::fromHex(str.toUtf8().data());
    return QString(helper::getQtHexHashSha256(baFromHexString));
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
