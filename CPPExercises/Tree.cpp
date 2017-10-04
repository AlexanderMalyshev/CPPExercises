#include "Tree.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <list>
#include <set>
#include <iostream>

void MakeNode(Node* root, const int& level, const int& height)
{
	if (level == height)
		return;

	bool left = (((double) std::rand() / RAND_MAX) * 8) >= 1;
	if (left)
	{
		int data = (int) (((double) std::rand() / RAND_MAX) * 10);
		root->AddLeft(new Node(data, nullptr, nullptr));
		MakeNode(root->GetLeft(), level + 1, height);
	}

	bool right = (((double) std::rand() / RAND_MAX) * 8) >= 1;
	if (right)
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

void PrintTreeInOrder(const Node* root)
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
	::PrintTreeInOrder(root.get());
	std::cout << std::endl;
}

void PrintTreePreOrder(const Node* root)
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
	::PrintTreePreOrder(root.get());
	std::cout << std::endl;
}

void PrintTreePostOrder(const Node* root)
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
	::PrintTreePostOrder(root.get());
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

	std::list<Node*> nodes { root.get() };
	std::set<Node*> visited;
	Node* node = nullptr;

	// L-V-R
	while (!nodes.empty())
	{
		const Node* node = nodes.back();
		
		if (node->GetLeft() != nullptr && !contains(visited, node->GetLeft()))
		{
			nodes.push_back(node->GetLeft());
			continue;
		}

		std::cout << node->GetData() << "  ";
		visited.emplace(node);
		nodes.pop_back();

		if (node->GetRight() != nullptr)
		{
			nodes.push_back(node->GetRight());
			continue;
		}
	}
	std::cout << std::endl;
}

void MyTree::PrintTreePreOrderIteratively()
{
	std::cout << "PrintTreePreOrderIteratively:" << std::endl;

	std::list<Node*> nodes { root.get() };

	// V-L-R
	while (!nodes.empty())
	{
		const Node* node = nodes.back();
		if (node == nullptr)
		{
			nodes.pop_back();
			continue;
		}

		std::cout << node->GetData() << "  ";
		nodes.pop_back();

		nodes.push_back(node->GetRight());
		nodes.push_back(node->GetLeft());
	}
	std::cout << std::endl;
}

void MyTree::PrintTreePostOrderIteratively()
{
	std::list<Node*> nodes { root.get() };

	// L-R-V
	while (!nodes.empty())
	{
		const Node* node = nodes.back();
		if (node == nullptr)
		{
			nodes.pop_back();
			continue;
		}

		std::cout << node->GetData() << "  ";
		nodes.pop_back();

		nodes.push_back(node->GetRight());
		nodes.push_back(node->GetLeft());
	}
	std::cout << std::endl;
}