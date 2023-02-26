#include <windows.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

CONST std::string MESSAGE_ERROR_EMPTY_VECTOR = "You have not entered any value!";
CONST std::string MESSAGE_ERROR_MIN_ZERO = "Minimum value cannot be 0!";
CONST int ROUND_THREE_DIGITS = 1000;
CONST int ERROR_EMPTY_VECTOR = 1;
CONST int ERROR_MIN_ZERO = 2;

std::vector <double> ReadArray(std::vector <double> numbers)
{
	while (!std::cin.eof())
	{
		double number;
		if (std::cin >> number)
			numbers.push_back(number);
		else
			break;
	}
	return numbers;
}

std::vector <double> ProcessArray(std::vector <double> numbers)
{
	double max = *max_element(numbers.begin(), numbers.end());
	double min = *min_element(numbers.begin(), numbers.end());

	for (auto &number : numbers)
		number = (number * max) / min;

	return numbers;
}

void PrintArray(std::vector <double> numbers)
{
	for (auto number : numbers)
		std::cout << round(number * ROUND_THREE_DIGITS) / ROUND_THREE_DIGITS << " ";
}

int IsEmptyVector(std::vector <double> numbers)
{
	if (size(numbers) == 0)
	{
		std::cout << MESSAGE_ERROR_EMPTY_VECTOR;
		return ERROR_EMPTY_VECTOR;
	}
	return 0;
}

int IsMinValueZero(std::vector <double> numbers)
{
	double min = *min_element(numbers.begin(), numbers.end());
	if (min == 0)
	{
		std::cout << MESSAGE_ERROR_MIN_ZERO;
		return ERROR_MIN_ZERO;
	}
	return 0;
}

bool CheckError(int &errorCode, std::vector <double> numbers)
{
	errorCode = IsEmptyVector(numbers);
	if (errorCode != 0)
		return true;
	errorCode = IsMinValueZero(numbers);
	if (errorCode != 0)
		return true;
	return false;
}

int main()
{
	std::vector <double> numbers;
	bool error = false;
	int errorCode = 0;

	numbers = ReadArray(numbers);

	error = CheckError(errorCode, numbers);
	if (error)
		return errorCode;

	numbers = ProcessArray(numbers);
	std::sort(std::begin(numbers), std::end(numbers));
	PrintArray(numbers);

	return 0;
}