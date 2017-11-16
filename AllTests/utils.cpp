#include "utils.hpp"

#include <openssl/ssl.h>
#include <openssl/ripemd.h>

#include <sstream>
#include <iomanip>

std::vector<unsigned char> utils::HexToBytes(const std::string& key)
{
    std::vector<unsigned char> result;
    for(size_t i = 0; i != key.size(); i += 2)
    {
        long d = std::strtol(key.substr(i, 2).c_str(), nullptr, 16);
        result.push_back(static_cast<unsigned char>(d));
    }

    return result;
}

std::string utils::BytesToHex(const std::vector<unsigned char>& bytes)
{
    std::stringstream ss;
    for(auto&& byte : bytes)
    {
        ss << std::hex << std::setfill('0') << std::setw(2) << (int)byte;
    }

    return ss.str();
}

std::vector<unsigned char> utils::SHA256(const std::vector<unsigned char>& digest)
{
    std::vector<unsigned char> resultDigest(SHA256_DIGEST_LENGTH);
    ::SHA256(reinterpret_cast<const unsigned char*>(&digest[0]),
             digest.size(),
             reinterpret_cast<unsigned char*>(&resultDigest[0]));
    return resultDigest;
}

std::vector<unsigned char> utils::RIPEMD160(const std::vector<unsigned char>& digest)
{
    std::vector<unsigned char> resultDigest(RIPEMD160_DIGEST_LENGTH);
    ::RIPEMD160(reinterpret_cast<const unsigned char*>(&digest[0]),
                digest.size(),
                reinterpret_cast<unsigned char*>(&resultDigest[0]));
    return resultDigest;
}

std::string utils::PrivateToPublic(const std::string& privateKey, point_conversion_form_t conversion)
{
    BIGNUM priv;
    BN_init(&priv);
    EC_KEY* key = EC_KEY_new_by_curve_name(NID_secp256k1);

    BIGNUM* hex2bnResult = &priv;
    BN_hex2bn(&hex2bnResult, privateKey.c_str());
    EC_KEY_set_private_key(key, &priv);

    BN_CTX* ctx = BN_CTX_new();
    BN_CTX_start(ctx);

    auto group = EC_KEY_get0_group(key);
    auto publicKeyPoint = EC_POINT_new(group);
    EC_POINT_mul(group, publicKeyPoint, &priv, nullptr, nullptr, ctx);
    EC_KEY_set_public_key(key, publicKeyPoint);

    char* result = EC_POINT_point2hex(group, publicKeyPoint, conversion, ctx);
    std::string hexPublicKey(result);

    EC_POINT_free(publicKeyPoint);
    EC_KEY_free(key);
    BN_CTX_free(ctx);
    BN_free(hex2bnResult);
    free(result);

    return hexPublicKey;
}
