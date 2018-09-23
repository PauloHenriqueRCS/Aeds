#pragma once
#include <string>
struct Cliente {
	int codigo;
	std::string nome;
	float saldo;
	Cliente * next;
};