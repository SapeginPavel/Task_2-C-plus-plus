#include "minibuses.h"
#include <iostream>
using namespace std;

void Minibus::startMoving()
{
	goToNextBusStop();
}

void Minibus::goToNextBusStop()
{
	int numOfStopsInRoute = route->stopsCount;
	if (currentStopNumber < numOfStopsInRoute - 1 && isGoToTheLast) {
		currentStopNumber++;
		if (currentStopNumber == numOfStopsInRoute - 1) {
			isGoToTheLast = false;
		}
	}
	else if (currentStopNumber > 0 && !isGoToTheLast) {
		currentStopNumber--;
		if (currentStopNumber == 0) {
			isGoToTheLast = true;
		}
	}
}

Stop* Minibus::getCurrentStop()
{
	if (currentStopNumber == -1) {
		return nullptr;
	}
	return route->getStopByNumber(currentStopNumber);
}

int Minibus::getCurrentsStopNumber()
{
	return currentStopNumber;
}

Passenger** Minibus::getPassengers()
{
	return passengersInMinibus;
}

int Minibus::getCountOfPassengers()
{
	return countOfPassengers;
}

void Minibus::pickUpPassengers()
{
	while (countOfPassengers < places && getCurrentStop()->getPassengersCount() > 0) {
		Passenger* p = getCurrentStop()->pickUpFirstPassenger();
		passengersInMinibus[countOfPassengers] = p;
		countOfPassengers++;
	}
}

void Minibus::disembarkPassengers()
{
	for (int i = 0; i < countOfPassengers; i++) {
		Stop* s = passengersInMinibus[i]->getTargetStop();
		if (s == getCurrentStop()) {
			removePassengerByIndex(i);
			i--; //чтобы ещё раз пройтись после смещения
		}
	}
}

void Minibus::removePassengerByIndex(int index)
{
	if (index >= countOfPassengers) {
		return; //сюда вообще по идее не зайдём
	}
	else if (countOfPassengers == 1 || index == countOfPassengers - 1) {
		//delete passengersInMinibus[index];
		passengersInMinibus[index] = nullptr;
	}
	else {
		int preLastPassenger = countOfPassengers - 2;
		for (int i = index; i <= preLastPassenger; i++) {
			passengersInMinibus[i] = passengersInMinibus[i + 1];
			if (i == preLastPassenger) {
				passengersInMinibus[i + 1] = nullptr;
			}
		}
	}
	countOfPassengers--;
}
