//
// Created on 7/10/21.
//

#include <catch2/catch.hpp>
#include <end_with.h>


TEST_CASE("end_with")
{
    REQUIRE(end_with("abc", "c") == true);
    REQUIRE(end_with("abc", "bc") == true);
    REQUIRE(end_with("abc", "a") == false);
    REQUIRE(end_with("abc", "") == true);
    REQUIRE(end_with("abc", "abcd") == false);
}
