#pragma once
#include <set>

int GetErrorCode(int argc, char* argv[], int& n);
int SumOfDigits(int n);
void PrintSets(std::set<int> const& set1, std::set<int> const& set2);
std::set<int> ReadFirstSet(int n);
std::set<int> ReadSecondSet(int n);
std::set<int> CrossSet(std::set<int> const& set1, std::set<int> const& set2);