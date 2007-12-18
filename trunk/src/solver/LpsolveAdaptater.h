#ifndef LPSOLVEADAPTATER_H_
#define LPSOLVEADAPTATER_H_

#include "lpsolve/lp_lib.h"
#include <cmath>

#include "Solver.h"
#include "../Solution.h"
#include "../LinearProblem.h"
#include "../Term.h"

class LpsolveAdaptater : public Solver {
private:
	Solution getSolution(lprec * lp);
public:
	LpsolveAdaptater();
	virtual ~LpsolveAdaptater();
	
	Solution getSolution(LinearProblem *lp);
};

#endif /*LPSOLVEADAPTATER_H_*/
