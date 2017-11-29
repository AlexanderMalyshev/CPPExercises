#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

template <typename Type>
std::ostream& operator << (std::ostream& o, const std::vector<Type>& v) {
	o << "Array: ";
	std::for_each(v.cbegin(), v.cend(), [&o](const Type& n) { o << n << " "; });

	return o;
}

void GenerateVector(std::vector<int>& vec, const int& size);
void QuickSort(std::vector<int>& vec, const int& start, const int& end);
int BinarySearch(std::vector<int>& vec, const int& item, const int& start, const int& end);
bool IsSorted(std::vector<int>& vec);
void KthSmallestElements(std::vector<int>& vec, const int& k);
