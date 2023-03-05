#include "Vector.h"
#include <algorithm>

std::vector <double> ProcessVector(std::vector <double>& numbers)
{
	double max = *max_element(numbers.begin(), numbers.end());
	double min = *min_element(numbers.begin(), numbers.end());
	std::transform(numbers.begin(), numbers.end(), numbers.begin(), [=](double number) { return (number * max) / min; });

	return numbers;
}