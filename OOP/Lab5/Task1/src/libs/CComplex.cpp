#include "CComplex.hpp"

// инициализация комплексного числа значениями действительной и мнимой частей
CComplex::CComplex(double real, double image)
	: m_realPart(real)
	, m_imagePart(image)
{
}

// возвращает действительную часть комплексного числа
double CComplex::Re() const
{
	return m_realPart;
}

// возвращает мнимую часть комплексного числа
double CComplex::Im() const
{
	return m_imagePart;
}

// возвращает модуль комплексного числа
double CComplex::GetMagnitude() const
{
	double magnitude = -1.0;
	magnitude = std::sqrt(AddDoubles(MulDoubles(m_realPart, m_realPart), MulDoubles(m_imagePart, m_imagePart)));
	return magnitude;
}

// возвращает аргумент комплексного числа
double CComplex::GetArgument() const
{
	return Atan2(m_imagePart, m_realPart) * RADIAN;
}

// OVERRIDES ===================================================================

// a+bi + c+di = (a + c) + (b + d)i
const CComplex CComplex::operator+(const CComplex& right) const
{
	double real = AddDoubles(m_realPart, right.Re());
	double image = AddDoubles(m_imagePart, right.Im());
	return CComplex(real, image);
}

const CComplex operator+(double left, const CComplex& right)
{
	return right + left;
}

// a+bi - c+di = (a - c) + (b - d)i
const CComplex CComplex::operator-(const CComplex& right) const
{
	double real = SubDoubles(m_realPart, right.Re());
	double image = SubDoubles(m_imagePart, right.Im());
	return CComplex(real, image);
}

const CComplex operator-(double left, const CComplex& right)
{
	return right - left;
}

// a+bi * c+di = (ac - bd) + (ad + bc)i
const CComplex CComplex::operator*(const CComplex& right) const
{
	double real = MulDoubles(m_realPart, right.Re()) - MulDoubles(m_imagePart, right.Im());
	double image = MulDoubles(m_realPart, right.Im()) + MulDoubles(m_imagePart, right.Re());
	return CComplex(real, image);
}

const CComplex operator*(double left, const CComplex& right)
{
	return right * left;
}

// a+bi / c+di = (ac + bd) / (c^2 + d^2) + (bc - ad) / (c^2 + d^2)
const CComplex CComplex::operator/(const CComplex& right) const
{
	double real = DivDoubles(MulDoubles(m_realPart, right.Re()) + MulDoubles(m_imagePart, right.Im()), MulDoubles(right.Re(), right.Re()) + MulDoubles(right.Im(), right.Im()));
	double image = DivDoubles(MulDoubles(m_imagePart, right.Re()) - MulDoubles(m_realPart, right.Im()), MulDoubles(right.Re(), right.Re()) + MulDoubles(right.Im(), right.Im()));
	return CComplex(real, image);
}

const CComplex operator/(double left, const CComplex& right)
{
	return CComplex(left, 0) / right;
}

const CComplex CComplex::operator+() const
{
	return CComplex(m_realPart, m_imagePart);
}

const CComplex CComplex::operator-() const
{
	return CComplex(-m_realPart, -m_imagePart);
}

void CComplex::operator+=(const CComplex& right)
{
	double real = AddDoubles(m_realPart, right.Re());
	double image = AddDoubles(m_imagePart, right.Im());
	m_realPart = real;
	m_imagePart = image;
}

void CComplex::operator-=(const CComplex& right)
{
	double real = SubDoubles(m_realPart, right.Re());
	double image = SubDoubles(m_imagePart, right.Im());
	m_realPart = real;
	m_imagePart = image;
}

void CComplex::operator*=(const CComplex& right)
{
	double real = MulDoubles(m_realPart, right.Re()) - MulDoubles(m_imagePart, right.Im());
	double image = MulDoubles(m_realPart, right.Im()) + MulDoubles(m_imagePart, right.Re());
	m_realPart = real;
	m_imagePart = image;
}

void CComplex::operator/=(const CComplex& right)
{
	double real = DivDoubles(MulDoubles(m_realPart, right.Re()) + MulDoubles(m_imagePart, right.Im()), MulDoubles(right.Re(), right.Re()) + MulDoubles(right.Im(), right.Im()));
	double image = DivDoubles(MulDoubles(m_imagePart, right.Re()) - MulDoubles(m_realPart, right.Im()), MulDoubles(right.Re(), right.Re()) + MulDoubles(right.Im(), right.Im()));
	m_realPart = real;
	m_imagePart = image;
}

const bool CComplex::operator==(const CComplex& right) const
{
	return NumbersAreEqual(m_realPart, right.Re()) && NumbersAreEqual(m_imagePart, right.Im());
}

const bool CComplex::operator!=(const CComplex& right) const
{
	return !(NumbersAreEqual(m_realPart, right.Re()) && NumbersAreEqual(m_imagePart, right.Im()));
}

std::ostream& operator<<(std::ostream& stream, const CComplex& self)
{
	stream << self.Re() << std::showpos << self.Im() << "i" << std::noshowpos;
	return stream;
}

std::istream& operator>>(std::istream& stream, CComplex& self)
{
	double real = ReadDouble(stream);
	double image = ReadDouble(stream);
	stream.ignore(STREAM_SIZE_MAX, '\n');
	self = CComplex(real, image);
	return stream;
}
