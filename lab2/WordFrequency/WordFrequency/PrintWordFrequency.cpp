#include <map>
#include <iostream>
#include <string>
#include "Frequency.h"

void PrintWordFrequency(const std::map<std::string, int>& frequency)
{
	for (const auto& pair : frequency)
		std::cout << pair.first << " -> " << pair.second << std::endl;
}