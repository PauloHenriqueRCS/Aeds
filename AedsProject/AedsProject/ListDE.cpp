#include "stdafx.h"

void ListDE::init() {
	root = nullptr;
}

inline bool ListDE::isEmpty()
{
	return (root == nullptr);
}

void ListDE::addBegin(Aluno * a)
{
	if (!isEmpty()) {
		a->next = root;
		root->prev = a;
		a->prev = nullptr;
	}
	root = a;
	root->prev = nullptr;
}

void ListDE::addEnd(Aluno * a)
{
	if (isEmpty())
		root = a;
	else {
		Aluno * aux = root;
		while (aux->next != nullptr)
			aux = aux->next;
		aux->next = a;
		a->prev = aux;
	}
}


bool ListDE::removeEnd()
{
	if (isEmpty()) {
		return false;
	}
	else {
		Aluno * aux = root;
		while (aux->next != nullptr)
			aux = aux->next;
		if (aux->prev != nullptr)
			(aux->prev)->next = nullptr;
		aux->prev = nullptr;
		delete aux;
		return true;
	}
}

bool ListDE::removeBegin()
{
	if (isEmpty())
		return false;
	else {
		Aluno * aux = root;
		if (aux->next == nullptr)
			root = nullptr;
		else {
			root = aux->next;
			root->prev = nullptr;
			aux->next = nullptr;
		}
		delete aux;
		return true;
	}
}

bool ListDE::removeAluno(int matricula)
{
	if (!isEmpty()) {
		Aluno * aux = root;
		while (aux != nullptr) {
			if (aux->matricula == matricula)
			{
				aux->prev->next = aux->next;
				if (aux->next != nullptr)
					aux->next->prev = aux->prev;
				aux = nullptr;
				delete aux;
				return true;
			}
			else
				aux = aux->next;
		}
		return false;
	}
	else {
		return false;
	}
}

Aluno * ListDE::search(int matricula)
{
	if (isEmpty())
		return nullptr;
	else {
		Aluno* aux = root;
		while (aux != nullptr)
		{
			if (aux->matricula == matricula)
				return aux;
			else
				aux = aux->next;
		}
		return nullptr;
	}
}

void ListDE::print()
{
	Aluno * c = root;
	while (c != nullptr)
	{
		float media = 0;
		for (size_t i = 0; i < 4; i++)
			media += c->notas[i];

		std::cout << "Codigo: " << c->matricula << ", Nome: " << c->nome << ", Media: " << media / 4 << "\n\n";
		c = c->next;
	}
}

void ListDE::unionList(ListDE * list)
{
	if (!list->isEmpty()) {
		Aluno * aux = root;
		while (aux->next != nullptr)
			aux = aux->next;
		aux->next = list->root;
		list->root->prev = aux;
	}
}

int ListDE::size()
{
	int count = 0;
	Aluno * c = root->next;
	while (c != root)
	{
		count++;
		c = c->next;
	}
	return count;
}
