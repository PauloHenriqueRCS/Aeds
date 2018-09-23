#include "stdafx.h"

using namespace std;

Record * createRecords() {
	Record * records = new Record[10];
	for (size_t i = 0; i < 10; i++) 
		records[i].num_record = i;
		//records[i].num_record = rand() % 100;
	return records;
}

int main()
{
	DCList list;
	list.init();
	Record * records = createRecords();
	for (size_t i = 0; i < 10; i++)
		list.addEnd(&records[i]);
	cout << "\n<------------------------------------------------->\n";
	cout << "List [";
	list.print();
	cout << "]\n<------------------------------------------------->\n";
	cout << "\n<------------------------------------------------->\n";
	cout << "Elementos pares = ";
	cout<< list.pairsElements();
	cout << "\n<------------------------------------------------->\n";
	cout << "ALtura de registro = ";
	cout << list.height(7);
	cout << "\n<------------------------------------------------->\n";


	system("pause");
	return EXIT_SUCCESS;
}
