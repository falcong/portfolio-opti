#include "Stock.h"

Stock::Stock(int position, float yield, float variance, float lowerBound,
		float upperBound) :
	position(position), yield(yield), variance(variance),
			lowerBound(lowerBound), upperBound(upperBound) {
}

Stock::~Stock() {
}

int Stock::getPosition() const {
	return position;
}
float Stock::getYield() const {
	return yield;
}
float Stock::getVariance() const {
	return variance;
}
float Stock::getLowerBound() const {
	return lowerBound;
}
float Stock::getUpperBound() const {
	return upperBound;
}

std::string Stock::toString() const {
	std::ostringstream os;
	os << "{ #"<< position << " µ="<< yield << ", σ²="<< variance << " ["
			<< lowerBound << ";"<< upperBound << "] }";
	return os.str();
}
