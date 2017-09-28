#include "Algorithms.h"
#include "Tree.h"

int main()
{
	MyTree mtr { new Node(1, nullptr, nullptr) };
	mtr.GenerateTree(4);
	
	std::cout << "Height: " << mtr.GetHeight() << std::endl;

	mtr.PrintTree();

	mtr.ConnectLayers();

	mtr.PrintTree();

	return 0;
}