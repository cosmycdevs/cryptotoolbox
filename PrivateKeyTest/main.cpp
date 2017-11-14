#include <openssl/ssl.h>
#include <openssl/ripemd.h>

#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

auto HexToBytes(const std::string& key)
{
    std::stringstream ss;
    for(size_t i = 0; i != key.size(); i += 2)
    {
        char* end;
        long d = std::strtol(key.substr(i, 2).c_str(), &end, 16);
        ss << static_cast<unsigned char>(d);
    }

    return ss.str();
}

auto BytesToHex(const std::vector<unsigned char>& bytes)
{
    std::stringstream ss;
    for(auto&& byte : bytes)
    {
        ss << std::hex << std::setfill('0') << std::setw(2) << (int)byte;
    }

    return ss.str();
}

int main()
{
    std::vector<unsigned char> digest(SHA256_DIGEST_LENGTH);
    std::string publicKey = "0450863AD64A87AE8A2FE83C1AF1A8403CB53F53E486D8511DAD8A04887E5B23522CD470243453A299FA9E77237716103ABC11A1DF38855ED6F2EE187E9C582BA6";

    // STEP 1

    auto hash = HexToBytes(publicKey);
    SHA256((unsigned char*)hash.c_str(), hash.size(), (unsigned char*)&digest[0]);
    std::cout << BytesToHex(digest) << std::endl;

    // STEP 2

    std::vector<unsigned char> digest2(RIPEMD160_DIGEST_LENGTH);
    RIPEMD160((unsigned char*)&digest[0], digest.size(), (unsigned char*)&digest2[0]);
    std::cout << BytesToHex(digest2) << std::endl;

    // STEP 3

    digest2.insert(digest2.begin(), 0);
    std::vector<unsigned char> digest3(SHA256_DIGEST_LENGTH);
    SHA256((unsigned char*)&digest2[0], digest2.size(), (unsigned char*)&digest3[0]);
    std::cout << BytesToHex(digest3) << std::endl;

    // STEP 4

    std::vector<unsigned char> digest4(SHA256_DIGEST_LENGTH);
    SHA256((unsigned char*)&digest3[0], digest3.size(), (unsigned char*)&digest4[0]);

    std::cout << BytesToHex(digest4) << std::endl;

    // STEP 5

    digest2.push_back(digest4[0]);
    digest2.push_back(digest4[1]);
    digest2.push_back(digest4[2]);
    digest2.push_back(digest4[3]);

    std::cout << BytesToHex(digest2) << std::endl;



    return 0;
}
