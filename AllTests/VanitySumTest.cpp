#include "VanitySumTests.hpp"
#include "utils.hpp"

#include <iostream>
#include <openssl/ec.h>
#include <openssl/ssl.h>

void VanitySumTest::RunTests()
{
    std::cout << "Testing vanity addresses sum" << std::endl;

    std::string firstPrivateKey = "18E14A7B6A307F426A94F8114701E7C8E774E7F9A47E2C2035DB29A206321725";
    std::string secondPrivateKey = "B18427B169E86DE681A1A62588E1D02AE4A7E83C1B413849989A76282A7B562F";

    std::cout << "Private key 1: " << firstPrivateKey << std::endl;
    std::cout << "Private key 2: " << secondPrivateKey << std::endl;

    std::string firstPublicKey = utils::PrivateToPublic(firstPrivateKey, POINT_CONVERSION_UNCOMPRESSED);
    std::string secondPublicKey = utils::PrivateToPublic(secondPrivateKey, POINT_CONVERSION_UNCOMPRESSED);

    std::cout << "Public key 1: " << firstPublicKey << std::endl;
    std::cout << "Public key 2: " << secondPublicKey << std::endl;

    auto result = utils::AddPrivateKeys(firstPrivateKey, secondPrivateKey);
    std::cout << std::endl << "Sum of private keys: " << result << std::endl;
    auto publicKeyFromPrivate = utils::PrivateToPublic(result, POINT_CONVERSION_UNCOMPRESSED);
    std::cout << std::endl << "Public key from the sum of private keys: " << publicKeyFromPrivate << std::endl;
    std::cout << std::endl << "Corresponding address: " << utils::PublicToBitcoinAddress(publicKeyFromPrivate) << std::endl;

//    EC_KEY* key = EC_KEY_new_by_curve_name(NID_secp256k1);
//    BN_CTX* ctx = BN_CTX_new();

//    auto group = EC_KEY_get0_group(key);
//    auto publicKeyPoint = EC_POINT_new(group);

//    EC_POINT_free(publicKeyPoint);
//    EC_KEY_free(key);

    std::cout << "\n\n" << std::endl;
}
