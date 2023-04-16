#include "CCone.h"

CCone::CCone(double baseRadius, double height, double density)
	: CSolidBody(density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
}

CCone::~CCone()
{
}

double CCone::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return PI * pow(m_baseRadius, 2) * (m_height / 3);
}

std::string CCone::GetType() const
{
	return "�����";
}

void CCone::AppendProperties(std::ostream & strm) const
{
	strm << "������ ��������� = " << GetBaseRadius() << std::endl
		 << "������ ������ = " << GetHeight() << std::endl;
}