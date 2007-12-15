#include "Variable.h"

Variable::~Variable() {
}

std::string Variable::toString() const {
	return "";
}

void Variable::print() const {
	std::cout << toString() << std::endl;
}
