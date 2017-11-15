#include <iostream>

#include "BitcoinAddressTest.hpp"
#include "VanityAddressTest.hpp"
#include "PrivateKeyTest.hpp"

int main()
{
    BitcoinAddressTest::RunTests();
    VanityAddressTest::RunTests();
    PrivateKeyTest::RunTests();
    return 0;
}
