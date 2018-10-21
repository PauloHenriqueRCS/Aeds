#pragma once
#include "Node.h"
#include "Airplane.h"
#include "Person.h"

struct Row {
	Node * front;
	Node * behind;
	void init();
	int qtd;
	bool isEmpty();
	void rowing(int element);
	bool deworming();
	void clearAll();
	void print();
	bool remove(int value);

	// Airplane
	Airplane * frontAirplane;
	Airplane * behindAirplane;
	bool isEmptyAirplane();
	void rowingAirplane(std::string name, int number);
	bool dewormingAirplane();
	void clearAllAirplane();
	void printAirplane();
	bool removeAirplane(int number);
	void printFirstAirplane();

	// Person
	Person * frontPerson;
	Person * behindPerson;
	bool isEmptyPerson();
	void rowingPerson(std::string name, int age);
	void orderPerson();
	bool dewormingPerson();
	void clearAllPerson();
	void printPerson();
	bool removePerson(int age);
};