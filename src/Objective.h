#ifndef OBJECTIVE_H_
#define OBJECTIVE_H_

#include <list>
#include <string>
#include <iostream>
#include <sstream>

#include "Term.h"
#include "Solution.h"

typedef const std::list<Term> TermList;

class Objective {
private:
	std::list<Term> terms;
	bool minimize;

public:
	Objective();
	Objective(bool minimize);
	virtual ~Objective();
	
	virtual bool isMinimize() const;
	
	virtual std::list<Term> getTerms() const;
	virtual void addTerm(Term term);
	
	virtual float result(Solution sol) const; 
	
	friend std::ostream& operator<<(std::ostream& os, const Objective& o) {
		return os << o.toString();
	};
	virtual std::string toString() const;
	virtual void print() const;
};

#endif /*OBJECTIVE_H_*/
