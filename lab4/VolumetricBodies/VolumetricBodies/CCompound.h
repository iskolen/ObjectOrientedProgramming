#pragma once
#include "CSolidBody.h"
#include <vector>
#include <memory>

class CCompound final : public CBody
{
public:
	CCompound();

	bool AddChildBody(std::shared_ptr<CBody> const &body);
	double GetDensity() const override;
	double GetMass() const override;
	double GetVolume() const override;
	std::string GetType() const override;
private:
	void AppendProperties(std::ostream & strm) const override;
	std::vector<std::shared_ptr<CBody>> m_bodies;
};
