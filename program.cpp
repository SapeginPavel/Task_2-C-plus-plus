#include <iostream>
#include <string>
#include "view.h"
#include "routes.h"
#include "minibuses.h"
#include "stops.h"
#include <random>
#include "values.h"
using namespace std;

//Рекомендации для след таска: сделать view и тд публичными для класса. Больше делать через контроллер - MVVM.

class Program {
public:
	void start() {
		srand(time(0));
		View* view = new View();
		int stopsCount = view->inputBusStopCount();

		Stop** stops = createStops(view, stopsCount);

		Route* route = new Route(stops, stopsCount);
		int placesCount = view->inputCountOfPlaces(); //COUNT_OF_PLACES_IN_MINIBUS

		Minibus* minibus = new Minibus(placesCount, route);

		int currentBusStop = minibus->getCurrentsStopNumber();
		
		addRandomPassengers(stops, stopsCount, 4);

		view->showAllStopsWithPassengers(stops, stopsCount);

		execute(view, minibus, stops, stopsCount);

	}

	void execute(View* view, Minibus* minibus, Stop** stops, int stopsCount) {
		string userAction = "start";

		view->showAvailableCommands();

		while (!userAction._Equal("exit")) {
			userAction = view->getNewUserAction();
			cout << userAction << endl;
			handleUserAction(userAction, view, minibus, stops, stopsCount);
		}
	}

	void handleUserAction(string userAction, View* view, Minibus* minibus, Stop** stops, int stopsCount) {
		if (userAction._Equal("m")) {
			move(minibus, view);
		}
		else if (userAction._Equal("u")) {
			createPassenger(view, stops, stopsCount);
		}
	}



	void createPassenger(View* view, Stop** stops, int count) {
		Passenger* p = view->createNewPassenger(stops, count);
		Stop* startStop = view->getStartStopByName(stops, count);
		startStop->addPassenger(p);
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
		cout << endl << endl << endl;

		view->showMinibusPassengers(minibus);
		minibus->goToNextBusStop();
		view->showCurrentBusStop(minibus);

		view->showDisembark();
		minibus->disembarkPassengers();
		view->showMinibusPassengers(minibus);

		view->showPickUp();
		minibus->pickUpPassengers();
		view->showMinibusPassengers(minibus);
	}
};