#include <catch2/catch.hpp>
#include <joaat.h>


TEST_CASE("joaat")
{
    SECTION("compute the hash of the string")
    {
        REQUIRE(joaat("adder") == 0xB779A091);
        REQUIRE(joaat("Adder") == 0x2153F8FD);
        REQUIRE(joaat("F") == 0xFE39FC60);
        REQUIRE(joaat("0xWaleed") == 0x6F07A88);
    }

    SECTION("return 0 when input is nullptr")
    {
        REQUIRE(joaat(nullptr) == 0);
    }
}
