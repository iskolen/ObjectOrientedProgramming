#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../Time/CTime.h"

TEST_CASE("CTime constructor - Hours, minutes, seconds")
{
	SECTION("Valid time")
	{
		CTime time(10, 30, 45);
		REQUIRE(time.GetHours() == 10);
		REQUIRE(time.GetMinutes() == 30);
		REQUIRE(time.GetSeconds() == 45);
	}

	SECTION("Invalid time")
	{
		REQUIRE_THROWS_AS(CTime(25, 0, 0), std::invalid_argument);
		REQUIRE_THROWS_WITH(CTime(25, 0, 0), ERROR_TIME_NOT_CORRECT);
		REQUIRE_THROWS_AS(CTime(0, 60, 0), std::invalid_argument);
		REQUIRE_THROWS_WITH(CTime(0, 60, 0), ERROR_TIME_NOT_CORRECT);
		REQUIRE_THROWS_AS(CTime(0, 0, 60), std::invalid_argument);
		REQUIRE_THROWS_WITH(CTime(0, 0, 60), ERROR_TIME_NOT_CORRECT);
		REQUIRE_THROWS_AS(CTime(25, 60, 60), std::invalid_argument);
		REQUIRE_THROWS_WITH(CTime(25, 60, 60), ERROR_TIME_NOT_CORRECT);
		std::cout << "CTime constructor - Hours, minutes, seconds - Complete" << std::endl;
	}
}

TEST_CASE("CTime constructor - Seconds after midnight")
{
	SECTION("Valid time")
	{
		CTime time(37845);
		REQUIRE(time.GetHours() == 10);
		REQUIRE(time.GetMinutes() == 30);
		REQUIRE(time.GetSeconds() == 45);
	}

	SECTION("Invalid time")
	{
		REQUIRE_THROWS_AS(CTime(MAX_SECONDS_IN_DAY + 1), std::invalid_argument);
		REQUIRE_THROWS_WITH(CTime(MAX_SECONDS_IN_DAY + 1), ERROR_TIME_NOT_CORRECT);
		std::cout << "CTime constructor - Seconds after midnight - Complete" << std::endl;
	}
}


TEST_CASE("GetHours")
{
	SECTION("Get hours from valid time")
	{
		CTime time(10, 30, 45);
		REQUIRE(time.GetHours() == 10);
	}

	SECTION("Get hours from zero time")
	{
		CTime time(0);
		REQUIRE(time.GetHours() == 0);
	}

	SECTION("Get hours from maximum time")
	{
		CTime time(MAX_SECONDS_IN_DAY);
		REQUIRE(time.GetHours() == HOURS_IN_DAY - 1);
		std::cout << "GetHours - Complete" << std::endl;
	}
}

TEST_CASE("GetMinutes")
{
	SECTION("Get minutes from 0 seconds")
	{
		CTime time(0);
		REQUIRE(time.GetMinutes() == 0);
	}

	SECTION("Get minutes from 60 seconds")
	{
		CTime time(60);
		REQUIRE(time.GetMinutes() == 1);
	}

	SECTION("Get minutes from 3600 seconds")
	{
		CTime time(3600);
		REQUIRE(time.GetMinutes() == 0);
	}

	SECTION("Get minutes from 3723 seconds")
	{
		CTime time(3723);
		REQUIRE(time.GetMinutes() == 2);
		std::cout << "GetMinutes - Complete" << std::endl;
	}
}

TEST_CASE("GetSeconds")
{
	SECTION("Get seconds from non-zero seconds")
	{
		CTime time(0, 0, 45);
		REQUIRE(time.GetSeconds() == 45);
	}

	SECTION("Get seconds from 0 seconds")
	{
		CTime time(10, 30, 0);
		REQUIRE(time.GetSeconds() == 0);
		std::cout << "GetSeconds - Complete" << std::endl;
	}
}

