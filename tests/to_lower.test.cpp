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

    SECTION("ignore space")
    {
        char input[] = "HellO World";
        REQUIRE_THAT(to_lower(input), Catch::Equals("hello world"));
    }

    SECTION("should not change non alphabetic char")
    {
        char input[] = "HellO 12345";
        REQUIRE_THAT(to_lower(input), Catch::Equals("hello 12345"));
    }

    SECTION("all alphabetic")
    {
        char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        REQUIRE_THAT(to_lower(input), Catch::Equals("abcdefghijklmnopqrstuvwxyz"));
    }
}

TEST_CASE("to_lower_char")
{
    SECTION("lower all letters")
    {
        char alphabetic_input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char alphabetic_expected[] = "abcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < sizeof(alphabetic_expected); ++i)
        {
            REQUIRE(to_lower_char(alphabetic_input[i]) == alphabetic_expected[i]);
        }
    }

    SECTION("ignore non alphabetic")
    {
        REQUIRE(to_lower_char('1') == '1');
    }


}

