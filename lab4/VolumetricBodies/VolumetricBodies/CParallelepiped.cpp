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
	return "Параллелепипед";
}

void CParallelepiped::AppendProperties(std::ostream & strm) const
{
	strm << "Ширина параллелепипеда = " << GetWidth() << std::endl
		 << "Длина параллелепипеда = " << GetDepth() << std::endl
		 << "Высота параллелепипеда = " << GetHeight() << std::endl;
}