TEST_CASE("operator++ - prefix")
{
	SECTION("Increment at the beginning")
	{
		CTime time(0);
		REQUIRE(time.GetHours() == 0);
		REQUIRE(time.GetMinutes() == 0);
		REQUIRE(time.GetSeconds() == 0);

		++time;

		REQUIRE(time.GetHours() == 0);
		REQUIRE(time.GetMinutes() == 0);
		REQUIRE(time.GetSeconds() == 1);
	}

	SECTION("Increment in the middle")
	{
		CTime time(3720);
		REQUIRE(time.GetHours() == 1);
		REQUIRE(time.GetMinutes() == 2);
		REQUIRE(time.GetSeconds() == 0);

		++time;

		REQUIRE(time.GetHours() == 1);
		REQUIRE(time.GetMinutes() == 2);
		REQUIRE(time.GetSeconds() == 1);
	}

	SECTION("Increment at the end")
	{
		CTime time(MAX_SECONDS_IN_DAY);
		REQUIRE(time.GetHours() == 23);
		REQUIRE(time.GetMinutes() == 59);
		REQUIRE(time.GetSeconds() == 59);

		++time;

		REQUIRE(time.GetHours() == 0);
		REQUIRE(time.GetMinutes() == 0);
		REQUIRE(time.GetSeconds() == 0);
		std::cout << "operator++ - prefix - Complete" << std::endl;
	}
}


TEST_CASE("operator++ - postfix")
{
	SECTION("Increment at the beginning")
	{
		CTime time(0);
		REQUIRE(time.GetSeconds() == 0);
		REQUIRE(time.GetMinutes() == 0);
		REQUIRE(time.GetHours() == 0);

		CTime oldTime = time++;
		REQUIRE(oldTime.GetSeconds() == 0);
		REQUIRE(oldTime.GetMinutes() == 0);
		REQUIRE(oldTime.GetHours() == 0);

		REQUIRE(time.GetSeconds() == 1);
		REQUIRE(time.GetMinutes() == 0);
		REQUIRE(time.GetHours() == 0);
	}

	SECTION("Increment at the end")
	{
		CTime time(86399);
		REQUIRE(time.GetSeconds() == 59);
		REQUIRE(time.GetMinutes() == 59);
		REQUIRE(time.GetHours() == 23);

		CTime oldTime = time++;
		REQUIRE(oldTime.GetSeconds() == 59);
		REQUIRE(oldTime.GetMinutes() == 59);
		REQUIRE(oldTime.GetHours() == 23);

		REQUIRE(time.GetSeconds() == 0);
		REQUIRE(time.GetMinutes() == 0);
		REQUIRE(time.GetHours() == 0);
		std::cout << "operator++ - postfix - Complete" << std::endl;
	}
}

TEST_CASE("operator-- - prefix")
{
	SECTION("Decrement at the beginning")
	{
		CTime time(0);
		--time;
		REQUIRE(time.GetHours() == 23);
		REQUIRE(time.GetMinutes() == 59);
		REQUIRE(time.GetSeconds() == 59);
	}

	SECTION("Decrement in the middle")
	{
		CTime time(3600);
		--time;
		REQUIRE(time.GetHours() == 0);
		REQUIRE(time.GetMinutes() == 59);
		REQUIRE(time.GetSeconds() == 59);
		std::cout << "operator-- - prefix - Complete" << std::endl;
	}
}

TEST_CASE("operator-- - postfix")
{
	SECTION("Decrement at the beginning")
	{
		CTime time(0);
		REQUIRE(time.GetSeconds() == 0);
		REQUIRE(time.GetMinutes() == 0);
		REQUIRE(time.GetHours() == 0);

		CTime oldTime = time--;
		REQUIRE(oldTime.GetSeconds() == 0);
		REQUIRE(oldTime.GetMinutes() == 0);
		REQUIRE(oldTime.GetHours() == 0);

		REQUIRE(time.GetSeconds() == 59);
		REQUIRE(time.GetMinutes() == 59);
		REQUIRE(time.GetHours() == 23);
	}

	SECTION("Decrement at the end")
	{
		CTime time(86399);
		REQUIRE(time.GetSeconds() == 59);
		REQUIRE(time.GetMinutes() == 59);
		REQUIRE(time.GetHours() == 23);

		CTime oldTime = time--;
		REQUIRE(oldTime.GetSeconds() == 59);
		REQUIRE(oldTime.GetMinutes() == 59);
		REQUIRE(oldTime.GetHours() == 23);

		REQUIRE(time.GetSeconds() == 58);
		REQUIRE(time.GetMinutes() == 59);
		REQUIRE(time.GetHours() == 23);
		std::cout << "operator-- - postfix - Complete" << std::endl;
	}
}

