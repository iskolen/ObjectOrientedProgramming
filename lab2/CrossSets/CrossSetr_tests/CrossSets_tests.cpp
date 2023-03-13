#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include <algorithm>
#include "../../../catch2/catch.hpp"
#include "../CrossSets/SetsHandler.h"

const int ERROR_NO_PARAMETER = -1;
const int ERROR_NEGATIVE = -2;
const int ERROR_NOT_DIGIT = -3;

TEST_CASE("SumOfDigits function")
{
	SECTION("Sum of digits of a single-digit number is the number itself")
	{
		REQUIRE(SumOfDigits(5) == 5);
		std::cout << "Sum of digits of a single-digit number is the number itself - Completed" << std::endl;
	}

	SECTION("Sum of digits of a multi-digit number is calculated correctly")
	{
		REQUIRE(SumOfDigits(12345) == 15);
		REQUIRE(SumOfDigits(987654321) == 45);
		std::cout << "Sum of digits of a multi-digit number is calculated correctly - Completed" << std::endl;
	}

	SECTION("Sum of digits of zero is zero")
	{
		REQUIRE(SumOfDigits(0) == 0);
		std::cout << "Sum of digits of zero is zero - Completed" << std::endl;
	}
	std::cout << std::endl;
}

TEST_CASE("GetErrorCode function")
{
	char programName[] = "CrossSets.exe";
	SECTION("When parameter is provided, function returns no error code and sets n to the correct value")
	{
		int argc = 2;
		char correctDigit[] = "123";
		char* argv[2] = { programName, correctDigit };
		int n = 0;
		int errorCode = GetErrorCode(argc, argv, n);
		REQUIRE(errorCode == 0);
		REQUIRE(n == 123);

		std::cout << "When parameter is provided, function returns no error code and sets n to the correct value - Completed";
	}

	SECTION("When no parameter is provided, function returns ERROR_NO_PARAMETER")
	{
		int argc = 1;
		char* argv[1] = { programName };
		int n = 0;
		int errorCode = GetErrorCode(argc, argv, n);
		REQUIRE(errorCode == ERROR_NO_PARAMETER);

		std::cout << "When no parameter is provided, function returns ERROR_NO_PARAMETER - Completed";
	}

	SECTION("When parameter is negative, function returns ERROR_NEGATIVE")
	{
		int argc = 2;
		char negativeDigit[] = "-123";
		char* argv[2] = { programName, negativeDigit };
		int n = 0;
		int errorCode = GetErrorCode(argc, argv, n);
		REQUIRE(errorCode == ERROR_NEGATIVE);

		std::cout << "When parameter is negative, function returns ERROR_NEGATIVE - Completed";
	}

	SECTION("When parameter is not a digit, function returns ERROR_NOT_DIGIT")
	{
		int argc = 2;
		char string[] = "abc";
		char* argv[2] = { programName, string };
		int n = 0;
		int errorCode = GetErrorCode(argc, argv, n);
		REQUIRE(errorCode == ERROR_NOT_DIGIT);

		std::cout << "When parameter is not a digit, function returns ERROR_NOT_DIGIT - Completed";
	}

	SECTION("When parameter is a mix of digits and non-digits, function returns ERROR_NOT_DIGIT")
	{
		int argc = 2;
		char mix[] = "123abc";
		char* argv[2] = { programName, mix };
		int n = 0;
		int errorCode = GetErrorCode(argc, argv, n);
		REQUIRE(errorCode == ERROR_NOT_DIGIT);

		std::cout << "When parameter is a mix of digits and non-digits, function returns ERROR_NOT_DIGIT - Completed";
	}

	std::cout << std::endl << std::endl;
}

