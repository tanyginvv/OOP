#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include <regex>
const std::string INVALID_URL = "invalid url";
const std::string INVALID_DOMAIN = "invalid domain";
const std::string INVALID_PROTOCOL = "invalid protocol";
const std::string INVALID_PORT = "invalid port";
const std::string HTTP = "http";
const std::string HTTPS = "https";
const int SLASH1 = '/';
const std::string SLASH2 = "/";
const std::string COLON = ":";
const std::string COLON_SLASH = "://";
const int ONE = 1;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int ZERO = 0;
const std::string EMPTY_STRING = "";
const int MIN_HTTP_PORT = 80;
const int MIN_HTTPS_PORT = 443;
const int MAX_PORT = 65535;



CHttpUrl::CHttpUrl(std::string const& url)
{
	std::regex urlRegex(R"(^(.+)://([^/:]+)(:?)([^/]*)(/?.*)$)");
	std::smatch match;

	if (!regex_search(url, match, urlRegex))
	{
		throw CUrlParsingError(INVALID_URL);
	}

	std::string protocolString = match[ONE];
	std::string domain = match[TWO];
	std::string port = match[FOUR].matched ? match[FOUR].str() : EMPTY_STRING;
	std::string document = match[FIVE].str();

	m_protocol = ConvertToValidProtocol(protocolString);
	if (domain.empty())
	{
		throw CUrlParsingError(INVALID_DOMAIN);
	}
	m_domain = domain;
	m_port = ConvertToValidPort(port);
	m_document = ConvertToValidDocument(document);
}

CHttpUrl::CHttpUrl(std::string const& domain,
	std::string const& document,
	Protocol protocol)
{
	if (domain.empty())
	{
		throw CUrlParsingError(INVALID_DOMAIN);
	}
	m_domain = domain;
	m_protocol = protocol;
	m_document = ConvertToValidDocument(document);
	std::string port = EMPTY_STRING;
	m_port = ConvertToValidPort(port);

}

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol,
	unsigned short port)
{
	if (domain.empty())
	{
		throw CUrlParsingError(INVALID_DOMAIN);
	}
	m_domain = domain;
	m_protocol = protocol;
	m_document = ConvertToValidDocument(document);
	m_port = port;
}

Protocol CHttpUrl::ConvertToValidProtocol(std::string& protocolString) const
{
	std::transform(protocolString.begin(), protocolString.end(), protocolString.begin(), tolower);
	if (protocolString == HTTP)
	{
		return Protocol::HTTP;
	}
	if (protocolString == HTTPS)
	{
		return Protocol::HTTPS;
	}
	throw CUrlParsingError(INVALID_PROTOCOL);
}

unsigned short CHttpUrl::ConvertToValidPort(const std::string& strPort) const
{
	if (strPort.empty())
	{
		if (m_protocol == Protocol::HTTP)
		{
			return MIN_HTTP_PORT;
		}
		if (m_protocol == Protocol::HTTPS)
		{
			return MIN_HTTPS_PORT;
		}
	}

	int portNum;
	try
	{
		portNum = std::stoi(strPort);
	}
	catch (const std::exception& e)
	{
		throw CUrlParsingError(INVALID_PORT);
	}

	if (portNum <= ZERO || portNum > MAX_PORT)
	{
		throw CUrlParsingError(INVALID_PORT);
	}

	return portNum;
}

std::string CHttpUrl::ConvertToValidDocument(std::string const& document) const
{
	if (document.empty() || document[ZERO] != SLASH1)
	{
		return SLASH2 + document;
	}
	return document;
}

std::string CHttpUrl::GetURL() const
{
	std::string port;
	if (!((m_protocol == Protocol::HTTP && m_port == MIN_HTTP_PORT) || (m_protocol == Protocol::HTTPS && m_port == MIN_HTTPS_PORT)))
	{
		port = COLON + std::to_string(m_port);
	}
	return GetProtocolLikeString() + COLON_SLASH + m_domain + port + m_document;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

std::string CHttpUrl::GetProtocolLikeString() const
{
	if (m_protocol == Protocol::HTTP)
	{
		return HTTP;
	}

	return HTTPS;

}