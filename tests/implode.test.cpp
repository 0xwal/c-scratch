#include <catch2/catch.hpp>
#include <implode.h>

TEST_CASE("implode_make") {
  SECTION("can implode_make an array to a string #1") {
    const char *input[] = {"abc", "def", NULL};
    const char *r = implode_make(input, ",");
    REQUIRE(r != NULL);
    REQUIRE_THAT(r, Catch::Matchers::Equals("abc,def"));
    implode_clean(r);
  }

  SECTION("can implode_make an array to a string with different length") {
    const char *input[] = {"1234", "12", "1", "12345", NULL};
    const char *r = implode_make(input, ",");
    REQUIRE(r != NULL);
    REQUIRE_THAT(r, Catch::Matchers::Equals("1234,12,1,12345"));
    implode_clean(r);
  }

  SECTION("can implode_make an array to a string with separator that has "
          "multiple chars") {
    const char *input[] = {"1234", "12", "1", "12345", NULL};
    const char *r = implode_make(input, "|===| ");
    REQUIRE(r != NULL);
    REQUIRE_THAT(r, Catch::Matchers::Equals("1234|===| 12|===| 1|===| 12345"));
    implode_clean(r);
  }

  SECTION("can implode_make to a string with no seperator") {
    const char *input[] = {"1234", "12", "1", "12345", NULL};
    const char *r = implode_make(input, NULL);
    REQUIRE(r != NULL);
    REQUIRE_THAT(r, Catch::Matchers::Equals("123412112345"));
    implode_clean(r);
  }

  SECTION("returns NULL when input is NULLL") {
    const char *r = implode_make(NULL, ",");
    REQUIRE(r == NULL);
    implode_clean(r);
  }
}
