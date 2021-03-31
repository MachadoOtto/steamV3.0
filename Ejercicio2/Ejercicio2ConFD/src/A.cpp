#include "../include/A.h"

#include <iostream>

claseA::claseA() {
	this->b = NULL;
	this->c = NULL;
}

claseA::~claseA() {}

void claseA::output() {
    std::cout << a << ") La clase A funciona" << std::endl;
}

