#pragma once
#include <iostream>
#include "routes.h"
using namespace std;

class Minibus {
	int places;
	Route* route;

	Passenger** passengersInMinibus;
	int countOfPassengers;

	int currentStopNumber;
	bool isGoToTheLast;

public:
	Minibus(int placesForBus, Route* route) {
		this->places = placesForBus;
		this->route = route;
		if (route->stopsCount != 0) {
			currentStopNumber = -1;
			isGoToTheLast = true;
		}
		passengersInMinibus = new Passenger*[places];
		countOfPassengers = 0;
	}

public:
	Stop* getCurrentStop();
	int getCurrentsStopNumber();
	int getCountOfPassengers();
	Passenger** getPassengers();

	void startMoving();
	void goToNextBusStop();
	void pickUpPassengers();
	void disembarkPassengers();

private:
	void removePassengerByIndex(int index);
};