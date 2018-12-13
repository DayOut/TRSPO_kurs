#pragma once
#include <random>
#include "QS.h"

template<typename T>
void fillRandomly(T data[], T data2[], QS &data3, const int size, const int min = -10000, const int max = 10000)
{
	std::random_device rd;
	std::uniform_int_distribution<T> uid(min, max);
	for (size_t i = 0; i < size; i++)
	{
		int a = uid(rd);
		data[i] = a;
		data2[i] = a;
		data3.addToArray(a);
	}
}

template<typename T>
void print(T data, T data2, QS data3, const int size)
{
	
	if (size <= 100) 
	{
		std::cout << "Before sort: \n\tSolo: \n\t";
		for (size_t i = 0; i < size; i++)
		{
			std::cout << data[i] << " ";
		}

		std::cout << "\n\tParallel: \n\t";
		for (size_t i = 0; i < size; i++)
		{
			std::cout << data2[i] << " ";
		}
		std::cout << "\n\t: QuickSort: \n\t";
		for(size_t i = 0; i < size; i++)
		{
			std::cout << data3.getArrElem(i) << " ";
		}
		std::cout << std::endl;
	}
}

//template for printing all arrays
//template<typename T>
//void printAll(T data, ...)
//{
//	int *p = &data;
//	p++;                //-3-установка «целого» на double
//	double *pp = (double *)p;    //--преобразование типа указателя
//	double sum = 0, count = data;
//	for (; n--; pp++)             //--правильное увеличение на 8
//		sum += (*pp);
//	return ((sum) ? sum / count : 0);
//}