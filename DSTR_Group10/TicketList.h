#pragma once

#include <iostream>
#include "TicketNode.h"

using namespace std;

class TicketList
{
	public:
		TicketNode* head;
		TicketNode* tail;
		TicketNode* sortedRef;
		int countOfTicket;




		// default constructor
		TicketList() {
			this->head = nullptr;
			this->tail = nullptr;
			this->countOfTicket = 0;
			this->sortedRef = nullptr;
		}
};

