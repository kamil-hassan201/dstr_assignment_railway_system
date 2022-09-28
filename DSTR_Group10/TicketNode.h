#pragma once
#include <iostream>

using namespace std;

class TicketNode
{
	public:
		TicketNode* next;

		int ticketId;
		int transactionId;
		string sourceStationName;
		string targetStationName;
		string transactionTime;
		string departureTime;
		int customerId;
		string estimatedArival;

		// default constructor
		TicketNode(int ticketId, int transactionId, string sourceStationName, string targetStationName , string transactionTime,
			string departureTime, int customerId, string estimatedArival) {
			this->ticketId = ticketId;
			this->transactionId = transactionId;
			this->sourceStationName = sourceStationName;
			this->targetStationName = targetStationName;
			this->transactionTime = transactionTime;
			this->departureTime = departureTime;
			this->customerId = customerId;
			this->estimatedArival = estimatedArival;

			this->next = nullptr;
		}
};

