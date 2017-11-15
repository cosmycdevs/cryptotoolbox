#include "BitcoinAddressTest.hpp"

#include <openssl/ssl.h>
#include <openssl/ripemd.h>

#include "base58.h"

#include <iostream>
#include <sstream>
#include <iomanip>

auto BitcoinAddressTest::HexToBytes(const std::string& key)
{
    std::vector<unsigned char> result;
    for(size_t i = 0; i != key.size(); i += 2)
    {
        char* end;
        long d = std::strtol(key.substr(i, 2).c_str(), &end, 16);
        result.push_back(static_cast<unsigned char>(d));
    }

    return result;
}

auto BitcoinAddressTest::BytesToHex(const std::vector<unsigned char>& bytes)
{
    std::stringstream ss;
    for(auto&& byte : bytes)
    {
        ss << std::hex << std::setfill('0') << std::setw(2) << (int)byte;
    }

    return ss.str();
}

std::vector<unsigned char> SHA256(const std::vector<unsigned char>& digest)
{
    std::vector<unsigned char> resultDigest(SHA256_DIGEST_LENGTH);
    SHA256(reinterpret_cast<const unsigned char*>(&digest[0]),
           digest.size(),
           reinterpret_cast<unsigned char*>(&resultDigest[0]));
    return resultDigest;
}

std::vector<unsigned char> RIPEMD160(const std::vector<unsigned char>& digest)
{
    std::vector<unsigned char> resultDigest(RIPEMD160_DIGEST_LENGTH);
    RIPEMD160(reinterpret_cast<const unsigned char*>(&digest[0]),
              digest.size(),
              reinterpret_cast<unsigned char*>(&resultDigest[0]));
    return resultDigest;
}


void BitcoinAddressTest::RunTests()
{
    std::cout << "Testing bitcoin address" << std::endl;

    std::string publicKey = "0450863AD64A87AE8A2FE83C1AF1A8403CB53F53E486D8511DAD8A04887E5B23522CD470243453A299FA9E77237716103ABC11A1DF38855ED6F2EE187E9C582BA6";

    // STEP 1

    auto publicKeyHash = SHA256(HexToBytes(publicKey));
    std::cout << "Step 1: SHA256 to public key\n" << BytesToHex(publicKeyHash) << std::endl;

    // STEP 2

    auto ripemdPublicKeyHash = RIPEMD160(publicKeyHash);
    std::cout << "Step 2: RIPEMD160 of Step 1\n" << BytesToHex(ripemdPublicKeyHash) << std::endl;

    // STEP 3

    ripemdPublicKeyHash.insert(ripemdPublicKeyHash.begin(), 0);
    std::cout << "Step 3: Add networking bytes 00 to Step 2\n" << BytesToHex(ripemdPublicKeyHash) << std::endl;

    // STEP 4

    auto firstChecksumHash = SHA256(ripemdPublicKeyHash);
    std::cout << "Step 4: SHA256 of Step 3\n" << BytesToHex(firstChecksumHash) << std::endl;

    // STEP 5

    auto secondCheckHash = SHA256(firstChecksumHash);
    std::cout << "Step 5: SHA256 of Step 4\n" << BytesToHex(secondCheckHash) << std::endl;

    // STEP 6

    ripemdPublicKeyHash.push_back(secondCheckHash[0]);
    ripemdPublicKeyHash.push_back(secondCheckHash[1]);
    ripemdPublicKeyHash.push_back(secondCheckHash[2]);
    ripemdPublicKeyHash.push_back(secondCheckHash[3]);

    std::cout << "Step 6: Add first 4 bytes of checksum from Step 5 to Step 3\n" << BytesToHex(ripemdPublicKeyHash) << std::endl;

    auto address = EncodeBase58(ripemdPublicKeyHash);

    // STEP 7

    std::cout << "Step 7: Address of Step 6\n" << address << std::endl;

    std::cout << "\n\n" << std::endl;
}
