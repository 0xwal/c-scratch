#include <catch2/catch.hpp>
#include <rc4.h>

TEST_CASE("rc4")
{
    SECTION("encrypt plain text with single char key")
    {
        char result[4] = { 0 };
        rc4("h", 1, "foo", 3, result);
        REQUIRE_THAT(result, Catch::Equals("\xc7\x22\xc7"));
    }

    SECTION("encrypt plain text with multiple chars key")
    {
        char result[4] = { 0 };
        const char key[] = "secret";
        size_t sizeOfKeyWithoutNull = sizeof(key) - 1;
        rc4(key, sizeOfKeyWithoutNull, "foo", 3, result);
        REQUIRE_THAT(result, Catch::Equals("\x8b\x59\xbd"));
    }

    SECTION("decrypt encrypted text with single char key")
    {
        char result[4] = { 0 };
        rc4("h", 1, "\xc7\x22\xc7", 3, result);
        REQUIRE_THAT(result, Catch::Equals("foo"));
    }

    SECTION("decrypt encrypted text with multiple char key")
    {
        char result[4] = { 0 };
        const char key[] = "secret";
        size_t sizeOfKeyWithoutNull = sizeof(key) - 1;
        rc4(key, sizeOfKeyWithoutNull, "\x8b\x59\xbd", 3, result);
        REQUIRE_THAT(result, Catch::Equals("foo"));
    }
}

