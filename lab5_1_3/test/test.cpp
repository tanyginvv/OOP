#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab5_1_3/Rational.cpp"

TEST_CASE("object creation")
{
	SECTION("a rational number equal to 0")
	{
		CRational number;
		REQUIRE(number.GetNumerator() == 0);
		REQUIRE(number.GetDenominator() == 1);
		REQUIRE(number.ToDouble() == 0);
		std::cout << "A rational number equal to 0 success" << std::endl;
	}
	SECTION("a rational number equal to 4")
	{
		CRational number(4);
		REQUIRE(number.GetNumerator() == 4);
		REQUIRE(number.GetDenominator() == 1);
		REQUIRE(number.ToDouble() == 4.0);
		std::cout << "A rational number equal to 4 success" << std::endl;
	}
	SECTION("a rational number equal to 2/5")
	{
		CRational number(2, 5);
		REQUIRE(number.GetNumerator() == 2);
		REQUIRE(number.GetDenominator() == 5);
		REQUIRE(number.ToDouble() == 0.4);
		std::cout << "A rational number equal to 2/5 success" << std::endl;
	}
	SECTION("the numerator is 0")
	{
		CRational number(0, 7);
		REQUIRE(number.GetNumerator() == 0);
		REQUIRE(number.GetDenominator() == 1);
		REQUIRE(number.ToDouble() == 0);
		std::cout << "The numerator is 0 success" << std::endl;
	}
	SECTION("the denominator is 0")
	{
		CRational number(7, 0);
		REQUIRE(number.GetNumerator() == 0);
		REQUIRE(number.GetDenominator() == 1);
		REQUIRE(number.ToDouble() == 0);
		std::cout << "the denominator is 0 success" << std::endl;
	}
	SECTION("a rational number equal to -2/5, numerator < 0")
	{
		CRational number(-2, 5);
		REQUIRE(number.GetNumerator() == -2);
		REQUIRE(number.GetDenominator() == 5);
		REQUIRE(number.ToDouble() == -0.4);
		std::cout << "a rational number equal to -2/5, numerator < 0 success" << std::endl;
	}
	SECTION("a rational number equal to -2/5, denumerator < 0")
	{
		CRational number(2, -5);
		REQUIRE(number.GetNumerator() == -2);
		REQUIRE(number.GetDenominator() == 5);
		REQUIRE(number.ToDouble() == -0.4);
		std::cout << "a rational number equal to -2/5, denumerator < 0 success" << std::endl;
	}
	
}

TEST_CASE("unary")
{
	SECTION("unary +")
	{
		CRational number(2, 5);
		number = +number;
		REQUIRE(number.GetNumerator() == 2);
		REQUIRE(number.GetDenominator() == 5);
		REQUIRE(number.ToDouble() == 0.4);
		std::cout << "unary + success" << std::endl;

	}
	SECTION("unary -")
	{
		CRational number(2, 5);
		number = -number;
		REQUIRE(number.GetNumerator() == -2);
		REQUIRE(number.GetDenominator() == 5);
		REQUIRE(number.ToDouble() == -0.4);
		std::cout << "unary - success" << std::endl;
	}
}

TEST_CASE("+, -")
{
	SECTION("+")
	{
		CRational number1(2, 5);
		CRational number2(2, 5);
		CRational result = number1 + number2;
		REQUIRE(result.GetNumerator() == 4);
		REQUIRE(result.GetDenominator() == 5);
		REQUIRE(result.ToDouble() == 0.8);
		std::cout << "+ success" << std::endl;
	}
	SECTION("+")
	{
		CRational number1(2, 3);
		CRational number2(1, 6);
		CRational result = number1 + number2;
		REQUIRE(result.GetNumerator() == 5);
		REQUIRE(result.GetDenominator() == 6);
		std::cout << "+ success" << std::endl;
	}
	SECTION("+ int")
	{
		CRational number1(1, 5);
		CRational result = number1 + 1;
		REQUIRE(result.GetNumerator() == 6);
		REQUIRE(result.GetDenominator() == 5);
		REQUIRE(result.ToDouble() == 1.2);
		std::cout << "+ int" << std::endl;
	}
	SECTION("int +")
	{
		CRational number2(1, 5);
		CRational result = 1 + number2;
		REQUIRE(result.GetNumerator() == 6);
		REQUIRE(result.GetDenominator() == 5);
		REQUIRE(result.ToDouble() == 1.2);
		std::cout << "int +" << std::endl;
	}
	SECTION("-")
	{
		CRational number1(4, 5);
		CRational number2(-2, 5);
		CRational result = number1 - number2;
		REQUIRE(result.GetNumerator() == 6);
		REQUIRE(result.GetDenominator() == 5);
		REQUIRE(result.ToDouble() == 1.2);
		std::cout << "- success" << std::endl;
	}
	SECTION("- int")
	{
		CRational number1(10, 5);
		CRational result = number1 - 1;
		REQUIRE(result.GetNumerator() == 1);
		REQUIRE(result.GetDenominator() == 1);
		REQUIRE(result.ToDouble() == 1.0);
		std::cout << "- int success" << std::endl;
	}
	SECTION("int -")
	{
		CRational number2(20, 5);
		CRational result = 6 - number2;
		REQUIRE(result.GetNumerator() == 2);
		REQUIRE(result.GetDenominator() == 1);
		REQUIRE(result.ToDouble() == 2.0);
		std::cout << "int - success" << std::endl;

	}
}

