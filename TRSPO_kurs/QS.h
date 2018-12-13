/*
 * QS.h
 *
 *  Created on: Apr 1, 2015
 *      Author: bryce14
 */

#ifndef QS_H_
#define QS_H_

#include "QSInterface.h"
#include <string>
#include <sstream>
#include <omp.h>


class QS: public QSInterface {
public:
	QS();
	virtual ~QS();

	void sortAll();
	int medianOfThree(int left, int right);
	int partition(int left, int right, int pivotIndex);
	string getArray();
	int getArrElem(int i);
	int getSize();
	void addToArray(int value);
	bool createArray(int capacity);
	void recSort(int left, int right);
	void clear();

private:
	int capacity;
	int size;
	int *Array;

};

#endif /* QS_H_ */

