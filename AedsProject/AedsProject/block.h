#pragma once
struct Block {
	char element;
	Block * next;
	Block * prev;
	void init(char element);
};

struct BlockC {
	int element;
	BlockC * next;
	void init(int element);
};