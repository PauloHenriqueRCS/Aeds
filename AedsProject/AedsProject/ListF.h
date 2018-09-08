#pragma once
#include "Funcionario.h"
struct ListF {
private:
	Funcionario * root;
public:
	bool isEmpty();
	void initializer();
	void addEnd(Funcionario * f);
	void addBegin(Funcionario * f);
	bool removeEnd();
	bool removeBegin();
	void print();
	void printThis(Funcionario * f);
	Funcionario * search(int such);
};
