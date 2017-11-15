#include "PrivateKeyTest.hpp"

#include <openssl/ssl.h>
#include <iostream>
#include <algorithm>

#include "base58.hpp"
#include "utils.hpp"

const u_int CHECKSUM_BYTES = 4;

std::vector<unsigned char> PrivateKeyTest::WifToPrivateKey(const std::string& wif)
{
    std::vector<unsigned char> key;
    DecodeBase58(wif, key);

    // drop last 4 checksum bytes
    key.erase(key.begin() + (key.size() - CHECKSUM_BYTES), key.end());

    // drop 1 network byte
    key.erase(key.begin());

    return key;
}

std::string PrivateKeyTest::PrivateKeyToWif(const std::vector<unsigned char>& privateKey)
{
    auto key = privateKey;

    // add networking byte
    key.insert(key.begin(), static_cast<unsigned char>('\x80'));

    // double-hashing
    auto firstKeyHash = utils::SHA256(key);
    auto secondKeyHash = utils::SHA256(firstKeyHash);

    // extract first 4 bytes (checksum) from hash
    std::vector<unsigned char> checksum;
    std::copy(secondKeyHash.begin(), secondKeyHash.begin() + CHECKSUM_BYTES, std::back_inserter(checksum));

    for(auto&& byte : checksum)
    {
        key.push_back(byte);
    }

    return EncodeBase58(key);
}

bool PrivateKeyTest::WifChecksumTest(const std::string& wif)
{
    std::vector<unsigned char> key;
    DecodeBase58(wif, key);

    // extract checksum for key and drop it
    std::vector<unsigned char> originalChecksum;
    std::copy(key.begin() + (key.size() - CHECKSUM_BYTES), key.end(), std::back_inserter(originalChecksum));
    key.erase(key.begin() + (key.size() - CHECKSUM_BYTES), key.end());

    // double-hashing
    auto firstKeyHash = utils::SHA256(key);
    auto secondKeyHash = utils::SHA256(firstKeyHash);

    // extract first 4 bytes (checksum) from hash
    std::vector<unsigned char> checksum;
    std::copy(secondKeyHash.begin(), secondKeyHash.begin() + CHECKSUM_BYTES, std::back_inserter(checksum));

    return checksum == originalChecksum;
}

void PrivateKeyTest::RunTests()
{
    auto key = WifToPrivateKey("5HueCGU8rMjxEXxiPuD5BDku4MkFqeZyd4dZ1jvhTVqvbTLvyTJ");
    std::cout << utils::BytesToHex(key) << std::endl;
    std::cout << PrivateKeyToWif(utils::HexToBytes("0C28FCA386C7A227600B2FE50B7CAE11EC86D3BF1FBE471BE89827E19D72AA1D")) << std::endl;
    std::cout << std::boolalpha << WifChecksumTest("5HueCGU8rMjxEXxiPuD5BDku4MkFqeZyd4dZ1jvhTVqvbTLvyTJ") << std::endl;
}
