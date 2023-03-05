#include "Vector.h"
#include <iterator>
#include <iostream>

void PrintVector(const std::vector<double>& numbers)
{
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(std::cout, " "));
}