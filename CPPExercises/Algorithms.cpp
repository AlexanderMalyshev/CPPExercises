#include "Algorithms.h"

#include <cstdlib>
#include <ctime>

void swap(int& val1, int& val2)
{
	int tmp = val1;
	val1 = val2;
	val2 = tmp;
}

void GenerateVector(std::vector<int>& vec, const int& size)
{
#pragma warning(disable:4244)
	std::srand(std::time(0));

	vec.resize(size);
	for (int i = 0; i < size; ++i)
	{
		int elem = 0;
		do
		{
			elem = (int) (((double) std::rand() / RAND_MAX) * 1000);
		} while (std::find(vec.cbegin(), vec.cend(), elem) != vec.cend());
		
		vec[i] = elem;
	}
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

int BinarySearch(std::vector<int>& vec, const int& item, const int& start, const int& end)
{
	if (start > end)
		return -1;

	int mid = start + (end - start) / 2;
	int pivot = vec[mid];

	if (pivot == item)
		return mid;
	else if (pivot < item)
		return BinarySearch(vec, item, mid + 1, end);
	else
		return BinarySearch(vec, item, start, mid - 1);
}

bool IsSorted(std::vector<int>& vec)
{
	for (int i = 1; i < vec.size(); ++i)
	{
		if (vec[i - 1] > vec[i])
			return false;
	}

	return true;
}
