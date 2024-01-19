#define CATCH_CONFIG_MAIN
#include "../../ooplabs/catch2/catch.hpp"
#include "../../ooplabs/lab7_1_3/FindMaxEx.h"

struct Sportsman
{
	std::string name;
	int height;
	int weight;
};

TEST_CASE("correct")
{
	SECTION("int")
	{
		std::vector<int> arr = { 1, 67, 4, 9, 34 };
		int max;
		bool isArrayNotEmpty;
		isArrayNotEmpty = FindMaxEx(arr, max, [](int a, int b) {return a < b; });
		REQUIRE(max == 67);
		REQUIRE(isArrayNotEmpty == true);
		std::cout << "correct int complete" << std::endl;
	}

	SECTION("double")
	{
		std::vector<double> arr = { 1.1 , 67.4 , 67.4, 67.9, 34.0 };
		double max;
		bool isArrayNotEmpty;
		isArrayNotEmpty = FindMaxEx(arr, max, [](double a, double b) {return a < b; });
		REQUIRE(max == 67.9);
		REQUIRE(isArrayNotEmpty == true);
		std::cout << "correct double complete" << std::endl;
	}

	SECTION("srting")
	{
		std::vector<std::string> arr = { "1", "12", "1234" };
		std::string max;
		bool isArrayNotEmpty;
		isArrayNotEmpty = FindMaxEx(arr, max, [](std::string const& a, std::string const& b) {return a < b; });
		REQUIRE(max == "1234");
		REQUIRE(isArrayNotEmpty == true);
		std::cout << "correct string complete" << std::endl;
	}

	SECTION("only one number in array")
	{
		std::vector<int> arr = { 1 };
		int max;
		bool isArrayNotEmpty;
		isArrayNotEmpty = FindMaxEx(arr, max, [](int a, int b) {return a < b; });
		REQUIRE(max == 1);
		REQUIRE(isArrayNotEmpty == true);
		std::cout << "correct only one number in array complete" << std::endl;
	}

	SECTION("Sportsman")
	{
		std::vector<Sportsman> arr = { {"Peter", 170, 90}, {"James", 180, 87}, {"Williams", 178, 98} };
		Sportsman max;
		bool isArrayNotEmpty;
		isArrayNotEmpty = FindMaxEx(arr, max, [](Sportsman const& a, Sportsman const& b) {return a.height < b.height; });
		REQUIRE(isArrayNotEmpty == true);
		REQUIRE(max.name == "James");
		isArrayNotEmpty = FindMaxEx(arr, max, [](Sportsman const& a, Sportsman const& b) {return a.weight < b.weight; });
		REQUIRE(isArrayNotEmpty == true);
		REQUIRE(max.name == "Williams");
		std::cout << "correct sportsman complete" << std::endl;
	}

}

TEST_CASE("incorrect data")
{
	SECTION("empty array of int")
	{
		std::vector<int> arr = {};
		int max;
		bool isArrayNotEmpty;
		isArrayNotEmpty = FindMaxEx(arr, max, [](int a, int b) {return a < b; });
		REQUIRE(isArrayNotEmpty == false);
		std::cout << "incorrect empty array of int complete" << std::endl;
	}

	SECTION(" empty array of Sportsman")
	{
		std::vector<Sportsman> arr = { {"Peter", 170, 90}, {"James", NULL, 87}, {"Williams", 178, NULL} };
		Sportsman max;
		bool isArrayNotEmpty;
		isArrayNotEmpty = FindMaxEx(arr, max, [](Sportsman const& a, Sportsman const& b) {return a.height < b.height; });
		REQUIRE(isArrayNotEmpty == true);
		isArrayNotEmpty = FindMaxEx(arr, max, [](Sportsman const& a, Sportsman const& b) {return a.weight < b.weight; });
		REQUIRE(isArrayNotEmpty == true);
		std::cout << "incorrect empty array of sprotsman complete" << std::endl;
	}

}