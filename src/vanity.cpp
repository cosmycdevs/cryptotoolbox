
#include <math.h>
#include "vanity.h"


const double cosmyc::Vanity::PatternComplexity(const QString pattern)
{
    double res = 1;
    int index = 0;

    while(pattern[++index] == '1'
          && index <= pattern.size()) {
        res *= 256;
    }

    return res * pow(double(58), double(pattern.size() - index)); // 58^m
}

const double cosmyc::Vanity::PatternLavishness(const uint64_t bounty, const double pattern_compl)
{
    // b - vanity address bounty (in Bitcoins)
    // c - vanity address complexity
    return 0x100000000 * (bounty / pattern_compl); // 2^32 * (b/c)
}
