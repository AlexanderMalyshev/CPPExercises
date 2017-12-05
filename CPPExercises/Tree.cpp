#include "Tree.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <list>
#include <set>
#include <iostream>

void MakeNode(std::shared_ptr<Node> root, const int& level, const int& height)
{
	if (level == height)
		return;

	bool left = (((double) std::rand() / RAND_MAX) * 8) >= 1;
	if (left)
	{
		int data = (int) (((double) std::rand() / RAND_MAX) * 10);
		root->AddLeft(std::make_shared<Node>(data, nullptr, nullptr));
		MakeNode(root->GetLeft(), level + 1, height);
	}

	bool right = (((double) std::rand() / RAND_MAX) * 8) >= 1;
	if (right)
	{
		int data = (int) (((double) std::rand() / RAND_MAX) * 10);
		root->AddRight(std::make_shared<Node>(data, nullptr, nullptr));
		MakeNode(root->GetRight(), level + 1, height);
	}
}

void MyTree::GenerateTree(const int& height)
{
#pragma warning(disable:4244)
	std::srand(std::time(0));
	MakeNode(root, 0, height);
}

std::shared_ptr<Node> MyTree::GetElem(const int& data, std::shared_ptr<Node> root)
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
		std::shared_ptr<Node> left = GetElem(data, root->GetLeft());
		std::shared_ptr<Node> right = GetElem(data, root->GetRight());
		return left != nullptr ? left : right;
	}
}

int GetTreeHeight(std::shared_ptr<Node> root)
{
	if (root == nullptr)
		return 0;

	return std::max(GetTreeHeight(root->GetLeft()), GetTreeHeight(root->GetRight())) + 1;
}

int MyTree::GetHeight()
{
	return GetTreeHeight(root);
}

void PrintTreeByLevels(std::list<std::shared_ptr<Node>>& nodes, const int& height, const int& level)
{
	double step = std::pow(2.0, height - level);

	if (level > height)
		return;

	std::list<std::shared_ptr<Node>> newNodes;
	std::for_each(nodes.cbegin(), nodes.cend(), [&newNodes, &step](std::shared_ptr<Node> node)
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
	std::list<std::shared_ptr<Node>> nodes { root };
	PrintTreeByLevels(nodes, GetHeight(), 0);
}

void PrintTreeInOrder(std::shared_ptr<Node> root)
{
	if (root == nullptr)
		return;
	
	PrintTreeInOrder(root->GetLeft());
	std::cout << root->GetData() << "  ";
	PrintTreeInOrder(root->GetRight());
}

void MyTree::PrintTreeInOrder()
{
	std::cout << "PrintTreeInOrder:" << std::endl;
	::PrintTreeInOrder(root);
	std::cout << std::endl;
}

void PrintTreePreOrder(std::shared_ptr<Node> root)
{
	if (root == nullptr)
		return;

	std::cout << root->GetData() << "  ";
	PrintTreePreOrder(root->GetLeft());
	PrintTreePreOrder(root->GetRight());
}

void MyTree::PrintTreePreOrder()
{
	std::cout << "PrintTreePreOrder:" << std::endl;
	::PrintTreePreOrder(root);
	std::cout << std::endl;
}

void PrintTreePostOrder(std::shared_ptr<Node> root)
{
	if (root == nullptr)
		return;

	PrintTreePostOrder(root->GetLeft());
	PrintTreePostOrder(root->GetRight());
	std::cout << root->GetData() << "  ";
}

void MyTree::PrintTreePostOrder()
{
	std::cout << "PrintTreePostOrder:" << std::endl;
	::PrintTreePostOrder(root);
	std::cout << std::endl;
}

bool contains(const std::set<Node*>& visited, const Node* node)
{
	return std::find_if(visited.cbegin(), visited.cend(), 
		[node](const Node* _node) { return _node == node; }) != visited.cend();
}

void MyTree::PrintTreeInOrderIteratively()
{
	std::cout << "PrintTreeInOrderIteratively:" << std::endl;

	std::list<std::shared_ptr<Node>> nodes { };
	std::shared_ptr<Node> curr = root;

	// L-V-R
	while (!nodes.empty() || curr != nullptr)
	{
		if (curr != nullptr)
		{
			nodes.push_back(curr);
			curr = curr->GetLeft();
			continue;
		}

		std::shared_ptr<Node> node = nodes.back();
		nodes.pop_back();

		std::cout << node->GetData() << " ";
		curr = node->GetRight();
	}
	std::cout << std::endl;
}

void MyTree::PrintTreePreOrderIteratively()
{
	std::cout << "PrintTreePreOrderIteratively:" << std::endl;

	std::cout << std::endl;
}

void MyTree::PrintTreePostOrderIteratively()
{
	std::cout << "PrintTreePostOrderIteratively:" << std::endl;

	std::cout << std::endl;
}