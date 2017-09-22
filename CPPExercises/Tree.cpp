#include "Tree.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <list>
#include <iostream>

void MakeNode(Node* root, const int& level, const int& height)
{
	if (level == height)
		return;

	bool left = (((double) std::rand() / RAND_MAX) * 2) >= 1;
	if (true)
	{
		int data = (int) (((double) std::rand() / RAND_MAX) * 10);
		root->AddLeft(new Node(data, nullptr, nullptr));
		MakeNode(root->GetLeft(), level + 1, height);
	}

	bool right = (((double) std::rand() / RAND_MAX) * 100) >= 1;
	if (true)
	{
		int data = (int) (((double) std::rand() / RAND_MAX) * 10);
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

int GetTreeHeight(const Node* root)
{
	if (root == nullptr)
		return 0;

	return std::max(GetTreeHeight(root->GetLeft()), GetTreeHeight(root->GetRight())) + 1;
}

int MyTree::GetHeight()
{
	return GetTreeHeight(root.get());
}

void PrintTreeByLevels(std::list<Node*>& nodes, const int& height, const int& level)
{
	double step = std::pow(2.0, height - level);

	if (level > height)
		return;

	std::list<Node*> newNodes;
	std::for_each(nodes.cbegin(), nodes.cend(), [&newNodes, &step](const Node* node)
	{
		if (node == nullptr)
		{
			newNodes.push_back(nullptr);
			newNodes.push_back(nullptr);

			for (int j = 0; j < step * 2; ++j)
				std::cout << " ";

			return;
		}

		for (int j = 0; j < step - 1; ++j)
			std::cout << " ";

		std::cout << node->GetData();

		for (int j = 0; j < step; ++j)
			std::cout << " ";

		newNodes.push_back(node->GetLeft());
		newNodes.push_back(node->GetRight());
	});
	
	std::cout << std::endl;
	PrintTreeByLevels(newNodes, height, level + 1);
}

void MyTree::PrintTree()
{
	std::list<Node*> nodes { root.get() };
	PrintTreeByLevels(nodes, GetHeight(), 0);
}