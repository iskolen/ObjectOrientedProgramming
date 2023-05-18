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

	CTime time1(3600);
	CTime time2(1800);

	time2 -= time1;
	std::cout << time2;

	return 0;
}