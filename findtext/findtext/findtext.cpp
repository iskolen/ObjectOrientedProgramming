#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

CONST char RUSSIANLANGUAGE[8] = "Russian";
CONST int RUSSIANENCODING = 1251;
CONST int FILEPARAMETER = 1;
CONST int SEARCHSTRINGPARAMETER = 2;
CONST int COMPLETEPROGRAM = 0;
CONST int ERRORNOTEXTFOUND = 1;
CONST int ERRORNONAMEFILE = 2;
CONST int ERRORNOSEARCHSTRING = 3;
CONST int ERRORNOFILE = 4;
CONST std::string MESSAGEERRORNONAMEFILE = "No file name entered!";
CONST std::string MESSAGEERRORNOSEARCHSTRING = "No search string entered!";
CONST std::string MESSAGEERRORNOFILE = "The file does not exist!";
CONST std::string MESSAGEERRORNOTEXTFOUND = "Text not found!";

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, RUSSIANLANGUAGE);
	SetConsoleCP(RUSSIANENCODING);
	SetConsoleOutputCP(RUSSIANENCODING);

	if (argv[FILEPARAMETER] == NULL)
	{
		std::cout << MESSAGEERRORNONAMEFILE;
		return ERRORNONAMEFILE;
	}
	if (argv[SEARCHSTRINGPARAMETER] == NULL)
	{
		std::cout << MESSAGEERRORNOSEARCHSTRING;
		return ERRORNOSEARCHSTRING;
	}

	std::ifstream inputFile(argv[FILEPARAMETER]);
	std::string searchStr(argv[SEARCHSTRINGPARAMETER]), str;
	int numberStr = 0;
	bool foundText = false;

	if (!inputFile.is_open())
	{
		std::cout << MESSAGEERRORNOFILE;
		return ERRORNOFILE;
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
		std::cout << MESSAGEERRORNOTEXTFOUND;
		return ERRORNOTEXTFOUND;
	}

	return COMPLETEPROGRAM;
}