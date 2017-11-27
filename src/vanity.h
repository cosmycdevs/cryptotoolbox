
#pragma once

#include "helper.h"

namespace cosmyc
{


class Vanity
{
public:
    static double PatternComplexity(const QString &pattern);

    static double PatternLavishness(const uint64_t bounty, const double pattern_compl);
};


} // namespace cosmyc
