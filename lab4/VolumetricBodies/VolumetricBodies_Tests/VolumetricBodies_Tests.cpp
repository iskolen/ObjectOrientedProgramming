#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../VolumetricBodies/CBody.h"
#include "../VolumetricBodies/CCone.h"
#include "../VolumetricBodies/CController.h"
#include "../VolumetricBodies/CCylinder.h"
#include "../VolumetricBodies/CParallelepiped.h"
#include "../VolumetricBodies/CSolidBody.h"
#include "../VolumetricBodies/CSphere.h"
#include "../VolumetricBodies/stdafx.h"



TEST_CASE("Test CCone class")
{
	SECTION("Test GetVolume - correct")
	{
		double baseRadius = 2.0;
		double height = 3.0;
		double density = 1.0;
		double expectedVolume = M_PI * pow(baseRadius, 2) * (height / 3);

		CCone cone(baseRadius, height, density);
		REQUIRE(cone.GetVolume() == expectedVolume);
		std::cout << "Test CCone class (GetVolume - correct) - Completed" << std::endl;
	}

	SECTION("Test GetVolume - base radius equal zero")
	{
		double baseRadius = 0.0;
		double height = 3.0;
		double density = 1.0;
		double expectedVolume = M_PI * pow(baseRadius, 2) * (height / 3);

		CCone cone(baseRadius, height, density);
		REQUIRE(cone.GetVolume() == expectedVolume);
		std::cout << "Test CCone class (GetVolume - base radius equal zero) - Completed" << std::endl;
	}

	SECTION("Test GetVolume - height equal negative value")
	{
		double baseRadius = 0.0;
		double height = -3.0;
		double density = 1.0;
		double expectedVolume = M_PI * pow(baseRadius, 2) * (height / 3);

		CCone cone(baseRadius, height, density);
		REQUIRE(cone.GetVolume() == expectedVolume);
		std::cout << "Test CCone class (GetVolume - height equal negative value) - Completed" << std::endl;
	}

	SECTION("Test GetType")
	{
		double baseRadius = 2.0;
		double height = 3.0;
		double density = 1.0;
		std::string expectedType = "Конус";

		CCone cone(baseRadius, height, density);
		REQUIRE(cone.GetType() == expectedType);
		std::cout << "Test CCone class (GetType) - Completed" << std::endl;
	}

	SECTION("Test AppendProperties")
	{
		double baseRadius = 2.0;
		double height = 3.0;
		double density = 1.0;
		std::string expectedType = "Конус";

		CCone cone(baseRadius, height, density);
		REQUIRE(cone.ToString() == "Конус\nПлотность = 1\nОбъём = 12.56637061\nМасса = 12.56637061\nРадиус основания = 2\nВысота конуса = 3\n");
		std::cout << "Test CCone class (AppendProperties) - Completed" << std::endl << std::endl;
	}
}



TEST_CASE("Test CCylinder class")
{
	SECTION("Test GetVolume - correct")
	{
		double baseRadius = 3.0;
		double height = 1.0;
		double density = 1.0;
		double expectedVolume = M_PI * pow(baseRadius, 2) * height;

		CCylinder cylinder(baseRadius, height, density);
		REQUIRE(cylinder.GetVolume() == expectedVolume);
		std::cout << "Test CCylinder class (GetVolume - correct) - Completed" << std::endl;
	}

	SECTION("Test GetVolume - height equal zero")
	{
		double baseRadius = 3.0;
		double height = 0.0;
		double density = 5.0;
		double expectedVolume = M_PI * pow(baseRadius, 2) * height;

		CCylinder cylinder(baseRadius, height, density);
		REQUIRE(cylinder.GetVolume() == expectedVolume);
		std::cout << "Test CCylinder class (GetVolume - height equal zero) - Completed" << std::endl;
	}

	SECTION("Test GetVolume - height equal negative value")
	{
		double baseRadius = 3.0;
		double height = -1.0;
		double density = 2.0;
		double expectedVolume = M_PI * pow(baseRadius, 2) * height;

		CCylinder cylinder(baseRadius, height, density);
		REQUIRE(cylinder.GetVolume() == expectedVolume);
		std::cout << "Test CCylinder class (GetVolume - height equal negative value) - Completed" << std::endl;
	}

	SECTION("Test GetType")
	{
		double baseRadius = 3.0;
		double height = 1.0;
		double density = 1.0;
		std::string expectedType = "Цилиндр";

		CCylinder cylinder(baseRadius, height, density);
		REQUIRE(cylinder.GetType() == expectedType);
		std::cout << "Test CCylinder class (GetType) - Completed" << std::endl;
	}

	SECTION("Test AppendProperties")
	{
		double baseRadius = 3.0;
		double height = 1.0;
		double density = 1.0;
		std::string expectedType = "Цилиндр";

		CCylinder cylinder(baseRadius, height, density);
		REQUIRE(cylinder.ToString() == "Цилиндр\nПлотность = 1\nОбъём = 28.27433388\nМасса = 28.27433388\nРадиус основания = 3\nВысота цилиндра = 1\n");
		std::cout << "Test CCylinder class (AppendProperties) - Completed" << std::endl << std::endl;
	}
}



