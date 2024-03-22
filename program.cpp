#include <iostream>
#include <string>
#include "view.h"
#include "routes.h"
#include "minibuses.h"
#include "stops.h"
#include <random>
#include "values.h"
using namespace std;

//todo ������� ����� ������� ��������� ��������� ��������� ��� �������� (��� ������)
//todo ���������� ����� ������ � ����������� ���������. ���� ������ �� view ���������

class Program {
public:
	void start() {
		srand(time(0));
		View* view = new View();
		int stopsCount = view->inputBusStopCount();

		Stop** stops = createStops(view, stopsCount);


		Route* route = new Route(stops, stopsCount);
		int placesCount = COUNT_OF_PLACES_IN_MINIBUS;

		Minibus* minibus = new Minibus(placesCount, route);

		int currentBusStop = minibus->getCurrentsStopNumber();
		
		addRandomPassengers(stops, stopsCount, 4);

		view->showAllStopsWithPassengers(stops, stopsCount);

		minibus->startMoving();

		for (int i = 0; i < stopsCount * 2 + 1; i++) {
			move(minibus, view);
		}

	}

	Stop** createStops(View* view, int stopsCount) {
		Stop** stops = new Stop * [stopsCount];
		for (int i = 0; i < stopsCount; i++) {
			string stopName = view->inputBusStopName(i);
			stops[i] = new Stop(stopName);
		}
		return stops;
	}

	void addRandomPassengers(Stop** stops, int stopsCount, int n) {
		for (int i = 0; i < stopsCount; i++) {
			for (int j = 0; j < n; j++) {
				string nameWithNum = stops[i]->getStopName() + to_string(j);
				Passenger* p = new Passenger(nameWithNum, stops[getRandNumberOfStop(0, stopsCount - 1, i)]);
				stops[i]->addPassenger(p);
			}
		}
	}

	int getRandNumberOfStop(int start, int end, int current) {
		int x = current;
		if (start == end) {
			return current;
		}
		while (x == current) {
			x = rand() % (end - start + 1) + start;
		}
		return x;
	}

	void move(Minibus* minibus, View* view) {
		cout << endl << endl << endl << endl;

		cout << "��������� � ���������: " << endl;
		view->showMinibusPassengers(minibus);

		minibus->goToNextBusStop();
		cout << "������������" << endl;

		cout << "������� ���������: " << minibus->getCurrentStop()->getStopName() << endl;

		cout << "��� ����� ���������� ����������" << endl;
		minibus->disembarkPassengers();
		cout << "�������� ����������" << endl;

		cout << "��������� � ���������: " << endl;
		view->showMinibusPassengers(minibus);

		cout << "��� ����� �������� ����������" << endl;
		minibus->pickUpPassengers();
		cout << "������� ����������" << endl;

		cout << "��������� � ���������: " << endl;
		view->showMinibusPassengers(minibus);
	}
};