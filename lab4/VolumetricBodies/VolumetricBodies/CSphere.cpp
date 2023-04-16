#include "CSphere.h"

CSphere::CSphere(double radius, double density)
	: CSolidBody(density)
	, m_radius(radius)
{
}

CSphere::~CSphere()
{
}

double CSphere::GetRadius() const
{
	return m_radius;
}

double CSphere::GetVolume() const
{
	return (4 / 3) * (PI * pow(m_radius, 3));
}

std::string CSphere::GetType() const
{
	return "Сфера";
}

void CSphere::AppendProperties(std::ostream & strm) const
{
	strm << "Радиус = " << GetRadius() << std::endl;
}