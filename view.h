#pragma once
#include <iostream>
#include "stops.h"
#include "minibuses.h"
using namespace std;

class View {
public:
	void notificateAboutRandomPassengers();

	string waitingForCommand();

	void showAvailableCommands();

	int inputBusStopCount();
	int inputCountOfPlaces();
	int inputCountOfRandomPassengers();
	string inputBusStopName(int serialNumber);

	void showAllStopsWithPassengers(Stop** stops, int count);

	void showMinibusPassengers(Minibus* minibus);
	void showCurrentBusStop(Minibus* minibus);

	string getNewUserAction();

	Passenger* createNewPassenger(Stop** stops, int count);
	Stop* getStopByName(Stop** stops, int count, string showBeforeInput);
	Stop* getStartStopByName(Stop** stops, int count);
	Stop* getTargetStopByName(Stop** stops, int count);

	void showDisembark();
	void showPickUp();

private:
	int inputIntNumber();
};