#pragma once
#include "Aluno.h"
struct ListDE {
	Aluno * root;
	void init();
	int size();
	void addEnd(Aluno * a);
	void addBegin(Aluno * a);
	void print();
	void unionList(ListDE * list);
	bool isEmpty();
	bool removeEnd();
	bool removeBegin();
	bool removeAluno(int matricula);
	Aluno * search(int matricula);
};