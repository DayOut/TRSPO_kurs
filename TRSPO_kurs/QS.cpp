/*
 * QS.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: bryce14
 */

#include "QS.h"
#include <array>



QS::QS() {
	// TODO Auto-generated constructor stub
	Array = NULL;
	capacity = 0;
	size = 0;
}

QS::~QS() {
	// TODO Auto-generated destructor stub
	//clear();
}

/*
 * sortAll()
 *
 * Sorts elements of the array.  After this function is called, every
 * element in the array is less than or equal its successor.
 *
 * Does nothing if the array is empty.
 */
void QS::sortAll() {
	if (Array == NULL) {
		;
	}
	else {
		double start = omp_get_wtime();
		recSort(0, size - 1);
		double end = omp_get_wtime();
		std::cout << "Numbers sorted: " << capacity << "\n";
		std::cout << std::fixed << "Time: " << (end - start) << "\n";
	}
}

void QS::recSort(int left, int right) {
	if (left >= right) {
		return;
	}
	int pivot = medianOfThree(left, right);
	int center = partition(left, right, pivot);
	recSort(left, center - 1);
	recSort(center + 1, right);
}


int QS::medianOfThree(int left, int right) {
	int middle = 0;
	if (size == 0 || left < 0 || right > (size - 1) || left >= right) {
		return -1;
	}
	else {
		middle = (left + right) / 2;
		if (Array[middle] < Array[left]) {
			swap(Array[left], Array[middle]);
		}
		if (Array[middle] > Array[right]) {
			swap(Array[middle], Array[right]);
		}
	}
	return middle;
}

int QS::partition(int left, int right, int pivotIndex) {
	int up = left;
	int down = right - 1;
	if (Array == NULL || left < 0 || right > size - 1 || left >= right || pivotIndex < left || pivotIndex > right) {
		return -1;
	}
	else {
		swap(Array[pivotIndex], Array[right]);
		while (up < down) {
			while (Array[up] < Array[right] && right > up) {
				++up;
			}
			while (Array[down] >= Array[right] && left < down) {
				--down;
			}
			if (up < down) {
				swap(Array[up], Array[down]);
			}
		}
		swap(Array[up], Array[right]);
		return up;
	}
}

string QS::getArray() {
	stringstream a;
	for (int i = 0; i < size; i++) {
		a << Array[i];
		if (i < size - 1) {
			a << ",";
		}
	}
	return a.str();
}

int QS::getArrElem(int i){
	if (i < capacity) {
		return Array[i];
	}
}

int QS::getSize() {
	return size;
}

void QS::addToArray(int value) {
	if (size >= capacity) {
		;
	}
	else {
		Array[size] = value;
		size++;
	}
}

bool QS::createArray(int capacity) {
	if (capacity <= 0) {
		return false;
	}
	else {
		Array = new int[capacity];
		this->capacity = capacity;
		size = 0;
		return true;
	}
}

void QS::clear() {
	delete [] Array;
	size = 0;
}








