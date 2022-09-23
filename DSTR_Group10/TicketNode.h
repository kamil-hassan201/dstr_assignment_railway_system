#pragma 
#include <iostream>

using namespace std;

class TicketNode
{
	public:
		TicketNode* next;

		int ticketId;
		int transactionId;
		int sourceStationId;
		int targetStationId;
		string transactionDate;
		string transactionTime;
		string departureTime;
		int customerId;

		// default constructor
		TicketNode(int ticketId, int transactionId, int sourceStationId, int targetStationId, string transactionDate, string transactionTime, 
			string departureTime,
		int customerId) {
			this->ticketId = ticketId;
			this->transactionId = transactionId;
			this->sourceStationId = sourceStationId;
			this->targetStationId = targetStationId;
			this->transactionDate = transactionDate;
			this->transactionTime = transactionTime;
			this->departureTime = departureTime;

			this->next = nullptr;
		}
};

