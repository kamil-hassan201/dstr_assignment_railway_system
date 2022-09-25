#include "utils.h"


StationList* makeStationList()
{
    StationList* sList = new StationList();

    StationNode* titi_node = new StationNode(sList->sizeOfList + 1, "Titiwangsa", 0.40, 3, 4);
    sList->insertFront(titi_node);

    StationNode* pwtc_node = new StationNode(sList->sizeOfList +1, "PWTC", 0.80, 7, 8);
    sList->insertEnd(pwtc_node);

    StationNode* sultan_node = new StationNode(sList->sizeOfList + 1, "Sultan Ismail", 0.80, 7, 8);
    sList->insertEnd(sultan_node);

    StationNode* masjeed_jamek = new StationNode(sList->sizeOfList + 1, "Majlis Jamek", 0.60, 5, 6);
    sList->insertEnd(masjeed_jamek);

    StationNode* plaza_rakyat = new StationNode(sList->sizeOfList + 1, "Plaza Rakyat", 1.00, 9, 10);
    sList->insertEnd(plaza_rakyat);

    StationNode* hang_tuah = new StationNode(sList->sizeOfList + 1, "Hang Tuah", 0.50, 4, 5);
    sList->insertEnd(hang_tuah);

    StationNode* pudu = new StationNode(sList->sizeOfList + 1, "Pudu", 0.50, 4, 5);
    sList->insertEnd(pudu);

    StationNode* chan_sow_lin = new StationNode(sList->sizeOfList + 1, "Chan Sow Lin", 0, 0, 0);
    sList->insertEnd(chan_sow_lin);

    return sList;
}

void showLogin()
{
    cout << "1. Login as old customer" << endl;
    cout << "1. Sign up as new customer" << endl;
    cout << "1. Login as Admin" << endl;
}

CustomerList* createDefaultCustomerList()
{
    CustomerList* cList = new CustomerList();

    Customer* first_customer = new Customer(cList->sizeOfList + 1, "Kamil Hassan", "A00092371", "1234");
    cList->insert(first_customer);

    Customer* second_customer = new Customer(cList->sizeOfList + 1, "Nishat Tonny", "B00072372", "4321");
    cList->insert(second_customer);


    return cList;
}

