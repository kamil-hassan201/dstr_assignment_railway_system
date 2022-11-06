#include "utils.h"
#include<limits> 
#include <string>
#include "TicketList.h"
#include <ctime>    
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>


#pragma warning(disable : 4996)

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

TicketList* makeDefaultTicketList() {
    TicketList* tList = new TicketList();

    TicketNode* ticket1 = new TicketNode(tList->sizeOfList + 1, getRandomId(), "Titiwangsa", "Majlis Jamek", "23-08-2022 20-28-90", "23-08-2022 20-38-00", 15, "Hassan", "23-08-2022 21-28-90");
    tList->insertEnd(ticket1);

    TicketNode* ticket2 = new TicketNode(tList->sizeOfList + 1, getRandomId(), "Majlis Jamek", "Majlis Jamek", "23-08-2022 20-28-90", "23-08-2022 20-38-00", 11, "Abbas", "23-08-2022 21-28-90");
    tList->insertEnd(ticket2);

    TicketNode* ticket3 = new TicketNode(tList->sizeOfList + 1, getRandomId(), "PWTC", "Pudu", "23-08-2022 20-28-90", "23-08-2022 20-38-00", 13, "Eiber", "23-08-2022 21-28-90");
    tList->insertEnd(ticket3);

    return tList;
}

void showLogin()
{
    cout << endl;
    cout << "1. Login as old customer" << endl;
    cout << "2. Sign up as new customer" << endl;
    cout << "3. Login as Admin" << endl;
    cout << "4. Quit" << endl;
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

    Customer* test = new Customer(1, "Kamil Hassan", "A00092371", "1");
    cTree->insert(test);

    return cTree;
}

int getRandomId()
{
    int randomId = rand();
    return randomId;
}

int loginCustomer(CustomerTree *cTree) {
    int id;
    string password;

    get_int(id, "Enter your id: ", "Your id doesn't match to our records!");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter your password: ";
    getline(cin,password); // read pass

    Customer* node = cTree->search(id);

    if (node == NULL) {
        cout << "No such id found!!" << endl;
        return NULL;
    }
    if (node->password != password) {
        cout << "Wrong Password!! " << endl;
        return NULL;
    }
    cout << endl << "Welcome Mr. " << node->name << endl;
    return id;
}

int signupCustomer(CustomerTree* cTree) {
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

    cout << "Welcome " << name << "! Your id is: " << id << endl;

    Customer* node = new Customer(id, name, identificationNum, password);
    cTree->insert(node);
    return id;
}

bool loginAdmin(admin admins[])
{
    int id;
    string password;

    get_int_between(id, 1, 3, "Enter your id: ", "Your id doesn't match to our records!");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter your password: ";
    getline(cin, password); // read pass


    if (admins[id - 1].pass == password) {
        return true;
    }

    return false;
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
    StationNode* cStation = sList->searchById(choosenStation1);
    StationNode* dStation = sList->searchById(choosenStation2);

    if (cStation == NULL || dStation == NULL) {
        cout << "Invalid Station Id!!" << endl;
        return;
    }

    cout << endl << "Station Details Between Cities: " << endl;
    cout << "Travel Time:\t " << sList->calculateTime(choosenStation1, choosenStation2) << " min" << endl;
    cout << "Distance:\t " << sList->calculateDistance(choosenStation1, choosenStation2) << " KM" << endl;
    cout << "Travel Fare:\t " << sList->calculateFare(choosenStation1, choosenStation2) << " RM" << endl;
    cout << endl;
}

