#pragma once
#include "No.h"

struct Tree {
	No *root;
	void init();
	void add(int value);
	No *insert(No *no, No* root);
	void remove();
	void preOrder(No *no);
	void posOrder(No *no);
	void inOrder(No *no);
	void preOrder();
	void posOrder();
	void inOrder();
	void printRoot();
};