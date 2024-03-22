#include <iostream>
#include "view.h"
#include "passenger.h"

using namespace std;

int View::inputBusStopCount()
{
	int size;
	cout << "Введите количество остановок: ";
	cin >> size;
	return size;
}

string View::inputBusStopName(int serialNumber)
{
	{
		cout << "Введите название остановки " << serialNumber << ": ";
		string stopName;
		cin >> stopName;
		return stopName;
	}
}

void View::showAllStopsWithPassengers(Stop** stops, int count)
{
	cout << "Все остановки: " << endl;
	for (int i = 0; i < count; i++) {
		cout << i << ": " << stops[i]->getStopName() << " [ ";
		Passenger** passengers = stops[i]->getPassengers();
		for (int j = 0; j < stops[i]->getPassengersCount(); j++) {
			cout << passengers[j]->getName() << " ";
		}
		cout << "]\n";
	}
	cout << endl;
}

void View::showMinibusPassengers(Minibus* minibus)
{
	Passenger** passengers = minibus->getPassengers();
	cout << "[  ";
	for (int i = 0; i < minibus->getCountOfPassengers(); i++) {
		cout << passengers[i]->to_string() << "  ";
	}
	cout << "]\n";
}

void View::showCurrentBusStop(Minibus* minibus)
{
	cout << "Текущая остановка: " << minibus->getCurrentStop()->getStopName() << endl;
}
