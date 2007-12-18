#include "Variable.h"

Variable::~Variable() {
}

int Variable::getPosition() const {
	return position;
}

std::string Variable::getName() const {
	return name;
}

char * Variable::getNameToChar() const {
	size_t size = name.size() + 1;
	char * buffer = new char[size];
	strncpy(buffer, name.c_str(), size);

	return buffer;
}

std::string Variable::toString() const {
	return "";
}

void Variable::print() const {
	std::cout << toString() << std::endl;
}
