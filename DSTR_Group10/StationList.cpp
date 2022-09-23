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
