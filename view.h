#pragma once
#include <iostream>
#include "stops.h"
#include "minibuses.h"
using namespace std;

class View {
public:
	string waitingForCommand() {

		return "";
	}

	int inputBusStopCount();
	string inputBusStopName(int serialNumber);

	void showAllStopsWithPassengers(Stop** stops, int count);

	void showMinibusPassengers(Minibus* minibus);
	void showCurrentBusStop(Minibus* minibus);
};