TEST_CASE("operator+")
{
	SECTION("Add two times within the same day")
	{
		CTime time1(60);
		CTime time2(120);
		CTime expected(180);
		CTime result = time1 + time2;
		REQUIRE(result.GetHours() == expected.GetHours());
		REQUIRE(result.GetMinutes() == expected.GetMinutes());
		REQUIRE(result.GetSeconds() == expected.GetSeconds());
	}

	SECTION("Add two times that cross midnight")
	{
		CTime time1(86340);
		CTime time2(120);
		CTime expected(60);
		CTime result = time1 + time2;
		REQUIRE(result.GetHours() == expected.GetHours());
		REQUIRE(result.GetMinutes() == expected.GetMinutes());
		REQUIRE(result.GetSeconds() == expected.GetSeconds());
		std::cout << "operator+ - Complete" << std::endl;
	}
}

TEST_CASE("operator-")
{
	SECTION("Subtracting the lesser from the greater")
	{
		CTime time1(3600);
		CTime time2(1800);
		CTime result = time1 - time2;
		REQUIRE(result.GetHours() == 0);
		REQUIRE(result.GetMinutes() == 30);
		REQUIRE(result.GetSeconds() == 0);
	}

	SECTION("Subtracting more from less")
	{
		CTime time1(3600);
		CTime time2(1800);
		CTime result = time2 - time1;
		REQUIRE(result.GetHours() == 23);
		REQUIRE(result.GetMinutes() == 30);
		REQUIRE(result.GetSeconds() == 0);
	}

	SECTION("Subtracting the same time")
	{
		CTime time1(3600);
		CTime time2(1800);
		CTime result = time1 - time1;
		REQUIRE(result.GetHours() == 0);
		REQUIRE(result.GetMinutes() == 0);
		REQUIRE(result.GetSeconds() == 0);
		std::cout << "operator- - Complete" << std::endl;
	}
}

TEST_CASE("operator+=")
{
	SECTION("Adding in the middle")
	{
		CTime time1(3600);
		CTime time2(1800);

		time1 += time2;
		REQUIRE(time1.GetHours() == 1);
		REQUIRE(time1.GetMinutes() == 30);
		REQUIRE(time1.GetSeconds() == 0);
	}

	SECTION("Adding up at midnight")
	{
		CTime time3(MAX_SECONDS_IN_DAY);
		CTime time4(1);
		time3 += time4;
		REQUIRE(time3.GetHours() == 0);
		REQUIRE(time3.GetMinutes() == 0);
		REQUIRE(time3.GetSeconds() == 0);
		std::cout << "operator+= - Complete" << std::endl;
	}
}

TEST_CASE("operator-=")
{
	SECTION("Subtraction in the middle")
	{
		CTime time1(3600);
		CTime time2(1800);

		time1 -= time2;
		REQUIRE(time1.GetHours() == 0);
		REQUIRE(time1.GetMinutes() == 30);
		REQUIRE(time1.GetSeconds() == 0);
	}

	SECTION("Subtraction at midnight")
	{
		CTime time3(0);
		CTime time4(1);
		time3 -= time4;
		REQUIRE(time3.GetHours() == 23);
		REQUIRE(time3.GetMinutes() == 59);
		REQUIRE(time3.GetSeconds() == 59);
		std::cout << "operator-= - Complete" << std::endl;
	}
}

TEST_CASE("operator*")
{
	SECTION("Multiplication in range")
	{
		CTime time(19815);
		CTime result = time * 2;
		REQUIRE(result.GetHours() == 11);
		REQUIRE(result.GetMinutes() == 0);
		REQUIRE(result.GetSeconds() == 30);
	}

	SECTION("Multiplication over a range")
	{
		CTime time(19815);
		CTime result = time * 5;
		REQUIRE(result.GetHours() == 3);
		REQUIRE(result.GetMinutes() == 31);
		REQUIRE(result.GetSeconds() == 15);
	}

	SECTION("Multiplication by zero")
	{
		CTime time(19815);
		CTime result = time * 0;
		REQUIRE(result.GetHours() == 0);
		REQUIRE(result.GetMinutes() == 0);
		REQUIRE(result.GetSeconds() == 0);
		std::cout << "operator*= - Complete" << std::endl;
	}
}

TEST_CASE("Operator* with integer as left operand")
{
	SECTION("Multiplication in range")
	{
		CTime time(19815);
		CTime result = 2 * time;
		REQUIRE(result.GetHours() == 11);
		REQUIRE(result.GetMinutes() == 0);
		REQUIRE(result.GetSeconds() == 30);
	}

	SECTION("Multiplication over a range")
	{
		CTime time(19815);
		CTime result = 5 * time;
		REQUIRE(result.GetHours() == 3);
		REQUIRE(result.GetMinutes() == 31);
		REQUIRE(result.GetSeconds() == 15);
	}

	SECTION("Multiplication by zero")
	{
		CTime time(19815);
		CTime result = 0 * time;
		REQUIRE(result.GetHours() == 0);
		REQUIRE(result.GetMinutes() == 0);
		REQUIRE(result.GetSeconds() == 0);
		std::cout << "operator* - Complete" << std::endl;
	}
}

