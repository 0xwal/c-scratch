//
// Created by 0xWaleed on 11/8/2021.
//

#include <catch2/catch.hpp>
#include <explode.h>

TEST_CASE("explode")
{
    SECTION("should returns ->count of exploded elements")
    {
        auto r = explode_make("Hello-World", '-');
        REQUIRE(r.count == 2);
        explode_clean(&r);
    }

    SECTION("should returns ->count as 0 when character is not found")
    {
        auto r = explode_make("Hello-World", '*');
        REQUIRE(r.count == 0);
        explode_clean(&r);
    }

    SECTION("should returns ->values as char** for each value between the character")
    {
        auto r = explode_make("Hello-World", '-');
        REQUIRE_THAT(r.values[0], Catch::Equals("Hello"));
        REQUIRE_THAT(r.values[1], Catch::Equals("World"));
        explode_clean(&r);
    }
}
