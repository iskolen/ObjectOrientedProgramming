#include <iostream>
#include <vector>
#include <string>

const char RUSSIAN_LANGUAGE[8] = "Russian";

const std::string MESSAGE_SUM_INT = "Сумма целых чисел: ";
const std::string MESSAGE_SUM_DOUBLE = "Сумма чисел с плавающей запятой: ";
const std::string MESSAGE_SUM_STRING = "Сумма строк (конкатенация): ";

const int INT_1 = 1;
const int INT_2 = 2;
const int INT_3 = 3;
const int INT_4 = 4;
const int INT_5 = 5;

const double DOUBLE_1_1 = 1.1;
const double DOUBLE_2_2 = 2.2;
const double DOUBLE_3_3 = 3.3;
const double DOUBLE_4_4 = 4.4;
const double DOUBLE_5_5 = 5.5;

const std::string STRING_HELLO = "Hello, ";
const std::string STRING_WORLD = "world";
const std::string STRING_EXCLAMATION_POINT = "!";

template <typename T>
T ArraySum(const std::vector<T>& arr)
{
	T sum = T();

	for (const auto& element : arr)
	{
		sum += element;
	}

	return sum;
}

int main()
{
	setlocale(LC_ALL, RUSSIAN_LANGUAGE);

	std::vector<int> arrayInt = { INT_1, INT_2, INT_3, INT_4, INT_5 };
	int sumInt = ArraySum(arrayInt);
	std::cout << MESSAGE_SUM_INT << sumInt << std::endl;

	std::vector<double> arrayDouble = { DOUBLE_1_1, DOUBLE_2_2, DOUBLE_3_3, DOUBLE_4_4, DOUBLE_5_5 };
	double sumDouble = ArraySum(arrayDouble);
	std::cout << MESSAGE_SUM_DOUBLE << sumDouble << std::endl;

	std::vector<std::string> arrayString = { STRING_HELLO, STRING_WORLD, STRING_EXCLAMATION_POINT};
	std::string sumString = ArraySum(arrayString);
	std::cout << MESSAGE_SUM_STRING << sumString << std::endl;

	return 0;
}