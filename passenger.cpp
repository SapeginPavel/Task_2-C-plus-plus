#include "passenger.h"

string Passenger::getName()
{
    return name;
}

Stop* Passenger::getTargetStop()
{
    return targetStop;
}

string Passenger::to_string()
{
    return this->getName() + "->" + targetStop->getStopName();
}
