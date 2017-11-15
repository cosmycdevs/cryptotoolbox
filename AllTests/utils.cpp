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
        char* end;
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

