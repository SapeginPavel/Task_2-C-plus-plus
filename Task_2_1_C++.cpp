#include <iostream>
#include<locale.h>
#include "Program.cpp"

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	cout << "Запускаем программу..." << endl;

	Program* program = new Program();
	program->start();
}