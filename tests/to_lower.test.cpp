#include <catch2/catch.hpp>
#include <to_lower.h>

TEST_CASE("to_lower")
{
    SECTION("return nullptr when providing nullptr")
    {
        REQUIRE(to_lower(nullptr) == nullptr);
    }

    SECTION("preserve the lower case string")
    {
        char input[] = "hello";
        REQUIRE_THAT(to_lower(input), Catch::Equals("hello"));
    }

    SECTION("should lower the string")
    {
        char input[] = "HELLO";
        REQUIRE_THAT(to_lower(input), Catch::Equals("hello"));
    }

    SECTION("lower mixed latter cases")
    {
        char input[] = "HellO";
        REQUIRE_THAT(to_lower(input), Catch::Equals("hello"));
    }
}

TEST_CASE("to_lower_char")
{
    SECTION("return lower letter")
    {
        REQUIRE(to_lower_char('A') == 'a');
    }
}

