#include "SetsHandler.h"
#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char* argv[]) 
{
	int n;

	int errorCode = GetErrorCode(argc, argv, n);
	if (errorCode != 0)
		return errorCode;

	std::set<int> set1 = ReadFirstSet(n);
	std::set<int> set2 = ReadSecondSet(n);
	PrintSets(set1, set2);

	return 0;
}