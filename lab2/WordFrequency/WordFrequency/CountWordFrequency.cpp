#include <map>
#include <iostream>
#include "Frequency.h"

std::map<std::string, int> CountWordFrequency(std::istream& input)
{
	std::map<std::string, int> frequency;

	std::string word;
	while (input >> word)
	{
		std::string lowered_word = ToLower(word);
		++frequency[lowered_word];
	}

	return frequency;
}