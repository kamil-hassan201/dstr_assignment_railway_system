#include <iostream>
#include "StationList.h"
#include "StationNode.h"
#include "CustomerTree.h"
#include "Customer.h"
#include "utils.h"
#include<limits> 

int main()
{
    StationList* sList = makeStationList();

    CustomerTree* cTree = createDefaultCustomers();

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
             
            if (loginCustomer(cTree)) {
                customerOptions(sList);
            }

            break;

        case 2:
            signupCustomer(cTree);
            customerOptions(sList);
            break;
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

