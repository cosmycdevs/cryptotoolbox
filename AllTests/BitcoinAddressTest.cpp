#include "BitcoinAddressTest.hpp"
#include "utils.hpp"

#include <iostream>

void BitcoinAddressTest::RunTests()
{
    using namespace utils;

    std::cout << "Testing bitcoin address" << std::endl;

    std::string privateKey = "18E14A7B6A307F426A94F8114701E7C8E774E7F9A47E2C2035DB29A206321725";

    auto publicKey(utils::PrivateToPublic(privateKey, POINT_CONVERSION_UNCOMPRESSED));

    std::cout << "Private Key: " << privateKey << std::endl;
    std::cout << "Public Key: " << publicKey << std::endl;

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
