#pragma once
// ������� "�����������" ����� ���� - ������������ ����
void siftDown(int *numbers, int root, int bottom)
{
	int maxChild; // ������ ������������� �������
	int done = 0; // ���� ����, ��� ���� ������������
	// ���� �� ����� �� ���������� ����
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    // ���� �� � ��������� ����, 
			maxChild = root * 2;    // ���������� ����� �������
		  // ����� ���������� ������� ������� �� ����
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// ���� ������� ������� ������ ������������� �������
		if (numbers[root] < numbers[maxChild])
		{
			int temp = numbers[root]; // ������ �� �������
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else // �����
			done = 1; // �������� ������������
	}
}
// ������� ���������� �� ����
void heapSort(int *numbers, int array_size)
{
	double start = omp_get_wtime();
	// ��������� ������ ��� ��������
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(numbers, i, array_size - 1);
	// ���������� ����� �������� ��������� ��������
	for (int i = array_size - 1; i >= 1; i--)
	{
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		siftDown(numbers, 0, i - 1);
	}
	double end = omp_get_wtime();
	std::cout << "Numbers sorted: " << array_size << "\n";
	std::cout << std::fixed << "Time: " << (end - start) << "\n";
}