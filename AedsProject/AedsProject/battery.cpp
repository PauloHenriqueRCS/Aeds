#include "stdafx.h"
#pragma once

using namespace std;

inline void Node::init(int element)
{
	this->element = element;
	this->next = nullptr;
}

void Battery::init()
{
	this->top = nullptr;
	this->qtd = 0;
}

bool Battery::isEmpty()
{
	return top == nullptr;
}

void Battery::stack(int element)
{
	Node * node = new Node();
	if (node == nullptr)
		std::cout << "faill memmory\n";
	else {
		if (isEmpty()) {
			node->init(element);
			node->next = top;
			top = node;
			qtd++;
		}
		else {
			node->init(element);
			node->next = top;
			top = node;
			qtd++;
		}
	}
}

bool Battery::unpack()
{
	if (isEmpty())
		return false;
	else {
		Node * node = top;
		top = node->next;
		node = nullptr;
		delete node;
		qtd--;
		return true;
	}
}

void Battery::clearAll()
{
	while (!isEmpty())
		unpack();
}

void Battery::print()
{
	if (!isEmpty()) {
		Node * node = top;
		while (node != nullptr)
		{
			std::cout << node->element << " ";
			node = node->next;
		}
		std::cout << "\n";
	}
}
