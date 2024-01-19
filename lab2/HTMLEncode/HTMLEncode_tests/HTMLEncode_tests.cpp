#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../HTMLEncode/Encode.h"

SCENARIO("Empty string gives empty string") {
	std::string text = "";
	std::string expected = "";
	REQUIRE(HtmlEncode(text) == expected);
}
SCENARIO("HtmlEncode replaces character in string") {
	std::string text = "<";
	std::string expected = "&lt;";

	REQUIRE(HtmlEncode(text) == expected);
}
SCENARIO("HtmlEncode replaces special characters with corresponding HTML entities") {
	std::string text = R"(<p>"'&</p>)";
	std::string expected = R"(&lt;p&gt;&quot;&apos;&amp;&lt;/p&gt;)";

	REQUIRE(HtmlEncode(text) == expected);
}
