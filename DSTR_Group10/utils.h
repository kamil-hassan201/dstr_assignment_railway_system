#pragma once

#include "StationList.h"
#include "StationNode.h"
#include "CustomerTree.h"
#include "Customer.h"




StationList* makeStationList();
void showLogin();
CustomerTree* createDefaultCustomers();
int getRandomId();
bool loginCustomer(CustomerTree* cTree);
void signupCustomer(CustomerTree* cTree);
void customerOptions(StationList* sList);
void showStationDetailsBetween(StationList* sList, int choosenStation1, int choosenStation2);
void showStationDetails(StationNode* node);