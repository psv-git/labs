#include "CCone.hpp"

CCone::CCone(double density, double baseRadius, double height)
	: CBody("Cone", density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
}

double CCone::getBaseRadius() const
{
	return m_baseRadius;
}

double CCone::getHeight() const
{
	return m_height;
}

double CCone::getVolume() const
{
	return (pow(m_baseRadius, 2) * m_height * M_PI) / 3;
}

void CCone::appendProperties(std::ostream& strm) const
{
	strm
		<< "     base_radius = " << getBaseRadius() << std::endl
		<< "     height = " << getHeight() << std::endl;
}
