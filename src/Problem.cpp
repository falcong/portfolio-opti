#include "Problem.h"

Problem::~Problem() {
}

std::string Problem::toString() const {
	return "";
}

void Problem::print() const {
	std::cout << toString() << std::endl;
}
