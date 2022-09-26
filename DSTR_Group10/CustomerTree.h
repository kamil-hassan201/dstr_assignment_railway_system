#pragma once

#include<iostream>
#include "Customer.h"

using namespace std;

class CustomerTree
{
    public:
        Customer* root;
        int sizeOfList;

        // functions
        //Customer* searchById(int id);

        void addLeftChild(Customer* parent, Customer* child);
        void addRightChild(Customer* parent, Customer* child);
        void insert(Customer* new_node);
        void displayInOrder(Customer *node);
        Customer* search(int id);


        // default constructor
        CustomerTree() {
            this->root = nullptr;
            this->sizeOfList = 0;
        }
};
