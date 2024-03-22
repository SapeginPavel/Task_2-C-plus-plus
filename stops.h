#pragma once
#include <iostream>
#include "passenger.h"
#include "values.h"
using namespace std;

class Passenger;

class Stop {
protected:
	string stopName;
	Passenger** passengers;
	int passengersCount;

public:
	Stop(string stopName) {
		this->stopName = stopName;
		passengers = new Passenger*[PASSENGERS_AT_A_STOP];
		passengersCount = 0;
	}

	string getStopName();
	int getPassengersCount();
	Passenger** getPassengers();

	void addPassenger(Passenger* p);
	Passenger* pickUpFirstPassenger();

protected:
	void transferPassengersByMoveLeft();
};