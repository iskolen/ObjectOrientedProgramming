#include "CHttpUrl.h"
#include "CUrlParsingError.h"

CHttpUrl::CHttpUrl(const std::string& url)
{
	ParseUrl(url);
}

CHttpUrl::CHttpUrl(
	const std::string& domain,
	const std::string& document,
	Protocol protocol)
{
	Initialize(domain, document, protocol, GetDefaultPort(protocol));
}

CHttpUrl::CHttpUrl(
	const std::string& domain,
	const std::string& document,
	Protocol protocol,
	unsigned short port)
{
	Initialize(domain, document, protocol, port);
}

std::string CHttpUrl::GetURL() const
{
	std::stringstream urlStream;
	urlStream << (m_protocol == Protocol::HTTP ? HTTP_PREFIX : HTTPS_PREFIX);
	urlStream << m_domain;
	if (m_port != GetDefaultPort(m_protocol))
	{
		urlStream << COLON << m_port;
	}
	urlStream << m_document;
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
	std::smatch urlMatch;

	if (!std::regex_match(url, urlMatch, URL_REGEX))
		throw CUrlParsingError(ERROR_INVALID_URL);

	Protocol protocol = (urlMatch[PROTOCOL_REGEX_INDEX] == HTTP) ? Protocol::HTTP : Protocol::HTTPS;
	std::string domain = urlMatch[DOMAIN_REGEX_INDEX];
	std::string portStr = urlMatch[PORT_REGEX_INDEX];
	std::string document = urlMatch[DOCUMENT_REGEX_INDEX];

	unsigned short port = GetDefaultPort(protocol);
	if (!portStr.empty())
	{
		int portValue = std::stoi(portStr);
		if (portValue < MIN_PORT_VALUE || portValue > MAX_PORT_VALUE)
		{
			throw CUrlParsingError(ERROR_INVALID_PORT);
		}
		port = static_cast<unsigned short>(portValue);
	}

	Initialize(domain, document, protocol, port);
}

void CHttpUrl::Initialize(
	const std::string& domain,
	const std::string& document,
	Protocol protocol,
	unsigned short port)
{
	if (domain.empty())
		throw CUrlParsingError(ERROR_EMPTY_DOMAIN);

	if (document[0] != SLASH)
		m_document = SLASH + document;
	else
		m_document = document;

	m_protocol = protocol;
	m_domain = domain;
	m_port = port;
}

unsigned short CHttpUrl::GetDefaultPort(Protocol protocol)
{
	return (protocol == Protocol::HTTP) ? HTTP_PORT : HTTPS_PORT;
}