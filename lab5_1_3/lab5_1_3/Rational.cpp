#include "../lab5_1_3/Rational.h"
#include <string>

CRational::CRational() :
	m_numerator(ZER0),
	m_denominator(ONE)
{
}

CRational::CRational(int value) :
	m_numerator(value),
	m_denominator(ONE)
{
}

int GetLeastCommonMultiplier(int a, int b)
{
	return a * b / GreatestCommonDivisor(a, b);
}

int GreatestCommonDivisor(int a, int b)
{
	if (a < ZER0)
	{
		a *= -ONE;
	}
	if (b < ZER0)
	{
		b *= -ONE;
	}

	while (a > ZER0 && b > ZER0)
	{
		if (a > b)
			a %= b;

		else
			b %= a;
	}

	return a + b;
}

void CRational::Normalize()
{
	int divisor = GreatestCommonDivisor(m_numerator, m_denominator);

	if (m_denominator < ZER0)
	{
		m_numerator *= -ONE;
		m_denominator *= -ONE;
	}

	m_numerator /= divisor;
	m_denominator /= divisor;
}

CRational::CRational(int numerator, int denominator) :
	m_numerator(numerator),
	m_denominator(denominator)
{
	if (m_denominator == ZER0)
	{
		m_denominator = ONE;
		m_numerator = ZER0;
	}
	else
	{
		Normalize();
	}

}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	std::ostringstream oss; 
	oss << std::fixed << std::setprecision(3) << static_cast<double>(m_numerator) / static_cast<double>(m_denominator);

	std::string formattedString = oss.str(); 
	return std::stod(formattedString); 
}

CRational const CRational::operator+() const
{
	return CRational(m_numerator, m_denominator);
}

CRational const CRational::operator-() const
{
	return CRational(m_numerator * (-ONE), m_denominator);
}

CRational& CRational::operator+=(const CRational& number)
{
	*this = *this + number;
	return *this;
}

CRational& CRational::operator-=(const CRational& number)
{
	*this = *this - number;
	return *this;
}

CRational& CRational::operator*=(const CRational& number)
{
	*this = *this * number;
	return *this;
}

CRational& CRational::operator/=(const CRational& number)
{
	*this = *this / number;
	return *this;
}

std::pair<int, CRational> CRational::ToCompoundFraction() const
{
	int intPart = m_numerator / m_denominator;
	return std::pair<int, CRational>(intPart, CRational(m_numerator - (intPart * m_denominator), m_denominator));
}

CRational operator+(const CRational& numberONE, const CRational& number2)
{
	int multiplier = GetLeastCommonMultiplier(numberONE.GetDenominator(), number2.GetDenominator());
	return CRational(numberONE.GetNumerator() * (multiplier / numberONE.GetDenominator()) + number2.GetNumerator() * (multiplier / number2.GetDenominator()),
		multiplier);
}

CRational operator-(const CRational& numberONE, const CRational& number2)
{
	int multiplier = GetLeastCommonMultiplier(numberONE.GetDenominator(), number2.GetDenominator());
	return CRational(numberONE.GetNumerator() * (multiplier / numberONE.GetDenominator()) - number2.GetNumerator() * (multiplier / number2.GetDenominator()),
		multiplier);
}

CRational operator*(const CRational& numberONE, const CRational& number2)
{
	return CRational(numberONE.GetNumerator() * number2.GetNumerator(), numberONE.GetDenominator() * number2.GetDenominator());
}

CRational operator/(const CRational& numberONE, const CRational& number2)
{
	return CRational(numberONE.GetNumerator() * number2.GetDenominator(), numberONE.GetDenominator() * number2.GetNumerator());
}

bool operator==(const CRational& numberONE, const CRational& number2)
{
	return (numberONE.ToDouble() == number2.ToDouble());
}

bool operator!=(const CRational& numberONE, const CRational& number2)
{
	return (numberONE.ToDouble() != number2.ToDouble());
}

bool operator<(const CRational& numberONE, const CRational& number2)
{
	return (numberONE.ToDouble() < number2.ToDouble());
}

bool operator>(const CRational& numberONE, const CRational& number2)
{
	return (numberONE.ToDouble() > number2.ToDouble());
}

bool operator<=(const CRational& numberONE, const CRational& number2)
{
	return (numberONE.ToDouble() <= number2.ToDouble());
}

bool operator>=(const CRational& numberONE, const CRational& number2)
{
	return (numberONE.ToDouble() >= number2.ToDouble());
}

std::istream& operator>>(std::istream& inStream, CRational& number)
{
	int numerator;
	int denominator;
	if (inStream >> numerator && inStream.get() == SLASH1 && inStream >> denominator)
	{
		number = CRational(numerator, denominator);
	}
	else
	{
		inStream.setstate(std::ios_base::failbit);
	}
	return inStream;
}

std::ostream& operator <<(std::ostream& outStream, const CRational& number)
{
	outStream << number.GetNumerator() << SLASH << number.GetDenominator();
	return outStream;
}