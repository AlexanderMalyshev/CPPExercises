#include "Tree.h"

#include <cstdlib>
#include <ctime>

void MakeNode(Node* root, const int& level, const int& height)
{
	if (level == height)
		return;

	bool left = (((double) std::rand() / RAND_MAX) * 2) >= 1;
	if (left)
	{
		int data = (int) (((double) std::rand() / RAND_MAX) * 100);
		root->AddLeft(new Node(data, nullptr, nullptr));
		MakeNode(root->GetLeft(), level + 1, height);
	}

	bool right = (((double) std::rand() / RAND_MAX) * 100) >= 1;
	if (right)
	{
		int data = (int) (((double) std::rand() / RAND_MAX) * 100);
		root->AddRight(new Node(data, nullptr, nullptr));
		MakeNode(root->GetRight(), level + 1, height);
	}
}


void MyTree::GenerateTree(const int& height)
{
#pragma warning(disable:4244)
	std::srand(std::time(0));
	MakeNode(root.get(), 0, height);
}

Node* MyTree::GetElem(const int& data, Node* root)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	else if (root->GetData() == data)
	{
		return root;
	}
	else
	{
		Node* left = GetElem(data, root->GetLeft());
		Node* right = GetElem(data, root->GetRight());
		return left != nullptr ? left : right;
	}
}

int MyTree::GetHeight()
{

}

void MyTree::PrintTree()
{

}