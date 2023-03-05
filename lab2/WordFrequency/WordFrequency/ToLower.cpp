#include "Frequency.h"
#include <algorithm>

std::string ToLower(const std::string& str)
{
	std::string result(str);
	std::transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}