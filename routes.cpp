#include <iostream>
#include "routes.h"

Stop* Route::getStopByNumber(int number)
{
	if (number >= stopsCount) {
		return nullptr;
	}
	return stopsInRoute[number];
}
