#pragma once
#include "stdafx.h"
#include "CBody.h"
#include "CSphere.h"
#include "CParallelepiped.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CCompound.h"

class CController
{
public:
	CController(std::istream &input, std::ostream &output, std::vector<std::shared_ptr<CBody>>& bodies);
	~CController();
	bool HandleCommand();

private:
	bool SetNewBody();
	bool GetInfoAboutAllBodies() const;
	bool GetMaxMassBody() const;
	bool GetLightestBodyInWater() const;
	bool GetInfoAboutBody(const std::shared_ptr<CBody>& body) const;
	double GetWeightBodyInWater(const std::shared_ptr<CBody>& body) const;
	double SetValueDouble(const std::string& prompt);

	bool SetSphere();
	bool SetParallelepiped();
	bool SetCone();
	bool SetCylinder();

	using Handler = std::function<bool(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	std::istream& m_input;
	std::ostream& m_output;
	std::vector<std::shared_ptr<CBody>>& m_bodies;

	const ActionMap m_actionMap;
};



const std::string COMMAND_ADD_BODY = "1";
const std::string COMMAND_GET_MAX_MASS_BODY = "2";
const std::string COMMAND_GET_LIGHTEST_BODY_IN_WATER = "3";
const std::string COMMAND_GET_INFO_ABOUT_ALL_BODIES = "4";

const int TYPE_BODY_SHPERE = 1;
const int TYPE_BODY_PARALLELEPIPED = 2;
const int TYPE_BODY_CONE = 3;
const int TYPE_BODY_CYLINDER = 4;
const int TYPE_BODY_COMPOUND = 5;

const char RUSSIAN_LANGUAGE[8] = "Russian";
const char LINE_BREAK = '\n';

const std::string MESSAGE_INCORRECT_COMMAND = "�������� �������!\n";
const std::string MESSAGE_NUMBER_COMMAND = "����� �������: ";

const double WATER_DENSITY = 1000;
const double ACCELERATION_OF_FREE_FALL = 9.806;

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
const std::string MESSAGE_ABOUT_TYPE_BODY = "\n������� ��� ���� \n1 - �����\n2 - ��������������\n3 - �����\n4 - �������\n\n";
const std::string UNKNOWN_BODY_TYPE = "����������� ��� ����\n";
const std::string ENTER_TYPE_BODY = "��� ����: ";
const std::string FIRST_PART_DIVISION = "-------";
const std::string SECOND_PART_DIVISION = "-------\n";
const std::string START_MESSAGE = "------- ��������� �������------- \n1 - �������� ����\n2 - ����� ���� � ���������� ������\n3 - ����� ���� ������� ����� ����� ����� ������, ������ ��������� ����������� � ����\n4 - ������� ���������� ��� ���� �����\n\n";

const std::string BODY_SUCCESSFULLY_ADDED = "���� ������� ���������!";
const std::string ERROR_VALUE_NEGATIVE = "�������� �� ����� ���� ��������������!";
const std::string ERROR_BODIES_ABSENT = "���� �����������!";
const std::string ERROR_VALUE_NOT_DIGIT = "������ �����! �������� ������ ���� ������!";