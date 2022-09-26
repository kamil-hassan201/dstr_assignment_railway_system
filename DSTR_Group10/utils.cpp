#include "utils.h"
#include<limits> 
#include <string>


using namespace std;

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
    cout << "2. Sign up as new customer" << endl;
    cout << "3. Login as Admin" << endl;
}

CustomerTree* createDefaultCustomers()
{
    CustomerTree* cTree = new CustomerTree();

    Customer * first = new Customer(10, "Kamil Hassan", "A00092371", "1234");
    cTree->insert(first);

    Customer* second = new Customer(5, "Nishat Tonny", "B00072372", "4321");
    cTree->insert(second);

    Customer* third = new Customer(7, "Prassan", "E00072372", "1234");
    cTree->insert(third);

    Customer* fourth = new Customer(2, "BQ", "C00072372", "1234");
    cTree->insert(fourth);

    Customer* fifth = new Customer(12, "Joy Bangla", "B00072372", "4321");
    cTree->insert(fifth);

    return cTree;
}

int getRandomId()
{
    int randomId = rand();
    return randomId;
}

bool loginCustomer(CustomerTree *cTree) {
    int id;
    string password;
    cout << "Enter your id: ";

    cin >> id; // read id
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter your password: ";
    getline(cin,password); // read pass

    Customer* node = cTree->search(id);

    if (node == NULL) {
        cout << "No such id found!!" << endl;
        return false;
    }
    if (node->password != password) {
        cout << "Wrong Password!! " << endl;
        return false;
    }
    cout << "Welcome Mr. " << node->name << endl << endl;
    return true;
}

void signupCustomer(CustomerTree* cTree) {
    string password;
    string name;
    string identificationNum;
    int id = getRandomId();


    cout << "Enter your name: ";
    getline(cin, name); 
    
    cout << "Enter your passport/ i-cad number: ";
    getline(cin, identificationNum); 
    
    cout << "Enter your password: ";
    getline(cin, password); 

    Customer* node = new Customer(id, name, identificationNum, password);
    cTree->insert(node);
}

void showStationDetails(StationNode* node) {
    cout << endl;
    cout << "Station Name:\t" << node->name << endl;
    cout << "Station Id:\t" << node->id << endl;
    if(node->prev != nullptr)
        cout << "Prev station:\t" << node->prev->name << endl;
    if(node->next != nullptr)
        cout << "Next Station:\t" << node->next->name << endl;
   

    cout << endl;
}

void showStationDetailsBetween(StationList* sList, int choosenStation1, int choosenStation2) {
    cout << "Station Details Between Cities: " << endl;
    cout << "Travel Time:\t" << sList->calculateTime(choosenStation1, choosenStation2) << " min" << endl;
    cout << "Distance:\t " << sList->calculateDistance(choosenStation1, choosenStation2) << " KM" << endl;
    cout << "Travel Fare:\t" << sList->calculateFare(choosenStation1, choosenStation2) << " RM" << endl;
    cout << endl;
}


void customerOptions(StationList* sList) {
    sList->displaytStations();

    while (true) {
        cout << "1. Search Station Details" << endl;
        cout << "2. View details between 2 cities" << endl;
        cout << "3. Make a purchase" << endl;

        int choice;
        cout << endl << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
            {
                // show details of 1 station
                int choosenStation;
                cout << endl << "Enter station number: ";
                cin >> choosenStation;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                StationNode* node = sList->searchById(choosenStation);
                if (node != NULL) {
                    showStationDetails(node);
                }
                else {
                    cout << "No such station!" << endl;

                }
                break; 
            }
            case 2:
            {
                // show details between 2 station
                int choosenStation1, choosenStation2;

                cout << endl << "Enter current station number: ";
                cin >> choosenStation1;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Enter destination station number: ";
                cin >> choosenStation2;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                
                showStationDetailsBetween(sList, choosenStation1, choosenStation1);

                break;
            }
            
            case 3:
            { // make a purchase
                int choosenStation1, choosenStation2, cChoice;

                cout << endl << "Enter current station number: ";
                cin >> choosenStation1;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Enter destination station number: ";
                cin >> choosenStation2;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                showStationDetailsBetween(sList, choosenStation1, choosenStation1);
                
                cout << endl << "Enter (1) to make the payment: ";
                cin >> cChoice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (cChoice == 1) {

                }

                break;
            }
            default:
                cout << "Invalid Choice!" << endl;
                break;
        }
    }
    
}

