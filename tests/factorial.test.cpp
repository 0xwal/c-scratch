#include <catch2/catch.hpp>
#include <factorial.h>


TEST_CASE("factorial")
{
    SECTION("able to calculate")
    {
        REQUIRE(factorial(1) == 1);
        REQUIRE(factorial(2) == 2);
        REQUIRE(factorial(3) == 6);
        REQUIRE(factorial(7) == 5040);
        REQUIRE(factorial(10) == 3628800);
        REQUIRE(factorial(15) == 1307674368000);
    }

}

