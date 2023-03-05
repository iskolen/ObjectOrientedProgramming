#include <vector>
#include <algorithm>
#include <iostream>
#include "Vector.h"

int main()
{
	std::vector <double> numbers;
	int errorCode;

	numbers = ReadVector(numbers, std::cin);

	errorCode = GetErrorCode(numbers);
	if (errorCode != 0)
		return errorCode;

	numbers = ProcessVector(numbers);
	std::sort(std::begin(numbers), std::end(numbers));
	PrintVector(numbers);

	return 0;
}