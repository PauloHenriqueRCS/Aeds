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
	void printInv();
	bool palin();
	std::string  getExpression();
	bool invert();
	bool transferElements(Battery *battery);
	int equals(Battery * battery);
	void insertCar(int position, char car);
	int calculator();
};

struct BatteryC {
	BlockC *top;
	void init();
	int qtd;
	bool isEmpty();
	void stack(int element);
	bool unpack();
	void clearAll();
	void print();
	int calculator();
};