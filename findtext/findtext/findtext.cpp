#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argv[1] == NULL)
	{
		std::cout << "No file name entered!";
		return 1;
	}
	if (argv[2] == NULL)
	{
		std::cout << "No search string entered!";
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	std::string searchStr(argv[2]), str;
	int numberStr = 0;
	bool foundText = false;

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
		std::cout << "Text not found!";
		return 1;
	}

	return 0;
}