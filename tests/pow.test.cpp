#include <catch2/catch.hpp>
#include <pow.h>

TEST_CASE("pow")
{
    REQUIRE(pow(2, 2) == 4);
    REQUIRE(pow(2, 4) == 16);
    REQUIRE(pow(4, 8) == 65536);
    REQUIRE(pow(4, 12) == 16777216);
    REQUIRE(pow(0, 0) == 1);
    REQUIRE(pow(1, 1) == 1);
}
