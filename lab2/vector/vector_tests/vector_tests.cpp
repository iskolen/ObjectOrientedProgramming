#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include "../../../catch2/catch.hpp"
#include "../vector/Vector.h"

TEST_CASE("ReadVector function")
{
	SECTION("Reading empty vector") 
	{
		std::vector<double> numbers;
		std::stringstream input;
		REQUIRE(ReadVector(numbers, input) == numbers);
		REQUIRE(numbers.empty());
	}

	SECTION("Reading vector with one element") 
	{
		std::vector<double> numbers;
		std::stringstream input("1.23");
		REQUIRE(ReadVector(numbers, input) == numbers);
		REQUIRE(numbers.size() == 1);
		REQUIRE(numbers[0] == 1.23);
	}

	SECTION("Reading vector with multiple elements") 
	{
		std::vector<double> numbers;
		std::stringstream input("1.23 4.56 -7.89\n");
		REQUIRE(ReadVector(numbers, input) == numbers);
		REQUIRE(numbers.size() == 3);
	}
}

TEST_CASE("ProcessVector function")
{
	SECTION("ProcessVector returns a vector with the same size as input vector")
	{
		std::vector<double> input{ 1.0, 2.0, 3.0 };
		std::vector<double> result = ProcessVector(input);
		REQUIRE(result.size() == input.size());
	}

	SECTION("ProcessVector returns a vector with transformed values")
	{
		std::vector<double> input{ 1.0, 2.0, 3.0 };
		std::vector<double> expected{ input[0] * 3.0 / 1.0, input[1] * 3.0 / 1.0, input[2] * 3.0 / 1.0 };
		std::vector<double> result = ProcessVector(input);

		REQUIRE(result == expected);
	}
}

TEST_CASE("PrintVector function")
{
	std::stringstream ss;

	SECTION("PrintVector prints empty vector")
	{
		std::vector<double> numbers;
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintVector(numbers);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "");
	}

	SECTION("PrintVector prints single element vector")
	{
		std::vector<double> numbers{ 3.14 };
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintVector(numbers);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "3.14 ");
	}

	SECTION("PrintVector prints multiple element vector")
	{
		std::vector<double> numbers{ 1.0, 2.0, 3.0 };
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintVector(numbers);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "1 2 3 ");
	}
}

TEST_CASE("GetErrorCode function")
{
	SECTION("GetErrorCode returns 0 for vector with valid values")
	{
		std::vector<double> numbers{ 1.0, 2.0, 3.0 };
		int result = GetErrorCode(numbers);
		REQUIRE(result == 0);
	}

	SECTION("GetErrorCode returns 1 for empty vector")
	{
		std::vector<double> numbers;
		int result = GetErrorCode(numbers);
		REQUIRE(result == 1);
	}

	SECTION("GetErrorCode returns 2 for vector with minimum value of 0")
	{
		std::vector<double> numbers{ 0.0, 1.0, 2.0 };
		int result = GetErrorCode(numbers);
		REQUIRE(result == 2);
	}
}