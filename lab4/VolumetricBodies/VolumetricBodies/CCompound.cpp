#include "CCompound.h"
#include <algorithm>

CCompound::CCompound()
{
}

bool CCompound::AddChildBody(std::shared_ptr<CBody> const &body)
{
	if (std::find_if(m_bodies.begin(), m_bodies.end(), [&](std::shared_ptr<CBody> const &child) 
	{
		return child.get() == body.get() || dynamic_cast<CCompound *>(body.get()) == this;
	})!= m_bodies.end()) 
	{
		return false;
	}

	m_bodies.push_back(body);
	return true;
}

double CCompound::GetDensity() const
{
	double total_mass = 0;
	double total_volume = 0;

	for (auto const &body : m_bodies) 
	{
		total_mass += body->GetMass();
		total_volume += body->GetVolume();
	}

	return total_mass == 0 ? 0 : total_mass / total_volume;
}

double CCompound::GetMass() const
{
	double total_mass = 0;

	for (auto const &body : m_bodies) 
	{
		total_mass += body->GetMass();
	}

	return total_mass;
}

double CCompound::GetVolume() const
{
	double total_volume = 0;

	for (auto const &body : m_bodies) 
	{
		total_volume += body->GetVolume();
	}

	return total_volume;
}

std::string CCompound::GetType() const
{
	return "Compound";
}

void CCompound::AppendProperties(std::ostream &strm) const
{
	for (auto const &body : m_bodies) 
	{
		strm << "  Child " << body->GetType() << ":" << std::endl;
	}
}
