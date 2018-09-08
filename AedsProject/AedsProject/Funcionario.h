#pragma once
#include <string>

struct Funcionario {
	int matricula;
	std::string nome;
	float salario;
	Funcionario * next;
};
