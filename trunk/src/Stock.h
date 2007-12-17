#ifndef STOCK_H_
#define STOCK_H_

#include <string>
#include <sstream>

class Stock {
private:
	int position;
	float yield;
	float variance;
	float lowerBound;
	float upperBound;
public:
	Stock(int position, float yield, float variance, float lowerBound,
			float upperBound);
	virtual ~Stock();

	virtual int getPosition() const;
	virtual float getYield() const;
	virtual float getVariance() const;
	virtual float getLowerBound() const;
	virtual float getUpperBound() const;
	
	virtual std::string toString() const;
	friend std::ostream& operator<<(std::ostream& os, const Stock& s) {
		return os << s.toString();
	};

	struct SortByPosition {
		bool operator ()(const Stock& s1, const Stock& s2) const {
			return s1.position < s2.position;
		}
	};
	struct SortByYield {
		bool operator ()(const Stock& s1, const Stock& s2) const {
			return s1.yield < s2.yield;
		}
	};
};

#endif /*STOCK_H_*/
