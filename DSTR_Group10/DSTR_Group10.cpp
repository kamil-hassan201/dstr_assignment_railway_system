#include <iostream>
#include "StationList.h"
#include "StationNode.h"
#include "CustomerTree.h"
#include "TicketList.h"
#include "TicketNode.h"
#include "Customer.h"
#include "utils.h"
#include<limits> 

int main()
{
    StationList* sList = makeStationList();
    CustomerTree* cTree = createDefaultCustomers();
    TicketList* tList = new TicketList();


    cout << "\t \t Railway System \t" << endl;
    cout << "===========================================================\n" << endl;
    int decision = 1;

    while (decision != -1) {
        showLogin(); // show login options

        int loginDecision;
        cout << endl << "Enter your choice: ";
        cin >> loginDecision;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (loginDecision) {
        case 1:
        {
            int customerId = loginCustomer(cTree);
            if (customerId != NULL) {
                customerOptions(sList, tList, customerId);
            }

            break;
        }

        case 2:
        {
            int customerId = signupCustomer(cTree);
            customerOptions(sList, tList, customerId);
            break;
        }
        case 3:
            // login admin
            break;
        default:
            cout << "Invalid input!!" << endl;
            break;

        }
    }

    return 0;
}

