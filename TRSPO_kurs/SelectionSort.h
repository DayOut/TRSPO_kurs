#pragma once

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int* A, int n) {
	std::cout << "Started selectionSort \n";
	int i = 0;
	double start = omp_get_wtime();
	int comparisons = 0;
	for (int j = 0; j < n - 1; j++) {
		int smallest = j;

		// tests all values after index j against the value at index j.
		// If value at index i is less that value at index j/smallest, swap the
		// two with each other
		for (int i = j + 1; i < n; i++) {
			std::cout << "\r" <<comparisons++;
			if (A[i] < A[smallest]) {
				smallest = i;
			}
		}

		swap(A[j], A[smallest]);
	}

	double end = omp_get_wtime();
	std::cout << "Numbers sorted: " << n << "\n";
	std::cout << std::fixed << "Time: " << (end - start) << "\n";
}
