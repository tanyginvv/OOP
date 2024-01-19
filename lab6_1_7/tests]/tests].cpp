#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab6_1_7/CHttpUrl.cpp"
#include "../lab6_1_7/CUrlParsingError.cpp"

TEST_CASE("correct")
{
	SECTION("Parse sample URL from string")
	{
		std::string str("http://www.example.com/docs/document1.html?page=30&lang=en#title");

		REQUIRE_NOTHROW(CHttpUrl(str));
		CHttpUrl url(str);
		REQUIRE(url.GetURL() == str);
		std::cout << "Parse sample URL from string complete" << std::endl;
	}

	SECTION("Parse sample URL from string with HTTP")
	{
		std::string str("HTTP://www.example.com/docs/document1.html?page=30&lang=en#title");
		std::string strOut("http://www.example.com/docs/document1.html?page=30&lang=en#title");

		REQUIRE_NOTHROW(CHttpUrl(str));
		CHttpUrl url(str);
		REQUIRE(url.GetURL() == strOut);
		std::cout << "Parse sample URL from string with HTTP complete" << std::endl;
	}

	SECTION("Parse sample URL with 3 parameters")
	{
		std::string str("http://www.example.com/docs/document1.html?page=30&lang=en#title");

		REQUIRE_NOTHROW(CHttpUrl("www.example.com", "/docs/document1.html?page=30&lang=en#title", Protocol::HTTP));
		CHttpUrl url("www.example.com", "/docs/document1.html?page=30&lang=en#title", Protocol::HTTP);
		REQUIRE(url.GetURL() == str);
		std::cout << "Parse sample URL with 3 parameters complete" << std::endl;
	}

	SECTION("Parse sample URL with 4 parameters")
	{
		std::string str("http://www.example.com:8080/path/");

		REQUIRE_NOTHROW(CHttpUrl("www.example.com", "/path/", Protocol::HTTP, 8080));
		CHttpUrl url("www.example.com", "/path/", Protocol::HTTP, 8080);
		REQUIRE(url.GetURL() == str);
		std::cout << "Parse sample URL with 4 parameters complete" << std::endl;
	}

	SECTION("Parse sample URL with 4 parameters, document without /")
	{
		std::string str("http://www.example.com:8080/path/");

		REQUIRE_NOTHROW(CHttpUrl("www.example.com", "/path/", Protocol::HTTP, 8080));
		CHttpUrl url("www.example.com", "path/", Protocol::HTTP, 8080);
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetDomain() == "www.example.com");
		REQUIRE(url.GetPort() == 8080);
		REQUIRE(url.GetDocument() == "/path/");
		REQUIRE(url.GetURL() == str);
		std::cout << "Parse sample URL with 4 parameters, document without / complete" << std::endl;
	}

	SECTION("Parse URL with port '1'")
	{
		std::string str("https://www.example.com:1/path/");
		CHttpUrl url(str);
		REQUIRE(url.GetURL() == str);
		REQUIRE(url.GetProtocol() == Protocol::HTTPS);
		REQUIRE(url.GetDomain() == "www.example.com");
		REQUIRE(url.GetPort() == 1);
		REQUIRE(url.GetDocument() == "/path/");
		std::cout << "Parse URL with port '1' complete" << std::endl;
	}

	SECTION("Parse URL with port '65535'")
	{
		std::string str("https://www.example.com:65535/path/");
		CHttpUrl url(str);
		REQUIRE(url.GetURL() == str);
		REQUIRE(url.GetProtocol() == Protocol::HTTPS);
		REQUIRE(url.GetDomain() == "www.example.com");
		REQUIRE(url.GetPort() == 65535);
		REQUIRE(url.GetDocument() == "/path/");
		std::cout << "Parse URL with port '65535' complete" << std::endl;
	}

	SECTION("Parse URL with empty document'")
	{
		std::string urlStr("http://www.example.com");
		CHttpUrl url(urlStr);
		REQUIRE(url.GetURL() == urlStr + "/");
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetDomain() == "www.example.com");
		REQUIRE(url.GetPort() == 80);
		REQUIRE(url.GetDocument() == "/");
		std::cout << "Parse URL with empty document complete" << std::endl;
	}

}

TEST_CASE("incorrect")
{
	SECTION("Parse empty string")
	{
		std::string str("");
		REQUIRE_THROWS_WITH(CHttpUrl(str), "invalid url");
		std::cout << "Parse empty string complete" << std::endl;
	}

	SECTION("Parse URL with port 0")
	{
		std::string str("http://www.example.com:0/example");
		REQUIRE_THROWS_WITH(CHttpUrl(str), "invalid port");
		std::cout << "Parse URL with port 0 complete" << std::endl;
	}

	SECTION("Parse URL with port 65536")
	{
		std::string str("http://www.example.com:65536/example");
		REQUIRE_THROWS_WITH(CHttpUrl(str), "invalid port");
		std::cout << "Parse URL with port 65536 complete" << std::endl;
	}

	SECTION("Parse URL with port 75536")
	{
		std::string str("http://www.example.com:75536/example");
		REQUIRE_THROWS_WITH(CHttpUrl(str), "invalid port");
		std::cout << "Parse URL with port 75536 complete" << std::endl;
	}
	SECTION("Parse URL without domain")
	{
		std::string str("http://:0/example");
		REQUIRE_THROWS_WITH(CHttpUrl(str), "invalid url");
		std::cout << "Parse URL without domain complete" << std::endl;
	}
	SECTION("Parse URL with wrong protocol")
	{
		std::string str("ttp://www.example.com:6/example");
		REQUIRE_THROWS_WITH(CHttpUrl(str), "invalid protocol");
		std::cout << "Parse URL with wrong protocol complete" << std::endl;
	}
}