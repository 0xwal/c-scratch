#include <catch2/catch.hpp>
#include <xor.h>

TEST_CASE("xor")
{
    SECTION("when input is nullptr return nullptr")
    {
        REQUIRE(xor_encrypt(nullptr, 'k') == nullptr);
    }

    SECTION("able to encrypt input")
    {
        char sample[][7] = {"sample", "sample", "sample"};
        REQUIRE_THAT(xor_encrypt(sample[0], 'k'), Catch::Equals("\x18\x0A\x06\x1B\x07\x0E"));
        REQUIRE_THAT(xor_encrypt(sample[1], 'B'), Catch::Equals("\x31\x23\x2f\x32\x2e\x27"));
        REQUIRE_THAT(xor_encrypt(sample[2], '\xFF'), Catch::Equals("\x8c\x9e\x92\x8f\x93\x9a"));
    }
}
