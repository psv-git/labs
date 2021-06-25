#ifndef CCOMPOUND_HPP
#define CCOMPOUND_HPP

#include "CBody.hpp"

class CCompound final : public CBody
{

public:
	CCompound();

	double getVolume() const override;
	bool addChildBody(CBody& child);
	bool isAlreadyContainBody(CBody& build, int depth);

private:
	double m_volume;
	double m_mass;
	std::vector<CBody*> m_bodyesList;

	void appendProperties(std::ostream& strm) const override;
	void setVolume();
	void setMass();
	void setDensity();
};

#endif // CCOMPOUND_HPP
