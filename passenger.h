#pragma once
#include <iostream>
#include "stops.h"
using namespace std;

class Stop;

class Passenger {
	string name;
	Stop* targetStop;

public:
	Passenger(string name, Stop* target) {
		this->name = name;
		this->targetStop = target;
	}

	string getName();
	Stop* getTargetStop();

	string to_string();
};
