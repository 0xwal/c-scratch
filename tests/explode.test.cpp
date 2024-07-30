//
// Created by 0xWaleed on 11/8/2021.
//

#include <catch2/catch.hpp>
#include <explode.h>

using Catch::Matchers::Equals;

TEST_CASE("explode") {
  SECTION("should returns ->count of exploded elements") {
    auto r = explode_make("Hello-World", '-');
    REQUIRE(r.count == 2);
    explode_clean(&r);
  }

  SECTION("should returns ->values with all content") {
    auto r = explode_make("This is a text for a test", ' ');
    REQUIRE(r.count == 7);
    REQUIRE_THAT(r.values[0], Equals("This"));
    REQUIRE_THAT(r.values[1], Equals("is"));
    REQUIRE_THAT(r.values[2], Equals("a"));
    REQUIRE_THAT(r.values[3], Equals("text"));
    REQUIRE_THAT(r.values[4], Equals("for"));
    REQUIRE_THAT(r.values[5], Equals("a"));
    REQUIRE_THAT(r.values[6], Equals("test"));
    REQUIRE(r.values[7] == NULL);
    explode_clean(&r);
  }

  SECTION("should returns ->count as 0 when character is not found") {
    auto r = explode_make("Hello-World", '*');
    REQUIRE(r.count == 0);
    explode_clean(&r);
  }

  SECTION("should returns ->values as char** for each value between the "
          "character") {
    auto r = explode_make("Hello-World", '-');
    REQUIRE_THAT(r.values[0], Catch::Equals("Hello"));
    REQUIRE_THAT(r.values[1], Catch::Equals("World"));
    explode_clean(&r);
  }
}
