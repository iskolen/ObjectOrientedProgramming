#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "CBody.h"
#include "CSolidBody.h"
#include "CSphere.h"
#include "CParallelepiped.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CCompound.h"

const char RUSSIAN_LANGUAGE[8] = "Russian";
const char LINE_BREAK = '\n';

const int TYPE_BODY_SHPERE = 1;
const int TYPE_BODY_PARALLELEPIPED = 2;
const int TYPE_BODY_CONE = 3;
const int TYPE_BODY_CYLINDER = 4;

const int COMMAND_ADD_BODY = 1;
const int COMMAND_FIND_MAX_MASS_BODY = 2;
const int COMMAND_FIND_LIGHTEST_BODY_IN_WATER = 3;
const int COMMAND_GET_INFO_ABOUT_ALL_BODIES = 4;
const int COMMAND_EXIT_COMMAND = 5;

const double WATER_DENSITY = 1000;
const double ACCELERATION_OF_FREE_FALL = 9.806;
const double MIN_WEIGHT_IN_WATER = 1000000000;

const std::string ENTER_RADIUS_SPHERE = "Введите радиус сферы: ";
const std::string ENTER_DENSITY_SPHERE = "Введите плотность сферы: ";

const std::string ENTER_WIDTH_PARALLELEPIPED = "Введите ширину параллелепипеда: ";
const std::string ENTER_DEPTH_PARALLELEPIPED = "Введите длину параллелепипеда: ";
const std::string ENTER_HEIGHT_PARALLELEPIPED = "Введите высоту параллелепипеда: ";
const std::string ENTER_DENSITY_PARALLELEPIPED = "Введите плотность параллелепипеда: ";

const std::string ENTER_BASE_RADIUS_CONE = "Введите радиус основания конуса: ";
const std::string ENTER_HEIGHT_CONE = "Введите высоту конуса: ";
const std::string ENTER_DENSITY_CONE = "Введите плотность конуса: ";

const std::string ENTER_BASE_RADIUS_CYLINDER = "Введите радиус основания цилиндра: ";
const std::string ENTER_HEIGHT_CYLINDER = "Введите высоту цилиндра: ";
const std::string ENTER_DENSITY_CYLINDER = "Введите плотность цилиндра: ";

const std::string UNKNOWN_BODY_TYPE = "Неизвестный тип тела\n";
const std::string ENTER_TYPE_BODY = "Тип тела: ";
const std::string MESSAGE_MAX_MASS_BODY = "Тело с максимальной массой: ";
const std::string MESSAGE_MIN_WEIGHT_IN_WATER = "Тело которое легче всего весит, будучи полностью погруженным в воду: ";
const std::string MESSAGE_WEIGHT_IN_WATER = "Вес тела в воде: ";
const std::string MESSAGE_EXIT_PROGRAM = "\nСпасибо за использование программы =)\n";
const std::string MESSAGE_INCORRECT_COMMAND = "Неверная команда!\n";
const std::string MESSAGE_NUMBER_COMMAND = "Номер команды: ";
const std::string MESSAGE_ABOUT_TYPE_BODY = "\nВведите тип тела \n1 - Сфера\n2 - Параллелепипед\n3 - Конус\n4 - Цилиндр\n5 - Составное тело\n\n";
const std::string FIRST_PART_DIVISION = "-------";
const std::string SECOND_PART_DIVISION = "-------\n";

void PrintStartMessage()
{
	std::cout << "-------Доступные команды-------\n"
			  << "1 - Добавить тело\n"
			  << "2 - Найти тело с наибольшей массой\n"
			  << "3 - Найти тело которое будет легче всего весить, будучи полностью погруженным в воду\n"
			  << "4 - Вывести информацию обо всех телах\n"
			  << "5 - Выйти из программы\n\n";
}

double ReadValueDouble(const std::string& prompt)
{
	double value;
	std::cout << prompt;
	std::cin >> value;
	return value;
}

