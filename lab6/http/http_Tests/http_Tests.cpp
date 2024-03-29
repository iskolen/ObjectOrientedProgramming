﻿#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../http/CHttpUrl.h"
#include "../http/CUrlParsingError.h"

TEST_CASE("Test CHttpUrl constructor from URL")
{
	SECTION("Test CHttpUrl constructor from URL - Valid HTTP URL")
	{
		CHttpUrl url("http://example.com/index.html");
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetDomain() == "example.com");
		REQUIRE(url.GetDocument() == "/index.html");
		REQUIRE(url.GetPort() == 80);
		std::cout << "Test CHttpUrl constructor from URL - Valid HTTP URL - Complete" << std::endl;
	}

	SECTION("Test CHttpUrl constructor from URL - Valid HTTPS URL")
	{
		CHttpUrl url("https://example.com/index.html");
		REQUIRE(url.GetProtocol() == Protocol::HTTPS);
		REQUIRE(url.GetDomain() == "example.com");
		REQUIRE(url.GetDocument() == "/index.html");
		REQUIRE(url.GetPort() == 443);
		std::cout << "Test CHttpUrl constructor from URL - Valid HTTPS URL - Complete" << std::endl;
	}

	SECTION("Test CHttpUrl constructor from URL - URL with port")
	{
		CHttpUrl url("https://example.com:8080/index.html");
		REQUIRE(url.GetProtocol() == Protocol::HTTPS);
		REQUIRE(url.GetDomain() == "example.com");
		REQUIRE(url.GetDocument() == "/index.html");
		REQUIRE(url.GetPort() == 8080);
		std::cout << "Test CHttpUrl constructor from URL - URL with port - Complete" << std::endl;
	}

	SECTION("Test CHttpUrl constructor from URL - Invalid URL")
	{
		REQUIRE_THROWS_AS(CHttpUrl("example.com"), CUrlParsingError);
		REQUIRE_THROWS_AS(CHttpUrl("http:/example.com/index.html"), CUrlParsingError);
		REQUIRE_THROWS_AS(CHttpUrl("http://example.com:abc/index.html"), CUrlParsingError);
		REQUIRE_THROWS_AS(CHttpUrl("http://example.com:-1/index.html"), CUrlParsingError);
		REQUIRE_THROWS_AS(CHttpUrl("http://example.com:65536/index.html"), CUrlParsingError);
		std::cout << "Test CHttpUrl constructor from URL - Invalid URL - Complete" << std::endl << std::endl;
	}
}

TEST_CASE("Test CHttpUrl constructor from Domain and Document")
{
	SECTION("Test CHttpUrl constructor from Domain and Document - Valid HTTP URL")
	{
		CHttpUrl url("/example.com", "/index.html", Protocol::HTTP);
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetDomain() == "/example.com");
		REQUIRE(url.GetDocument() == "/index.html");
		REQUIRE(url.GetPort() == 80);
		std::cout << "Test CHttpUrl constructor from Domain and Document - Valid HTTP URL - Complete" << std::endl;
	}

	SECTION("Test CHttpUrl constructor from Domain and Document - Valid HTTPS URL")
	{
		CHttpUrl url("/example.com", "/index.html", Protocol::HTTPS);
		REQUIRE(url.GetProtocol() == Protocol::HTTPS);
		REQUIRE(url.GetDomain() == "/example.com");
		REQUIRE(url.GetDocument() == "/index.html");
		REQUIRE(url.GetPort() == 443);
		std::cout << "Test CHttpUrl constructor from Domain and Document - Valid HTTPS URL - Complete" << std::endl;
	}

	SECTION("Test CHttpUrl constructor from Domain and Document - Invalid URL")
	{
		REQUIRE_THROWS_AS(CHttpUrl("", "/index.html", Protocol::HTTP), std::invalid_argument);
		REQUIRE_THROWS_AS(CHttpUrl("", "", Protocol::HTTP), std::invalid_argument);
		std::cout << "Test CHttpUrl constructor from Domain and Document - Invalid URL - Complete" << std::endl << std::endl;
	}
}

TEST_CASE("Test CHttpUrl constructor from Domain and Document with port")
{
	SECTION("Test CHttpUrl constructor from Domain and Document with port - Valid HTTP URL with port")
	{
		CHttpUrl url("/example.com", "/index.html", Protocol::HTTP, 8080);
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetDomain() == "/example.com");
		REQUIRE(url.GetDocument() == "/index.html");
		REQUIRE(url.GetPort() == 8080);
		std::cout << "Test CHttpUrl constructor from Domain and Document with port - Valid HTTP URL with port - Complete" << std::endl;
	}

	SECTION("Test CHttpUrl constructor from Domain and Document with port - Valid HTTPS URL with port")
	{
		CHttpUrl url("/example.com", "/index.html", Protocol::HTTPS, 880);
		REQUIRE(url.GetProtocol() == Protocol::HTTPS);
		REQUIRE(url.GetDomain() == "/example.com");
		REQUIRE(url.GetDocument() == "/index.html");
		REQUIRE(url.GetPort() == 880);
		std::cout << "Test CHttpUrl constructor from Domain and Document with port - Valid HTTPS URL with port - Complete" << std::endl;
	}

	SECTION("Test CHttpUrl constructor from Domain and Document with port - Invalid URL with port")
	{
		REQUIRE_THROWS_AS(CHttpUrl("", "/index.html", Protocol::HTTP, 8080), std::invalid_argument);
		REQUIRE_THROWS_AS(CHttpUrl("", "", Protocol::HTTP, 9090), std::invalid_argument);
		std::cout << "Test CHttpUrl constructor from Domain and Document with port - Invalid URL with port - Complete" << std::endl << std::endl;
	}
}

