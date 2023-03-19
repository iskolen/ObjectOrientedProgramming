#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../TV/CTVSet.h"

TEST_CASE("TV can be turned on and off")
{
	CTVSet tv;
	REQUIRE(tv.IsTurnedOn() == false);
	tv.TurnOn();
	REQUIRE(tv.IsTurnedOn() == true);
	tv.TurnOff();
	REQUIRE(tv.IsTurnedOn() == false);
	std::cout << "TV can be turned on and off - Completed" << std::endl;
}

TEST_CASE("TV selects a valid channel")
{
	CTVSet tv;
	tv.TurnOn();
	REQUIRE(tv.SelectChannel(50) == true);
	REQUIRE(tv.GetChannel() == 50);
	std::cout << std::endl << "TV selects a valid channel - Completed" << std::endl;
}

TEST_CASE("TV does not select an invalid channel")
{
	CTVSet tv;
	tv.TurnOn();
	REQUIRE(tv.SelectChannel(0) == false);
	REQUIRE(tv.SelectChannel(100) == false);
	REQUIRE(tv.GetChannel() == 1);
	std::cout << std::endl << "TV does not select an invalid channel - Completed" << std::endl;
}

TEST_CASE("Select channel when TV set is turned off and then on")
{
	CTVSet tv;
	tv.SelectChannel(5);
	tv.TurnOn();
	REQUIRE(tv.GetChannel() == 1);
	std::cout << std::endl << "Select channel when TV set is turned off and then on - Completed" << std::endl;
}

TEST_CASE("TV remembers the selected channel when turned off and on again")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(50);
	tv.TurnOff();
	tv.TurnOn();
	REQUIRE(tv.GetChannel() == 50);
	std::cout << std::endl << "TV remembers the selected channel when turned off and on again - Completed" << std::endl;
}