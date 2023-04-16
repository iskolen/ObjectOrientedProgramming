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
		 << "���������: " << GetDensity() << std::endl
		 << "�����: " << GetVolume() << std::endl
		 << "�����: " << GetMass() << std::endl;
	AppendProperties(strm);
	return strm.str();
}