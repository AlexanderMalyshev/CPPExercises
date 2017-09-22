#include "Tree.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <iostream>

void MakeNode(Node* root, const int& level, const int& height)
{
	if (level == height)
		return;

	bool left = (((double) std::rand() / RAND_MAX) * 2) >= 1;
	if (true)
	{
		int data = (int) (((double) std::rand() / RAND_MAX) * 100);
		root->AddLeft(new Node(data, nullptr, nullptr));
		MakeNode(root->GetLeft(), level + 1, height);
	}

	bool right = (((double) std::rand() / RAND_MAX) * 100) >= 1;
	if (true)
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

void PrintTreeByLevels(std::vector<Node*>& nodes, const int& height, const int& level)
{
	double width = std::pow(2.0, height + 2) / (std::pow(2.0, level) + 1);
	if (level > height)
		return;

	std::vector<Node*> newNodes;
	for (unsigned int i = 0; i < nodes.size(); ++i)
	{
		if (nodes[i] == nullptr)
		{
			double step = width * i;
			newNodes.push_back(nullptr);
			newNodes.push_back(nullptr);

			for (int j = 0; j < width; ++j)
				std::cout << " ";

			continue;
		}

		int numLength = nodes[i]->GetData() > 10 ? 2 : 1;
		for (int j = 0; j < width; ++j)
			std::cout << " ";

		std::cout << nodes[i]->GetData();
		newNodes.push_back(nodes[i]->GetLeft());
		newNodes.push_back(nodes[i]->GetRight());
	}

	std::cout << std::endl;
	PrintTreeByLevels(newNodes, height, level + 1);
}

void MyTree::PrintTree()
{
	std::vector<Node*> nodes { root.get() };
	PrintTreeByLevels(nodes, GetHeight(), 1);
}