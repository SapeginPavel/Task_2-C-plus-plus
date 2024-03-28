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
	cout << "��������� �������: " << endl;
	cout << "'u' - ������� ������ ���������" << endl;
	cout << "'m' - ����������� ���������" << endl;
	cout << "'exit' - ����� �� ���������" << endl;
}

int View::inputBusStopCount()
{
	cout << "������� ���������� ���������: ";
	return inputIntNumber();
}

int View::inputCountOfPlaces()
{
	cout << "������� ���������� ���� � ���������: ";
	return inputIntNumber();
}

string View::inputBusStopName(int serialNumber)
{
	{
		cout << "������� �������� ��������� " << serialNumber << ": ";
		string stopName;
		cin >> stopName;
		return stopName;
	}
}

void View::showAllStopsWithPassengers(Stop** stops, int count)
{
	cout << "��� ���������: " << endl;
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
	cout << "��������� � ���������: ";
	cout << "[  ";
	for (int i = 0; i < minibus->getCountOfPassengers(); i++) {
		cout << passengers[i]->to_string() << "  ";
	}
	cout << "]\n";
}

void View::showCurrentBusStop(Minibus* minibus)
{
	cout << "������� ���������: " << minibus->getCurrentStop()->getStopName() << endl;
}

string View::getNewUserAction()
{
	cout << endl << "������� ��������� ��������: ";
	string act;
	cin >> act;
	return act;
}

Passenger* View::createNewPassenger(Stop** stops, int count)
{
	cout << "\n---�� ������� ���������!---" << endl;

	cout << "������� ��� ���: ";
	string name;
	cin >> name;

	Stop* targetStop = getTargetStopByName(stops, count);
	Passenger* p = new Passenger(name, targetStop);

	return p;
}

Stop* View::getStopByName(Stop** stops, int count, string showBeforeInput)
{
	//���� ������� ������������ ����
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
				cout << "�� ���������� ��������� ���������" << endl;
				stopName = ""; //���� �� ���������� ����� ���������
			}
		}
	}
	return stop;
}

Stop* View::getStartStopByName(Stop** stops, int count)
{
	return getStopByName(stops, count, "������� �������� ��������� ���������: ");
}

Stop* View::getTargetStopByName(Stop** stops, int count)
{
	return getStopByName(stops, count, "������� �������� �������� ���������: ");
}

void View::showDisembark()
{
	cout << "�������" << endl;
}

void View::showPickUp()
{
	cout << "�������" << endl;
}

int View::inputIntNumber()
{
	int num;
	cin >> num;
	return num;
}


