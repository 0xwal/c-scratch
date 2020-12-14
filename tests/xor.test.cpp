#include <catch2/catch.hpp>
#include <xor.h>

TEST_CASE("xor")
{
    SECTION("when input is nullptr return nullptr")
    {
        REQUIRE(xor_encrypt(nullptr, "k") == nullptr);
    }

    SECTION("able to encrypt input")
    {
        char sample[][7] = { "sample", "sample", "sample", "sample" };
        REQUIRE_THAT(xor_encrypt(sample[0], "k"), Catch::Equals("\x18\x0A\x06\x1B\x07\x0E"));
        REQUIRE_THAT(xor_encrypt(sample[1], "B"), Catch::Equals("\x31\x23\x2f\x32\x2e\x27"));
        REQUIRE_THAT(xor_encrypt(sample[2], "\xFF"), Catch::Equals("\x8c\x9e\x92\x8f\x93\x9a"));
        REQUIRE_THAT(xor_encrypt(sample[3], "hello"), Catch::Equals("\x1b\x04\x01\x1c\x03\x0d"));
    }

    SECTION("return the value with xoring if key and value are same")
    {
        char sample[] = "sample";
        REQUIRE_THAT(xor_encrypt(sample, "secret"), Catch::Equals("\x73\x04\x0e\x02\x09\x11"));
    }

    SECTION("able to decrypt")
    {
        char sample[][7] = { "\x18\x0A\x06\x1B\x07\x0E", "\x31\x23\x2f\x32\x2e\x27", "\x8c\x9e\x92\x8f\x93\x9a", "\x73\x04\x0e\x02\x09\x11" };
        REQUIRE_THAT(xor_decrypt(sample[0], "k"), Catch::Equals("sample"));
        REQUIRE_THAT(xor_decrypt(sample[1],"B"), Catch::Equals("sample"));
        REQUIRE_THAT(xor_decrypt(sample[2], "\xFF"), Catch::Equals("sample"));
        REQUIRE_THAT(xor_decrypt(sample[3], "secret"), Catch::Equals("sample"));
    }
}
