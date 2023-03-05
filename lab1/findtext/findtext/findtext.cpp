#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

const char RUSSIAN_LANGUAGE[8] = "Russian";

const int RUSSIAN_ENCODING = 1251;
const int FILE_PARAMETER = 1;
const int SEARCH_STRING_PARAMETER = 2;
const int ERROR_NO_TEXT_FOUND = 1;
const int ERROR_NO_NAME_FILE = 2;
const int ERROR_NO_SEARCH_STRING = 3;
const int ERROR_NO_FILE = 4;
const int ERROR_EMPTY_LINE = 5;

const std::string MESSAGE_ERROR_NO_NAME_FILE = "No file name entered!";
const std::string MESSAGE_ERROR_NO_SEARCH_STRING = "No search string entered!";
const std::string MESSAGE_ERROR_NO_FILE = "The file does not exist!";
const std::string MESSAGE_ERROR_NO_TEXT_FOUND = "Text not found!";
const std::string MESSAGE_ERROR_EMPTY_LINE = "The line cannot be empty!";
const std::string MESSAGE_RULE = "The rule of entry is - findtext.exe <file name> <text to search>";

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, RUSSIAN_LANGUAGE);
	SetConsoleCP(RUSSIAN_ENCODING);
	SetConsoleOutputCP(RUSSIAN_ENCODING);

	if (argv[FILE_PARAMETER] == NULL)
	{
		std::cout << MESSAGE_ERROR_NO_NAME_FILE << std::endl;
		std::cout << MESSAGE_RULE;
		return ERROR_NO_NAME_FILE;
	}
	if (argv[SEARCH_STRING_PARAMETER] == NULL)
	{
		std::cout << MESSAGE_ERROR_NO_SEARCH_STRING << std::endl;
		std::cout << MESSAGE_RULE;
		return ERROR_NO_SEARCH_STRING;
	}
	std::ifstream inputFile(argv[FILE_PARAMETER]);
	if (!inputFile.is_open())
	{
		std::cout << MESSAGE_ERROR_NO_FILE << std::endl;
		std::cout << MESSAGE_RULE;
		return ERROR_NO_FILE;
	}
	std::string searchString = argv[SEARCH_STRING_PARAMETER];
	if (searchString.empty())
	{
		std::cout << MESSAGE_ERROR_EMPTY_LINE << std::endl;
		std::cout << MESSAGE_RULE;
		return ERROR_EMPTY_LINE;
	}

	std::string str;
	int lineNumber = 0;
	bool foundText = false;

	while (getline(inputFile, str))
	{
		lineNumber++;
		if (str.find(searchString) != std::string::npos)
		{
			std::cout << lineNumber << std::endl;
			foundText = true;
		}
	}
	if (foundText == false)
	{
		std::cout << MESSAGE_ERROR_NO_TEXT_FOUND << std::endl;
		std::cout << MESSAGE_RULE;
		return ERROR_NO_TEXT_FOUND;
	}

	return 0;
}