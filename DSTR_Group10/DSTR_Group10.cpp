#include <iostream>
#include "StationList.h"
#include "StationNode.h"
#include "CustomerList.h"
#include "Customer.h"
#include "utils.h"
#include<limits> 

int main()
{
    StationList* sList = makeStationList();
    CustomerList* cList = createDefaultCustomerList();

    //sList->displayList();

    cout << "\t \t Railway System \t" << endl;
    cout << "===========================================================" << endl;

    int decision = 1;

    while (decision == -1) {
        showLogin(); // show login options

        int loginDecision;
        cout << "Enter your choice: ";
        cin >> loginDecision;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (loginDecision) {
        case 1:
            // login customer
            break;
        
        case 2:
            // create customer
            break;
        case 3:
            // login admin
            break;
        default:
            cout << "Invalid input!!" << endl;
            break;

    }

    // sList->displatStations();

    return 0;
}

