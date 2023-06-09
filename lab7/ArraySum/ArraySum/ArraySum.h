#pragma once
/*	Сильный уровень безопасности
	При выбросе исключений гарантируется
		Гарантии базового уровня безопасности
		Отсутствие побочных эффектов (commit-or-rollback)
			Объекты возвращаются в состояние, в котором они находились до выполнения операции

	Базовый уровень безопасности
	При выбросе исключений гарантируется
		Гарантии минимального уровня безопасности
		Сохранение инвариантов объекта
			Данные находятся в согласованном, пусть даже непредсказуемом состоянии

	Минимальный уровень безопасности
	При выбросе исключений гарантируется:
		Отсутствие утечек памяти и Undefined Behavior
		Возможность безопасного разрушения объектов

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
	catch (const std::exception& error)// Возвращаем валидное состояние
	{
		std::cerr << ERROR_EXCEPTION_MESSAGE << error.what() << std::endl;
		return T();
	}

	return sum;
}