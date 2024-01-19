#pragma once

#include <string>

enum class Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	CHttpUrl(std::string const& url);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol = Protocol::HTTP);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port);

	std::string GetURL() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;

	std::string GetProtocolLikeString() const;

private:
	void ParseUrl(std::string const& url);
	std::string ConvertToValidDocument(std::string const& document) const;
	Protocol ConvertToValidProtocol(std::string& protocolString) const;
	unsigned short ConvertToValidPort(const std::string& strPort) const;

	std::string m_url;
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;
};

