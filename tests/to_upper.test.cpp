#include <catch2/catch.hpp>
#include <to_upper.h>

TEST_CASE("to_upper")
{
    SECTION("return nullptr for nullptr")
    {
        REQUIRE(to_upper(nullptr) == nullptr);
    }

    SECTION("upper all input")
    {
        char input[] = "hello";
        REQUIRE_THAT(to_upper(input), Catch::Equals("HELLO"));
    }

    SECTION("upper mixed")
    {
        char input[] = "hELLo";
        REQUIRE_THAT(to_upper(input), Catch::Equals("HELLO"));
    }

    SECTION("ignore space")
    {
        char input[] = "hello world";
        REQUIRE_THAT(to_upper(input), Catch::Equals("HELLO WORLD"));
    }

    SECTION("with digit")
    {
        char input[] = "hello 122";
        REQUIRE_THAT(to_upper(input), Catch::Equals("HELLO 122"));
    }

    SECTION("all letters")
    {
        char input[] = "abcdefghijklmnopqrstuvwxyz";
        REQUIRE_THAT(to_upper(input), Catch::Equals("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    }
}


TEST_CASE("to_upper_char")
{
    SECTION("do nothing to no alphabetic")
    {
        REQUIRE(to_upper_char('2') == '2');
    }

    SECTION("upper a letter")
    {
        char alphabetic_input[] = "abcdefghijklmnopqrstuvwxyz";
        char alphabetic_expected[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        for (int i = 0; i < sizeof(alphabetic_expected); ++i)
        {
            REQUIRE(to_upper_char(alphabetic_input[i]) == alphabetic_expected[i]);
        }

    }
}