void adminOptions(StationList* sList, TicketList* tList)
{
    while (true) {
        cout << endl;
        cout << "1. Add subway station" << endl;
        cout << "2. Edit a subway station" << endl;
        cout << "3. View all purchase transactions" << endl;
        cout << "4. Sort purchases based on name" << endl;
        cout << "5. Search specific customer ticket purchase information" << endl;
        cout << "6. Edit specific ticket purchase information" << endl;
        cout << "7. Delete specific customer ticket purchase information" << endl;
        cout << "8. Log out" << endl;

        int choice;
        get_int_between(choice, 1, 8, "Enter your choice: ", "Invalid input!");
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: // add new station
        {
            int decision;
            cout  << "1. Insert at the beginning" << endl;
            cout  << "2. Insert at the end" << endl;
            cout << "3. Insert after a sation" << endl;

            cout << endl << "Enter your choice: ";
            cin >> decision;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // initialize station node variables
            string stationName;
            float nextFare;
            float nextTime;
            float nextDistance;

            StationNode* new_node;


            switch (decision) {
            case 1: // insert at the front
            {
                cout << "Enter new name of station: ";
                getline(cin, stationName);

                cout  << "Enter fare (RM) to next station: ";
                cin >> nextFare;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout  << "Enter time (min) to reach next station: ";
                cin >> nextTime;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout  << "Enter distance (KM) to next station: ";
                cin >> nextDistance;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                new_node = new StationNode(sList->sizeOfList + 1, stationName, nextFare, nextTime, nextDistance);
                sList->insertFront(new_node);
                cout << "Successfully added new station!" << endl;
                break;
            }
            case 2: // insert at the end
            {
                cout << "Enter new name of station: ";
                getline(cin, stationName);

                cout  << "Enter fare (RM) to this station: ";
                cin >> nextFare;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout  << "Enter time (min) to reach this station: ";
                cin >> nextTime;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout  << "Enter distance (KM) from previous station: ";
                cin >> nextDistance;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                sList->insertEndByAdmin(stationName, nextFare, nextTime, nextDistance);
                cout << "Successfully added new station!" << endl;
                break;
            }
            case 3:
            {
                int targetStationId;
                cout << endl << "Enter id of station to insert after: ";
                cin >> targetStationId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (targetStationId == sList->sizeOfList) {
                    cout << "Choose 2nd option to insert at the end" << endl;
                    break;
                }
               

                cout << "Enter new name of station: ";
                getline(cin, stationName);

                cout  << "Enter fare (RM) to next station: ";
                cin >> nextFare;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout  << "Enter time (min) to reach next station: ";
                cin >> nextTime;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter distance (KM) to next station: ";
                cin >> nextDistance;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                new_node = new StationNode(sList->sizeOfList + 1, stationName, nextFare, nextTime, nextDistance);
                sList->insertAfter(targetStationId, new_node);
                cout << "Successfully added new station!" << endl;
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
                break;
            }


            break;
        }
        case 2: // edit a subway station
        {
            sList->displaytStations();

            int stationId;
            cout << endl << "Enter Station id: ";
            cin >> stationId;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            StationNode* editableStation = sList->searchById(stationId);

            if (editableStation == NULL) {
                cout << "No station with the id found!" << endl;
            }

            if (editableStation == NULL) {
                cout << "No such station found!" << endl;
                break;
            }

            float nextFare;
            float nextTravelTime;
            string stationName;

            // reading new info
            cout << "Enter new fare to next station: ";
            cin >> nextFare;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter new time to reach next staion: ";
            cin >> nextTravelTime;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter new name of station: ";
            getline(cin, stationName);

            editableStation->nextFare = nextFare;
            editableStation->nextTime = nextTravelTime;
            editableStation->name = stationName;
            cout << "Edited successfully!" << endl;

            break;
        }
        case 3:            // view all purchase transactions
        {
            int count = 0;
            TicketNode* current_node = tList->head;
            cout << "====================================================\n" << endl;

            while (current_node != nullptr) {
                showTicketDetails(current_node);
                current_node = current_node->next;
                count++;
            }

            if (count == 0) {
                cout << "No ticket info found!" << endl;
            }
            cout << "====================================================\n" << endl;
            break;
        }

        case 4:            // sort purchase based on name
            tList->MergeSort(&tList->head);
            cout << "Sorted by customer name" << endl;
            break;

        case 5:             // show specific customer info
        {
            int customerId;
            
            get_int(customerId, "Enter Customer id: ", "Invalid id!");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            showSpecificCustomerTicketInfo(tList, customerId);
            break;
        }
        case 6:             // Edit specific customer ticket purchase information
        {
            int ticketId;
            cout << endl << "Enter Ticket id: ";
            cin >> ticketId;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string transactionTime;
            string departureTime;
            string sourceStation;
            string destinationStation;

            TicketNode* editableNode = tList->searchByTicketId(ticketId);
            if (editableNode == NULL) {
                cout << "No such ticket id found!" << endl;
                break;
            }

            // read new information
            cout << "Enter ticket's transaction time: ";
            getline(cin, transactionTime);

            cout << "Enter ticket's departure time: ";
            getline(cin, departureTime);

            cout << "Enter ticket's source station name: ";
            getline(cin, sourceStation);

            cout << "Enter ticket's destination station name: ";
            getline(cin, destinationStation);

            // insert new information
            editableNode->transactionTime = transactionTime;
            editableNode->departureTime = departureTime;
            editableNode->sourceStationName = sourceStation;
            editableNode->targetStationName = destinationStation;

            cout << endl << "Edited successfully" << endl;
            break;
        }

        case 7: // delete ticket node
        {
            int deleteTicketId;
            cout << endl << "Enter Ticket to delete! (-1 to go back): ";
            cin >> deleteTicketId;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (deleteTicketId == -1) {
                break;
            }

            else {
                tList->deleteNodeByTicketId(deleteTicketId);
            }

            break;
        }
        case 8:
            return;
        default:
            cout << "Invalid input!!" << endl;
        }
    }
}

