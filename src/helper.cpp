#include "helper.h"

#include <sstream>
#include <iostream>

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

int helper::qt_secp256k1_ec_privkey_tweak_mul(const secp256k1_context* ctx, unsigned char *seckey, const unsigned char *tweak) {
    secp256k1_scalar factor;
    secp256k1_scalar sec;
    int ret = 0;
    int overflow = 0;
    VERIFY_CHECK(ctx != NULL);
    ARG_CHECK(seckey != NULL);
    ARG_CHECK(tweak != NULL);

    secp256k1_scalar_set_b32(&factor, tweak, &overflow);
    secp256k1_scalar_set_b32(&sec, seckey, NULL);
    ret = !overflow && secp256k1_eckey_privkey_tweak_mul(&sec, &factor);
    //memset(seckey, 0, 32);
    //seckey = new unsigned char[32]();
    //seckey = calloc(32, sizeof(unsigned char));
    if (ret) {
        secp256k1_scalar_get_b32(seckey, &sec);
    }

    secp256k1_scalar_clear(&sec);
    secp256k1_scalar_clear(&factor);
    return ret;
}

QString helper::getPrivateKeysMultiplication(const QString &key1, const QString &key2)
{
    const secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN); // | SECP256K1_CONTEXT_VERIFY

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

    const secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);
    QByteArray ba1 = QByteArray::fromHex(key1.toUtf8().data());
    const unsigned char *input = reinterpret_cast<const unsigned char *>(ba1.data());

    secp256k1_pubkey pubkey;
    int ret = secp256k1_ec_pubkey_parse(ctx, &pubkey, input, clen);
    assert(ret);

    QByteArray ba2 = QByteArray::fromHex(key2.toUtf8().data());
    const unsigned char *tweak = reinterpret_cast<const unsigned char *>(ba2.data());

    ret = secp256k1_ec_pubkey_tweak_add(ctx, &pubkey, tweak);
    assert(ret);

    unsigned char result[clen];
    ret = secp256k1_ec_pubkey_serialize(ctx, result, &clen, &pubkey, compressedFlag ? SECP256K1_EC_COMPRESSED : SECP256K1_EC_UNCOMPRESSED);
    assert(ret);

    return "";
}

boost::multiprecision::uint256_t helper::binPow(boost::multiprecision::uint256_t val, boost::multiprecision::uint256_t power)
{
    boost::multiprecision::uint256_t res = 1;
    while (power) {
        if (power & 1)
            res *= val;
        val *= val;
        power >>= 1;
    }
    return res;
}


QString helper::getStringFromDouble(double val)
{
    std::stringstream ss;
    ss << std::setprecision( 15 );
    ss << val;

    return QString(ss.str().c_str());
}
