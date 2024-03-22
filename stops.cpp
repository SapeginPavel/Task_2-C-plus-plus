#include "stops.h"

string Stop::getStopName()
{
	return stopName;
}

int Stop::getPassengersCount()
{
	return passengersCount;
}

Passenger** Stop::getPassengers()
{
	return passengers;
}

void Stop::addPassenger(Passenger* p)
{
	passengers[passengersCount++] = p;
}

Passenger* Stop::pickUpFirstPassenger()
{
	if (getPassengersCount() == 0) {
		return nullptr;
	}
	else {
		Passenger* firstPassenger = passengers[0];
		transferPassengersByMoveLeft();
		passengersCount--;
		return firstPassenger;
	}
}

void Stop::transferPassengersByMoveLeft()
{
	passengers[0] = nullptr; //TODO TODO TODO TODO TODO
	//delete passengers[0];
	for (int i = 0; i < getPassengersCount() - 1; i++) {
		passengers[i] = passengers[i + 1];
	}
}
