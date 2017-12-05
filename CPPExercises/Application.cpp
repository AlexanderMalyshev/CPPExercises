#include "Algorithms.h"
#include "Tree.h"
#include "InorderTreeIterator.h"

int main()
{
	MyTree mtr(new Node(0, nullptr, nullptr));
	mtr.GenerateTree(4);

	mtr.PrintTree();

	mtr.PrintTreeInOrderIteratively();

	InorderTreeIterator iti(mtr.GetRoot());
	while (auto node = iti.GetNext())
	{
		std::cout << node->GetData() << " ";
	}

	std::cout << std::endl;

	return 0;
}