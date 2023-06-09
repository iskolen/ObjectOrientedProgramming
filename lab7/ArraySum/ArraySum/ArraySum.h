#pragma once
/*	������� ������� ������������
	��� ������� ���������� �������������
		�������� �������� ������ ������������
		���������� �������� �������� (commit-or-rollback)
			������� ������������ � ���������, � ������� ��� ���������� �� ���������� ��������

	������� ������� ������������
	��� ������� ���������� �������������
		�������� ������������ ������ ������������
		���������� ����������� �������
			������ ��������� � �������������, ����� ���� ��������������� ���������

	����������� ������� ������������
	��� ������� ���������� �������������:
		���������� ������ ������ � Undefined Behavior
		����������� ����������� ���������� ��������

*/
#include <iostream>
#include <string>
#include <vector>
const std::string ERROR_EXCEPTION_MESSAGE = "There was an exception: ";

template <typename T>
T ArraySum(const std::vector<T>& arr)
{
	if (arr.empty())
		return T();

	T sum = arr[0];

	try
	{
		for (std::size_t i = 1; i < arr.size(); ++i)
		{
			T elementCopy = arr[i];
			sum = sum + elementCopy;
		}
	}
	catch (const std::exception& error)// ���������� �������� ���������
	{
		std::cerr << ERROR_EXCEPTION_MESSAGE << error.what() << std::endl;
		return T();
	}

	return sum;
}