TEST_CASE("operator/") 
{

	SECTION("Valid division") 
	{
		CTime time1(3600);
		CTime time2(1800);
		CTime result(0);
		result = time1 / 2;
		REQUIRE(result == time2);
		REQUIRE((time1 / time2) == 2);
	}

	SECTION("Dividing by zero throws an exception") 
	{
		CTime time(3600);
		CTime timeZero(0);
		REQUIRE_THROWS_AS(time / timeZero, std::invalid_argument);
		REQUIRE_THROWS_WITH(time / timeZero, ERROR_TIME_ZERO);
		std::cout << "operator/ - Complete" << std::endl;
	}
}

TEST_CASE("operator*=")
{
	SECTION("Multiplication")
	{
		CTime time(10, 0, 0);
		time *= 3;
		REQUIRE(time.GetHours() == 6);
		REQUIRE(time.GetMinutes() == 0);
		REQUIRE(time.GetSeconds() == 0);
	}

	SECTION("Multiplication with zero")
	{
		CTime time(10, 0, 0);
		time *= 0;
		REQUIRE(time.GetHours() == 0);
		REQUIRE(time.GetMinutes() == 0);
		REQUIRE(time.GetSeconds() == 0);
		std::cout << "operator*= - Complete" << std::endl;
	}
}

TEST_CASE("operator/=")
{
	SECTION("Valid division")
	{
		CTime time(3600);
		CTime result(1800);
		time /= 2;
		REQUIRE(time == result);
	}

	SECTION("Dividing by zero throws an exception")
	{
		CTime time(3600);
		REQUIRE_THROWS_AS(time /= 0, std::invalid_argument);
		REQUIRE_THROWS_WITH(time /= 0, ERROR_TIME_ZERO);
		std::cout << "operator/= - Complete" << std::endl;
	}
}

TEST_CASE("operator<<")
{
	SECTION("Valid output - 1")
	{
		CTime time(10, 30, 45);
		std::ostringstream oss;
		oss << time;
		REQUIRE(oss.str() == "10:30:45");
	}

	SECTION("Valid output - 2")
	{
		CTime time(121);
		std::ostringstream oss;
		oss << time;
		REQUIRE(oss.str() == "00:02:01");
		std::cout << "operator<< - Complete" << std::endl;
	}
}

TEST_CASE("operator>>")
{
	SECTION("Valid input")
	{
		CTime time;
		std::istringstream input("01:23:45");
		input >> time;
		REQUIRE(time == CTime(1, 23, 45));
	}

	SECTION("Invalid input")
	{
		CTime time;
		std::istringstream input("asd");
		REQUIRE_THROWS_AS(input >> time, std::invalid_argument);
		std::cout << "operator>> - Complete" << std::endl;
	}
}

TEST_CASE("comparison operators")
{
	CTime time1(1, 10, 30);
	CTime time2(1, 30, 10);
	CTime time3(2, 10, 30);

	SECTION("operator== returns true for equal times")
	{
		REQUIRE(time1 == time1);
		REQUIRE_FALSE(time1 == time3);
	}

	SECTION("operator!= returns true for unequal times")
	{
		REQUIRE_FALSE(time2 != time2);
		REQUIRE(time2 != time3);
	}

	SECTION("operator< returns true for earlier times")
	{
		REQUIRE_FALSE(time1 < time1);
		REQUIRE(time2 < time3);
		REQUIRE_FALSE(time3 < time3);
	}

	SECTION("operator> returns true for later times")
	{
		REQUIRE_FALSE(time1 > time3);
		REQUIRE(time2 > time1);
		REQUIRE(time3 > time2);
	}

	SECTION("operator<= returns true for earlier or equal times")
	{
		REQUIRE(time1 <= time3);
		REQUIRE_FALSE(time2 <= time1);
		REQUIRE(time3 <= time3);
	}

	SECTION("operator>= returns true for later or equal times")
	{
		REQUIRE(time1 >= time1);
		REQUIRE_FALSE(time2 >= time3);
		REQUIRE(time3 >= time3);
		std::cout << "comparison operators - Complete" << std::endl;
	}
}
