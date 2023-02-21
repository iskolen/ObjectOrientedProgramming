#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

CONST char RUSSIAN_LANGUAGE[8] = "Russian";
CONST int RUSSIAN_ENCODING = 1251;
CONST int FILE_PARAMETER = 1;
CONST int SEARCH_STRING_PARAMETER = 2;
CONST int ERROR_NO_TEXT_FOUND = 1;
CONST int ERROR_NO_NAME_FILE = 2;
CONST int ERROR_NO_SEARCH_STRING = 3;
CONST int ERROR_NO_FILE = 4;
CONST std::string MESSAGE_ERROR_NO_NAME_FILE = "No file name entered!";
CONST std::string MESSAGE_ERROR_NO_SEARCH_STRING = "No search string entered!";
CONST std::string MESSAGE_ERROR_NO_FILE = "The file does not exist!";
CONST std::string MESSAGE_ERROR_NO_TEXT_FOUND = "Text not found!";

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, RUSSIAN_LANGUAGE);
	SetConsoleCP(RUSSIAN_ENCODING);
	SetConsoleOutputCP(RUSSIAN_ENCODING);

	if (argv[FILE_PARAMETER] == NULL)
	{
		std::cout << MESSAGE_ERROR_NO_NAME_FILE;
		return ERROR_NO_NAME_FILE;
	}
	if (argv[SEARCH_STRING_PARAMETER] == NULL)
	{
		std::cout << MESSAGE_ERROR_NO_SEARCH_STRING;
		return ERROR_NO_SEARCH_STRING;
	}

	std::ifstream inputFile(argv[FILE_PARAMETER]);
	std::string searchStr(argv[SEARCH_STRING_PARAMETER]), str;
	int numberStr = 0;
	bool foundText = false;

	if (!inputFile.is_open())
	{
		std::cout << MESSAGE_ERROR_NO_FILE;
		return ERROR_NO_FILE;
	}
	while (getline(inputFile, str))
	{
		numberStr++;
		if (str.find(searchStr) != std::string::npos)
		{
			std::cout << numberStr << std::endl;
			foundText = true;
		}
	}
	if (foundText == false)
	{
		std::cout << MESSAGE_ERROR_NO_TEXT_FOUND;
		return ERROR_NO_TEXT_FOUND;
	}

	return 0;
}