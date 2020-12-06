#include <catch2/catch.hpp>
#include <string_length.h>

TEST_CASE("string_length")
{
    SECTION("return 0 for empty string")
    {
        REQUIRE(string_length("") == 0);
    }
}

