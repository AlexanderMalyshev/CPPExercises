#pragma once

#include <memory>

class Node
{
	int data;
	std::unique_ptr<Node> left;
	std::unique_ptr<Node> right;

public:
	Node(int _data, Node* _left, Node* _right) : data { _data }, left { _left }, right { _right }
	{
	}

	void AddLeft(Node* _left)
	{
		left.reset(_left);
	}

	void AddRight(Node* _right)
	{
		right.reset(_right);
	}

	int GetData()
	{
		return data;
	}

	Node* GetLeft()
	{
		return left.get();
	}

	Node* GetRight()
	{
		return right.get();
	}
};

class MyTree
{
	std::unique_ptr<Node> root;

public:
	MyTree(Node* _root) : root { _root }
	{
	};

	void GenerateTree(const int& height);
	Node* GetElem(const int& data, Node* root);
	int GetHeight();

	void PrintTree();
};