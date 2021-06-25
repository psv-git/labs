#ifndef CCYLINDER_HPP
#define CCYLINDER_HPP

#include "CBody.hpp"

class CCylinder final : public CBody
{

public:
	CCylinder(double density, double baseRadius, double height);

	double getBaseRadius() const;
	double getHeight() const;
	double getVolume() const override;

private:
	double m_baseRadius;
	double m_height;

	void appendProperties(std::ostream& strm) const override;
};

#endif // CCYLINDER_HPP