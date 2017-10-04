#include "Algorithms.h"
#include "Tree.h"

int main()
{
	MyTree mtr { new Node(1, nullptr, nullptr) };
	mtr.GenerateTree(4);
	
	std::cout << "Height: " << mtr.GetHeight() << std::endl;

	mtr.PrintTree();

	mtr.PrintTreeInOrder();
	mtr.PrintTreePreOrder();
	mtr.PrintTreePostOrder();

	mtr.PrintTreeInOrderIteratively();
	mtr.PrintTreePreOrderIteratively();
	mtr.PrintTreePostOrderIteratively();

	return 0;
}