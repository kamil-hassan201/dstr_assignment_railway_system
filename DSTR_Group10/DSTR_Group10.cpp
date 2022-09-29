#include <iostream>
#include "StationList.h"
#include "StationNode.h"
#include "CustomerTree.h"
#include "TicketList.h"
#include "TicketNode.h"
#include "Customer.h"
#include "utils.h"
#include<limits> 
#include "admin.h"


int main()
{
    StationList* sList = makeStationList();
    CustomerTree* cTree = createDefaultCustomers();
    TicketList* tList = new TicketList();
    admin* admins;
    admins = makeAdmins();


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
            int customerId = loginCustomer(cTree); // login old customer
            if (customerId != NULL) {
                customerOptions(sList, tList, customerId, cTree); // show customer options
            }

            break;
        }

        case 2:
        {
            int customerId = signupCustomer(cTree); // create new customer
            customerOptions(sList, tList, customerId, cTree); // show customer options
            break;
        }
        case 3:
            // login admin
            if (loginAdmin(admins)) {
                adminOptions(sList, tList);
            }
            else {
                cout << "Login unsuccessfull!" << endl;
            }
            break;
        case 4:
            decision = -1;
            break;
        default:
            cout << "Invalid input!!" << endl;
            break;

        }
    }

    // freeing up memory

    delete cTree;
    delete sList;
    delete tList;

    return 0;
}

