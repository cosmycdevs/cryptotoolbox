
#pragma once

#include "helper.h"

namespace cosmyc
{


class Vanity
{
public:
    static const double PatternComplexity(const QString &pattern);

    static const double PatternLavishness(const uint64_t bounty, const double pattern_compl);
};


} // namespace cosmyc
