#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../vectorstl/vectorstlhead.h"

SCENARIO("Empty vector gives empty vector")
{
	WHEN("input string is empty")
	{
		std::vector<float> empty = {};
		std::vector<float> process = {};
		THEN("Output string is also empty")
		{
			ProcessVector(process);
			REQUIRE(process == empty);
			PrintVector(process);
			REQUIRE(process == empty);
		}
	}
}
SCENARIO("Vector works succesfully with 2 numbers")
{
	WHEN("input string consists of 2 numbers")
	{
		std::vector<float> process = { 5.00, 2.00 };
		std::vector<float> check = { 10.00, -5.00 };
		std::vector<float> out = { -5.00, 10.00 };
		THEN("Process with vector")
		{
			ProcessVector(process);
			REQUIRE(process == check);
			THEN("Output vector")
			{
				std::sort(process.begin(), process.end());
				PrintVector(process);
				REQUIRE(process == out);
			}
		}
	}
}

SCENARIO("Vector works succesfully with numbers")
{
	WHEN("input string consists many numbers")
	{
		std::vector<float> process = { 5.00, 2.00, 13.05, 6.03, 1.00, 3.5, 6.78, 0 };
		std::vector<float> check = { 10, -35.36, 26.1, -31.33, 2 ,-33.86, 13.56, -37.36 };
		std::vector<float> out = { -37.36 ,- 35.36, -33.86, -31.33, 2 ,10, 13.56, 26.1 };
		THEN("Process with vector")
		{
			ProcessVector(process);
			REQUIRE(process == check);
			THEN("Output vector")
			{
				std::sort(process.begin(), process.end());
				PrintVector(process);
				REQUIRE(process == out);
			}
		}
	}
}
