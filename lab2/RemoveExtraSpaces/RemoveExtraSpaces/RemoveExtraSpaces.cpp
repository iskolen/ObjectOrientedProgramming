#include <iostream>
#include <algorithm>
#include <string>

std::string remove_duplicated_spaces(std::string s)
{
	auto last = std::unique(s.begin(), s.end(), [](char c1, char c2) { return c1 == c2 && ' ' == c1; });
	s.erase(last, s.end());
	return s;
}

int main()
{
	std::string s = "this    line  contains      a  number   of redundant     space     characters   ";
	std::cout << "Result: " << remove_duplicated_spaces(s) << std::endl;
	return 0;
}