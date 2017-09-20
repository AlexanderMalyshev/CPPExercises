#include "Algorithms.h"
#include "Tree.h"

int main()
{
	MyTree mtr { new Node(1, nullptr, nullptr) };
	mtr.GenerateTree(10);
	mtr.PrintTree();

	return 0;
}