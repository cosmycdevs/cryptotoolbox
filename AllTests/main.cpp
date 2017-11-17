#include <iostream>

#include "BitcoinAddressTest.hpp"
#include "VanityAddressTest.hpp"
#include "PrivateKeyTest.hpp"
#include "VanitySumTests.hpp"
#include "VanityMultiplicationTest.hpp"

int main()
{
    BitcoinAddressTest::RunTests();
    VanityAddressTest::RunTests();
    PrivateKeyTest::RunTests();
    VanitySumTest::RunTests();
    VanityMultiplicationTest::RunTests();

    return 0;
}
