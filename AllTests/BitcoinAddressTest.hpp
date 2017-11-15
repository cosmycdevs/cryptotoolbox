#ifndef BITCOINADDRESSTEST_HPP
#define BITCOINADDRESSTEST_HPP

#include <vector>
#include <string>

namespace BitcoinAddressTest
{
    auto HexToBytes(const std::string& key);
    auto BytesToHex(const std::vector<unsigned char>& bytes);
    void RunTests();
}

#endif // BITCOINADDRESSTEST_HPP
