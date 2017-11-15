#include "VanityAddressTest.hpp"

#include <iostream>
#include <limits>
#include <chrono>
#include <sstream>
#include <regex>

#include "base58.h"

using namespace boost::multiprecision;

const uint256_t Base = 58;
const u_int BITS = 8;
const u_int MAX_BYTES = 25;

// 2^192 / 2^160 (we remove 4-byte checksum)
const boost::uint64_t ChecksumBytes = 4294967296;

// 2^160 (all possible variants of 20-byte number)
const uint256_t MaxAmountOf20byteNumbers("1461501637330902918203684832716283019655932542976");

uint256_t VanityAddressTest::GetDecimalPattern(const std::string& stringPattern)
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

auto VanityAddressTest::FindRanges(uint256_t pattern, u_int maxBytes)
{
    uint256_t maxNumber, minNumber;
    maxNumber = boost::multiprecision::pow(uint256_t(2), BITS * maxBytes);
    minNumber = boost::multiprecision::pow(uint256_t(2), BITS * maxBytes - BITS);

    std::vector<std::pair<uint256_t, uint256_t>> ranges;
    uint256_t beginRange = 0, endRange = 0;
    uint16_t extent = 0;

    while(beginRange <= maxNumber && endRange <= maxNumber)
    {
        beginRange = pattern * boost::multiprecision::pow(Base, extent);
        endRange = (pattern + 1) * boost::multiprecision::pow(Base, extent) - 1;

        if(beginRange > minNumber && beginRange <= maxNumber &&
           endRange > minNumber && endRange <= maxNumber)
        {
            ranges.emplace_back(std::make_pair(beginRange, endRange));
        }
        ++extent;
    }

    return ranges;
}

uint256_t VanityAddressTest::GetComplexity(const std::string& pattern)
{
    std::smatch matches;
    if(std::regex_search(pattern, matches, std::regex("[^1]+")))
    {
        std::regex_search(pattern, matches, std::regex("[1]+"));
        uint256_t decimalPattern = GetDecimalPattern(pattern);
        auto ranges = FindRanges(decimalPattern, MAX_BYTES - matches[0].length());

        uint256_t result;
        // summing all variants that match our pattern
        for(auto&& pair : ranges)
        {
            result += pair.second - pair.first;
        }

        return MaxAmountOf20byteNumbers/(result/ChecksumBytes);
    }

    return boost::multiprecision::pow(uint256_t(256), static_cast<uint>(pattern.size() - 1));
}

uint256_t VanityAddressTest::GetLavishness(uint64_t bounty, uint256_t complexity)
{
    return ChecksumBytes * bounty / complexity;
}

void VanityAddressTest::RunTests()
{
    std::cout << "Testing vanity address" << std::endl;

    auto begin = std::chrono::system_clock::now();

    auto complexity = GetComplexity("1A");
    auto lavishness = GetLavishness(10, complexity);

    auto end = std::chrono::system_clock::now();

    std::cout << "Complexity: " << complexity << std::endl;
    std::cout << "Lavishness: " << lavishness << std::endl;
    std::cout << "Duration (microseconds): " << std::chrono::duration<double, std::micro>(end - begin).count() << std::endl;

    std::cout << "\n\n" << std::endl;
}
