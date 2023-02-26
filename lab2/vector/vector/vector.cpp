#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


std::vector <double> ReadArray(std::vector <double> numbers)
{
	while (!std::cin.eof())
	{
		double number;
		if (std::cin >> number)
		{
			numbers.push_back(number);
		}
		else
		{
			break;
		}
	}
	return numbers;
}

std::vector <double> ProcessArray(std::vector <double> numbers, std::vector <double> numbers2)
{
	std::sort(numbers.begin(), numbers.end());
	for (int i = 0; i <= 2; i++)
	{
		numbers2.push_back(numbers.at(i));
	}
	double sum_of_elems = std::accumulate(numbers2.begin(), numbers2.end(), 0.0);
	for (auto &number : numbers)
	{
		number += sum_of_elems;
	}

	return numbers;
}

void PrintArray(std::vector <double> numbers)
{
	for (auto number : numbers)
	{
		std::cout << number << " ";
	}
}

int main()
{
	std::vector <double> numbers;
	std::vector <double> numbers2;

	numbers = ReadArray(numbers);
	numbers = ProcessArray(numbers, numbers2);
	PrintArray(numbers);
}