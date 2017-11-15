#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>

namespace utils
{
    std::vector<unsigned char> HexToBytes(const std::string& key);
    std::string BytesToHex(const std::vector<unsigned char>& bytes);
    std::vector<unsigned char> SHA256(const std::vector<unsigned char>& digest);
    std::vector<unsigned char> RIPEMD160(const std::vector<unsigned char>& digest);
}

#endif // UTILS_HPP
