#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <string>
#include <iostream>
#include <sstream>

#include "Solution.h"

class Problem {
public:
	virtual ~Problem();

	virtual float objectiveFunction(Solution sol) const = 0;
	// TODO: give a more explicit name to x
	virtual Solution getNeighbour(Solution x, int size) const = 0;
	virtual void getReglage(float temp) const = 0;

	friend std::ostream& operator<<(std::ostream& os, const Problem& p) {
		return os << p.toString();
	};
	virtual std::string toString() const;
	virtual void print() const;
};

#endif /*PROBLEM_H_*/
