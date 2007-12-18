#include "VariableBool.h"

VariableBool::VariableBool(int position) {
	Variable::position = position;
}

VariableBool::VariableBool(int position, std::string name) {
	Variable::position = position;
	Variable::name = name;
}

VariableBool::~VariableBool() {
}

bool VariableBool::isBinary() const {
	return true;
}
