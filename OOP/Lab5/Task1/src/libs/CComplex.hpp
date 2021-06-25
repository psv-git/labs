#ifndef CCOMPLEX_HPP
#define CCOMPLEX_HPP

#include "../task/stdafx.h"
#include "functions.hpp"

class CComplex
{

public:
	// инициализация комплексного числа значениями действительной и мнимой частей
	CComplex(double real = 0, double image = 0);

	// возвращает действительную часть комплексного числа
	double Re() const;
	// возвращает мнимую часть комплексного числа
	double Im() const;
	// возвращает модуль комплексного числа
	double GetMagnitude() const;
	// возвращает аргумент комплексного числа
	double GetArgument() const;

	const CComplex operator+(const CComplex& right) const;
	friend const CComplex operator+(double left, const CComplex& right);

	const CComplex operator-(const CComplex& right) const;
	friend const CComplex operator-(double left, const CComplex& right);

	const CComplex operator*(const CComplex& right) const;
	friend const CComplex operator*(double left, const CComplex& right);

	const CComplex operator/(const CComplex& right) const;
	friend const CComplex operator/(double left, const CComplex& right);

	const CComplex operator+() const;
	const CComplex operator-() const;

	void operator+=(const CComplex& right);
	void operator-=(const CComplex& right);
	void operator*=(const CComplex& right);
	void operator/=(const CComplex& right);

	const bool operator==(const CComplex& right) const;
	const bool operator!=(const CComplex& right) const;

	friend std::ostream& operator<<(std::ostream& stream, const CComplex& self);
	friend std::istream& operator>>(std::istream& stream, CComplex& self);

private:
	double m_realPart;
	double m_imagePart;
};

#endif // CCOMPLEX_HPP
