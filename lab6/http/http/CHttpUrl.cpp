#include "CHttpUrl.h"
#include "CUrlParsingError.h"

CHttpUrl::CHttpUrl(const std::string& url)
{
	try
	{
		ParseUrl(url);
	}
	catch (std::invalid_argument& error)
	{
		throw CUrlParsingError(error.what());
	}
}

CHttpUrl::CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol)
{
	try
	{
		Initialize(domain, document, protocol, GetDefaultPort(protocol));
	}
	catch (std::invalid_argument& error)
	{
		throw std::invalid_argument(error.what());
	}
}

CHttpUrl::CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol, unsigned short port)
{
	try
	{
		Initialize(domain, document, protocol, port);
	}
	catch (std::invalid_argument& error)
	{
		throw std::invalid_argument(error.what());
	}
}

std::string CHttpUrl::GetURL() const
{
	std::stringstream urlStream;
	urlStream << (m_protocol == Protocol::HTTP ? HTTP_PREFIX : HTTPS_PREFIX)
		<< m_domain
		<< (m_port != GetDefaultPort(m_protocol) ? (COLON + std::to_string(m_port)) : "")
		<< m_document;
	return urlStream.str();
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

void CHttpUrl::ParseUrl(const std::string& url)
{
	std::string domain;
	std::string portStr;
	std::string document;
	Protocol protocol;

	ExtractUrlComponents(url, domain, portStr, document, protocol);
	unsigned short port = ParsePort(portStr, protocol);
	SetUrlComponents(domain, document, protocol, port);
}

void CHttpUrl::Initialize(const std::string& domain, const std::string& document, Protocol protocol, unsigned short port)
{
	if (domain.empty())
		throw std::invalid_argument(ERROR_EMPTY_DOMAIN);
	if (port < MIN_PORT_VALUE || port > MAX_PORT_VALUE)
		throw std::invalid_argument(ERROR_INVALID_PORT);

	SetUrlComponents(domain, document, protocol, port);
}

unsigned short CHttpUrl::ParsePort(const std::string& portStr, Protocol protocol)
{
	if (portStr.empty())
		return GetDefaultPort(protocol);

	unsigned short port = std::stoi(portStr);

	if (port < MIN_PORT_VALUE || port > MAX_PORT_VALUE)
		throw std::invalid_argument(ERROR_INVALID_PORT);

	return port;
}

std::string CHttpUrl::AddLeadingSlashIfNeeded(const std::string& document)
{
	if (document.empty() || document[0] == SLASH)
		return document;
	else
		return SLASH + document;
}

void CHttpUrl::ExtractUrlComponents(const std::string& url, std::string& domain, std::string& portStr, std::string& document, Protocol& protocol)
{
	std::smatch urlMatch;

	if (!std::regex_match(url, urlMatch, URL_REGEX))
		throw std::invalid_argument(ERROR_INVALID_URL);

	protocol = (urlMatch[PROTOCOL_REGEX_INDEX] == HTTP) ? Protocol::HTTP : Protocol::HTTPS;
	domain = urlMatch[DOMAIN_REGEX_INDEX];
	portStr = urlMatch[PORT_REGEX_INDEX];
	document = urlMatch[DOCUMENT_REGEX_INDEX];
}

void CHttpUrl::SetUrlComponents(const std::string& domain, const std::string& document, Protocol protocol, unsigned short port)
{
	m_protocol = protocol;
	m_document = AddLeadingSlashIfNeeded(document);
	m_domain = domain;
	m_port = port;
}

unsigned short CHttpUrl::GetDefaultPort(Protocol protocol)
{
	return (protocol == Protocol::HTTP) ? HTTP_PORT : HTTPS_PORT;
}