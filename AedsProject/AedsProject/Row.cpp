#include "stdafx.h"
#pragma once

using namespace std;

inline void Node::init(int element)
{
	this->element = element;
	this->next = nullptr;
}

void Row::init()
{
	this->front = this->behind = nullptr;
	this->qtd = 0;
}

bool Row::isEmpty()
{
	return (this->front == nullptr) && (this->behind == nullptr);
}

void Row::rowing(int element)
{
	Node * node = new Node();
	if (node == nullptr)
		std::cout << "faill memmory\n";
	else {
		node->init(element);
		if (isEmpty()) {
			front = node;
			behind = node;
		}
		else {
			behind->next = node;
			behind = node;
		}
		qtd++;
	}
}

bool Row::deworming()
{
	if (isEmpty())
		return false;
	else {
		Node * node = front;
		front = node->next;
		if (front == nullptr)
			behind = nullptr;
		delete node;
		qtd--;
		return true;
	}
}

void Row::clearAll()
{
	while (!isEmpty())
		deworming();
}

void Row::print()
{
	if (!isEmpty()) {
		Node * node = front;
		while (node != nullptr)
		{
			std::cout << node->element << " ";
			node = node->next;
		}
		std::cout << "\n";
	}
}

bool Row::remove(int value)
{
	Node * node = front;
	if (node->element == value) {
		deworming();
		return true;
	}
	else {
		Node * prev = node;
		node = node->next;
		while (node != nullptr)
		{
			if (node->element == value) {
				prev->next = node->next;
				node = nullptr;
				delete node;
				qtd--;
				return true;
			}
			prev = node;
			node = node->next;
		}
	}
	return false;
}

// 3. Airplane

void Airplane::init(std::string name, int number)
{
	this->name = name;
	this->number = number;
}

void Row::initAirplane()
{
	this->frontAirplane = this->behindAirplane = nullptr;
	this->qtd = 0;
}

bool Row::isEmptyAirplane()
{
	return (this->frontAirplane == nullptr) && (this->behindAirplane == nullptr);
}

void Row::rowingAirplane(std::string name, int number)
{
	Airplane * airplane = new Airplane();
	if (airplane == nullptr)
		std::cout << "faill memmory\n";
	else {
		airplane->init(name, number);
		if (isEmptyAirplane()) {
			frontAirplane = airplane;
			behindAirplane = airplane;
		}
		else {
			behindAirplane->next = airplane;
			behindAirplane = airplane;
		}
		qtd++;
	}
}

bool Row::dewormingAirplane()
{
	if (isEmptyAirplane())
		return false;
	else {
		Airplane * airplane = frontAirplane;
		frontAirplane = airplane->next;
		if (frontAirplane == nullptr)
			behindAirplane = nullptr;
		delete airplane;
		qtd--;
		return true;
	}
}

void Row::clearAllAirplane()
{
	while (!isEmptyAirplane())
		dewormingAirplane();
}

void Row::printAirplane()
{
	if (!isEmptyAirplane()) {
		Airplane * airplane = frontAirplane;
		while (airplane != nullptr)
		{
			std::cout << airplane->name << " " << airplane->number << "\n";
			airplane = airplane->next;
		}
		std::cout << "\n";
	}
}


bool Row::removeAirplane(int number)
{
	Airplane * airplane = frontAirplane;
	if (airplane->number == number) {
		dewormingAirplane();
		return true;
	}
	else {
		Airplane * airplanePrev = airplane;
		airplane = airplane->next;
		while (airplane != nullptr)
		{
			if (airplane->number == number) {
				airplanePrev->next = airplane->next;
				airplane = nullptr;
				delete airplane;
				qtd--;
				return true;
			}
			airplanePrev = airplane;
			airplane = airplane->next;
		}
	}
	return false;
}

void Row::printFirstAirplane()
{
	if (!isEmptyAirplane())
		std::cout << frontAirplane->name << " " << frontAirplane->number << "\n";
}

// 4. Person

void Person::init(std::string name, int age)
{
	this->name = name;
	this->age = age;
}


void Row::initPerson()
{
	this->frontPerson = this->behindPerson = nullptr;
	this->qtd = 0;
}

