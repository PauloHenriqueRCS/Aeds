#include "ListF.h"
#include "stdafx.h"

inline bool ListF::isEmpty()
{
	return (root == nullptr);
}

void ListF::initializer()
{
	root = nullptr;
}

void ListF::addEnd(Funcionario * f)
{
	if (isEmpty())
		root = f;
	else {
		Funcionario * auxF = root;
		while (auxF->next != nullptr)
			auxF = auxF->next;
		auxF->next = f;
	}
}

void ListF::addBegin(Funcionario * f)
{
	f->next = root;
	root = f;
}

bool ListF::removeEnd()
{
	if (isEmpty())
		return false;
	else {
		Funcionario * prev = root;
		Funcionario * curr = root->next;
		if (curr != nullptr) {
			while (curr->next != nullptr)
			{
				prev = curr;
				curr = curr->next;
			}
			prev->next = nullptr;
		}
		else {
			curr = root;
			root = nullptr;
		}
		delete curr;
		return true;
	}
}

bool ListF::removeBegin()
{
	if (isEmpty())
		return false;
	else {
		Funcionario * auxF = root;
		if (auxF->next == nullptr)
			root = nullptr;
		else {
			root = auxF->next;
			auxF->next = nullptr;
		}
		delete auxF;
		return true;
	}
}

void ListF::print()
{
	if (!isEmpty()) {
		Funcionario * auxF = root;
		while (auxF != nullptr)
		{
			std::cout << auxF->nome << ", " << auxF->salario << "\n";
			auxF = auxF->next;
		}
		std::cout << "\n\n";
	}
}

void ListF::printThis(Funcionario * f)
{
	if (f != nullptr)
	std::cout << f->nome << "\n";
	std::cout << "\n\n";
}

Funcionario * ListF::search(int such)
{
	if (isEmpty())
		return nullptr;
	else {
		Funcionario * auxF = root;
		while (auxF != nullptr && auxF->matricula != such)
			auxF = auxF->next;
		if (auxF != nullptr && auxF->matricula == such)
			return auxF;
		else
			return false;
	}
}
