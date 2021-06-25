#include "CBody.hpp"

CBody::CBody(const std::string& type, double density)
	: m_density(density)
	, m_type(type)
{
}

CBody::~CBody() {}

double CBody::getDensity() const
{
	return m_density;
}

double CBody::getMass() const
{
	return getVolume() * getDensity();
}

std::string CBody::getType() const
{
	return m_type;
}

std::string CBody::toString() const
{
	std::ostringstream strm;
	strm
		<< m_type << ":" << std::endl
		<< "     density = " << getDensity() << std::endl
		<< "     volume = " << getVolume() << std::endl
		<< "     mass = " << getMass() << std::endl;
	appendProperties(strm);
	return strm.str();
}
