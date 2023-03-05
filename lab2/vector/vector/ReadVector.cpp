#include "Vector.h"
#include <iostream>

std::vector <double> ReadVector(std::vector<double>& numbers, std::istream& input)
{
	double number;
	while (input >> number)
		numbers.push_back(number);
	return numbers;
}