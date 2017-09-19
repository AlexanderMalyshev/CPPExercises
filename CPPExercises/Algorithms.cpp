#include "Algorithms.h"

#include <cstdlib>
#include <ctime>

void swap(int& val1, int& val2)
{
	int tmp = val1;
	val1 = val2;
	val2 = tmp;
}

void GenrateVector(std::vector<int>& vec, const int& size)
{
#pragma warning(disable:4244)
	std::srand(std::time(0));

	vec.resize(size);
	for (int i = 0; i < size; ++i)
		vec[i] = (int) (((double) std::rand() / RAND_MAX) * 100);
}

void QuickSort(std::vector<int>& vec, const int& start, const int& end)
{
	if (start >= end)
		return;

	int mid = start + (end - start) / 2;
	int pivot = vec[mid];

	int lInd = start;
	int rInd = end;

	while (lInd < rInd)
	{
		for (; lInd <= end && vec[lInd] < pivot; ++lInd);
		for (; rInd >= start && vec[rInd] > pivot; --rInd);

		if (lInd < rInd)
		{
			swap(vec[lInd], vec[rInd]);
			mid = lInd == mid ? rInd : (mid == rInd ? lInd : mid);
		}

	}

	QuickSort(vec, start, mid - 1);
	QuickSort(vec, mid + 1, end);

}

