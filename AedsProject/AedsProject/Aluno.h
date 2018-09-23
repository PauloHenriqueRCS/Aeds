#pragma once
#include <string>
struct Aluno {
	int matricula;
	std::string nome;
	float notas[4];
	Aluno * next = nullptr;
	Aluno * prev = nullptr;
};
