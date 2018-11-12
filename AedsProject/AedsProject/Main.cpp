#include "stdafx.h"

using namespace std;

int main()
{
	Tree tree;
	tree.init();
	int values[] = { 2, 90, 30, 10, 12, 23 , 19 };

	for (size_t i = 0; i < 7; i++)
		tree.add(values[i]);
	tree.preOrder();
	tree.inOrder();
	tree.posOrder();

	system("pause");
	return EXIT_SUCCESS;
}
