#ifndef SPORTSMEN_HPP
#define SPORTSMEN_HPP

class Sportsmen
{
public:
	Sportsmen(const std::string& name, double height, double weight);

	std::string GetFullName() const;
	double GetHeight() const;
	double GetWeight() const;

private:
	std::string m_fullName;
	double m_height;
	double m_weight;
};

#endif // SPORTSMEN_HPP
