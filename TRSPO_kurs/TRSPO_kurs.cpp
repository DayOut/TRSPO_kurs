// TRSPO_kurs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>
#include "HeapSort.h"
#include "HeapSortParallel.h"
#include "Utilities.h"
#include "QS.h"
#include "SelectionSort.h"

#define LIM 1001313


int main()
{
	std::cout << "Enter n (array size): ";
	unsigned int size = 0;
	std::cin >> size; // size of array
	int *selectSort, *heapSortP;
	selectSort = new int[size];
	heapSortP = new int[size];
	QS quickSort;
	quickSort.createArray(size);


	fillRandomly(selectSort, heapSortP, quickSort, size);
	print(selectSort, heapSortP, quickSort, size);
	/*std::cout << quick.getArrElem(0);
	std::cout << quick.getArrElem(2);*/
	//heapSort(solo, n); // вызов функции сортировки
	selectionSort(selectSort, size);
	heapSortParallel(heapSortP, size);
	quickSort.sortAll();
	print(selectSort, heapSortP, quickSort, size);
	system("pause");
	delete selectSort;
	delete heapSortP;

	return 0;
}


