#include "helper.h"

#include "base58.h"
#include "crypto/ripemd160.h"
#include "crypto/sha256.h"
#include "secp256k1/src/secp256k1.c"

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

void helper::updateContextWithBasePointFromPubkey(secp256k1_context* orig_ctx, const secp256k1_pubkey &pubkey)
{
    secp256k1_ge modified_point;
    int ret = secp256k1_pubkey_load(orig_ctx, &modified_point, &pubkey);
    assert(ret);

    secp256k1_ecmult_gen_context *ctx   = &(orig_ctx->ecmult_gen_ctx);
    const secp256k1_callback* cb        = &(orig_ctx->error_callback);

// rewrite function static void secp256k1_ecmult_gen_context_build(secp256k1_ecmult_gen_context *ctx, const secp256k1_callback* cb)
// from ecmult_gen_impl.h modified_point => secp256k1_ge_const_g

#ifndef USE_ECMULT_STATIC_PRECOMPUTATION
    secp256k1_ge prec[1024];
    secp256k1_gej gj;
    secp256k1_gej nums_gej;
    int i, j;
#endif

//    if (ctx->prec != NULL) {
//        return;
//    }
#ifndef USE_ECMULT_STATIC_PRECOMPUTATION
    ctx->prec = (secp256k1_ge_storage (*)[64][16])checked_malloc(cb, sizeof(*ctx->prec));

    /* get the generator */
    //secp256k1_gej_set_ge(&gj, &secp256k1_ge_const_g);
    secp256k1_gej_set_ge(&gj, &modified_point);

    /* Construct a group element with no known corresponding scalar (nothing up my sleeve). */
    {
        static const unsigned char nums_b32[33] = "The scalar for this x is unknown";
        secp256k1_fe nums_x;
        secp256k1_ge nums_ge;
        int r;
        r = secp256k1_fe_set_b32(&nums_x, nums_b32);
        (void)r;
        VERIFY_CHECK(r);
        r = secp256k1_ge_set_xo_var(&nums_ge, &nums_x, 0);
        (void)r;
        VERIFY_CHECK(r);
        secp256k1_gej_set_ge(&nums_gej, &nums_ge);
        /* Add G to make the bits in x uniformly distributed. */
        //secp256k1_gej_add_ge_var(&nums_gej, &nums_gej, &secp256k1_ge_const_g, NULL);
        secp256k1_gej_add_ge_var(&nums_gej, &nums_gej, &modified_point, NULL);

    }

    /* compute prec. */
    {
        secp256k1_gej precj[1024]; /* Jacobian versions of prec. */
        secp256k1_gej gbase;
        secp256k1_gej numsbase;
        gbase = gj; /* 16^j * G */
        numsbase = nums_gej; /* 2^j * nums. */
        for (j = 0; j < 64; j++) {
            /* Set precj[j*16 .. j*16+15] to (numsbase, numsbase + gbase, ..., numsbase + 15*gbase). */
            precj[j*16] = numsbase;
            for (i = 1; i < 16; i++) {
                secp256k1_gej_add_var(&precj[j*16 + i], &precj[j*16 + i - 1], &gbase, NULL);
            }
            /* Multiply gbase by 16. */
            for (i = 0; i < 4; i++) {
                secp256k1_gej_double_var(&gbase, &gbase, NULL);
            }
            /* Multiply numbase by 2. */
            secp256k1_gej_double_var(&numsbase, &numsbase, NULL);
            if (j == 62) {
                /* In the last iteration, numsbase is (1 - 2^j) * nums instead. */
                secp256k1_gej_neg(&numsbase, &numsbase);
                secp256k1_gej_add_var(&numsbase, &numsbase, &nums_gej, NULL);
            }
        }
        secp256k1_ge_set_all_gej_var(prec, precj, 1024, cb);
    }
    for (j = 0; j < 64; j++) {
        for (i = 0; i < 16; i++) {
            secp256k1_ge_to_storage(&(*ctx->prec)[j][i], &prec[j*16 + i]);
        }
    }
#else
    (void)cb;
    ctx->prec = (secp256k1_ge_storage (*)[64][16])secp256k1_ecmult_static_context;
#endif
    //secp256k1_ecmult_gen_blind(ctx, NULL);

////
    // rewrite static void secp256k1_ecmult_gen_blind(secp256k1_ecmult_gen_context *ctx, const unsigned char *seed32) {
    // from ecmult_gen_impl.h modified_point => secp256k1_ge_const_g
    const unsigned char *seed32 = NULL;

    secp256k1_scalar b;
    secp256k1_gej gb;
    secp256k1_fe s;
    unsigned char nonce32[32];
    secp256k1_rfc6979_hmac_sha256_t rng;
    int retry;
    unsigned char keydata[64] = {0};
    if (seed32 == NULL) {
        /* When seed is NULL, reset the initial point and blinding value. */
        //secp256k1_gej_set_ge(&ctx->initial, &secp256k1_ge_const_g);
        secp256k1_gej_set_ge(&ctx->initial, &modified_point);
        secp256k1_gej_neg(&ctx->initial, &ctx->initial);
        secp256k1_scalar_set_int(&ctx->blind, 1);
    }
    /* The prior blinding value (if not reset) is chained forward by including it in the hash. */
    secp256k1_scalar_get_b32(nonce32, &ctx->blind);
    /** Using a CSPRNG allows a failure free interface, avoids needing large amounts of random data,
     *   and guards against weak or adversarial seeds.  This is a simpler and safer interface than
     *   asking the caller for blinding values directly and expecting them to retry on failure.
     */
    memcpy(keydata, nonce32, 32);
    if (seed32 != NULL) {
        memcpy(keydata + 32, seed32, 32);
    }
    secp256k1_rfc6979_hmac_sha256_initialize(&rng, keydata, seed32 ? 64 : 32);
    memset(keydata, 0, sizeof(keydata));
    /* Retry for out of range results to achieve uniformity. */
    do {
        secp256k1_rfc6979_hmac_sha256_generate(&rng, nonce32, 32);
        retry = !secp256k1_fe_set_b32(&s, nonce32);
        retry |= secp256k1_fe_is_zero(&s);
    } while (retry); /* This branch true is cryptographically unreachable. Requires sha256_hmac output > Fp. */
    /* Randomize the projection to defend against multiplier sidechannels. */
    secp256k1_gej_rescale(&ctx->initial, &s);
    secp256k1_fe_clear(&s);
    do {
        secp256k1_rfc6979_hmac_sha256_generate(&rng, nonce32, 32);
        secp256k1_scalar_set_b32(&b, nonce32, &retry);
        /* A blinding value of 0 works, but would undermine the projection hardening. */
        retry |= secp256k1_scalar_is_zero(&b);
    } while (retry); /* This branch true is cryptographically unreachable. Requires sha256_hmac output > order. */
    secp256k1_rfc6979_hmac_sha256_finalize(&rng);
    memset(nonce32, 0, 32);
    secp256k1_ecmult_gen(ctx, &gb, &b);
    secp256k1_scalar_negate(&b, &b);
    ctx->blind = b;
    ctx->initial = gb;
    secp256k1_scalar_clear(&b);
    secp256k1_gej_clear(&gb);

}

