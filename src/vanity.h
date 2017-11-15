
#pragma once

#include "helper.h"

namespace cosmyc {
class Vanity
{
public:
    static boost::multiprecision::uint256_t PatternComplexity(QString pattern);

    static double PatternLavishness(const uint64_t bounty,
                                    const boost::multiprecision::uint256_t pattern_compl);
};

} // namespace cosmyc
