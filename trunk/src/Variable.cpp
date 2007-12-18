#include "Variable.h"

Variable::~Variable() {
}

int Variable::getPosition() const {
	return position;
}

std::string Variable::getName() const {
	return name;
}

std::string Variable::toString() const {
	return "";
}

void Variable::print() const {
	std::cout << toString() << std::endl;
}
