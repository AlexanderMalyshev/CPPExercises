#include "Algorithms.h"

#include <iostream>

int main()
{
	std::vector<int> source;

	GenrateVector(source, 10);
	QuickSort(source, 0, source.size() - 1);

	std::cout << source << std::endl;

	return 0;
}