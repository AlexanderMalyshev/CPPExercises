#include "Algorithms.h"
#include "Tree.h"

int main()
{
	MyTree mtr { new Node(1, nullptr, nullptr) };
	mtr.GenerateTree(3);
	
	std::cout << "Height: " << mtr.GetHeight() << std::endl;

	mtr.PrintTree();

	return 0;
}