void customerOptions(StationList* sList, TicketList *tList, int customerId, CustomerTree *cTree) {
    sList->displaytStations();

    while (true) {
        cout << "Customer Menu: " << endl;
        cout << "1. Search Station Details" << endl;
        cout << "2. View details between 2 cities" << endl;
        cout << "3. Make a purchase" << endl;
        cout << "4. View purchase transaction history" << endl;
        cout << "5. Delete purchase transaction" << endl;
        cout << "6. Log out" << endl;

        int choice;
        get_int_between(choice, 1, 6, "Enter your choice: ", "Invalid input!");

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:                // show details of 1 station

            {
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
            case 2:                // show details between 2 station

            {
                int choosenStation1, choosenStation2;

                cout << endl << "Enter current station number: ";
                cin >> choosenStation1;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Enter destination station number: ";
                cin >> choosenStation2;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                
                showStationDetailsBetween(sList, choosenStation1, choosenStation2);

                break;
            }
            
            case 3:         // make a purchase
            { 
                int choosenStation1, choosenStation2, cChoice;
                string customerName = cTree->search(customerId)->name;
                
                get_int(choosenStation1, "Enter current station number: ", "Invalid station id!");

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                get_int(choosenStation2, "Enter destination station number: ", "Invalid station id!");

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                StationNode* cStation = sList->searchById(choosenStation1);
                StationNode* dStation = sList->searchById(choosenStation2);

                if (cStation == NULL || dStation == NULL) {
                    cout << "Invalid Station Id!!" << endl;
                    break;
                }if (cStation == dStation) {
                    cout << "Current and Destination Station are same! Try again." << endl;
                    break;
                }

                string departureTime = getDepartureTime(sList, choosenStation1, choosenStation2);

                string arrivalTime = addTime(departureTime, sList->calculateTime(choosenStation1, choosenStation2));

                showStationDetailsBetween(sList, choosenStation1, choosenStation2);

                cout << "Next LRT comming at: " << departureTime.substr(11) << endl;
                cout << "Estimated Arrival at: " << arrivalTime.substr(11) << endl;


                get_int(cChoice, "Enter (1) to make the payment: ", "Invalid input!");

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                
                if (cStation != NULL && dStation != NULL) {
                    if (cChoice == 1) {
                        string cDateTime = getDateTime();

                        TicketNode* new_node = new TicketNode(tList->sizeOfList + 1, getRandomId(), cStation->name, dStation->name, cDateTime, departureTime, customerId, customerName, arrivalTime);
                        tList->insertEnd(new_node); // insert into list
                        cout << "Payment Completed!!" << endl;
                        showTicketDetails(new_node); // show ticket details
                    }
                    else {
                        cout << "Purchase unsuccessfull!" << endl;
                    }
                }
                

                break;
            }
            
            case 4:
            {
                showSpecificCustomerTicketInfo(tList, customerId);
                break;
            }
            case 5:
            {
                int deleteTicketId;
                cout << endl << "Enter Ticket id you want to delete! (-1 to go back): ";
                cin >> deleteTicketId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (deleteTicketId == -1) {
                    break;
                }
                else {
                    tList->deleteNodeByTicketId(deleteTicketId);
                }
                
                break;
            }

            case 6:
                return;

            default:
                cout << "Invalid Choice!" << endl;
                break;
        }
    }
    
}

