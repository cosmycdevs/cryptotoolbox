#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>
#include <openssl/ec.h>

#include "base58.hpp"

namespace utils
{
    std::vector<unsigned char> HexToBytes(const std::string& key);
    std::string BytesToHex(const std::vector<unsigned char>& bytes);

    std::vector<unsigned char> SHA256(const std::vector<unsigned char>& digest);
    std::vector<unsigned char> RIPEMD160(const std::vector<unsigned char>& digest);

    std::string PrivateToPublic(const std::string& privateKey, point_conversion_form_t conversion);
    std::string PublicToBitcoinAddress(const std::string& publicKey);

    std::string AddPrivateKeys(const std::string& firstPrivateKey, const std::string& secondPrivateKey);
    std::string MultiplyPrivateKeys(const std::string& firstPrivateKey, const std::string& secondPrivateKey);
}

#endif // UTILS_HPP
