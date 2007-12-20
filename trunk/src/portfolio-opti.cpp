//============================================================================
// Name        : portfolio-opti.cpp
// Author      : Mathieu
// Version     :
// Copyright   : GPL3
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>

#include "util/FileParser.h"
#include "algo/SimulatedAnnealing.h"
#include "Solution.h"
#include "solver/LpsolveAdaptator.h"

typedef std::vector<float> vf;
typedef std::vector< std::vector<float> > vvf;

int main(void) {
	FileParser* fp = new FileParser();
	DetQuadProblem * dqp = fp->parseDetModel("benchmark/FTSE.txt",
			"benchmark/SIMPLE_FE.txt");
	LinearProblem lp = dqp->getSimpleLinearProblem();

#ifdef DEBUG
	dqp->print();
	lp.print();
#endif

	Algo * algo = new SimulatedAnnealing();
	Solver * s = new LpsolveAdaptator();

	Solution sol = algo->solve(*dqp, s);

	/*Solution sol = s->getAdmissibleSolution(&lp);
	 std::cout << "Risk = "<< dqp->objectiveFunction(sol) << " : "
	 << sol.toString() << std::endl;
	 sol = lp.getNeighbour(sol, 1);
	 lp = dqp->getFixedLP(sol);
	 sol = s->getAdmissibleSolution(&lp);
	 std::cout << "Risk = "<< dqp->objectiveFunction(sol) << " : "
	 << sol.toString() << std::endl;
	 sol = lp.getNeighbour(sol, 1);
	 lp = dqp->getFixedLP(sol);
	 sol = s->getAdmissibleSolution(&lp);
	 std::cout << "Risk = "<< dqp->objectiveFunction(sol) << " : "
	 << sol.toString() << std::endl;*/


	return EXIT_SUCCESS;
}