TEST_CASE("+=, -=")
{
	SECTION("+=")
	{
		CRational number1(3, 4);
		CRational number2(1, 4);
		number1 += number2;
		REQUIRE(number1.GetNumerator() == 1);
		REQUIRE(number1.GetDenominator() == 1);
		REQUIRE(number1.ToDouble() == 1.0);
		std::cout << "+= success" << std::endl;
	}
	SECTION("+= int")
	{
		CRational number1(1, 1);
		number1 += 1;
		REQUIRE(number1.GetNumerator() == 2);
		REQUIRE(number1.GetDenominator() == 1);
		REQUIRE(number1.ToDouble() == 2.0);
		std::cout << "+= int success" << std::endl;
	}
	SECTION("-=")
	{
		CRational number1(3, 4);
		CRational number2(1, 4);
		number1 -= number2;
		REQUIRE(number1.GetNumerator() == 1);
		REQUIRE(number1.GetDenominator() == 2);
		REQUIRE(number1.ToDouble() == 0.5);
		std::cout << "-= success" << std::endl;
	}
	SECTION("-= int")
	{
		CRational number1(4, 4);
		number1 -= 1;
		REQUIRE(number1.GetNumerator() == 0);
		REQUIRE(number1.GetDenominator() == 1);
		REQUIRE(number1.ToDouble() == 0);
		std::cout << "-= int success" << std::endl;
	}
}

TEST_CASE("*, /")
{
	SECTION("*")
	{
		CRational number1(3, 4);
		CRational number2(1, 4);
		CRational result = number1 * number2;
		REQUIRE(result.GetNumerator() == 3);
		REQUIRE(result.GetDenominator() == 16);
		REQUIRE(result.ToDouble() == 0.188);
		std::cout << "* success" << std::endl;
	}
	SECTION("* int")
	{
		CRational number1(3, 4);
		CRational result = number1 * 0;
		REQUIRE(result.GetNumerator() == 0);
		REQUIRE(result.GetDenominator() == 1);
		REQUIRE(result.ToDouble() == 0);
		std::cout << "* int success" << std::endl;
	}
	SECTION("int *")
	{
		CRational number2(1, 4);
		CRational result = 3 * number2;
		REQUIRE(result.GetNumerator() == 3);
		REQUIRE(result.GetDenominator() == 4);
		REQUIRE(result.ToDouble() == 0.75);
		std::cout << "int * success" << std::endl;
	}
	SECTION("/")
	{
		CRational number1(3, 4);
		CRational number2(1, 4);
		CRational result = number1 / number2;
		REQUIRE(result.GetNumerator() == 3);
		REQUIRE(result.GetDenominator() == 1);
		REQUIRE(result.ToDouble() == 3.0);
		std::cout << "/ success" << std::endl;
	}
	SECTION("/ int")
	{
		CRational number1(3, 4);
		CRational result = number1 / 3;
		REQUIRE(result.GetNumerator() == 1);
		REQUIRE(result.GetDenominator() == 4);
		REQUIRE(result.ToDouble() == 0.25);
		std::cout << "/ int success" << std::endl;
	}
	SECTION("int /")
	{
		CRational number2(1, 4);
		CRational result = 1 / number2;
		REQUIRE(result.GetNumerator() == 4);
		REQUIRE(result.GetDenominator() == 1);
		REQUIRE(result.ToDouble() == 4.0);
		std::cout << "int / success" << std::endl;
	}
}

TEST_CASE("*=, /=")
{
	SECTION("*=")
	{
		CRational number1(3, 4);
		CRational number2(1, 4);
		number1 *= number2;
		REQUIRE(number1.GetNumerator() == 3);
		REQUIRE(number1.GetDenominator() == 16);
		REQUIRE(number1.ToDouble() == 0.188);
		std::cout << "*= success" << std::endl;
	}
	SECTION("*= int")
	{
		CRational number1(3, 4);
		number1 *= 2;
		REQUIRE(number1.GetNumerator() == 3);
		REQUIRE(number1.GetDenominator() == 2);
		REQUIRE(number1.ToDouble() == 1.5);
		std::cout << "*= int success" << std::endl;
	}
	SECTION("/=")
	{
		CRational number1(3, 4);
		CRational number2(1, 4);
		number1 /= number2;
		REQUIRE(number1.GetNumerator() == 3);
		REQUIRE(number1.GetDenominator() == 1);
		REQUIRE(number1.ToDouble() == 3.0);
		std::cout << "/= success" << std::endl;
	}
	SECTION("/= int")
	{
		CRational number1(3, 4);
		number1 /= 3;
		REQUIRE(number1.GetNumerator() == 1);
		REQUIRE(number1.GetDenominator() == 4);
		REQUIRE(number1.ToDouble() == 0.25);
		std::cout << "/= int success" << std::endl;
	}
}

