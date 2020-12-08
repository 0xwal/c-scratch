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

    SECTION("able to parse hex when input prefixed with 0x")
    {
        REQUIRE(parse_int("0x9") == 0x9);
        REQUIRE(parse_int("0x88") == 0x88);
        REQUIRE(parse_int("0x999") == 0x999);
        REQUIRE(parse_int("0x4422") == 0x4422);
        REQUIRE(parse_int("0x4422F") == 0x4422F);
        REQUIRE(parse_int("0x1E60") == 0x1E60);
        REQUIRE(parse_int("0x1acf") == 0x1ACF);
        REQUIRE(parse_int("0xbeef") == 0xBEEF);
    }

    SECTION("return valid numbers before any non-number when the hex number not prefixed with 0x")
    {
        REQUIRE(parse_int("1FF") == 1);
        REQUIRE(parse_int("12E1") == 12);
        REQUIRE(parse_int("3F") == 3);
        REQUIRE(parse_int("123EFC") == 123);
    }

    SECTION("return 0 when input is 0x")
    {
        REQUIRE(parse_int("0x") == 0);
    }

    SECTION("able to parse binary number")
    {
        REQUIRE(parse_int("0b1") == 0b1);
        REQUIRE(parse_int("0b101") == 0b101);
        REQUIRE(parse_int("0b0101011") == 0b0101011);
        REQUIRE(parse_int("0b01010000") == 0b01010000);
        REQUIRE(parse_int("0b111111111") == 0b111111111);
    }

    SECTION("return calculated valid numbers only and stop calculating on invalid digits")
    {
        REQUIRE(parse_int("0b") == 0);
        REQUIRE(parse_int("0b12") == 1);
        REQUIRE(parse_int("0b1013") == 0b101);
        REQUIRE(parse_int("0b51013") == 0b0);
    }
}