TEST_CASE("Test GetURL")
{
	SECTION("Test GetURL - HTTP URL with default port")
	{
		CHttpUrl url("http://www.example.com/document");
		REQUIRE(url.GetURL() == "http://www.example.com/document");
		std::cout << "Test GetURL - HTTP URL with default port - Complete" << std::endl;
	}

	SECTION("Test GetURL - HTTP URL with custom port")
	{
		CHttpUrl url("http://www.example.com:8080/document");
		REQUIRE(url.GetURL() == "http://www.example.com:8080/document");
		std::cout << "Test GetURL - HTTP URL with custom port - Complete" << std::endl;
	}

	SECTION("Test GetURL - HTTPS URL with default port")
	{
		CHttpUrl url("https://www.example.com/document");
		REQUIRE(url.GetURL() == "https://www.example.com/document");
		std::cout << "Test GetURL - HTTPS URL with default port - Complete" << std::endl;
	}

	SECTION("Test GetURL - HTTPS URL with custom port")
	{
		CHttpUrl url("https://www.example.com:8443/document");
		REQUIRE(url.GetURL() == "https://www.example.com:8443/document");
		std::cout << "Test GetURL - HTTPS URL with custom port - Complete" << std::endl << std::endl;
	}
}

TEST_CASE("Test GetDomain")
{
	SECTION("Test GetDomain - HTTP URL")
	{
		CHttpUrl url("http://www.example.com/document");
		REQUIRE(url.GetDomain() == "www.example.com");
		std::cout << "Test GetDomain - HTTP URL - Complete" << std::endl;
	}

	SECTION("Test GetDomain - HTTPS URL")
	{
		CHttpUrl url("https://www.example.com/document");
		REQUIRE(url.GetDomain() == "www.example.com");
		std::cout << "Test GetDomain - HTTPS URL - Complete" << std::endl << std::endl;
	}
}

TEST_CASE("Test GetDocument")
{
	SECTION("Test GetDocument - HTTP URL")
	{
		CHttpUrl url("http://www.example.com/document");
		REQUIRE(url.GetDocument() == "/document");
		std::cout << "Test GetDocument - HTTP URL - Complete" << std::endl;
	}

	SECTION("Test GetDocument - HTTPS URL")
	{
		CHttpUrl url("https://www.example.com/document");
		REQUIRE(url.GetDocument() == "/document");
		std::cout << "Test GetDocument - HTTP URLS - Complete" << std::endl << std::endl;
	}
}

TEST_CASE("Test GetProtocol")
{
	SECTION("Test GetProtocol - HTTP URL")
	{
		CHttpUrl url("http://www.example.com/document");
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		std::cout << "Test GetProtocol - HTTP URL - Complete" << std::endl;
	}

	SECTION("Test GetProtocol - HTTPS URL")
	{
		CHttpUrl url("https://www.example.com/document");
		REQUIRE(url.GetProtocol() == Protocol::HTTPS);
		std::cout << "Test GetProtocol - HTTPS URL - Complete" << std::endl << std::endl;
	}
}

TEST_CASE("Test GetPort")
{
	SECTION("Test GetPort - HTTP URL with default port")
	{
		CHttpUrl url("http://www.example.com/document");
		REQUIRE(url.GetPort() == 80);
		std::cout << "Test GetPort - HTTP URL with default port - Complete" << std::endl;
	}

	SECTION("Test GetPort - HTTP URL with custom port")
	{
		CHttpUrl url("http://www.example.com:8080/document");
		REQUIRE(url.GetPort() == 8080);
		std::cout << "Test GetPort - HTTP URL with custom port - Complete" << std::endl;
	}

	SECTION("Test GetPort - HTTPS URL with default port")
	{
		CHttpUrl url("https://www.example.com/document");
		REQUIRE(url.GetPort() == 443);
		std::cout << "Test GetPort - HTTPS URL with default port - Complete" << std::endl;
	}

	SECTION("Test GetPort - HTTPS URL with custom port")
	{
		CHttpUrl url("https://www.example.com:8443/document");
		REQUIRE(url.GetPort() == 8443);
		std::cout << "Test GetPort - HTTPS URL with custom port - Complete" << std::endl;
	}
}