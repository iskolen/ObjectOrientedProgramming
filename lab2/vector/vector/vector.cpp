#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "Vector.h"

const int ERROR_EMPTY_VECTOR = 1;
const int ERROR_MIN_ZERO = 2;

const std::string MESSAGE_ERROR_EMPTY_VECTOR = "You have not entered any value!";
const std::string MESSAGE_ERROR_MIN_ZERO = "Minimum value cannot be 0!";

int main()
{
	std::vector <double> numbers;
	int errorCode;

	numbers = ReadVector(numbers, std::cin);

	if (numbers.empty())
	{
		std::cout << MESSAGE_ERROR_EMPTY_VECTOR;
		return ERROR_EMPTY_VECTOR;
	}

	double max = *max_element(numbers.begin(), numbers.end());
	double min = *min_element(numbers.begin(), numbers.end());

	if (min == 0)
	{
		std::cout << MESSAGE_ERROR_MIN_ZERO;
		return ERROR_MIN_ZERO;
	}

	numbers = ProcessVector(numbers, min, max);
	std::sort(std::begin(numbers), std::end(numbers));
	PrintVector(numbers);

	return 0;
}