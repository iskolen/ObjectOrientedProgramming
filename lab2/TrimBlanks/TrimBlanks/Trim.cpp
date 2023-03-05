#include "Trim.h"

const std::string SPACE = " ";
const int NEXT_CHAR = 1;

std::string Trim(std::string const& str)
{
	std::string result = str;
	result.erase(0, result.find_first_not_of(SPACE));
	result.erase(result.find_last_not_of(SPACE) + NEXT_CHAR);
	return result;
}