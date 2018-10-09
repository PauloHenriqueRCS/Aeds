#pragma once
struct Block {
	char element;
	Block * next;
	void init(char element);
};