#include <catch2/catch.hpp>
#include <pow.h>

TEST_CASE("pow")
{
    REQUIRE(s_pow(2, 2) == 4);
    REQUIRE(s_pow(2, 4) == 16);
    REQUIRE(s_pow(4, 8) == 65536);
    REQUIRE(s_pow(4, 12) == 16777216);
    REQUIRE(s_pow(0, 0) == 1);
    REQUIRE(s_pow(1, 1) == 1);
}
