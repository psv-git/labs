#include "CBodiesController.hpp"

CBodiesController::CBodiesController() {}

CBodiesController::~CBodiesController()
{
	DeleteBodies();
}

// PUBLIC ======================================================================

void CBodiesController::ReadBodiesFromIstream(std::istream& stream)
{
	bool error = false;
	std::string inStr;
	std::vector<std::string> bodyParameters;
	while (!error)
	{
		inStr = ReadLine(stream, error);
		if (!inStr.empty())
		{
			bodyParameters = ParseString(inStr, ' ');
			if (bodyParameters.size() > 0)
			{
				CreateBody(bodyParameters);
			}
		}
	}
}

void CBodiesController::PrintBodies() const
{
	for (auto bodyPair : m_bodiesContainer)
	{
		std::cout << bodyPair.second->toString() << std::endl
				  << std::endl;
	}
}

void CBodiesController::PrintBodyWithMaxMass() const
{
	double maxMass = 0;
	CBody* bodyWithMaxMass = nullptr;
	for (auto bodyPair : m_bodiesContainer)
	{
		double bodyMass = bodyPair.second->getMass();
		if (bodyMass > maxMass)
		{
			maxMass = bodyMass;
			bodyWithMaxMass = bodyPair.second;
		}
	}
	if (bodyWithMaxMass)
	{
		std::cout << std::endl
				  << "Body with max mass:" << std::endl
				  << bodyWithMaxMass->toString() << std::endl;
	}
}

void CBodiesController::PrintBodyWithMinWeightInWater() const
{
	double waterDensity = 1000;
	double g = 10;
	double minWeight = std::numeric_limits<double>::infinity();
	CBody* bodyWithMinWeight = nullptr;
	for (auto bodyPair : m_bodiesContainer)
	{
		double weight = (bodyPair.second->getDensity() - waterDensity) * g * bodyPair.second->getVolume();
		if (weight < minWeight)
		{
			minWeight = weight;
			bodyWithMinWeight = bodyPair.second;
		}
	}
	if (bodyWithMinWeight)
	{
		std::cout << std::endl
				  << "Body with min weight in water:" << std::endl
				  << bodyWithMinWeight->toString() << std::endl;
	}
}

// PRIVATE =====================================================================

void CBodiesController::CreateBody(std::vector<std::string>& bodyParameters)
{
	bool error = false;
	std::pair<std::string, CBody*> bodyPair;
	std::string bodyType = bodyParameters[0];
	bodyPair.first = bodyParameters[1];
	if (bodyType == "cone")
	{
		double density = StringToDouble(bodyParameters[3], error);
		double baseRadius = StringToDouble(bodyParameters[4], error);
		double height = StringToDouble(bodyParameters[5], error);
		CCone* cone = new CCone(density, baseRadius, height);
		bodyPair.second = dynamic_cast<CBody*>(cone);
	}
	else if (bodyType == "cylinder")
	{
		double density = StringToDouble(bodyParameters[3], error);
		double baseRadius = StringToDouble(bodyParameters[4], error);
		double height = StringToDouble(bodyParameters[5], error);
		CCylinder* cylinder = new CCylinder(density, baseRadius, height);
		bodyPair.second = dynamic_cast<CBody*>(cylinder);
	}
	else if (bodyType == "sphere")
	{
		double density = StringToDouble(bodyParameters[3], error);
		double radius = StringToDouble(bodyParameters[4], error);
		CSphere* sphere = new CSphere(density, radius);
		bodyPair.second = dynamic_cast<CBody*>(sphere);
	}
	else if (bodyType == "paralellepiped")
	{
		double density = StringToDouble(bodyParameters[3], error);
		double width = StringToDouble(bodyParameters[4], error);
		double height = StringToDouble(bodyParameters[5], error);
		double depth = StringToDouble(bodyParameters[6], error);
		CParalellepiped* paralellepiped = new CParalellepiped(density, width, height, depth);
		bodyPair.second = dynamic_cast<CBody*>(paralellepiped);
	}
	else if (bodyType == "compound")
	{
		CCompound* compound = new CCompound();
		for (size_t i = 3; i < bodyParameters.size(); i++)
		{
			compound->addChildBody(*FindBodyByName(bodyParameters[i]));
		}
		bodyPair.second = dynamic_cast<CBody*>(compound);
	}
	m_bodiesContainer.push_back(bodyPair);
}

void CBodiesController::DeleteBodies()
{
	for (auto bodyPair : m_bodiesContainer)
	{
		delete bodyPair.second;
	}
}

CBody* CBodiesController::FindBodyByName(const std::string& bodyName) const
{
	CBody* body = nullptr;
	for (auto bodyPair : m_bodiesContainer)
	{
		if (bodyPair.first == bodyName)
		{
			body = bodyPair.second;
		}
	}
	return body;
}

// ============================================================================

double CBodiesController::StringToDouble(const std::string& string, bool& err) const
{
	err = false;
	double number = 0;
	size_t pos;
	try
	{
		number = std::stod(string, &pos);
		if (pos != string.size())
			err = true;
	}
	catch (...)
	{
		err = true;
	}
	return number;
}

std::string CBodiesController::ReadLine(std::istream& stream, bool& err) const
{
	err = false;
	std::string line;
	if (stream.eof())
		err = true;
	else
		std::getline(stream, line);
	return line;
}

std::vector<std::string> CBodiesController::ParseString(const std::string& str, char delim) const
{
	std::vector<std::string> container;
	std::string subStr;
	for (char ch : str)
	{
		if (ch == delim)
		{
			if (!subStr.empty())
			{
				container.push_back(subStr);
				subStr.clear();
			}
		}
		else if (ch != '\0' && ch != '\n' && ch != '\r')
		{
			subStr.push_back(ch);
		}
		else
			break;
	}
	if (!subStr.empty())
		container.push_back(subStr);
	return container;
}