TEST_CASE("Test CParallelepiped class")
{
	SECTION("Test GetVolume - correct")
	{
		double width = 3.0;
		double height = 1.0;
		double depth = 4.0;
		double density = 1.0;
		double expectedVolume = width * height * depth;

		CParallelepiped parallelepiped(width, depth, height, density);
		REQUIRE(parallelepiped.GetVolume() == expectedVolume);
		std::cout << "Test CParallelepiped class (GetVolume - correct) - Completed" << std::endl;
	}

	SECTION("Test GetVolume - height and width equal zero")
	{
		double width = 0.0;
		double height = 0.0;
		double depth = 4.0;
		double density = 3.0;
		double expectedVolume = width * height * depth;

		CParallelepiped parallelepiped(width, depth, height, density);
		REQUIRE(parallelepiped.GetVolume() == expectedVolume);
		std::cout << "Test CParallelepiped class (GetVolume - height and width equal zero) - Completed" << std::endl;
	}

	SECTION("Test GetVolume - height equal negative value")
	{
		double width = 5.0;
		double height = -1.0;
		double depth = 4.0;
		double density = 3.0;
		double expectedVolume = width * height * depth;

		CParallelepiped parallelepiped(width, depth, height, density);
		REQUIRE(parallelepiped.GetVolume() == expectedVolume);
		std::cout << "Test CParallelepiped class (GetVolume - height equal negative value) - Completed" << std::endl;
	}

	SECTION("Test GetType")
	{
		double width = 3.0;
		double height = 1.0;
		double depth = 4.0;
		double density = 1.0;
		std::string expectedType = "Параллелепипед";

		CParallelepiped parallelepiped(width, depth, height, density);
		REQUIRE(parallelepiped.GetType() == expectedType);
		std::cout << "Test CParallelepiped class (GetType) - Completed" << std::endl;
	}

	SECTION("Test AppendProperties")
	{
		double width = 3.0;
		double height = 1.0;
		double depth = 4.0;
		double density = 1.0;
		std::string expectedType = "Параллелепипед";

		CParallelepiped parallelepiped(width, depth, height, density);
		REQUIRE(parallelepiped.ToString() == "Параллелепипед\nПлотность = 1\nОбъём = 12\nМасса = 12\nШирина параллелепипеда = 3\nДлина параллелепипеда = 4\nВысота параллелепипеда = 1\n");
		std::cout << "Test CParallelepiped class (AppendProperties) - Completed" << std::endl << std::endl;
	}
}



TEST_CASE("Test CSphere class")
{
	SECTION("Test GetVolume - correct")
	{
		double radius = 2.0;
		double density = 1.0;
		double expectedVolume = (4 / 3) * (M_PI * pow(radius, 3));

		CSphere sphere(radius, density);
		REQUIRE(sphere.GetVolume() == expectedVolume);
		std::cout << "Test CSphere class (GetVolume - correct) - Completed" << std::endl;
	}

	SECTION("Test GetVolume - radius equal zero")
	{
		double radius = 0.0;
		double density = 1.0;
		double expectedVolume = (4 / 3) * (M_PI * pow(radius, 3));

		CSphere sphere(radius, density);
		REQUIRE(sphere.GetVolume() == expectedVolume);
		std::cout << "Test CSphere class (GetVolume - radius equal zero) - Completed" << std::endl;
	}

	SECTION("Test GetVolume - radius equal negative value")
	{
		double radius = -9.0;
		double density = 1.0;
		double expectedVolume = (4 / 3) * (M_PI * pow(radius, 3));

		CSphere sphere(radius, density);
		REQUIRE(sphere.GetVolume() == expectedVolume);
		std::cout << "Test CSphere class (GetVolume - radius equal negative value) - Completed" << std::endl;
	}

	SECTION("Test GetType")
	{
		double radius = 2.0;
		double density = 1.0;
		std::string expectedType = "Сфера";

		CSphere sphere(radius, density);
		REQUIRE(sphere.GetType() == expectedType);
		std::cout << "Test CSphere class (GetType) - Completed" << std::endl;
	}

	SECTION("Test AppendProperties")
	{
		double radius = 2.0;
		double density = 1.0;
		std::string expectedType = "Сфера";

		CSphere sphere(radius, density);
		REQUIRE(sphere.ToString() == "Сфера\nПлотность = 1\nОбъём = 25.13274123\nМасса = 25.13274123\nРадиус = 2\n");
		std::cout << "Test CSphere class (AppendProperties) - Completed" << std::endl << std::endl;
	}
}