void AddBody(std::vector<std::shared_ptr<CBody>>& bodies)
{
	int bodyType;
	std::cout << MESSAGE_ABOUT_TYPE_BODY;
	std::cout << ENTER_TYPE_BODY;
	std::cin >> bodyType;

	if (bodyType == TYPE_BODY_SHPERE)
	{
		double radius = ReadValueDouble(ENTER_RADIUS_SPHERE);
		double density = ReadValueDouble(ENTER_DENSITY_SPHERE);
		std::shared_ptr<CSphere> sphere = std::make_shared<CSphere>(radius, density);
		bodies.push_back(sphere);
		return;
	}
	if (bodyType == TYPE_BODY_PARALLELEPIPED)
	{
		double width = ReadValueDouble(ENTER_WIDTH_PARALLELEPIPED);
		double depth = ReadValueDouble(ENTER_DEPTH_PARALLELEPIPED);
		double height = ReadValueDouble(ENTER_HEIGHT_PARALLELEPIPED);
		double density = ReadValueDouble(ENTER_DENSITY_PARALLELEPIPED);
		std::shared_ptr<CParallelepiped> parallelepiped = std::make_shared<CParallelepiped>(width, depth, height, density);
		bodies.push_back(parallelepiped);
		return;
	}
	if (bodyType == TYPE_BODY_CONE)
	{
		double baseRadius = ReadValueDouble(ENTER_BASE_RADIUS_CONE);
		double height = ReadValueDouble(ENTER_HEIGHT_CONE);
		double density = ReadValueDouble(ENTER_DENSITY_CONE);
		std::shared_ptr<CCone> cone = std::make_shared<CCone>(baseRadius, height, density);
		bodies.push_back(cone);
		return;
	}
	if (bodyType == TYPE_BODY_CYLINDER)
	{
		double baseRadius = ReadValueDouble(ENTER_BASE_RADIUS_CYLINDER);
		double height = ReadValueDouble(ENTER_HEIGHT_CYLINDER);
		double density = ReadValueDouble(ENTER_DENSITY_CYLINDER);
		std::shared_ptr<CCylinder> cylinder = std::make_shared<CCylinder>(baseRadius, height, density);
		bodies.push_back(cylinder);
		return;
	}
	else
	{
		std::cout << UNKNOWN_BODY_TYPE;
	}
}

void FindMaxMassBody(const std::vector<std::shared_ptr<CBody>>& bodies)
{
	double maxMass = 0;
	std::shared_ptr<CBody> maxMassBody;

	if (!bodies.empty())
	{
		for (auto body : bodies)
		{
			if (body->GetMass() > maxMass)
			{
				maxMass = body->GetMass();
				maxMassBody = body;
			}
		}
		std::cout << MESSAGE_MAX_MASS_BODY << maxMassBody->ToString() << std::endl;
	}
}

double GetWeightBodyInWater(std::shared_ptr<CBody>& body)
{
	return ((body->GetDensity() - WATER_DENSITY) * ACCELERATION_OF_FREE_FALL * body->GetVolume());
}

void FindLightestBodyInWater(const std::vector<std::shared_ptr<CBody>>& bodies)
{
	double minWeightInWater = MIN_WEIGHT_IN_WATER;
	std::shared_ptr<CBody> minWeightInWaterBody;

	if (!bodies.empty())
	{
		for (auto body : bodies)
		{
			if (GetWeightBodyInWater(body) < minWeightInWater)
			{
				minWeightInWater = GetWeightBodyInWater(body);
				minWeightInWaterBody = body;
			}
		}
		std::cout << MESSAGE_MIN_WEIGHT_IN_WATER << minWeightInWaterBody->ToString() << LINE_BREAK;
		std::cout << MESSAGE_WEIGHT_IN_WATER << minWeightInWater;
	}
}

void GetInfoAboutAllBodies(const std::vector<std::shared_ptr<CBody>>& bodies)
{
	if (!bodies.empty())
	{
		for (int i = 0; i < bodies.size(); i++)
		{
			std::cout << FIRST_PART_DIVISION << (i + 1) << SECOND_PART_DIVISION << bodies[i]->ToString() << LINE_BREAK;
		}
	}
}

int main()
{
	setlocale(LC_ALL, RUSSIAN_LANGUAGE);
	PrintStartMessage();

	std::vector<std::shared_ptr<CBody>> bodies;
	int command = 0;
	while (true)
	{
		std::cout << MESSAGE_NUMBER_COMMAND;
		std::cin >> command;
		switch (command)
		{
		case COMMAND_ADD_BODY:
			AddBody(bodies);
			std::cout << LINE_BREAK;
			break;
		case COMMAND_FIND_MAX_MASS_BODY:
			FindMaxMassBody(bodies);
			std::cout << LINE_BREAK;
			break;
		case COMMAND_FIND_LIGHTEST_BODY_IN_WATER:
			FindLightestBodyInWater(bodies);
			std::cout << LINE_BREAK;
			break;
		case COMMAND_GET_INFO_ABOUT_ALL_BODIES:
			GetInfoAboutAllBodies(bodies);
			std::cout << LINE_BREAK;
			break;
		case COMMAND_EXIT_COMMAND:
			std::cout << MESSAGE_EXIT_PROGRAM;
			return 0;
			break;
		default:
			std::cout << MESSAGE_INCORRECT_COMMAND;
			break;
		}
	}
	return 0;
}