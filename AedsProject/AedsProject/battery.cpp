#include "stdafx.h"
#pragma once

void Block::init(char element)
{
	this->element = element;
	this->next = nullptr;
}

void Battery::init()
{
	top = nullptr;
	qtd = 0;
}

bool Battery::isEmpty()
{
	return top == nullptr;
}

void Battery::stack(char element)
{
	Block * block = new Block();
	if (block == nullptr)
		std::cout << "faill memmory\n";
	else {
		block->init(element);
		block->next = top;
		top = block;
	}
}

bool Battery::unpack()
{
	if (isEmpty())
		return false;
	else {
		Block * block = top;
		top = block->next;
		block = nullptr;
		delete block;
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
		Block * block = top;
		while (block != nullptr)
		{
			std::cout << block->element << std::endl;
			block = block->next;
		}
	}
}

bool Battery::chainBalancing(std::string *chain)
{
	for (size_t i = 0; i < chain->length(); i++)
	{

		if (chain->at(i) == '(')
			this->stack(chain->at(i));
		else if (chain->at(i) == ')')
			if (this->top->element == '(')
				this->unpack();
	}
	return this->isEmpty();
}
