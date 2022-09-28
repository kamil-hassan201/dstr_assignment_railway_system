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

TicketNode* TicketList::searchByTicketId(int ticketId) {
	TicketNode* current_node = head;
	while (current_node != nullptr) {

		if (current_node->ticketId == ticketId)
		{
			break;
		}
		current_node = current_node->next;
	}
	return current_node;
}

void TicketList::deleteNodeByTicketId(int ticketId)
{
	TicketNode* current_node = head;
	TicketNode* previous = head;

	while (current_node != nullptr) {

		if (current_node->ticketId == ticketId)
		{
			break;
		}
		previous = current_node;
		current_node = current_node->next;
	}
	if (current_node == nullptr) {
		cout << "No such ticket id found!" << endl;
		return;
	}
	// if the node is head
	if (current_node == head) {
		head = head->next;
		free(current_node);
		cout << "Deleted successfully!" << endl;

		return;
	}

	// if the node is tail
	if (current_node == tail) {
		previous->next = nullptr;
		tail = previous;
		free(current_node);
		cout << "Deleted successfully!" << endl;

		return;
	}

	// if the node is in middle
	previous->next = current_node->next;
	free(current_node);
	cout << "Deleted successfully!" << endl;
	return;
}
