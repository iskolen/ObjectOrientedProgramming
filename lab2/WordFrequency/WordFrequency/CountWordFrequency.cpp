#include <map>
#include <iostream>
#include "Frequency.h"

std::map<std::string, int> CountWordFrequency(std::istream& input)
{
	std::map<std::string, int> frequency;

	std::string word;
	while (input >> word)
	{
		ToLower(word);
		++frequency[word];
	}

	return frequency;
}