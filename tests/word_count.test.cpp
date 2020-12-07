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

    SECTION("return words count that separated by space")
    {
        REQUIRE(words_count("Hello World") == 2);
        REQUIRE(words_count("Hello World From Cpp") == 4);
    }

    SECTION("return words count for all capital letters")
    {
        REQUIRE(words_count("HELLO WORLD") == 2);
    }

    SECTION("ignore leading spaces")
    {
        REQUIRE(words_count(" Hello World") == 2);
        REQUIRE(words_count("   Hello World") == 2);
    }

    SECTION("ignore trailing spaces")
    {
        REQUIRE(words_count("Hello World    ") == 2);
        REQUIRE(words_count("Hello World ") == 2);
    }

    SECTION("ignore leading and trailing spaces")
    {
        REQUIRE(words_count("    Hello World    ") == 2);
        REQUIRE(words_count(" Hello World ") == 2);
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

    SECTION("any non alphabetic is not a word")
    {
        REQUIRE(words_count("> Hello World !") == 2);
        REQUIRE(words_count("> Hello :) World !") == 2);
        REQUIRE(words_count("> Hello :) World I miss you, 1337 !") == 5);
    }
}
