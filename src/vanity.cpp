#include "vanity.h"


boost::multiprecision::uint256_t cosmyc::Vanity::PatternComplexity(QString pattern)
{
    boost::multiprecision::uint256_t res = 1;
    int index = 0;

    while(pattern[++index] == '1'
          && index <= pattern.size()) {
        res *= 256;
    }

    return res * helper::binPow(boost::multiprecision::uint256_t(58),
                                boost::multiprecision::uint256_t(pattern.size() - index)); // 58^m
}

double cosmyc::Vanity::PatternLavishness(const uint64_t bounty,
                                         const boost::multiprecision::uint256_t pattern_compl)
{
    // b - vanity address bounty (in Bitcoins)
    // c - vanity address complexity
    return 0x100000000 * (bounty / static_cast<double>(pattern_compl)); // 2^32 * (b/c)
}