TEST_CASE("==, !=")
{
	SECTION("==")
	{
		CRational number1(3, 4);
		CRational number2(1, 4);
		REQUIRE((number1 == number2) == false);
		std::cout << "== success" << std::endl;
	}
	SECTION("== int")
	{
		CRational number1(3, 4);
		REQUIRE((number1 == 3) == false);
		std::cout << "== int success" << std::endl;
	}
	SECTION("int ==")
	{
		CRational number1(4, 4);
		REQUIRE((1 == number1) == true);
		std::cout << "int == success" << std::endl;
	}
	SECTION("!=")
	{
		CRational number1(3, 4);
		CRational number2(1, 4);
		REQUIRE((number1 != number2) == true);
		std::cout << "!= success" << std::endl;
	}
	SECTION("!= int")
	{
		CRational number1(3, 4);
		REQUIRE((number1 != 7) == true);
		std::cout << "!= int success" << std::endl;
	}
	SECTION("int !=")
	{
		CRational number1(4, 4);
		REQUIRE((1 != number1) == false);
		std::cout << "int != success" << std::endl;
	}
}

TEST_CASE("<, >")
{
	SECTION("<")
	{
		CRational number1(3, 4);
		CRational number2(1, 4);
		REQUIRE((number1 < number2) == false);
		std::cout << "< success" << std::endl;
	}
	SECTION("< int")
	{
		CRational number1(3, 4);
		REQUIRE((number1 < -3) == false);
		std::cout << "< int success" << std::endl;
	}
	SECTION(">")
	{
		CRational number1(3, 4);
		CRational number2(1, 4);
		REQUIRE((number1 > number2) == true);
		std::cout << "> success" << std::endl;
	}
	SECTION("> int")
	{
		CRational number1(3, 4);
		REQUIRE((number1 > -2) == true);
		std::cout << "> int success" << std::endl;
	}
}

TEST_CASE("<=, >=")
{
	SECTION("<=")
	{
		CRational number1(3, 4);
		CRational number2(1, 4);
		REQUIRE((number1 <= number2) == false);
		std::cout << "<= success" << std::endl;
	}
	SECTION("<= int")
	{
		CRational number1(3, 4);
		REQUIRE((number1 <= -1) == false);
		std::cout << "<= int success" << std::endl;
	}
	SECTION(">=")
	{
		CRational number1(3, 4);
		CRational number2(1, 4);
		REQUIRE((number1 >= number2) == true);
		std::cout << ">= success" << std::endl;
	}
	SECTION(">= int")
	{
		CRational number1(3, 4);
		REQUIRE((number1 >= 0) == true);
		std::cout << ">= int success" << std::endl;
	}
}

TEST_CASE("<<, >>")
{
	SECTION("<<")
	{
		CRational number(-7, 15);
		std::ostringstream strm("");
		strm << number;
		REQUIRE(strm.str() == "-7/15");
		std::cout << "<< success" << std::endl;
	}
	SECTION(">>")
	{
		CRational number;
		std::istringstream strm("7/15");
		strm >> number;
		REQUIRE(number.GetNumerator() == 7);
		REQUIRE(number.GetDenominator() == 15);
		std::cout << ">> success" << std::endl;
	}
}

TEST_CASE("to compound fraction")
{
	SECTION("a positive number to compound fraction")
	{
		CRational number1(7, 4);
		std::pair<int, CRational> result = number1.ToCompoundFraction();
		REQUIRE(result.first == 1);
		REQUIRE(result.second.GetNumerator() == 3);
		REQUIRE(result.second.GetDenominator() == 4);
		std::cout << "a positive number to compound fraction success" << std::endl;
	}

	SECTION("a negative number to compound fraction")
	{
		CRational number1(-7, 4);
		std::pair<int, CRational> result = number1.ToCompoundFraction();
		REQUIRE(result.first == -1);
		REQUIRE(result.second.GetNumerator() == -3);
		REQUIRE(result.second.GetDenominator() == 4);
		std::cout << "a negative number to compound fraction success" << std::endl;
	}

	SECTION("a number whithout intPart to compound fraction")
	{
		CRational number1(3, 4);
		std::pair<int, CRational> result = number1.ToCompoundFraction();
		REQUIRE(result.first == 0);
		REQUIRE(result.second.GetNumerator() == 3);
		REQUIRE(result.second.GetDenominator() == 4);
		std::cout << "a number whithout intPart to compound fraction success" << std::endl;
	}
}