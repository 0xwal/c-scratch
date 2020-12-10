#include <catch2/catch.hpp>
#include <power.h>

TEST_CASE("power")
{
    SECTION("when base number is 0 retunr 0")
    {
        REQUIRE(power(0, 3) == 0);
    }

    SECTION("calculate")
    {
        REQUIRE(power(1, 3) == 1);
        REQUIRE(power(2, 4) == 16);
        REQUIRE(power(4, 8) == 65536);
        REQUIRE(power(5, 6) == 15625);

        REQUIRE(power(10, 8) == 100000000);
        REQUIRE(power(15, 6) == 11390625);
        REQUIRE(power(6.5, 8) == 3186448.12890625);

        REQUIRE(power(5, 0) == 1);
        REQUIRE(power(1, 2147483647) == 1);
    }

    SECTION("calculate when exponent is negative")
    {
        REQUIRE(power(2, -2) == 0.25);
        REQUIRE(power(2, -2147483648) == 0);
//        REQUIRE(power(8.95371, -1) == 0.11169); TODO:: supports
    }
}
