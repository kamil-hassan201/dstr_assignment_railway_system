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
		int sizeOfList;

		void insertEnd(TicketNode* new_node);
		TicketNode* searchByTicketId(int ticketId);
		void deleteNodeByTicketId(int ticketId);

		//sorting functions & utilities
		void MergeSort(TicketNode ** headRef);
		TicketNode* SortedMerge(TicketNode* a, TicketNode* b);
		void FrontBackSplit(TicketNode* source, TicketNode** frontRef, TicketNode** backRef);


		// default constructor
		TicketList() {
			this->head = nullptr;
			this->tail = nullptr;
			this->sizeOfList = 0;
			this->sortedRef = nullptr;
		}
};

