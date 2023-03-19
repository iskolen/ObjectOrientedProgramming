#pragma once
#include <set>

int GetErrorCode(int argc, char* argv[], int& n);
int SumOfDigits(int n);
void PrintSets(std::set<int> const& divDigitSumSet, std::set<int> const& evenDigitSumSet);
std::set<int> CreateDivDigitSumSet(int n);
std::set<int> CreateEvenDigitSumSet(int n);
std::set<int> CrossSet(std::set<int> const& divDigitSumSet, std::set<int> const& evenDigitSumSet);