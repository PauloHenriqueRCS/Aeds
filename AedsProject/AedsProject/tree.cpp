#include "stdafx.h"
#include "tree.h"

void Tree::init()
{
	root = nullptr;
}

No* Tree::insert(No *no, No *root)
{
	if (this->root == nullptr)
		return no;
	if (root->value > no->value)
		root->left = insert(no, root->left);
	else
		root->right = insert(no, root->right);
	return root;
}

void Tree::add(int value)
{
	No *no = new No();
	no->init(value);
	root = insert(no, root);
}

void Tree::remove()
{
}

void Tree::preOrder(No *no)
{
	if (no != nullptr) {
		printRoot();
		preOrder(no->left);
		preOrder(no->right);
	}
}

void Tree::preOrder()
{
	if (root != nullptr)
		preOrder(root);
}

void Tree::posOrder(No * no)
{
	if (no != nullptr) {
		preOrder(no->left);
		preOrder(no->right);
		printRoot();
	}
}

void Tree::posOrder()
{
	if (root != nullptr)
		posOrder(root);
}

void Tree::inOrder(No * no)
{
	if (no != nullptr) {
		inOrder(no->right);
		printRoot();
		inOrder(no->left);
	}
}

void Tree::inOrder()
{
	if (root != nullptr)
		inOrder(root);
}

void Tree::printRoot()
{
	if (root != nullptr)
		std::cout << root->value << std::endl;
}

