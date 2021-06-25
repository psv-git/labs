#include "CCylinder.hpp"

CCylinder::CCylinder(double density, double baseRadius, double height)
	: CBody("Cilinder", density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
}

double CCylinder::getBaseRadius() const
{
	return m_baseRadius;
}

double CCylinder::getHeight() const
{
	return m_height;
}

double CCylinder::getVolume() const
{
	return pow(m_baseRadius, 2) * m_height * M_PI;
}

void CCylinder::appendProperties(std::ostream& strm) const
{
	strm
		<< "     base_radius = " << getBaseRadius() << std::endl
		<< "     height = " << getHeight() << std::endl;
}
