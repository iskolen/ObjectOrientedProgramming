#include "Vector.h"
#include <iostream>
#include <algorithm>
#include <string>

const int ERROR_EMPTY_VECTOR = 1;
const int ERROR_MIN_ZERO = 2;

const std::string MESSAGE_ERROR_EMPTY_VECTOR = "You have not entered any value!";
const std::string MESSAGE_ERROR_MIN_ZERO = "Minimum value cannot be 0!";

int GetErrorCode(std::vector <double>& numbers)
{
	if (numbers.empty())
	{
		std::cout << MESSAGE_ERROR_EMPTY_VECTOR;
		return ERROR_EMPTY_VECTOR;
	}
	if (*std::min_element(numbers.begin(), numbers.end()) == 0)
	{
		std::cout << MESSAGE_ERROR_MIN_ZERO;
		return ERROR_MIN_ZERO;
	}
	return 0;
}