#include <iostream>
#include "CTime.h"

int main()
{
	CTime timeMax(86399);
	std::cout << timeMax.GetHours() << SEPARATOR << timeMax.GetMinutes() << SEPARATOR << timeMax.GetSeconds() << std::endl;
	std::cout << timeMax << std::endl;

	CTime timeMin(0);
	std::cout << timeMin.GetHours() << SEPARATOR << timeMin.GetMinutes() << SEPARATOR << timeMin.GetSeconds() << std::endl;
	std::cout << timeMin << std::endl;

	return 0;
}