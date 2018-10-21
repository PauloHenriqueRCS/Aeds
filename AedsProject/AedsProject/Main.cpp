#include "stdafx.h"

using namespace std;

void invertRow(Battery *battery, Row *row) {
	Node * node = row->front;
	while (node != nullptr)
	{
		battery->stack(node->element);
		row->deworming();
		node = row->front;
	}
	node = battery->top;
	while (node != nullptr)
	{
		row->rowing(node->element);
		battery->unpack();
		node = battery->top;
	}
}

void rowBank() {
	Row row, row2;
	row.initPerson();
	row2.initPerson();
	for (int i = 0; i < 10; i++)
		row.rowingPerson("Pessoa", rand() % 100);
	row.printPerson();
	Person * person = row.frontPerson;
	while (person != nullptr)
	{
		if (person->age >= 60) {
			row2.rowingOrderPerson(person->name, person->age);
			row.removePerson(person->age);
		}
		person = person->next;
	}
	row.printPerson();
	row2.printPerson();
}

void rowProcess() {
	Row row;
	row.initProcess();
	for (size_t i = 0; i < 10; i++)
		row.rowingProcess(rand() % 100, rand() % 100);
	row.printProcess();
	Process * process = row.frontProcess;
	int bigger = row.frontProcess->timeStamp;
	while (process != nullptr)
	{
		if (process->timeStamp > bigger)
			bigger = process->timeStamp;
		process = process->next;
	}
	row.removeProcess(bigger);
	row.printProcess();
}

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}
