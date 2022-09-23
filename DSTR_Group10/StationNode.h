#pragma once
#include <iostream>

using namespace std;

class StationNode
{
	public:
		StationNode* next;
		StationNode* prev;


		int id;
		string  name;
		float nextFare;
		float nextTime;
		float nextDistance;


		// default constructor
		StationNode(int id, string name, float nextFare, float nextTime, float nexDistance) {
			this->id = id;
			this->name = name;
			this->nextFare = nextFare;
			this->nextTime = nextTime;
			this->nextDistance = nextDistance;

			this->next = nullptr;
			this->prev = nullptr;
		}
};

