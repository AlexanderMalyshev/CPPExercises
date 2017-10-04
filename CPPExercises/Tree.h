#pragma once

#include <memory>

class Node
{
	int m_data;
	Node* m_ptr;
	std::unique_ptr<Node> m_left;
	std::unique_ptr<Node> m_right;

public:
	Node(int _data, Node* _left, Node* _right) : 
		m_data { _data }, m_left { _left }, m_right { _right }
	{
		m_ptr = nullptr;
	}

	void AddLeft(Node* _left) {	m_left.reset(_left); }
	void AddRight(Node* _right)	{ m_right.reset(_right); }
	void SetPtr(Node* ptr)	{ m_ptr = ptr; }
	int GetData() const	{ return m_data; }
	Node* GetLeft() const {	return m_left.get(); }
	Node* GetRight() const { return m_right.get(); }	
	Node* GetPtr() const { return m_ptr; }
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

	void ConnectLayers();
};