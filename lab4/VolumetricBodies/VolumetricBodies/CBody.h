#pragma once
#include "stdafx.h"

class CBody
{
public:
	CBody();

	virtual double GetDensity() const = 0;// ���������
	virtual double GetVolume() const = 0; // �����
	virtual double GetMass() const = 0;   // ����� = ��������� * �����
	virtual std::string GetType() const = 0;
	std::string ToString() const;

	virtual ~CBody();
private:
	virtual void AppendProperties(std::ostream& strm) const = 0;
	double m_density;
	std::string m_type;
};



const int PRECISION = 10;

const std::string BODY_DENSITY = "��������� = ";
const std::string BODY_VOLUME = "����� = ";
const std::string BODY_MASS = "����� = ";

const std::string TYPE_CONE = "�����";
const std::string TYPE_CYLINDER = "�������";
const std::string TYPE_SPHERE = "�����";
const std::string TYPE_PARALLELEPIPED = "��������������";

const std::string APPEND_CONE_RADIUS = "������ ��������� = ";
const std::string APPEND_CONE_HEIGHT = "������ ������ = ";

const std::string APPEND_CYLINDER_RADIUS = "������ ��������� = ";
const std::string APPEND_CYLINDER_HEIGHT = "������ �������� = ";

const std::string APPEND_SPHERE_RADIUS = "������ = ";

const std::string APPEND_PARALLELEPIPED_WIDTH = "������ ��������������� = ";
const std::string APPEND_PARALLELEPIPED_DEPTH = "����� ��������������� = ";
const std::string APPEND_PARALLELEPIPED_HEIGHT = "������ ��������������� = ";