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
	DetQuadProblem * dqp = fp->parseDetModel("benchmark/SIMPLE.txt",
			"benchmark/SIMPLE_FE.txt");
	LinearProblem lp = dqp->getLinearProblem();
	
#ifdef DEBUG
	dqp->print();
	lp.print();
#endif

	Algo * algo = new SimulatedAnnealing();
	Solver * s = new LpsolveAdaptator();
	//TODO does not work Solution sol = algo->solve(lp, s);
	//sol.print();

	return EXIT_SUCCESS;
}
