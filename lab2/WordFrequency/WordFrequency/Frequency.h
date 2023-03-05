#pragma once
#include <map>
#include <string>

std::string ToLower(const std::string& str);
std::map<std::string, int> CountWordFrequency(std::istream& input);
void PrintWordFrequency(const std::map<std::string, int>& frequency);