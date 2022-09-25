#pragma once

#include<iostream>
#include "Customer.h"

using namespace std;

class CustomerList
{
    public:
        Customer* head;
        Customer* tail;
        int sizeOfList;

        // functions
        void insert(Customer* new_node);
        Customer* searchById(int id);


        // default constructor
        CustomerList() {
            this->head = nullptr;
            this->tail = nullptr;
            this->sizeOfList = 0;
        }
};
