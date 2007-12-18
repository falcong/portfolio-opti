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
#include "algo/InitialSolver.h"
#include "algo/NaiveAlgorithm.h"
#include "algo/Algo.h"
#include "algo/SimulatedAnnealing.h"
#include "Solution.h"
#include "solver/LpsolveAdaptater.h"

typedef std::vector<float> vf;
typedef std::vector< std::vector<float> > vvf;

int main(void) {
	FileParser* fp = new FileParser();
	DetQuadProblem * dqp = fp->parseDetModel("benchmark/SIMPLE.txt",
			"benchmark/SIMPLE_FE.txt");

	dqp->print();
	LinearProblem lp = dqp->getLinearProblem();
	lp.print();
	
	//Algo * algo = new SimulatedAnnealing();
	//InitialSolver * is = new NaiveAlgorithm();
	// TODO bug Solution sol = algo->solve(*dqp, is);
	//sol.print();

	LpsolveAdaptater * la = new LpsolveAdaptater();
	Solution sol = la->getSolution(&lp);
	//sol.print();
	
	return EXIT_SUCCESS;
}
