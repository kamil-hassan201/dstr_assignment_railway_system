#include "StationList.h"

void StationList::insertFront(StationNode* new_node)
{
	if (head == nullptr) {
		head = tail = new_node;
	}
	else {
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	sizeOfList++;
}


void StationList::insertEnd(StationNode* new_node)
{
	if (head == nullptr) {
		head = tail = new_node;
	}
	else {
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	sizeOfList++;
}


void StationList::insertAfter(StationNode* targetNode, StationNode * new_node)
{
	new_node->prev = targetNode;
	new_node->next = targetNode->next;
	targetNode->next->prev = new_node;
	targetNode->next = new_node;
	if(targetNode == tail) {
		tail = new_node;
	}
	sizeOfList++;
}

void StationList::editNextFare(StationNode* targetNode, float nextFare)
{
	targetNode->nextFare = nextFare;
}

void StationList::editNextTravelTime(StationNode* targetNode, float nextTime)
{
	targetNode->nextTime = nextTime;
}

void StationList::editStationName(StationNode* targetNode, string new_name)
{
	targetNode->name = new_name;
}

StationNode* StationList::searchById(int id)
{
	StationNode* current_node = head;
	while (current_node->id == id) {
		current_node = current_node->next;
	}
	return current_node;
}

float StationList::calculateDistance(int sourceId, int destinationId)
{
	StationNode* current_node = searchById(sourceId);
	float totalDistance = 0;

	while (current_node->id != destinationId) {
		totalDistance += current_node->nextDistance;
		current_node = current_node->next;
	}

	return totalDistance;
}

float StationList::calculateFare(int sourceId, int destinationId)
{
	StationNode* current_node = searchById(sourceId);
	float totalFare = 0;

	while (current_node->id != destinationId) {
		totalFare += current_node->nextFare  ;
		current_node = current_node->next;
	}

	return totalFare;
}

float StationList::calculateTime(int sourceId, int destinationId)
{
	StationNode* current_node = searchById(sourceId);
	float totalTime = 0;

	while (current_node->id != destinationId) {
		totalTime += current_node->nextTime;
		current_node = current_node->next;
	}

	return totalTime;
}
