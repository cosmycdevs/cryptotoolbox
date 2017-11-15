#include <iostream>

#include "BitcoinAddressTest.hpp"
#include "VanityAddressTest.hpp"

int main()
{
    BitcoinAddressTest::RunTests();
    VanityAddressTest::RunTests();
    return 0;
}
