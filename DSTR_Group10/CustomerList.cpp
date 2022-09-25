#include "CustomerList.h"

void CustomerList::insert(Customer* new_node)
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

Customer* CustomerList::searchById(int id)
{
	return nullptr;
}
