#include <catch2/catch.hpp>
#include <string_length.h>

TEST_CASE("string_length")
{
    SECTION("return 0 for empty string")
    {
        REQUIRE(string_length("") == 0);
    }

    SECTION("return length of given string")
    {
        const char input[] = "Hello World";
        size_t sizeWithoutNullTerminator = sizeof(input) - 1;
        REQUIRE(string_length(input) == sizeWithoutNullTerminator);
    }

    SECTION("return 0 when providing nullptr")
    {
        REQUIRE(string_length(nullptr) == 0);
    }
}

