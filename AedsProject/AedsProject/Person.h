#pragma once
#include <string>
struct Person {
	Person * next;
	std::string name;
	int age;
	void init(std::string name, int age);
};