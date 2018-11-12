#pragma once
struct No {
	int value;
	No *left;
	No *right;
	void init(int value);
};

void No::init(int value)
{
	this->value = value;
}