TEST_CASE("ReadFirstSet function")
{
	SECTION("ReadFirstSet - n = 10")
	{
		std::set<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		std::set<int> result = ReadFirstSet(10);
		REQUIRE(result == expected);
		std::cout << "ReadFirstSet - n = 10 - Completed" << std::endl;
	}

	SECTION("ReadFirstSet - n = 20")
	{
		std::set<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 18, 20 };
		std::set<int> result = ReadFirstSet(20);
		REQUIRE(result == expected);
		std::cout << "ReadFirstSet - n = 20 - Completed" << std::endl;
	}
	std::cout << std::endl;
}

TEST_CASE("ReadSecondSet function")
{
	SECTION("ReadSecondSet - n = 10")
	{
		std::set<int> expected = { 2, 4, 6, 8 };
		std::set<int> result = ReadSecondSet(10);
		REQUIRE(result == expected);
		std::cout << "ReadSecondSet - n = 10 - Completed" << std::endl;
	}

	SECTION("ReadSecondSet - n = 20")
	{
		std::set<int> expected = { 2, 4, 6, 8, 11, 13, 15, 17, 19, 20 };
		std::set<int> result = ReadSecondSet(20);
		REQUIRE(result == expected);
		std::cout << "ReadSecondSet - n = 20 - Completed" << std::endl;
	}
	std::cout << std::endl;
}

TEST_CASE("CrossSet function")
{
	std::set<int> set1 = { 1, 2, 3, 4, 5 };
	std::set<int> set2 = { 4, 5, 6, 7, 8 };
	std::set<int> emptySet;
	SECTION("Intersection of set1 and set2")
	{
		std::set<int> expected = { 4, 5 };
		std::set<int> result = CrossSet(set1, set2);
		REQUIRE(result == expected);
		std::cout << "Intersection of set1 and set2 - Completed" << std::endl;
	}

	SECTION("Intersection of set2 and set1")
	{
		std::set<int> expected = { 4, 5 };
		std::set<int> result = CrossSet(set2, set1);
		REQUIRE(result == expected);
		std::cout << "Intersection of set2 and set1 - Completed" << std::endl;
	}

	SECTION("Intersection of set1 and empty set")
	{
		std::set<int> expected = {};
		std::set<int> result = CrossSet(set1, emptySet);
		REQUIRE(result == expected);
		std::cout << "Intersection of set1 and empty set - Completed" << std::endl;
	}

	SECTION("Intersection of empty set and set2")
	{
		std::set<int> expected = {};
		std::set<int> result = CrossSet(emptySet, set2);
		REQUIRE(result == expected);
		std::cout << "Intersection of empty set and set2 - Completed" << std::endl;
	}

	SECTION("Intersection of two empty sets")
	{
		std::set<int> expected = {};
		std::set<int> result = CrossSet(emptySet, emptySet);
		REQUIRE(result == expected);
		std::cout << "Intersection of two empty sets - Completed" << std::endl;
	}

	std::cout << std::endl;
}

TEST_CASE("PrintSets function")
{
	std::set<int> set1 = { 1, 2, 3 };
	std::set<int> set2 = { 2, 3, 4 };
	std::set<int> emptySet;
	std::stringstream ss;

	SECTION("Prints sets and their intersection")
	{
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintSets(set1, set2);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "Set 1: 1 2 3 \nSet 2: 2 3 4 \nIntersection: 2 3 ");
		std::cout << "Prints sets and their intersection - Completed" << std::endl;
	}

	SECTION("Prints empty sets and empty intersection")
	{
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintSets(emptySet, emptySet);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "Set 1: \nSet 2: \nIntersection: ");
		std::cout << "Prints empty sets and empty intersection - Completed" << std::endl;
	}

	SECTION("Prints set1 and empty set2")
	{
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintSets(set1, emptySet);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "Set 1: 1 2 3 \nSet 2: \nIntersection: ");
		std::cout << "Prints set1 and empty set2 - Completed" << std::endl;
	}

	SECTION("Prints empty set1 and set2")
	{
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintSets(emptySet, set2);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "Set 1: \nSet 2: 2 3 4 \nIntersection: ");
		std::cout << "Prints empty set1 and set2 - Completed" << std::endl;
	}
	std::cout << std::endl;
}
