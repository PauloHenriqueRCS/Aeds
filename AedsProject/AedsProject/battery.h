#pragma once
#include "Node.h"

struct Battery {
	Node *top;
	void init();
	int qtd;
	bool isEmpty();
	void stack(int element);
	bool unpack();
	void clearAll();
	void print();
};
