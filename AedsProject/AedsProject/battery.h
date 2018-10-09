#pragma once
#include <string>
#include "block.h"
struct Battery {
	Block *top;
	void init();
	int qtd;
	bool isEmpty();
	void stack(char element);
	bool unpack();
	void clearAll();
	void print();
	bool chainBalancing(std::string *chain);
};