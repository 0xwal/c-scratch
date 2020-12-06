#include <catch2/catch.hpp>
#include <word_count.h>

TEST_CASE("words_count")
{
    SECTION("return 0 when input is nullptr")
    {
        REQUIRE(words_count(nullptr) == 0);
    }

    SECTION("return 0 when input is empty string")
    {
        REQUIRE(words_count("") == 0);
    }

    SECTION("return word count that separated by space")
    {
        REQUIRE(words_count("Hello World") == 2);
        REQUIRE(words_count("Hello World From Cpp") == 4);
    }

    SECTION("ignore leading spaces")
    {
        REQUIRE(words_count("   Hello World") == 2);
    }

    SECTION("ignore trailing spaces")
    {
        REQUIRE(words_count("Hello World    ") == 2);
    }

    SECTION("ignore leading and trailing spaces when both exist")
    {
        REQUIRE(words_count("    Hello World    ") == 2);
    }

    SECTION("repeated spaces considered one")
    {
        REQUIRE(words_count("Hello      World") == 2);
    }

    SECTION("repeated spaces everywhere")
    {
        REQUIRE(words_count("      Hello      World      ") == 2);
    }

    SECTION("return 0 when input is just a space")
    {
        REQUIRE(words_count(" ") == 0);
    }

    SECTION("symbols are not word")
    {
        FAIL("todo");
    }
}
