#ifndef CPARALELLEPIPED_HPP
#define CPARALELLEPIPED_HPP

#include "CBody.hpp"

class CParalellepiped final : public CBody
{

public:
	CParalellepiped(double density, double width, double height, double depth);

	double getWidth() const;
	double getHeight() const;
	double getDepth() const;
	double getVolume() const override;

private:
	double m_width;
	double m_height;
	double m_depth;

	void appendProperties(std::ostream& strm) const override;
};

#endif // CPARALELLEPIPED_HPP