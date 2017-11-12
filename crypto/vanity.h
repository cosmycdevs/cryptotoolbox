
#pragma once
#include <string>

#include "crypto_global.h"

namespace cosmyc {
namespace crypto {


class CRYPTOSHARED_EXPORT Vanity
{

public:

    double PatternComplexity(const std::string & pattern);

    double PatternLavishness(const uint64_t bounty, const double pattern_compl);

};


} // namespace crypto
} // namespace cosmyc
