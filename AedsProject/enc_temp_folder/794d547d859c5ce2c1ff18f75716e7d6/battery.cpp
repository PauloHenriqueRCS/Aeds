#include "stdafx.h"
#pragma once

using namespace std;

void Block::init(char element)
{
	this->element = element;
	this->next = this->prev = nullptr;
}


void BlockC::init(int element)
{
	this->element = element;
	this->next = nullptr;
}

void Battery::init()
{
	top = nullptr;
	qtd = 0;
}

void BatteryC::init()
{
	top = nullptr;
	qtd = 0;
}

bool Battery::isEmpty()
{
	return top == nullptr;
}

bool BatteryC::isEmpty()
{
	return top == nullptr;
}

void Battery::stack(char element)
{
	Block * block = new Block();
	if (block == nullptr)
		std::cout << "faill memmory\n";
	else {
		if (isEmpty()) {
			block->init(element);
			block->next = top;
			top = block;
			qtd++;
		}
		else {
			block->init(element);
			block->next = top;
			top->prev = block;
			top = block;
			qtd++;
		}
	}
}

void BatteryC::stack(int element)
{
	BlockC * block = new BlockC();
	if (block == nullptr)
		std::cout << "faill memmory\n";
	else {
		block->init(element);
		block->next = top;
		top = block;
		qtd++;
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
bool BatteryC::unpack()
{
	if (isEmpty())
		return false;
	else {
		BlockC * block = top;
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

void BatteryC::clearAll()
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
			std::cout << block->element;
			block = block->next;
		}
	}
}

void BatteryC::print()
{
	if (!isEmpty()) {
		BlockC * block = top;
		while (block != nullptr)
		{
			std::cout << block->element;
			block = block->next;
		}
	}
}

void Battery::printInv()
{
	if (!isEmpty()) {
		Block * block = top;

		while (block->next != nullptr)
			block = block->next;

		while (block != nullptr)
		{
			std::cout << block->element;
			block = block->prev;
		}
	}
}

bool Battery::palin()
{
	std::string a, b;
	a = getExpression();
	b = a;
	std::reverse(b.begin(), b.end());

	return a == b;
}

std::string Battery::getExpression()
{
	std::string exp = "";
	if (!isEmpty()) {
		Block * block = top;
		while (block != nullptr)
		{
			exp += block->element;
			block = block->next;
		}
	}
	return exp;
}

bool Battery::invert()
{
	if (!isEmpty()) {
		Block * block = top;
		while (block->next != nullptr)
			block = block->next;
		top = block;
		while (block != nullptr)
		{
			block->next = block->prev;
			block = block->prev;
		}
		return true;
	}
	return false;
}

bool Battery::transferElements(Battery * battery)
{
	if (this->isEmpty())
		return false;
	else {
		std::string exp = this->getExpression();
		std::reverse(exp.begin(), exp.end());
		for (size_t i = 0; i < exp.length(); i++)
			battery->stack(exp.at(i));
		return true;
	}
}

int Battery::equals(Battery * battery)
{
	if (this->isEmpty() || battery->isEmpty())
		return 0;
	else {
		if (this->getExpression() == battery->getExpression())
			return 1;
		else
			return 0;
	}
}

void Battery::insertCar(int position, char car)
{
	if (!isEmpty() && (0 >= position <= qtd)) {
		Block * block = top;
		Battery * out;
		out = new Battery();
		out->init();
		for (size_t i = 0; i < position; i++)
		{
			out->stack(block->element);
			this->unpack();
			block = top;
		}

		out->unpack();
		out->stack(car);
		block = out->top;

		for (size_t i = 0; i < out->qtd; i++)
		{
			this->stack(block->element);
			block = block->next;
		}
	}
}

int Battery::calculator()
{
	BatteryC * calc = new BatteryC();
	calc->init();

	string exp = this->getExpression();
	std::reverse(exp.begin(), exp.end());
	cout << exp;
	for (size_t i = 0; i < exp.length(); i++)
	{
		switch (exp.at(0))
		{
			// E
		case 69:
			break;
			// C
		case 67:
			this->clearAll();
			break;
			// /
		case 47:
			break;
			// *
		case 42:
			break;
			// -
		case 45:
			break;
			// +
		case 43:
			break;
			// 0-9
		default:
			break;
		}
	}

	

	return 0;
}
