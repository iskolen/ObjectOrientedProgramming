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

const std::string MESSAGE_EXIT_PROGRAM = "\n������� �� ������������� ��������� =)\n";
const std::string MESSAGE_INCORRECT_COMMAND = "�������� �������!\n";
const std::string MESSAGE_NUMBER_COMMAND = "����� �������: ";

const int TYPE_BODY_SHPERE = 1;
const int TYPE_BODY_PARALLELEPIPED = 2;
const int TYPE_BODY_CONE = 3;
const int TYPE_BODY_CYLINDER = 4;
const int TYPE_BODY_COMPOUND = 5;

const double WATER_DENSITY = 1000;
const double ACCELERATION_OF_FREE_FALL = 9.806;
const double MIN_WEIGHT_IN_WATER = 1000000000;

const std::string ENTER_RADIUS_SPHERE = "������� ������ �����: ";
const std::string ENTER_DENSITY_SPHERE = "������� ��������� �����: ";

const std::string ENTER_WIDTH_PARALLELEPIPED = "������� ������ ���������������: ";
const std::string ENTER_DEPTH_PARALLELEPIPED = "������� ����� ���������������: ";
const std::string ENTER_HEIGHT_PARALLELEPIPED = "������� ������ ���������������: ";
const std::string ENTER_DENSITY_PARALLELEPIPED = "������� ��������� ���������������: ";

const std::string ENTER_BASE_RADIUS_CONE = "������� ������ ��������� ������: ";
const std::string ENTER_HEIGHT_CONE = "������� ������ ������: ";
const std::string ENTER_DENSITY_CONE = "������� ��������� ������: ";

const std::string ENTER_BASE_RADIUS_CYLINDER = "������� ������ ��������� ��������: ";
const std::string ENTER_HEIGHT_CYLINDER = "������� ������ ��������: ";
const std::string ENTER_DENSITY_CYLINDER = "������� ��������� ��������: ";

const std::string ENTER_NUMBER_OF_BODIES = "������� ���������� ���, ������� ������ ���������� � ��������� ����: ";

const std::string MESSAGE_MAX_MASS_BODY = "���� � ������������ ������: ";
const std::string MESSAGE_MIN_WEIGHT_IN_WATER = "���� ������� ����� ����� �����, ������ ��������� ����������� � ����: ";
const std::string MESSAGE_WEIGHT_IN_WATER = "��� ���� � ����: ";
const std::string MESSAGE_ABOUT_TYPE_BODY = "\n������� ��� ���� \n1 - �����\n2 - ��������������\n3 - �����\n4 - �������\n5 - ��������� ����\n\n";
const std::string UNKNOWN_BODY_TYPE = "����������� ��� ����\n";
const std::string ENTER_TYPE_BODY = "��� ����: ";
const std::string FIRST_PART_DIVISION = "-------";
const std::string SECOND_PART_DIVISION = "-------\n";
const std::string START_MESSAGE = "------- ��������� �������------- \n1 - �������� ����\n2 - ����� ���� � ���������� ������\n3 - ����� ���� ������� ����� ����� ����� ������, ������ ��������� ����������� � ����\n4 - ������� ���������� ��� ���� �����\n5 - ����� �� ���������\n\n";