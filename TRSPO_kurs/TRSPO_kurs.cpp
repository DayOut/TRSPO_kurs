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

#define LIM 1001313


int main()
{
	std::cout << "Enter n (array size) and m (amount of sequences): ";
	unsigned int n = 0;
	std::cin >> n;
	int *solo, *paral;
	solo = new int[n];
	paral = new int[n];
	int * sec = new int[n];
	QS quick;
	quick.createArray(n);


	fillRandomly(solo, paral, quick, n);
	print(solo, paral, quick, n);
	/*std::cout << quick.getArrElem(0);
	std::cout << quick.getArrElem(2);*/
	heapSort(solo, n); // вызов функции сортировки
	heapSortParallel(paral, n);
	quick.sortAll();
	print(solo, paral, quick, n);
	system("pause");
	delete solo;
	delete paral;

	return 0;
}


