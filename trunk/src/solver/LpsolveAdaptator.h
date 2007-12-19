#ifndef LPSOLVEADAPTATOR_H_
#define LPSOLVEADAPTATOR_H_

#include "lpsolve/lp_lib.h"
#include <cmath>

#include <string>
#include <iostream>
#include <sstream>

#include "Solver.h"
#include "../Solution.h"
#include "../LinearProblem.h"
#include "../Term.h"

class LpsolveAdaptator : public Solver {
private:
	Solution getSolution(lprec * lp);
public:
	LpsolveAdaptator();
	virtual ~LpsolveAdaptator();
	
	Solution getBestSolution(LinearProblem *lp);
	Solution getAdmissibleSolution(LinearProblem *lp);
};

#endif /*LPSOLVEADAPTATOR_H_*/
