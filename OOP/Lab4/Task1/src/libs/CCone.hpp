#ifndef CCONE_HPP
#define CCONE_HPP

#include "CBody.hpp"

class CCone final : public CBody
{

public:
	CCone(double density, double baseRadius, double height);

	double getBaseRadius() const;
	double getHeight() const;
	double getVolume() const override;

private:
	double m_baseRadius;
	double m_height;

	void appendProperties(std::ostream& strm) const override;
};

#endif // CONE_HPP