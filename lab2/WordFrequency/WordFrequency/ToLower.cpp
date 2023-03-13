#include "Frequency.h"
#include <algorithm>

void ToLower(std::string& str)
{
	for (char& ch : str)
		ch = ::tolower(static_cast<unsigned char>(ch));
}