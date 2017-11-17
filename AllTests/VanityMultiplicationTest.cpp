#include "VanityMultiplicationTest.hpp"
#include "utils.hpp"

#include <iostream>
#include <openssl/bn.h>

void VanityMultiplicationTest::RunTests()
{
    std::cout << "Testing vanity addresses muultiplication" << std::endl;

    std::string firstPrivateKey = "8D358EDA964A16786CF4089268881C52370FCB34426F56602BE0DE39FBE49E49";
    std::string secondPrivateKey = "1B4019E609EB8EBDA9F7260B305D456831FC706B942268C2D4017BBA92953414";

    std::cout << "Private key 1: " << firstPrivateKey << std::endl;
    std::cout << "Private key 2: " << secondPrivateKey << std::endl;

    std::string firstPublicKey = utils::PrivateToPublic(firstPrivateKey, POINT_CONVERSION_UNCOMPRESSED);
    std::string secondPublicKey = utils::PrivateToPublic(secondPrivateKey, POINT_CONVERSION_UNCOMPRESSED);

    std::cout << "Public key 1: " << firstPublicKey << std::endl;
    std::cout << "Public key 2: " << secondPublicKey << std::endl;

    auto result = utils::MultiplyPrivateKeys(firstPrivateKey, secondPrivateKey);
    std::cout << std::endl << "Multiplication of private keys: " << result << std::endl;
    auto publicKeyFromPrivate = utils::PrivateToPublic(result, POINT_CONVERSION_UNCOMPRESSED);
    std::cout << std::endl << "Public key from the multiplication of private keys: " << publicKeyFromPrivate << std::endl;
    std::cout << std::endl << "Corresponding address: " << utils::PublicToBitcoinAddress(publicKeyFromPrivate) << std::endl;

    std::cout << "\n\n" << std::endl;
}
