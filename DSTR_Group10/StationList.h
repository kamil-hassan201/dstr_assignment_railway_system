#pragma once
#include <iostream>
#include "StationNode.h"

using namespace std;


class StationList
{
public:
	StationNode* head;
	StationNode* tail;
	StationNode* sortedRef;
	int sizeOfList;

	void insertFront(StationNode* new_node);
	void insertEnd(StationNode* new_node);
	void insertAfter(StationNode* new_node);



	// default constructor
	StationList() {
		this->head = nullptr;
		this->tail = nullptr;
		this->sizeOfList = 0;
		this->sortedRef = nullptr;
	}
};

