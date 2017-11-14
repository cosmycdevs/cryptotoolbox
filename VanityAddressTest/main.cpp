#include <iostream>
#include <limits>
#include <chrono>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>

#include "base58.h"

using namespace boost::multiprecision;

// base58
const uint256_t Base = 58;

// maximum 24-byte number
const uint256_t Max24ByteNumber("6277101735386680763835789423207666416102355444464034512895");

// minimum 24-byte number
const uint256_t Min24ByteNumber("24519928653854221733733552434404946937899825954937634816");

// 2^192 / 2^160 (we remove 4-byte checksum)
const boost::uint64_t ChecksumBytes = 4294967296;

// 2^160 (all possible variant of 20-byte number)
const uint256_t MaxAmountOf20byteNumbers("1461501637330902918203684832716283019655932542976");

uint256_t GetDecimalPattern(const std::string& stringPattern)
{
    uint256_t pattern;
    std::stringstream ss;
    std::vector<unsigned char> res;
    DecodeBase58(stringPattern.c_str(), res);
    for(auto&& c : res)
    {
        ss << std::hex << static_cast<short>(c);
    }
    ss >> pattern;
    return pattern;
}

auto FindRanges(uint256_t pattern)
{
    std::vector<std::pair<uint256_t, uint256_t>> ranges;
    uint256_t beginRange = 0, endRange = 0;
    uint16_t extent = 0;

    while(beginRange <= Max24ByteNumber && endRange <= Max24ByteNumber) // until we reach 25-byte number
    {
        beginRange = pattern * boost::multiprecision::pow(Base, extent);
        endRange = (pattern + 1) * boost::multiprecision::pow(Base, extent) - 1;

        if(beginRange >= Min24ByteNumber && beginRange <= Max24ByteNumber &&
           endRange >= Min24ByteNumber && endRange <= Max24ByteNumber)
        {
            ranges.emplace_back(std::make_pair(beginRange, endRange));
        }
        ++extent;
    }

    return ranges;
}

uint64_t GetComplexity(uint256_t pattern)
{
    auto ranges = FindRanges(pattern);

    uint256_t result;
    // summing all variants that match our pattern
    for(auto&& pair : ranges)
    {
        result += pair.second - pair.first;
    }

    return static_cast<uint64_t>(MaxAmountOf20byteNumbers/(result/ChecksumBytes));
}

long double GetLavishness(long double bounty, uint64_t complexity)
{
    return std::exp2(32.0L) * bounty / complexity;
}

int main()
{
    auto begin = std::chrono::system_clock::now();

    auto complexity = GetComplexity(GetDecimalPattern("1A"));
    auto lavishness = GetLavishness(10, complexity);

    auto end = std::chrono::system_clock::now();

    std::cout << "Complexity: " << complexity << std::endl;
    std::cout << "Lavishness: " << lavishness << std::endl;
    std::cout << "Duration (microseconds): " << std::chrono::duration<double, std::micro>(end - begin).count() << std::endl;
    return 0;
}
