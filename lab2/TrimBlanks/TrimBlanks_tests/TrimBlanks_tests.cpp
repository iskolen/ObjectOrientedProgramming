#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include "../../../catch2/catch.hpp"
#include "../TrimBlanks/Trim.h"

TEST_CASE("Trim removes leading and trailing spaces")
{
	REQUIRE(Trim("  hello world  ") == "hello world");
	REQUIRE(Trim("     ") == "");
	REQUIRE(Trim("  onlyleading") == "onlyleading");
	REQUIRE(Trim("trailingonly  ") == "trailingonly");
}

TEST_CASE("Trim doesn't remove spaces inside the string")
{
	REQUIRE(Trim("  hello  world  ") == "hello  world");
}

TEST_CASE("Trim returns an empty string for empty input")
{
	REQUIRE(Trim("") == "");
}

TEST_CASE("Trim returns the input string if it doesn't contain leading or trailing spaces")
{
	REQUIRE(Trim("hello world") == "hello world");
}