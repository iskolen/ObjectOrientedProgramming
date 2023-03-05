#pragma once
#include <vector>
#include <iosfwd>

std::vector <double> ReadVector(std::vector <double>& numbers, std::istream& input);
std::vector <double> ProcessVector(std::vector <double>& numbers);
void PrintVector(const std::vector<double>& numbers);
int GetErrorCode(std::vector <double>& numbers);