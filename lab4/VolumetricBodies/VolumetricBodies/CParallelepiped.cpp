#include "CParallelepiped.h"

CParallelepiped::CParallelepiped(double width, double depth, double height, double density)
	: CSolidBody(density)
	, m_width(width)
	, m_depth(depth)
	, m_height(height)
{
}

CParallelepiped::~CParallelepiped()
{
}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetHeight() const
{
	return m_height;
}

double CParallelepiped::GetDepth() const
{
	return m_depth;
}

double CParallelepiped::GetVolume() const
{
	return m_width * m_height * m_depth;
}

std::string CParallelepiped::GetType() const
{
	return "��������������";
}

void CParallelepiped::AppendProperties(std::ostream & strm) const
{
	strm << "������ ��������������� = " << GetWidth() << std::endl
		 << "����� ��������������� = " << GetDepth() << std::endl
		 << "������ ��������������� = " << GetHeight() << std::endl;
}