#include "../third_party/doctest.h"
#include "ResultParser.hpp"

TEST_CASE("Parser - #01")
{
    long int result = ResultParser::GetLast8Digits(123456789);
    CHECK(result == 23456789);
}

TEST_CASE("Parser - #02")
{
    long int result = ResultParser::GetLast8Digits(1234567890);
    CHECK(result == 34567890);
}

TEST_CASE("Parser - #03")
{
    long int result = ResultParser::GetLast8Digits(12345678901);
    CHECK(result == 45678901);
}

TEST_CASE("Parser - #04")
{
    long int result = ResultParser::GetLast8Digits(123456789012);
    CHECK(result == 56789012);
}

TEST_CASE("Parser - #05")
{
    long int result = ResultParser::GetLast8Digits(8975721234567890123);
    CHECK(result == 67890123);
}