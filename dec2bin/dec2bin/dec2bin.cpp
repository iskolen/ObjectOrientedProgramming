#include <iostream>
#include <fstream>
#include <string>
#include <limits>

void ToBinary(unsigned int n)
{
	if (n / 2 != 0) 
		ToBinary(n / 2);

	std::cout << n % 2;
}

void InputCondition()
{
	std::cout << "The number must be in the range from 0 to 2^32-1";
	exit(1);
}

void СheckNegative(std::string inputNum)
{
	if (inputNum[0] == '-')
	{
		InputCondition();
	}
}

void CheckNotDigits(std::string inputNum)
{
	if (inputNum.find_first_not_of("0123456789") != UINT_MAX)
	{
		InputCondition();
	}
}

void CheckMax(unsigned long long inputNum)
{
	if (inputNum > UINT_MAX)
	{
		InputCondition();
	}
}

int main(int argc, char* argv[])
{
	if (argv[1] == NULL)
	{
		std::cout << "The input number is not entered!";
		return 1;
	}

	std::string inputNumStr(argv[1]);
	unsigned long long inputNum = atoll(argv[1]);

	СheckNegative(inputNumStr);
	CheckNotDigits(inputNumStr);
	CheckMax(inputNum);

	ToBinary(inputNum);

	return 0;
}