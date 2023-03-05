#include <iostream>
#include <fstream>
#include <string>
#include <limits>

const char MINUS = '-';
const char ZERO = '0';
const char NINE = '9';

const int ERROR_NO_PARAMETER = 1;
const int ERROR_NEGATIVE = 2;
const int ERROR_NOT_DIGIT = 3;
const int ERROR_EXCEEDED = 4;
const int FIRST_CHAR = 0;
const int DIGIT_PARAMETER = 1;

const std::string MESSAGE_ERROR_NO_PARAMETER = "The input number is not entered!";
const std::string MESSAGE_ERROR_NEGATIVE = "A negative number is entered!";
const std::string MESSAGE_ERROR_NOT_DIGIT = "Entered not a digit!";
const std::string MESSAGE_ERROR_EXCEEDED = "Exceeded the maximum value!";
const std::string MESSAGE_RULE = "The rule of entry is - bin2dec.exe <binary number>";
const std::string EMPTY_STRING = "";

std::string ToBinary(unsigned long long digit, std::string &binaryDigit)
{
	if (digit == 0)
		return "0";
	if (digit)
	{
		ToBinary(digit >> 1, binaryDigit);
		binaryDigit += std::to_string(digit & 1);
	}
	return binaryDigit;
}

int GetErrorCode(unsigned long long &inputNum, std::string &inputNumStr)
{
	if (inputNumStr[FIRST_CHAR] == MINUS)
	{
		std::cout << MESSAGE_ERROR_NEGATIVE << std::endl;
		std::cout << MESSAGE_RULE;
		return ERROR_NEGATIVE;
	}
	if (inputNum > UINT_MAX)
	{
		std::cout << MESSAGE_ERROR_EXCEEDED << std::endl;
		std::cout << MESSAGE_RULE;
		return ERROR_EXCEEDED;
	}
	for (int i = 0; i < inputNumStr.size(); i++)
	{
		if (inputNumStr[i] < ZERO || inputNumStr[i] > NINE)
		{
			std::cout << MESSAGE_ERROR_NOT_DIGIT << std::endl;
			std::cout << MESSAGE_RULE;
			return ERROR_NOT_DIGIT;
		}
	}
	return 0;
}

int main(int argc, char* argv[])
{
	if (argv[DIGIT_PARAMETER] == NULL)
	{
		std::cout << MESSAGE_ERROR_NO_PARAMETER << std::endl;
		std::cout << MESSAGE_RULE;
		return ERROR_NO_PARAMETER;
	}

	std::string inputNumStr(argv[DIGIT_PARAMETER]);
	std::string binaryDigit = EMPTY_STRING;
	unsigned long long inputNum = atoll(argv[DIGIT_PARAMETER]);
	int errorCode;

	errorCode = GetErrorCode(inputNum, inputNumStr);
	if (errorCode != 0)
		return errorCode;

	binaryDigit = ToBinary(inputNum, binaryDigit);
	std::cout << binaryDigit;

	return 0;
}