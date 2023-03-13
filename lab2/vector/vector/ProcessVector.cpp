#include "Vector.h"
#include <algorithm>

std::vector <double> ProcessVector(std::vector <double>& numbers, double min, double max)
{
	std::transform(numbers.begin(), numbers.end(), numbers.begin(), [=](double number) { return (number * max) / min; });

	return numbers;
}