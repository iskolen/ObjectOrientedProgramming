#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

CONST std::string MESSAGE_ERROR_NO_PARAMETER = "The input number is not entered!";
CONST std::string MESSAGE_ERROR_NEGATIVE = "A negative number is entered!";
CONST std::string MESSAGE_ERROR_NOT_DIGIT = "Entered not a digit!";
CONST std::string MESSAGE_ERROR_EXCEEDED = "Exceeded the maximum value!";
CONST std::string EMPTY_STRING = "";
CONST int ERROR_NO_PARAMETER = 1;
CONST int ERROR_NEGATIVE = 2;
CONST int ERROR_NOT_DIGIT = 3;
CONST int ERROR_EXCEEDED = 4;
CONST int FIRST_CHAR = 0;
CONST int DIGIT_PARAMETER = 1;
CONST char MINUS = '-';
CONST char ZERO = '0';
CONST char NINE = '9';

std::string ToBinary(unsigned long long a, std::string &binaryDigit)
{
	if (a)
	{
		ToBinary(a >> 1, binaryDigit);
		binaryDigit += std::to_string(a & 1);
	}
	return binaryDigit;
}

int IsNegative(std::string inputNum)
{
	if (inputNum[FIRST_CHAR] == MINUS)
	{
		std::cout << MESSAGE_ERROR_NEGATIVE;
		return ERROR_NEGATIVE;
	}
	return 0;
}

int IsNotDigits(std::string inputNum)
{
	for (int i = 0; i < inputNum.size(); i++) 
	{
		if (inputNum[i] < ZERO || inputNum[i] > NINE)
		{
			std::cout << MESSAGE_ERROR_NOT_DIGIT;
			return ERROR_NOT_DIGIT;
		}
	}
	return 0;
}

int IsMax(unsigned long long inputNum)
{
	if (inputNum > UINT_MAX)
	{
		std::cout << MESSAGE_ERROR_EXCEEDED;
		return ERROR_EXCEEDED;
	}
	return 0;
}

bool CheckError(int &errorCode, unsigned long long &inputNum, std::string &inputNumStr)
{
	errorCode = IsNegative(inputNumStr);
	if (errorCode != 0)
		return true;
	errorCode = IsNotDigits(inputNumStr);
	if (errorCode != 0)
		return true;
	errorCode = IsMax(inputNum);
	if (errorCode != 0)
		return true;
	return false;
}

int main(int argc, char* argv[])
{
	if (argv[DIGIT_PARAMETER] == NULL)
	{
		std::cout << MESSAGE_ERROR_NO_PARAMETER;
		return ERROR_NO_PARAMETER;
	}

	std::string inputNumStr(argv[DIGIT_PARAMETER]);
	std::string binaryDigit = EMPTY_STRING;
	unsigned long long inputNum = atoll(argv[DIGIT_PARAMETER]);
	int errorCode = 0;
	bool error = false;

	error = CheckError(errorCode, inputNum, inputNumStr);
	if (error)
		return errorCode;
	binaryDigit = ToBinary(inputNum, binaryDigit);
	std::cout << binaryDigit;

	return 0;
}