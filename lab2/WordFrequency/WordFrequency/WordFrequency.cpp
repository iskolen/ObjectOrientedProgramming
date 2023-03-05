#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include "Frequency.h"

int main()
{
	std::map<std::string, int> frequency = CountWordFrequency(std::cin);
	PrintWordFrequency(frequency);

	return 0;
}