#include <iostream>
#include "Trim.h"

int main()
{
	std::string str;
	while (std::getline(std::cin, str))
	{
		std::string trimmedLine = Trim(str);
		std::cout << trimmedLine << std::endl;
	}
	return 0;
}
