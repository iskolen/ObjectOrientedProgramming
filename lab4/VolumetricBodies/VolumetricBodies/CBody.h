#pragma once
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

class CBody
{
public:
	CBody();

	virtual double GetDensity() const = 0;// Плотность
	virtual double GetVolume() const = 0; // Объём
	virtual double GetMass() const = 0;   // Масса = Плотность * Объём
	virtual std::string GetType() const = 0;
	std::string ToString() const;

	virtual ~CBody();
private:
	virtual void AppendProperties(std::ostream& strm) const = 0;
	double m_density;
	std::string m_type;
};

const double PI = 3.141592653589793;