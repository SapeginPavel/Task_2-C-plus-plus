#pragma once
#include "program.cpp"

class Controller {
	Program* program;
	Controller(Program* program) {
		this->program = program;
	}

	void createPassenger();
};