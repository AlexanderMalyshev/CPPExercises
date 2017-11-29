#include "Algorithms.h"
#include "Tree.h"

int main()
{
	MyTree mtr(new Node(0, nullptr, nullptr));
	mtr.GenerateTree(4);

	mtr.PrintTree();

	mtr.PrintTreeInOrderIteratively();

	return 0;
}