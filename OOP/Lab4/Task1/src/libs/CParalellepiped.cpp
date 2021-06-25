#include "CParalellepiped.hpp"

CParalellepiped::CParalellepiped(double density, double width, double height, double depth)
	: CBody("Paralellepiped", density)
	, m_width(width)
	, m_height(height)
	, m_depth(depth)
{
}

double CParalellepiped::getWidth() const
{
	return m_width;
}

double CParalellepiped::getHeight() const
{
	return m_height;
}

double CParalellepiped::getDepth() const
{
	return m_depth;
}

double CParalellepiped::getVolume() const
{
	return m_width * m_height * m_depth;
}

void CParalellepiped::appendProperties(std::ostream& strm) const
{
	strm
		<< "     width = " << getWidth() << std::endl
		<< "     height = " << getHeight() << std::endl
		<< "     depth = " << getDepth() << std::endl;
}
