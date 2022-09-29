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


// for sorting, took help from https://www.geeksforgeeks.org/merge-sort-for-linked-list/

void TicketList::MergeSort(TicketNode **headRef)
{
	TicketNode* head = *headRef;
	TicketNode* a;
	TicketNode* b;
	/* Base case -- length 0 or 1 */
	if ((head == nullptr) || (head->next == nullptr)) {
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);

	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}

TicketNode* TicketList::SortedMerge(TicketNode* a, TicketNode* b)
{
	TicketNode* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	/* Pick either a or b, and recur */
	if (a->customerName.compare(b->customerName) < 0) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

void TicketList::FrontBackSplit(TicketNode* source, TicketNode** frontRef, TicketNode** backRef) // split list into 2 halves
{
	TicketNode* fast;
	TicketNode* slow;
	slow = source;
	fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two
	at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}
