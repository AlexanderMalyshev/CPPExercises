#pragma once

#include <memory>

class Node
{
	int data;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;

public:
	Node(int _data, Node* _left, Node* _right) : data { _data }, left { _left }, right { _right }
	{
	}

	void AddLeft(std::shared_ptr<Node> _left) { left = _left; }
	void AddRight(std::shared_ptr<Node> _right)	{ right = _right; }
	int GetData() const	{ return data; }
	std::shared_ptr<Node> GetLeft() const {	return left; }
	std::shared_ptr<Node> GetRight() const { return right; }
};

class MyTree
{
	std::shared_ptr<Node> root;

public:
	MyTree(Node* _root) : root { _root }
	{
	};

	void GenerateTree(const int& height);
	std::shared_ptr<Node> GetRoot() { return root; }
	std::shared_ptr<Node> GetElem(const int& data, std::shared_ptr<Node> root);
	int GetHeight();

	void PrintTree();
	void PrintTreeInOrder();
	void PrintTreePreOrder();
	void PrintTreePostOrder();
	void PrintTreeInOrderIteratively();
	void PrintTreePreOrderIteratively();
	void PrintTreePostOrderIteratively();
};