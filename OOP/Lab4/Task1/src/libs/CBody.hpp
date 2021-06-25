#ifndef CBODY_HPP
#define CBODY_HPP

#include "../task/stdafx.h"

class CBody
{

public:
	CBody(const std::string& type, double density);
	virtual ~CBody();

	virtual double getVolume() const = 0;
	double getDensity() const;
	double getMass() const;
	std::string getType() const;
	std::string toString() const;

protected:
	std::string m_type;
	double m_density;

	virtual void appendProperties(std::ostream& strm) const = 0;
};

#endif // CBODY_HPP