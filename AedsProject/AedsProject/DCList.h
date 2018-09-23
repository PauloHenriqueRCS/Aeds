#include "Record.h"
struct DCList {
	Record * first;
	Record * last;
	int size;
	int height(int num_record);
	int pairsElements();
	void init();
	bool isEmpty();
	void addEnd(Record * record);
	void addBegin(Record * record);
	bool removeEnd();
	bool removeBegin();
	bool removeRecord(int num_record);
	Record * search(int num_record);
	void print();
	void printIn();
};