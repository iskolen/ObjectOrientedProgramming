#pragma once
#include "CBody.h"
#include "CSphere.h"
#include "CParallelepiped.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CCompound.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class CController
{
public:
	CController(std::istream &input, std::ostream &output);
	int ReadValueInt(const std::string& prompt);
	double GetWeightBodyInWater(std::shared_ptr<CBody>& body);
	double ReadValueDouble(const std::string& prompt);
	void PrintStartMessage();
	void AddBody(std::vector<std::shared_ptr<CBody>>& bodies);
	void AddBodyToCompound(std::shared_ptr<CCompound>& compound);
	void FindMaxMassBody(const std::vector<std::shared_ptr<CBody>>& bodies);
	void FindLightestBodyInWater(const std::vector<std::shared_ptr<CBody>>& bodies);
	void GetInfoAboutAllBodies(const std::vector<std::shared_ptr<CBody>>& bodies);
private:
	std::istream &m_input;
	std::ostream &m_output;
};


const int COMMAND_ADD_BODY = 1;
const int COMMAND_FIND_MAX_MASS_BODY = 2;
const int COMMAND_FIND_LIGHTEST_BODY_IN_WATER = 3;
const int COMMAND_GET_INFO_ABOUT_ALL_BODIES = 4;
const int COMMAND_EXIT_COMMAND = 5;

const char RUSSIAN_LANGUAGE[8] = "Russian";
const char LINE_BREAK = '\n';

const std::string MESSAGE_EXIT_PROGRAM = "\nСпасибо за использование программы =)\n";
const std::string MESSAGE_INCORRECT_COMMAND = "Неверная команда!\n";
const std::string MESSAGE_NUMBER_COMMAND = "Номер команды: ";

const int TYPE_BODY_SHPERE = 1;
const int TYPE_BODY_PARALLELEPIPED = 2;
const int TYPE_BODY_CONE = 3;
const int TYPE_BODY_CYLINDER = 4;
const int TYPE_BODY_COMPOUND = 5;

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

const std::string ENTER_NUMBER_OF_BODIES = "Введите количество тел, которое должно находиться в составном теле: ";

const std::string MESSAGE_MAX_MASS_BODY = "Тело с максимальной массой: ";
const std::string MESSAGE_MIN_WEIGHT_IN_WATER = "Тело которое легче всего весит, будучи полностью погруженным в воду: ";
const std::string MESSAGE_WEIGHT_IN_WATER = "Вес тела в воде: ";
const std::string MESSAGE_ABOUT_TYPE_BODY = "\nВведите тип тела \n1 - Сфера\n2 - Параллелепипед\n3 - Конус\n4 - Цилиндр\n5 - Составное тело\n\n";
const std::string UNKNOWN_BODY_TYPE = "Неизвестный тип тела\n";
const std::string ENTER_TYPE_BODY = "Тип тела: ";
const std::string FIRST_PART_DIVISION = "-------";
const std::string SECOND_PART_DIVISION = "-------\n";
const std::string START_MESSAGE = "------- Доступные команды------- \n1 - Добавить тело\n2 - Найти тело с наибольшей массой\n3 - Найти тело которое будет легче всего весить, будучи полностью погруженным в воду\n4 - Вывести информацию обо всех телах\n5 - Выйти из программы\n\n";