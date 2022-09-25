#include "StationList.h"

void StationList::displatStations()
{
	StationNode* current_node = head;

	if (head == nullptr) {
		cout << "The list is empty!!" << endl;
	}

	while (current_node->next != nullptr) {
		
		cout << current_node->id << ". " << current_node->name << "  <-->  ";
		current_node = current_node->next;
	}
	cout << current_node->id << ". " << current_node->name << endl;
}

void StationList::insertFront(StationNode* new_node)
{
	if (head == nullptr) {
		head = tail = new_node;
	}
	else {
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
		this->serializeId();
	}
	sizeOfList++;
}


void StationList::insertEnd(StationNode* new_node)
{
	if (head == nullptr) {
		head = tail = new_node;
	}
	else {
		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;
	}
	sizeOfList++;
}

// not tested yet
void StationList::insertEndByAdmin(int id, string name, float prevFare, float prevTime, float prevDistance)
{
	StationNode* new_node = new StationNode(id, name, NULL, NULL, NULL);

	tail->nextFare = prevFare;
	tail->nextTime = prevTime;
	tail->nextDistance = prevDistance;

	tail->next = new_node;
	new_node->prev = tail;
	tail = new_node;

	sizeOfList++;
}


void StationList::insertAfter(int targetId, StationNode * new_node)
{
	StationNode* targetNode = searchById(targetId);
	
	if (targetNode == tail) {
		this->insertEnd(new_node);
		return;
	}

	new_node->prev = targetNode;
	new_node->next = targetNode->next;
	targetNode->next->prev = new_node;
	targetNode->next = new_node;
	if(targetNode == tail) {
		tail = new_node;
	}

	this->serializeId();

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
	while (current_node->id != id) {
		current_node = current_node->next;
	}
	return current_node;
}

float StationList::calculateDistance(int sourceId, int destinationId)
{
	StationNode* current_node = searchById(sourceId);
	float totalDistance = 0;

	if (sourceId <= destinationId) {
		while (current_node->id != destinationId) {
			totalDistance += current_node->nextDistance;
			current_node = current_node->next;
		}
	}
	else {
		while (current_node->id != destinationId) {
			totalDistance += current_node->prev->nextDistance;
			current_node = current_node->prev;
		}
	}
	return totalDistance;
}

float StationList::calculateFare(int sourceId, int destinationId)
{
	StationNode* current_node = searchById(sourceId);
	float totalFare = 0;

	if (sourceId <= destinationId) {
		while (current_node->id != destinationId) {
			totalFare += current_node->nextFare;
			current_node = current_node->next;
		}
	}
	else {
		while (current_node->id != destinationId) {
			totalFare += current_node->prev->nextFare;
			current_node = current_node->prev;
		}
	}

	return totalFare;
}

float StationList::calculateTime(int sourceId, int destinationId)
{
	StationNode* current_node = searchById(sourceId);
	float totalTime = 0;

	if (sourceId <= destinationId) {
		while (current_node->id != destinationId) {
			totalTime += current_node->nextTime;
			current_node = current_node->next;
		}
	}
	else {
		while (current_node->id != destinationId) {
			totalTime += current_node->prev->nextTime;
			current_node = current_node->prev;

		}
	}
	return totalTime;
}

void StationList::serializeId()
{
	StationNode* current_node = head;
	int count = 1;
	while (current_node != nullptr) {
		current_node->id = count;
		count++;
		current_node = current_node->next;
	}
}
