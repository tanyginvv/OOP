#include <iostream>
#include <iomanip>
#include <sstream>
const int ZER0 = 0;
const int ONE = 1;
const std::string SLASH = "/";
const int SLASH1 = '/';

class CRational
{
public:
	//  онструирует рациональное число, равное нулю (ZER0/ONE)
	CRational();
	//  онструирует рациональное число, равное value (value/ONE)
	CRational(int value);

	//  онструирует рациональное число, равное numerator/denominator
	// –ациональное число должно хранитьс€ в нормализованном виде:
	//	знаменатель положительный (числитель может быть отрицательным)
	//	числитель и знаменатель не имеют общиз делителей (6/8 => 3/4 и т.п.)
	// ≈сли знаменатель равен нулю, должно сконструироватьс€ рациональное число, равное нулю,
	// либо должно быть выброшено исключение std::invalid_argument.
	CRational(int numerator, int denominator);

	// ¬озвращает числитель
	int GetNumerator()const;
	// ¬озвращает знаменатель (натуральное число)
	int GetDenominator()const;
	// ¬озвращает отношение числител€ и знаменател€ в виде числа double
	double ToDouble()const;

	CRational const operator + () const;
	CRational const operator - () const;
	CRational& operator+=(const CRational& number);
	CRational& operator-=(const CRational& number);
	CRational& operator*=(const CRational& number);
	CRational& operator/=(const CRational& number);
	// ¬озвращает представление рационального числа в виде смешанной дроби
	std::pair<int, CRational> ToCompoundFraction()const;

private:
	int m_numerator;
	int m_denominator;
	void Normalize();

};

CRational operator+(const CRational& numberONE, const CRational& number2);
CRational operator-(const CRational& numberONE, const CRational& number2);

CRational operator*(const CRational& numberONE, const CRational& number2);
CRational operator/(const CRational& numberONE, const CRational& number2);

bool operator==(const CRational& numberONE, const CRational& number2);
bool operator!=(const CRational& numberONE, const CRational& number2);

bool operator<(const CRational& numberONE, const CRational& number2);
bool operator>(const CRational& numberONE, const CRational& number2);

bool operator<=(const CRational& numberONE, const CRational& number2);
bool operator>=(const CRational& numberONE, const CRational& number2);


std::istream& operator >>(std::istream& inStream, CRational& number);
std::ostream& operator <<(std::ostream& outStream, const CRational& number);

int GetLeastCommonMultiplier(int a, int b); //ѕолучение наименьшего общего кратного
int GreatestCommonDivisor(int a, int b);//ѕолучение наибольшего общего делител€