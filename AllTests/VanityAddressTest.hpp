#ifndef VANITYADDRESSTEST_HPP
#define VANITYADDRESSTEST_HPP

#include <boost/multiprecision/cpp_int.hpp>

namespace VanityAddressTest
{
    boost::multiprecision::uint256_t GetDecimalPattern(const std::string& stringPattern);
    auto FindRanges(boost::multiprecision::uint256_t pattern, u_int maxBytes);
    boost::multiprecision::uint256_t GetComplexity(const std::string& pattern);
    boost::multiprecision::uint256_t GetLavishness(uint64_t bounty,
                                                   boost::multiprecision::uint256_t complexity);
    void RunTests();
}

#endif // VANITYADDRESSTEST_HPP
