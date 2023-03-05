#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include "../../../catch2/catch.hpp"
#include "../WordFrequency/Frequency.h"

TEST_CASE("ToLower function")
{
	SECTION("Empty string")
	{
		REQUIRE(ToLower("") == "");
	}

	SECTION("String with only uppercase letters")
	{
		REQUIRE(ToLower("HELLO") == "hello");
	}

	SECTION("String with only lowercase letters")
	{
		REQUIRE(ToLower("world") == "world");
	}

	SECTION("String with mixed uppercase and lowercase letters")
	{
		REQUIRE(ToLower("MixEdCaSe") == "mixedcase");
	}

	SECTION("String with non-letter characters")
	{
		REQUIRE(ToLower("123$%#") == "123$%#");
	}
}

TEST_CASE("CountWordFrequency function")
{
	SECTION("Empty input")
	{
		std::istringstream input("");
		auto result = CountWordFrequency(input);
		std::map<std::string, int> expected = {};
		REQUIRE(result == expected);
	}

	SECTION("Input with one word")
	{
		std::istringstream input("Hello");
		auto result = CountWordFrequency(input);
		std::map<std::string, int> expected = { {"hello", 1} };
		REQUIRE(result == expected);
	}

	SECTION("Input with multiple words")
	{
		std::istringstream input("Hello world hello");
		auto result = CountWordFrequency(input);
		std::map<std::string, int> expected = { {"hello", 2}, {"world", 1} };
		REQUIRE(result == expected);
	}

	SECTION("Input with mixed case words")
	{
		std::istringstream input("Hello World hELLO");
		auto result = CountWordFrequency(input);
		std::map<std::string, int> expected = { {"hello", 2}, {"world", 1} };
		REQUIRE(result == expected);
	}
}

TEST_CASE("PrintWordFrequency")
{
	std::stringstream ss;

	SECTION("PrintWordFrequency prints correct output for empty map")
	{
		std::map<std::string, int> frequency;
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintWordFrequency(frequency);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "");
	}

	SECTION("PrintWordFrequency prints correct output for non-empty map")
	{
		std::map<std::string, int> frequency = { {"apple", 3}, {"banana", 1}, {"orange", 2} };
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintWordFrequency(frequency);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "apple -> 3\nbanana -> 1\norange -> 2\n");
	}
}