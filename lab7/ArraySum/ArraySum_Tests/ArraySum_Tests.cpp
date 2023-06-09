#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../ArraySum/ArraySum.h"

TEST_CASE("ArraySum - Empty vector")
{
	std::vector<int> emptyVectorInt;
	REQUIRE(ArraySum(emptyVectorInt) == 0);

	std::vector<double> emptyVectorDouble;
	REQUIRE(ArraySum(emptyVectorDouble) == 0.0);

	std::vector<std::string> emptyVectorString;
	REQUIRE(ArraySum(emptyVectorString) == "");

	std::cout << "ArraySum - Empty vector - Complete" << std::endl;
}

TEST_CASE("ArraySum - Integer vector")
{
	std::vector<int> vectorInt{ 1, 2, 3, 4, 5 };
	REQUIRE(ArraySum(vectorInt) == 15);

	std::vector<int> vectorIntNegative{ -1, -2, -3, -4, -5 };
	REQUIRE(ArraySum(vectorIntNegative) == -15);

	std::cout << "ArraySum - Integer vector - Complete" << std::endl;
}

TEST_CASE("ArraySum - Double vector")
{
	std::vector<double> vectorDouble{ 1.1, 2.2, 3.3, 4.4, 5.5 };
	REQUIRE(ArraySum(vectorDouble) == Approx(16.5));

	std::vector<double> vectorDoubleNegative{ -1.1, -2.2, -3.3, -4.4, -5.5 };
	REQUIRE(ArraySum(vectorDoubleNegative) == Approx(-16.5));

	std::cout << "ArraySum - Double vector - Complete" << std::endl;
}

TEST_CASE("ArraySum - String vector")
{
	std::vector<std::string> vectorString{ "Hello", " ", "World" };
	REQUIRE(ArraySum(vectorString) == "Hello World");

	std::vector<std::string> vectorStringLong{ "gh", " ", "fg", " ", "fgdfgdfgr", " ", "flgkdgdg", " ", "peorer" };
	REQUIRE(ArraySum(vectorStringLong) == "gh fg fgdfgdfgr flgkdgdg peorer");

	std::cout << "ArraySum - String vector - Complete" << std::endl;
}