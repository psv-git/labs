#ifndef CSPHERE_HPP
#define CSPHERE_HPP

#include "CBody.hpp"

class CSphere final : public CBody
{

public:
	CSphere(double density, double radius);
	~CSphere();

	double getVolume() const override;
	double getRadius() const;

private:
	double m_radius;

	void appendProperties(std::ostream& strm) const override;
};

#endif // CSPHERE_HPP