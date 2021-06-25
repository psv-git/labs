#include "CCompound.hpp"

CCompound::CCompound()
	: CBody("Compound", 0)
	, m_volume(0)
{
}

// ============================================================================

double CCompound::getVolume() const
{
	return m_volume;
}

// ============================================================================

void CCompound::setVolume()
{
	m_volume = 0;
	for (auto body : m_bodyesList)
	{
		m_volume += body->getVolume();
	}
}

// Масса составного тела вычисляется через массу составляющих его частей
void CCompound::setMass()
{
	m_mass = 0;
	for (auto body : m_bodyesList)
	{
		m_mass += body->getMass();
	}
}

// Средняя плотность составного тела может быть вычислена как отношение массы составляющих его тел к их суммарному объему.
void CCompound::setDensity()
{
	m_density = m_mass / m_volume;
}

// ============================================================================

bool CCompound::addChildBody(CBody& child)
{
	if (!isAlreadyContainBody(child, 0))
	{
		CBody* ptr = &child;
		m_bodyesList.push_back(ptr);
		setVolume();
		setMass();
		setDensity();
		return true;
	}
	return false;
}

bool CCompound::isAlreadyContainBody(CBody& body, int depth)
{
	auto bodyPtr = &body;
	// если фигура составная
	if (bodyPtr->getType() == m_type)
	{
		auto compoundPtr = dynamic_cast<CCompound*>(bodyPtr);
		// проверка на попытку добавления себя
		if (this == compoundPtr)
		{
			return true;
		}
		// проверить наличие себя в составной фигуре
		if (!depth)
		{
			if (compoundPtr->isAlreadyContainBody(*this, 1))
			{
				return true;
			}
		}
	}
	// проверить наличие фигуры в себе
	for (auto existBodyPtr : m_bodyesList)
	{
		if (existBodyPtr == bodyPtr)
		{
			return true;
		}
		// если найдена составная фигура - проверяем в ней
		if (existBodyPtr->getType() == m_type)
		{
			auto existBodyCompPtr = dynamic_cast<CCompound*>(existBodyPtr);
			if (existBodyCompPtr->isAlreadyContainBody(body, 0))
			{
				return true;
			}
		}
	}
	return false;
}

// ============================================================================

void CCompound::appendProperties(std::ostream& strm) const
{
	strm
		<< "     figures contain = " << m_bodyesList.size() << std::endl;
	for (auto figure : m_bodyesList)
	{
		strm << m_type << ": " << figure->toString();
	}
}
