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

std::string helper::encodeBase58(const QByteArray &ba)
{
    std::vector<unsigned char> beforeBase58Vector;
    for (int i = 0; i < ba.size(); i++) {
        beforeBase58Vector.push_back(ba.at(i));
    }
    return EncodeBase58(beforeBase58Vector);
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
    const secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);
    secp256k1_pubkey pubkey;

    int ret = secp256k1_ec_pubkey_create(ctx, &pubkey, seckey);
    assert(ret);

    size_t clen = compressedFlag ? 33 : 65;
    unsigned char result[clen];
    ret = secp256k1_ec_pubkey_serialize(ctx, result, &clen, &pubkey, compressedFlag ? SECP256K1_EC_COMPRESSED : SECP256K1_EC_UNCOMPRESSED);
    assert(ret);

    return QString(QByteArray(reinterpret_cast<const char*>(result), clen).toHex());
}

QString helper::getPrivateKeysSum(const QString &key1, const QString &key2)
{
    const secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);

    QByteArray ba1 = QByteArray::fromHex(key1.toUtf8().data());
    unsigned char *result = reinterpret_cast<unsigned char *>(ba1.data());

    QByteArray ba2 = QByteArray::fromHex(key2.toUtf8().data());
    const unsigned char *tweak = reinterpret_cast<const unsigned char *>(ba2.data());

    bool ret = secp256k1_ec_privkey_tweak_add(ctx, result, tweak);
    assert(ret);

    return QString(QByteArray(reinterpret_cast<const char*>(result), strlen((char*)result)).toHex());
}

QString helper::getPrivateKeysMultiplication(const QString &key1, const QString &key2)
{
    const secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);

    QByteArray ba1 = QByteArray::fromHex(key1.toUtf8().data());
    unsigned char *result = reinterpret_cast<unsigned char *>(ba1.data());

    QByteArray ba2 = QByteArray::fromHex(key2.toUtf8().data());
    const unsigned char *tweak = reinterpret_cast<const unsigned char *>(ba2.data());

    int ret = secp256k1_ec_privkey_tweak_mul(ctx, result, tweak);
    assert(ret);

    return QString(QByteArray(reinterpret_cast<const char*>(result), strlen((char*)result)).toHex());
}

QString helper::getPublicKeysSum(const QString &key1, const QString &key2, bool compressedFlag)
{
    size_t clen = compressedFlag ? 33 : 65;
    int ret = 0;

    const secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);

    QByteArray key1ba = QByteArray::fromHex(key1.toUtf8().data());
    const unsigned char *key1cuc = reinterpret_cast<const unsigned char *>(key1ba.data());
    secp256k1_pubkey pubkey1;
    ret = secp256k1_ec_pubkey_parse(ctx, &pubkey1, key1cuc, clen);
    assert(ret);

    QByteArray key2ba = QByteArray::fromHex(key2.toUtf8().data());
    const unsigned char *key2cuc = reinterpret_cast<const unsigned char *>(key2ba.data());
    secp256k1_pubkey pubkey2;
    ret = secp256k1_ec_pubkey_parse(ctx, &pubkey2, key2cuc, clen);
    assert(ret);

    const secp256k1_pubkey *pubkeys[2];
    pubkeys[0] = &pubkey1;
    pubkeys[1] = &pubkey2;

    secp256k1_pubkey pubkey;
    ret = secp256k1_ec_pubkey_combine(ctx, &pubkey, pubkeys, 2);
    assert(ret);

    unsigned char result[clen];
    ret = secp256k1_ec_pubkey_serialize(ctx, result, &clen, &pubkey, compressedFlag ? SECP256K1_EC_COMPRESSED : SECP256K1_EC_UNCOMPRESSED);
    assert(ret);

    return QString(QByteArray(reinterpret_cast<const char*>(result), clen).toHex());
}

QString helper::getWIFFromPublicKey(const QString &pubkey)
{
    QByteArray ba = QByteArray::fromHex(pubkey.toUtf8().data());
    QByteArray sha256FormHexPubkey = encodeSha256(ba);
    QByteArray ripemd160OfSha256 = encodeRipemd160(sha256FormHexPubkey);
    ripemd160OfSha256.insert(0, QChar(0x00));
    QByteArray sha256FromRipemd160 = encodeSha256(ripemd160OfSha256);
    QByteArray sha256FromSha256 = encodeSha256(sha256FromRipemd160);

    for (int i = 0; i < 4; i++) {
        ripemd160OfSha256.append(sha256FromSha256.at(i));
    }

    std::string stdWIF = encodeBase58(ripemd160OfSha256);

    return QT_STRING(stdWIF);

}
