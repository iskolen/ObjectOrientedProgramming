#include "CHttpUrl.h"
#include "CUrlParsingError.h"

int main()
{
	std::string url;
	while (std::getline(std::cin, url))
	{
		try
		{
			CHttpUrl httpUrl(url);
			std::cout << MESSAGE_URL << httpUrl.GetURL() << std::endl;
			std::cout << MESSAGE_DOMAIN << httpUrl.GetDomain() << std::endl;
			std::cout << MESSAGE_DOCUMENT << httpUrl.GetDocument() << std::endl;
			std::cout << MESSAGE_PROTOCOL << (httpUrl.GetProtocol() == Protocol::HTTP ? MESSAGE_HTTP : MESSAGE_HTTPS) << std::endl;
			std::cout << MESSAGE_PORT << httpUrl.GetPort() << std::endl;
		}
		catch (const CUrlParsingError& error)
		{
			std::cerr << ERROR_PARSING_URL << error.what() << std::endl;
		}
	}

	return 0;
}
