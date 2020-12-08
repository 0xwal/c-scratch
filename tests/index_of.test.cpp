#include <catch2/catch.hpp>
#include <index_of.h>

TEST_CASE("index_of")
{
    SECTION("return -1 when haystack is nullptr")
    {
        REQUIRE(index_of(nullptr, "needle") == -1);
    }

    SECTION("return -1 when needle is nullptr")
    {
        REQUIRE(index_of("haystack", nullptr) == -1);
    }

    SECTION("return -1 when haystack is empty")
    {
        REQUIRE(index_of("", "needle") == -1);
    }

    SECTION("return -1 when needle is empty")
    {
        REQUIRE(index_of("haystack", "") == -1);
    }

    SECTION("return index of single char needle")
    {
        REQUIRE(index_of("haystack", "h") == 0);
        REQUIRE(index_of("haystack", "a") == 1);
        REQUIRE(index_of("haystack", "y") == 2);
        REQUIRE(index_of("haystack", "k") == 7);
    }

    SECTION("return index of multi char needle")
    {
        REQUIRE(index_of("haystack", "ac") == 5);
        REQUIRE(index_of("rarbrc", "rb") == 2);
        REQUIRE(index_of("robrori", "ri") == 5);
    }

    SECTION("return -1 when needle is longer than haystack")
    {
        REQUIRE(index_of("ac", "acr") == -1);
        REQUIRE(index_of("rarbrc", "rarbrccd") == -1);
    }

    SECTION("return -1 when there is no match")
    {
        REQUIRE(index_of("abcde", "efg") == -1);
        REQUIRE(index_of("decent", "rem") == -1);
    }

    SECTION("return the index of first match")
    {
        REQUIRE(index_of("sabcdabcd", "abcd") == 1);
        REQUIRE(index_of("queue", "ue") == 1);
    }
}
