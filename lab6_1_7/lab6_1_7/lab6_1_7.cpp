#include "CHttpUrl.h"
#include <iostream>
#include <string>
const std::string URL = "URL: ";
const std::string DOMAIN_ = "Domain: ";
const std::string DOCUMENT = "Document: ";
const std::string PROTOCOL = "Protocol: ";
const std::string HTTP = "HTTP";
const std::string HTTPS = "HTTPS";
const std::string PORT = "Port: ";
const std::string ERROR = "Error: ";


int main()
{
	std::string url;
	while (std::getline(std::cin, url))
	{
		try
		{
			CHttpUrl httpUrl(url);
			std::cout << URL << httpUrl.GetURL() << std::endl;
			std::cout << DOMAIN_ << httpUrl.GetDomain() << std::endl;
			std::cout << DOCUMENT << httpUrl.GetDocument() << std::endl;
			std::cout << PROTOCOL <<((httpUrl.GetProtocol() == Protocol::HTTP) ? HTTP : HTTPS) << std::endl;
			std::cout << PORT << httpUrl.GetPort() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << ERROR << e.what() << std::endl;
		}
	}

	return 0;
}