QString helper::getPublicFromModfiedBasePoint(const QString &publicKey, const QString &privateKey)
{
    int ret = 0;
    size_t clen = 65;

    secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);

    QByteArray publicKeyBa = QByteArray::fromHex(publicKey.toUtf8().data());
    const unsigned char *publicKeyCuc = reinterpret_cast<const unsigned char *>(publicKeyBa.data());

    secp256k1_pubkey pubkeyOfModifiedPoint;
    ret = secp256k1_ec_pubkey_parse(ctx, &pubkeyOfModifiedPoint, publicKeyCuc, clen);
    assert(ret);

    updateContextWithBasePointFromPubkey(ctx, pubkeyOfModifiedPoint);

    QByteArray privKeyBa = QByteArray::fromHex(privateKey.toUtf8().data());
    const unsigned char *seckey = reinterpret_cast<const unsigned char *>(privKeyBa.data());

    secp256k1_pubkey pubkeyFromModifiedPoint;
    ret = secp256k1_ec_pubkey_create(ctx, &pubkeyFromModifiedPoint, seckey);
    assert(ret);

    unsigned char resultFromModifiedPoint[clen];
    ret = secp256k1_ec_pubkey_serialize(ctx, resultFromModifiedPoint, &clen, &pubkeyFromModifiedPoint, SECP256K1_EC_UNCOMPRESSED);
    assert(ret);

//    QByteArray pubKeyFromModifiedPoint = QByteArray(reinterpret_cast<const char*>(resultFromModifiedPoint), clen);
//    QString pubFromModifiedPoint = QString(pubKeyFromModifiedPoint.toHex());
//    qDebug() << "pubFromModifiedPoint == " << pubFromModifiedPoint;

    return QString(QByteArray(reinterpret_cast<const char*>(resultFromModifiedPoint), clen).toHex());
}
