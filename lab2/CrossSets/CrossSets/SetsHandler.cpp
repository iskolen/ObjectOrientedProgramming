#include "SetsHandler.h"
#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <cctype>

const char MINUS = '-';
const char DELIMITER[] = " ";

const std::string MESSAGE_ERROR_NO_PARAMETER = "The input number is not entered!";
const std::string MESSAGE_ERROR_NEGATIVE = "A negative number is entered!";
const std::string MESSAGE_ERROR_NOT_DIGIT = "Entered not a digit!";
const std::string MESSAGE_RULE = "The rule of entry is - CrossSets.exe <number>";
const std::string DIV_DIGIT_SUM_PREFIX = "Set 1: ";
const std::string EVEN_DIGIT_SUM_PREFIX = "Set 2: ";
const std::string INTERSECTION_PREFIX = "Intersection: ";

const int FIRST_CHAR = 0;
const int BASE = 10;
const int EVEN_DIGIT_SUM = 2;
const int DIGIT_PARAMETER = 1;

const int ERROR_NO_PARAMETER = -1;
const int ERROR_NEGATIVE = -2;
const int ERROR_NOT_DIGIT = -3;

int GetErrorCode(int argc, char* argv[], int& n)
{
	if (argc <= DIGIT_PARAMETER)
	{
		std::cout << MESSAGE_ERROR_NO_PARAMETER << std::endl;
		std::cout << MESSAGE_RULE << std::endl;
		std::cout << std::endl;
		return ERROR_NO_PARAMETER;
	}

	std::string nStr = argv[DIGIT_PARAMETER];

	if (nStr[FIRST_CHAR] == MINUS)
	{
		std::cout << MESSAGE_ERROR_NEGATIVE << std::endl;
		std::cout << MESSAGE_RULE << std::endl;
		std::cout << std::endl;
		return ERROR_NEGATIVE;
	}

	for (char ch : nStr)
	{
		if (!std::isdigit(ch))
		{
			std::cout << MESSAGE_ERROR_NOT_DIGIT << std::endl;
			std::cout << MESSAGE_RULE << std::endl;
			std::cout << std::endl;
			return ERROR_NOT_DIGIT;
		}
	}

	n = std::stoi(nStr);

	return 0;
}


int SumOfDigits(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % BASE;
		n /= BASE;
	}
	return sum;
}

std::set<int> CreateDivDigitSumSet(int n)
{
	std::set<int> divDigitSumSet;
	for (int i = 1; i <= n; i++)
	{
		if (i % SumOfDigits(i) == 0)
			divDigitSumSet.insert(i);
	}
	return divDigitSumSet;
}

std::set<int> CreateEvenDigitSumSet(int n)
{
	std::set<int> evenDigitSumSet;
	for (int i = 1; i <= n; i++)
	{
		if (SumOfDigits(i) % EVEN_DIGIT_SUM == 0)
			evenDigitSumSet.insert(i);
	}
	return evenDigitSumSet;
}

std::set<int> CrossSet(std::set<int> const& divDigitSumSet, std::set<int> const& evenDigitSumSet)
{
	std::set<int> result;
	std::set_intersection(divDigitSumSet.begin(), divDigitSumSet.end(), evenDigitSumSet.begin(), evenDigitSumSet.end(), std::inserter(result, result.begin()));
	return result;
}

void PrintSets(std::set<int> const& divDigitSumSet, std::set<int> const& evenDigitSumSet)
{
	std::cout << DIV_DIGIT_SUM_PREFIX;
	std::copy(divDigitSumSet.begin(), divDigitSumSet.end(), std::ostream_iterator<int>(std::cout, DELIMITER));
	std::cout << std::endl;

	std::cout << EVEN_DIGIT_SUM_PREFIX;
	std::copy(evenDigitSumSet.begin(), evenDigitSumSet.end(), std::ostream_iterator<int>(std::cout, DELIMITER));
	std::cout << std::endl;

	std::set<int> intersection = CrossSet(divDigitSumSet, evenDigitSumSet);
	std::cout << INTERSECTION_PREFIX;
	std::copy(intersection.begin(), intersection.end(), std::ostream_iterator<int>(std::cout, DELIMITER));
}