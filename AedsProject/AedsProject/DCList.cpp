#include "stdafx.h"
int DCList::height(int num_record)
{
	if (first->num_record == num_record)
		return size - 1;
	else if (last->num_record == num_record)
		return 0;
	else {
		Record * record = first->next;
		int count = 2;
		do
		{
			if (record->num_record == num_record)
				return size - count;
			else {
				count++;
				record = record->next;
			}
		} while (record != first);
	}
}

int DCList::pairsElements()
{
	if (size % 2 == 0)
		return size / 2;
	else
		return ((size - 1) / 2);
}

void DCList::init() {
	first = last = nullptr;
	size = 0;
}

inline bool DCList::isEmpty()
{
	return (first == nullptr);
}

void DCList::addBegin(Record * record)
{
	if (isEmpty()) {
		first = last = record;
		first->next = last;
		first->prev = last;
		last->next = first;
		last->prev = first;
		size++;
	}
	else {
		last->next = record;
		record->prev = last;
		record->next = first;
		first->prev = record;
		first = record;
		size++;
	}
}

void DCList::addEnd(Record * record)
{
	if (isEmpty()) {
		first = last = record;
		first->next = last;
		first->prev = last;
		last->next = first;
		last->prev = first;
		size++;
	}
	else {
		last->next = record;
		record->prev = last;
		record->next = first;
		first->prev = record;
		last = record;
		size++;
	}
}
bool DCList::removeEnd()
{
	if (isEmpty())
		return false;
	else {
		Record * aux = last->prev;
		aux->next = first;
		first->prev = aux;
		aux = last;
		aux = nullptr;
		last = first->prev;
		delete aux;
		size--;
		return true;
	}
}

bool DCList::removeBegin()
{
	if (isEmpty())
		return false;
	else {
		Record * aux = first->next;
		aux->prev = last;
		last->next = aux;
		aux = first;
		aux = nullptr;
		first = last->next;
		delete aux;
		size--;
		return true;
	}
}
Record * DCList::search(int num_record)
{
	if (isEmpty())
		return nullptr;
	else {
		Record* aux = first;
		do
		{
			if (aux->num_record == num_record)
				return aux;
			else
				aux = aux->next;
		} while (aux != first);
		return nullptr;
	}
}
bool DCList::removeRecord(int num_record)
{
	if (isEmpty())
		return false;
	else {
		Record * aux = first;
		do
		{
			if (aux->num_record == num_record)
			{
				aux->prev->next = aux->next;
				aux->next->prev = aux->prev;
				aux = nullptr;
				delete aux;
				size--;
				return true;
			}
			else
				aux = aux->next;
		} while (aux != first);
		return false;
	}
}
void DCList::print()
{
	Record * record = first;
	if (!isEmpty()) {
		do
		{
			std::cout << record->num_record << ' ';
			record = record->next;
		} while (record != first);
	}
}
void DCList::printIn()
{
	Record * record = last;
	if (!isEmpty()) {
		do
		{
			std::cout << record->num_record << ' ';
			record = record->prev;
		} while (record != last);
	}
}