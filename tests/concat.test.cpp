#include <catch2/catch.hpp>
#include <concat.h>

#define del(p) delete p

TEST_CASE("concat")
{
    char* out = nullptr;

    SECTION("able to concat strings")
    {
        const char* input1[] = { "a", "b", nullptr };
        const char* input2[] = { "a", "b", "c", nullptr };
        REQUIRE_THAT(out = concat(input1, nullptr), Catch::Equals("ab"));
        del(out);
        REQUIRE_THAT(out = concat(input2, nullptr), Catch::Equals("abc"));
        del(out);
    }

    SECTION("able to concat strings with separator")
    {
        const char* input1[] = { "a", "b", nullptr };
        const char* input2[] = { "a", "b", "c", nullptr };

        REQUIRE_THAT(out = concat(input1, ","), Catch::Equals("a,b"));
        del(out);
        REQUIRE_THAT(out = concat(input2, ":"), Catch::Equals("a:b:c"));
        del(out);
        REQUIRE_THAT(out = concat(input2, " "), Catch::Equals("a b c"));
        del(out);
        REQUIRE_THAT(out = concat(input2, "<>"), Catch::Equals("a<>b<>c"));
        del(out);
    }

    SECTION("able to return empty string if input is empty")
    {
        REQUIRE(concat(nullptr, ",") == nullptr);
    }

    SECTION("should able to handle lengthy items")
    {
        const char* input[] = {
                "aliquam etiam erat velit scelerisque in dictum non consectetur a erat nam at lectus urna duis convallis convallis tellus id",
                "aliquam etiam erat velit scelerisque in dictum non consectetur a erat nam at lectus urna duis convallis convallis tellus id",
                nullptr
        };
        REQUIRE_THAT(out = concat(input, ","), Catch::Equals(
                "aliquam etiam erat velit scelerisque in dictum non consectetur a erat nam at lectus urna duis convallis convallis tellus id,aliquam etiam erat velit scelerisque in dictum non consectetur a erat nam at lectus urna duis convallis convallis tellus id"));
        del(out);
    }


}
