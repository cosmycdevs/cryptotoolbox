#ifndef PRIVATEKEYTEST_HPP
#define PRIVATEKEYTEST_HPP

#include <vector>
#include <string>

namespace PrivateKeyTest
{
    std::string PrivateKeyToWif(const std::vector<unsigned char>& privateKey);
    std::vector<unsigned char> WifToPrivateKey(const std::string& wif);
    bool WifChecksumTest(const std::string& wif);
    void RunTests();
}


#endif // PRIVATEKEYTEST_HPP
