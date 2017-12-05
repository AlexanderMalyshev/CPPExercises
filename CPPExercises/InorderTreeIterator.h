#pragma once

#include <memory>
#include <list>
#include "Tree.h"

class InorderTreeIterator
{
public:
	InorderTreeIterator(std::shared_ptr<Node> root): curr { root }
	{
	}

	std::shared_ptr<Node> GetNext()
	{
		if (curr == nullptr && nodes.empty())
			return nullptr;

		while (curr != nullptr)
		{
			nodes.emplace_back(curr);
			curr = curr->GetLeft();
		}

		std::shared_ptr<Node> res = nodes.back();
		nodes.pop_back();

		curr = res->GetRight();

		return res;

	}
private:
	std::list<std::shared_ptr<Node>> nodes;
	std::shared_ptr<Node> curr;
};