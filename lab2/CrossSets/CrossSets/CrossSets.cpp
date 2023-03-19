#include "SetsHandler.h"
#include <iostream>
#include <string>
#include <cctype>

// Поменять название переменных set1 и set2, также поменять название функций ReadFirstSet и ReadSecondSet
// Исправить тесты
int main(int argc, char* argv[]) 
{
	int n;

	int errorCode = GetErrorCode(argc, argv, n);
	if (errorCode != 0)
		return errorCode;

	std::set<int> divDigitSumSet = CreateDivDigitSumSet(n);
	std::set<int> evenDigitSumSet = CreateEvenDigitSumSet(n);
	PrintSets(divDigitSumSet, evenDigitSumSet);

	return 0;
}