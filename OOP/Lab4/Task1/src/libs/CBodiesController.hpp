#ifndef CBODIESCONTROLLER_HPP
#define CBODIESCONTROLLER_HPP

#include "../task/stdafx.h"
#include "CBodiesHeader.hpp"

class CBodiesController
{

public:
	CBodiesController();
	~CBodiesController();

	void ReadBodiesFromIstream(std::istream& stream);
	void PrintBodies() const;
	void PrintBodyWithMaxMass() const;
	void PrintBodyWithMinWeightInWater() const;

protected:
	std::vector<std::pair<std::string, CBody*>> m_bodiesContainer;

	void CreateBody(std::vector<std::string>& bodyParameters);
	void DeleteBodies();

	CBody* FindBodyByName(const std::string& bodyName) const;

	double StringToDouble(const std::string& string, bool& err) const;
	std::string ReadLine(std::istream& stream, bool& err) const;
	std::vector<std::string> ParseString(const std::string& str, char delim) const;
};

#endif // CBODIESCONTROLLER_HPP
