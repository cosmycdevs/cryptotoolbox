#include "BitcoinAddressTest.hpp"

#include "base58.hpp"
#include "utils.hpp"

#include <iostream>


void BitcoinAddressTest::RunTests()
{
    using namespace utils;

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

    auto secondChecksumHash = SHA256(firstChecksumHash);
    std::cout << "Step 5: SHA256 of Step 4\n" << BytesToHex(secondChecksumHash) << std::endl;

    // STEP 6

    ripemdPublicKeyHash.push_back(secondChecksumHash[0]);
    ripemdPublicKeyHash.push_back(secondChecksumHash[1]);
    ripemdPublicKeyHash.push_back(secondChecksumHash[2]);
    ripemdPublicKeyHash.push_back(secondChecksumHash[3]);

    std::cout << "Step 6: Add first 4 bytes of checksum from Step 5 to Step 3\n" << BytesToHex(ripemdPublicKeyHash) << std::endl;

    auto address = EncodeBase58(ripemdPublicKeyHash);

    // STEP 7

    std::cout << "Step 7: Address of Step 6\n" << address << std::endl;

    std::cout << "\n\n" << std::endl;
}