bool Row::isEmptyPerson()
{
	return (this->frontPerson == nullptr) && (this->behindPerson == nullptr);
}

void Row::rowingPerson(std::string name, int age)
{
	Person * person = new Person();
	if (person == nullptr)
		std::cout << "faill memmory\n";
	else {
		person->init(name, age);
		if (isEmptyPerson()) {
			frontPerson = person;
			behindPerson = person;
		}
		else {
			behindPerson->next = person;
			behindPerson = person;
		}
		qtd++;
	}
}

void Row::rowingOrderPerson(string name, int age)
{
	Person * person = new Person();
	person->init(name, age);

	if (isEmptyPerson())
	{
		frontPerson = person;
		behindPerson = person;
	}
	else
	{
		Person * curr = frontPerson;
		Person * prev = nullptr;

		while (curr != nullptr && curr->age > person->age) {
			prev = curr;
			curr = curr->next;
		}
		person->next = curr;
		if (prev == nullptr) {
			frontPerson = person;
			behindPerson = person;
		}
		else {
			prev->next = person;
		}	
	}
}

bool Row::dewormingPerson()
{
	if (isEmptyPerson())
		return false;
	else {
		Person * person = frontPerson;
		frontPerson = person->next;
		if (frontPerson == nullptr)
			behindPerson = nullptr;
		delete person;
		qtd--;
		return true;
	}
}

void Row::clearAllPerson()
{
	while (!isEmptyPerson())
		dewormingPerson();
}

void Row::printPerson()
{
	if (!isEmptyPerson()) {
		Person * person = frontPerson;
		while (person != nullptr)
		{
			std::cout << person->name << " " << person->age << "\n";
			person = person->next;
		}
		std::cout << "\n";
	}
}

bool Row::removePerson(int age)
{
	Person * person = frontPerson;
	if (person->age == age) {
		dewormingPerson();
		return true;
	}
	else {
		Person * personPrev = person;
		person = person->next;
		while (person != nullptr)
		{
			if (person->age == age) {
				personPrev->next = person->next;
				person = nullptr;
				delete person;
				qtd--;
				return true;
			}
			personPrev = person;
			person = person->next;
		}
	}
	return false;
}



// 5. Process

void Process::init(int id, int timeStamp)
{
	this->id = id;
	this->timeStamp = timeStamp;
}

void Row::initProcess()
{
	this->frontProcess = this->behindProcess = nullptr;
	this->qtd = 0;
}

bool Row::isEmptyProcess()
{
	return (this->frontProcess == nullptr) && (this->behindProcess == nullptr);
}

void Row::rowingProcess(int id, int timeStamp)
{
	Process * process = new Process();
	if (process == nullptr)
		std::cout << "faill memmory\n";
	else {
		process->init(id, timeStamp);
		if (isEmptyProcess()) {
			frontProcess = process;
			behindProcess = process;
		}
		else {
			behindProcess->next = process;
			behindProcess = process;
		}
		qtd++;
	}
}


bool Row::dewormingProcess()
{
	if (isEmptyProcess())
		return false;
	else {
		Process * process = frontProcess;
		frontProcess = process->next;
		if (frontProcess == nullptr)
			behindProcess = nullptr;
		delete process;
		qtd--;
		return true;
	}
}

void Row::clearAllProcess()
{
	while (!isEmptyProcess())
		dewormingProcess();
}

void Row::printProcess()
{
	if (!isEmptyProcess()) {
		Process * process = frontProcess;
		while (process != nullptr)
		{
			std::cout << process->id << " " << process->timeStamp << "\n";
			process = process->next;
		}
		std::cout << "\n";
	}
}

bool Row::removeProcess(int timeStamp)
{
	Process * process = frontProcess;
	if (process->timeStamp == timeStamp) {
		dewormingProcess();
		return true;
	}
	else {
		Process * processPrev = process;
		process = process->next;
		while (process != nullptr)
		{
			if (process->timeStamp == timeStamp) {
				processPrev->next = process->next;
				process = nullptr;
				delete process;
				qtd--;
				return true;
			}
			processPrev = process;
			process = process->next;
		}
	}
	return false;
}
