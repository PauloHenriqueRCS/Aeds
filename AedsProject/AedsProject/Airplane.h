#pragma once
#include <string>
struct Airplane {
	Airplane * next;
	std::string name;
	int number;
	void init(std::string name, int number);
};