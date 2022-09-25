#pragma once

#include <iostream>
using namespace std;

class Customer
{
public:
	int id;
	string name;
	string identificationNumber;
	string password;
	Customer* next;

	// default constructor
	Customer(int id, string name, string identificationNumber, string password) {
		this->id = id;
		this->name = name;
		this->identificationNumber = identificationNumber;
		this->password = password;
	}
};

