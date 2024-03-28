#include <iostream>
#include "view.h"
#include "passenger.h"

using namespace std;

string View::waitingForCommand()
{
	return "";
}

void View::showAvailableCommands()
{
	cout << "Доступные команды: " << endl;
	cout << "'u' - создать нового пассажира" << endl;
	cout << "'m' - переместить маршрутку" << endl;
	cout << "'exit' - выход из программы" << endl;
}

int View::inputBusStopCount()
{
	cout << "Введите количество остановок: ";
	return inputIntNumber();
}

int View::inputCountOfPlaces()
{
	cout << "Введите количество мест в маршрутке: ";
	return inputIntNumber();
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
	cout << "Пассажиры в маршрутке: ";
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

string View::getNewUserAction()
{
	cout << endl << "Введите следующее действие: ";
	string act;
	cin >> act;
	return act;
}

Passenger* View::createNewPassenger(Stop** stops, int count)
{
	cout << "\n---Вы создаёте пассажира!---" << endl;

	cout << "Введите его имя: ";
	string name;
	cin >> name;

	Stop* targetStop = getTargetStopByName(stops, count);
	Passenger* p = new Passenger(name, targetStop);

	return p;
}

Stop* View::getStopByName(Stop** stops, int count, string showBeforeInput)
{
	//пока немного дублирования кода
	string stopName = "";
	Stop* stop = nullptr;
	while (stopName._Equal("")) {
		cout << showBeforeInput;
		cin >> stopName;
		for (int i = 0; i < count; i++) {
			if (stops[i]->getStopName()._Equal(stopName)) {
				stop = stops[i];
				break;
			}
			if (i == count - 1) {
				cout << "Не существует указанной остановки" << endl;
				stopName = ""; //если не существует такой остановки
			}
		}
	}
	return stop;
}

Stop* View::getStartStopByName(Stop** stops, int count)
{
	return getStopByName(stops, count, "Введите название начальной остановки: ");
}

Stop* View::getTargetStopByName(Stop** stops, int count)
{
	return getStopByName(stops, count, "Введите название конечной остановки: ");
}

void View::showDisembark()
{
	cout << "Высадка" << endl;
}

void View::showPickUp()
{
	cout << "Посадка" << endl;
}

int View::inputIntNumber()
{
	int num;
	cin >> num;
	return num;
}


