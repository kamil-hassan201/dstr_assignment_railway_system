#include "TicketList.h"

void TicketList::insertEnd(TicketNode* new_node)
{
	if (head == nullptr) {
		head = tail = new_node;
	}
	else {
		tail->next = new_node;
		tail = new_node;
	}
	sizeOfList++;
}
