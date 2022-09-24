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
	void insertAfter(StationNode* targetNode, StationNode* new_node);
	void editNextFare(StationNode* targetNode, float nextFare);
	void editNextTravelTime(StationNode* targetNode, float nextTime);
	void editStationName(StationNode* targetNode, string new_name);
	float calculateDistance(int sourceId, int destinationId);
	float calculateFare(int sourceId, int destinationId);
	float calculateTime(int sourceId, int destinationId);


	StationNode* searchById(int id);



	// default constructor
	StationList() {
		this->head = nullptr;
		this->tail = nullptr;
		this->sizeOfList = 0;
		this->sortedRef = nullptr;
	}
};