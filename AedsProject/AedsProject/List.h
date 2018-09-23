#pragma once
#include "Cliente.h"

class  List {
public:
	Cliente * root;
	List();
	bool isEmpty();
	void initializer();
	void addEnd(Cliente * c);
	void addBegin(Cliente * c);
	bool removeEnd();
	bool removeBegin();
	bool bet(int codigo, float value);
	Cliente * search(int codigo);
	void print();
	void printThis(int codigo);
	int size();
};

