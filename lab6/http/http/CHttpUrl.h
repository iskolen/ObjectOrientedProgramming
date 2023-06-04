#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <regex>

const std::regex URL_REGEX(R"(^(http|https)://([^/:]+)(?::(\d+))?(/.*)?$)");

const std::string HTTP = "http";
const std::string HTTP_PREFIX = "http://";
const std::string HTTPS_PREFIX = "https://";
const std::string ERROR_PARSING_URL = "Error parsing URL: ";
const std::string ERROR_INVALID_URL = "Invalid URL format";
const std::string ERROR_INVALID_PORT = "Invalid port number";
const std::string ERROR_EMPTY_DOMAIN = "Empty domain";

const std::string MESSAGE_URL = "URL: ";
const std::string MESSAGE_DOMAIN = "Domain: ";
const std::string MESSAGE_DOCUMENT = "Document: ";
const std::string MESSAGE_PROTOCOL = "Protocol: ";
const std::string MESSAGE_PORT = "Port: ";
const std::string MESSAGE_HTTP = "HTTP";
const std::string MESSAGE_HTTPS = "HTTPS";

const char COLON = ':';
const char SLASH = '/';
const char RUSSIAN_LANGUAGE[8] = "Russian";

const int MIN_PORT_VALUE = 0;
const int MAX_PORT_VALUE = 65535;

const int PROTOCOL_REGEX_INDEX = 1;
const int DOMAIN_REGEX_INDEX = 2;
const int PORT_REGEX_INDEX = 3;
const int DOCUMENT_REGEX_INDEX = 4;

const unsigned short HTTP_PORT = 80;
const unsigned short HTTPS_PORT = 443;

enum class Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	CHttpUrl(const std::string& url);
	CHttpUrl(
		const std::string& domain,
		const std::string& document,
		Protocol protocol = Protocol::HTTP);
	CHttpUrl(
		const std::string& domain,
		const std::string& document,
		Protocol protocol,
		unsigned short port);

	std::string GetURL() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;

private:
	void ParseUrl(const std::string& url);
	void Initialize(
		const std::string& domain,
		const std::string& document,
		Protocol protocol,
		unsigned short port);

	Protocol m_protocol;
	std::string m_domain;
	std::string m_document;
	unsigned short m_port;

	static unsigned short GetDefaultPort(Protocol protocol);
};
