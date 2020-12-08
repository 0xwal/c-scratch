#include <catch2/catch.hpp>
#include <parse_int.h>

TEST_CASE("parse_int")
{
    SECTION("return 0 when input is nullptr")
    {
        REQUIRE(parse_int(nullptr) == 0);
    }

    SECTION("return 0 when input is empty")
    {
        REQUIRE(parse_int("") == 0);
    }

    SECTION("return 0 when input is a space")
    {
        REQUIRE(parse_int(" ") == 0);
    }

    SECTION("return single digit number as int")
    {
        REQUIRE(parse_int("9") == 9);
        REQUIRE(parse_int("5") == 5);
        REQUIRE(parse_int("0") == 0);
    }

    SECTION("return two digits number as int")
    {
        REQUIRE(parse_int("10") == 10);
        REQUIRE(parse_int("15") == 15);
        REQUIRE(parse_int("20") == 20);
        REQUIRE(parse_int("99") == 99);
    }

    SECTION("return three digits number as int")
    {
        REQUIRE(parse_int("123") == 123);
        REQUIRE(parse_int("343") == 343);
        REQUIRE(parse_int("505") == 505);
        REQUIRE(parse_int("811") == 811);
        REQUIRE(parse_int("999") == 999);
    }

    SECTION("able to parse negative numbers")
    {
        REQUIRE(parse_int("-123") == -123);
        REQUIRE(parse_int("-343") == -343);
        REQUIRE(parse_int("-505") == -505);
        REQUIRE(parse_int("-811") == -811);
        REQUIRE(parse_int("-999") == -999);
    }

    SECTION("ignore leading spaces")
    {
        REQUIRE(parse_int("  123") == 123);
        REQUIRE(parse_int(" 343") == 343);
        REQUIRE(parse_int("  505") == 505);
    }


    SECTION("ignore tailing spaces")
    {
        REQUIRE(parse_int("123 ") == 123);
        REQUIRE(parse_int("343  ") == 343);
        REQUIRE(parse_int("505   ") == 505);
    }

    SECTION("ignore leading and trailing spaces")
    {
        REQUIRE(parse_int(" 123 ") == 123);
        REQUIRE(parse_int(" 343  ") == 343);
        REQUIRE(parse_int(" 505   ") == 505);
    }

    SECTION("return 0 when input starts with non-number")
    {
        REQUIRE(parse_int("u123") == 0);
        REQUIRE(parse_int("T123") == 0);
        REQUIRE(parse_int(":123") == 0);
    }
}

