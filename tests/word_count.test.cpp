#include <catch2/catch.hpp>
#include <word_count.h>

TEST_CASE("word_count")
{
    SECTION("return 0 when input is nullptr")
    {
        REQUIRE(word_count(nullptr) == 0);
    }

    SECTION("return 0 when input is empty string")
    {
        REQUIRE(word_count("") == 0);
    }

    SECTION("return word count that separated by space")
    {
        REQUIRE(word_count("Hello World") == 2);
        REQUIRE(word_count("Hello World From Cpp") == 4);
    }

    SECTION("ignore leading spaces")
    {
        REQUIRE(word_count("   Hello World") == 2);
    }

    SECTION("ignore trailing spaces")
    {
        REQUIRE(word_count("Hello World    ") == 2);
    }

    SECTION("ignore leading and trailing spaces when both exist")
    {
        REQUIRE(word_count("    Hello World    ") == 2);
    }

    SECTION("repeated spaces considered one")
    {
        REQUIRE(word_count("Hello      World") == 2);
    }

    SECTION("repeated spaces everywhere")
    {
        REQUIRE(word_count("      Hello      World      ") == 2);
    }

    SECTION("return 0 when input is just a space")
    {
        REQUIRE(word_count(" ") == 0);
    }

    SECTION("symbols are not word")
    {
        FAIL("todo");
    }
}
