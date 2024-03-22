#pragma once
#include <iostream>
#include <string>
#include "stops.h"

class Route {
public:
	Stop** stopsInRoute;
	int stopsCount;

	Route(Stop** newRoute, int stopsCount) {
		this->stopsInRoute = newRoute;
		this->stopsCount = stopsCount;
	}

	Stop* getStopByNumber(int number);
};