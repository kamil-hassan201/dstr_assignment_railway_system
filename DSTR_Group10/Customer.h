#pragma once

#include <iostream>
using namespace std;

class Customer
{
	int id;
	string name;
	string identificationNumber;

	// default constructor
	Customer(int id, string name, string identificationNumber) {
		this->id = id;
		this->name = name;
		this->identificationNumber = identificationNumber;
	}
};

