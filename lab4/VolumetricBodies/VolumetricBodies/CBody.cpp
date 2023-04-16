#include "CBody.h"

CBody::CBody()
{
}

CBody::~CBody()
{
}

std::string CBody::ToString() const
{
	std::ostringstream strm;
	strm << GetType() << std::endl << std::setprecision(10)
		 << "Плотность: " << GetDensity() << std::endl
		 << "Объём: " << GetVolume() << std::endl
		 << "Масса: " << GetMass() << std::endl;
	AppendProperties(strm);
	return strm.str();
}