#include "CSolidBody.h"
#include <string>

CSolidBody::CSolidBody(double density)
	: m_density(density)
{
}

double CSolidBody::GetDensity() const
{
	return m_density;
}

double CSolidBody::GetMass() const
{
	return GetDensity() * GetVolume();
}