void showTicketDetails(TicketNode* node) {
    cout << "----------------" << endl;
    cout << "Ticket Details" << endl;
    cout << "----------------" << endl;
    cout << "Customer ID:\t " << node->customerId << endl;
    cout << "Customer Name:\t " << node->customerName << endl;
    cout << "Ticket ID:\t " << node->ticketId << endl;
    cout << "Transaction ID:\t "<< node->transactionId <<   endl;
    cout << "Purchase Time:\t" << node->transactionTime << endl;
    cout << "Source Station:\t" << node->sourceStationName << endl;
    cout << "Destination:\t" << node->targetStationName << endl;
    try {
        cout << "Departure Time:\t" << node->departureTime.substr(11) << endl;
        cout << "Arrival Time:\t" << node->estimatedArival.substr(11) << endl;
    }
    catch (exception) {
        cout << "Not valid date" << endl;
    }
    
    cout << "----------------" << endl;
}

void showSpecificCustomerTicketInfo(TicketList *tList, int customerId) {
    int count = 0;
    TicketNode* current_node = tList->head;
    cout << "====================================================\n" << endl;

    while (current_node != nullptr) {
        if (current_node->customerId == customerId) {
            showTicketDetails(current_node);
            count++;
        }
        current_node = current_node->next;

    }
    if (count == 0) {
        cout << "No ticket info found!" << endl;
    }
    cout << "====================================================\n" << endl;

    cout << endl;
}


// following code reference https://stackoverflow.com/questions/16357999/current-date-and-time-as-string

string getDateTime() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;

    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");

    auto str = oss.str();
    return str;
}

// following code reference https://stackoverflow.com/questions/16357999/current-date-and-time-as-string

string addTime(string ct, float min) {
    struct std::tm tm;
    std::istringstream ss(ct);
    ss >> std::get_time(&tm, "%d-%m-%Y %H-%M-%S"); 
    std::time_t time = mktime(&tm) + (int) min * 60;

    auto tm2 = *std::localtime(&time);

    std::ostringstream oss;

    oss << std::put_time(&tm2, "%d-%m-%Y %H-%M-%S");

    auto str = oss.str();

    return str;
}

// function to get next departure time
string getDepartureTime(StationList* sList, int c_station, int d_station) {
    string next_departure_from_root;
    string departure_from_current;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    int d = tm.tm_mday;
    int mn = tm.tm_mon + 1;
    int y = tm.tm_year + 1900;
    int h = tm.tm_hour;
    int m = tm.tm_min;
    int s = 00;
    if (m <= 30) {
        m = 30;
    }
    else {
        m = 00;
        h++;
    }
    if (h > 1 && h < 6) {
        h = 6;
    }
    if (h == 24) {
        h = 00;
    }

    // next_departure time from root station
    next_departure_from_root = "" + to_string(d) + "-" + to_string(mn) + "-" + to_string(y) + " " + to_string(h) + "-" + to_string(m) + "-" + to_string(s);
    int time_duration;
    if (c_station < d_station) {

        time_duration = sList->calculateTime(1, c_station); // time to reach current station

        departure_from_current = addTime(next_departure_from_root, time_duration); // departure time from current station

    }
    else {
        time_duration = sList->calculateTime(sList->sizeOfList, c_station); // time to reach current station
        cout << time_duration << endl;
        departure_from_current = addTime(next_departure_from_root, time_duration); // departure time from current station
    }
    return departure_from_current;
    
}


// took help from https://stackoverflow.com/questions/15467412/c-cin-only-accept-numeric-values
void get_int(int& d, std::string prompt, std::string fail)
{
    while (1) {

        std::cout << prompt;
        std::string str;
        std::cin >> str;

        std::istringstream ss(str);
        int val1;
        ss >> val1;

        if (!ss.eof()) {
            std::cout << fail << endl;;
            continue;
        }
        else {
            d = val1;
            break;
        }
    }
}

void get_int_between(int& d, int min, int max, std::string prompt, std::string fail)
{
    while (1) {
        get_int(d, prompt, fail);
        if (d > max || d < min) {
            std::cout << "Sorry, your choice is out of range.\n";
            continue;
        }
        break;
    }
}