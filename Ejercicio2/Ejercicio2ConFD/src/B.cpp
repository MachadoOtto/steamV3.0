#include "../include/B.h"

#include <iostream>

claseB::claseB() {
	this->a = NULL;
	this->c = NULL;
}

claseB::~claseB() {}

void claseB::output() {
    std::cout << b << ") La clase B funciona" << std::endl;
}

