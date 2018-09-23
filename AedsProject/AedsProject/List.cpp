#include "stdafx.h"

List::List() {
	root = new Cliente();
	root->codigo = -1;
	root->next = root;
}

inline bool List::isEmpty()
{
	return (root->next == root);
}

void List::initializer()
{
	root = new Cliente();
	root->codigo = -1;
	root->next = root;
}

void List::addEnd(Cliente * c)
{
	if (isEmpty()) {
		root->next = c;
		c->next = root;
	}
	else {
		Cliente * aux = root->next;
		while (aux->next != root)
			aux = aux->next;
		aux->next = c;
		c->next = root;
	}
}

void List::addBegin(Cliente * c)
{
	Cliente * aux;
	aux = root->next;
	root->next = c;
	c->next = aux;
}

bool List::removeEnd()
{
	if (isEmpty()) return false;
	else {
		Cliente * prev = root->next;
		Cliente * curr = prev->next;
		while (curr->next != root)
		{
			prev = curr;
			curr = curr->next;
		}
		prev->next = root;
		curr = nullptr;
		delete curr;
		return true;
	}
}

bool List::removeBegin()
{
	if (isEmpty()) return false;
	else {
		Cliente * aux = root->next;
		root->next = aux->next;
		aux = nullptr;
		delete aux;
		return true;
	}
}

bool List::bet(int codigo, float value)
{
	if (isEmpty()) return false;
	else {
		Cliente * aux = root->next;
		while (aux != root)
		{
			if (aux->codigo == codigo)
			{
				aux->saldo = aux->saldo + value;
				return true;
			}
			else
				aux = aux->next;
		}
		return false;
	}
}

Cliente * List::search(int codigo)
{
	if (!isEmpty()) {
		Cliente * aux = root->next;
		while (aux != root)
		{
			if (aux->codigo == codigo)
				return aux;
			else
				aux = aux->next;
		}
	}
}

void List::print()
{
	Cliente * c = root->next;
	while (c != root)
	{
		std::cout << "Codigo: " << c->codigo << ", Nome: " << c->nome << ", Saldo: " << c->saldo << "\n\n";
		c = c->next;
	}
}

void List::printThis(int codigo)
{
	if (!isEmpty()) {
		Cliente * c = root->next;
		while (c != root)
		{
			if (c->codigo == codigo)
			{
				std::cout << "Codigo: " << c->codigo << ", Nome: " << c->nome << ", Saldo: " << c->saldo << "\n\n";
				break;
			}
			else
				c = c->next;
		}
	}
}

int List::size()
{
	int count = 0;
	Cliente * c = root->next;
	while (c != root)
	{
		count++;
		c = c->next;
	}
	return count;
}
