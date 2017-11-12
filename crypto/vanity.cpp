
#include <math.h>
#include <iostream>

#include "vanity.h"


namespace cosmyc {
namespace crypto {


double Vanity::PatternComplexity(const std::string & pattern)
{
    double res = 1;
    size_t index = 0;

    while(pattern[++index] == '1'
          && index <= pattern.size()) {
        res *= 256;
    }

    return res * pow(58.0, (double)(pattern.size() - index)); // 58^m
}

double Vanity::PatternLavishness(const uint64_t bounty, const double pattern_compl)
{
    // b - vanity address bounty (in Bitcoins)
    // c - vanity address complexity
    return 0x100000000 * (bounty / pattern_compl); // 2^32 * (b/c)
}


} // namespace crypto
} // namespace cosmyc
