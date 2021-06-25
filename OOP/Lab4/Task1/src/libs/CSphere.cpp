#include "CSphere.hpp"

CSphere::CSphere(double density, double radius)
	: CBody("Sphere", density)
	, m_radius(radius)
{
}

CSphere::~CSphere() {}

double CSphere::getRadius() const
{
	return m_radius;
}

double CSphere::getVolume() const
{
	return (pow(m_radius, 3) * M_PI) * 4 / 3;
}

void CSphere::appendProperties(std::ostream& strm) const
{
	strm << "     radius = " << getRadius() << std::endl;
}
