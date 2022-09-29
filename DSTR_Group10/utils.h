#pragma once

#include "StationList.h"
#include "TicketList.h"
#include "StationNode.h"
#include "CustomerTree.h"
#include "Customer.h"
#include "admin.h"


StationList* makeStationList();
void showLogin();
CustomerTree* createDefaultCustomers();
TicketList* makeDefaultTicketList();
int getRandomId();
int signupCustomer(CustomerTree* cTree);
void customerOptions(StationList* sList, TicketList *tList, int customerId, CustomerTree* cTree);
void showStationDetailsBetween(StationList* sList, int choosenStation1, int choosenStation2);
void showStationDetails(StationNode* node);
string getDateTime();
int loginCustomer(CustomerTree* cTree);
string addTime(string ct, float min);
string getDepartureTime(StationList* sList, int c_station, int d_station);
void showTicketDetails(TicketNode* new_node);
bool loginAdmin(admin admins[]);
void adminOptions(StationList* sList, TicketList* tList);
void showSpecificCustomerTicketInfo(TicketList* tList, int customerId);