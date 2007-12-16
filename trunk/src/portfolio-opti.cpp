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
#include "algo/NaiveAlgorithm.h"
#include "Solution.h"

typedef std::vector<float> vf;
typedef std::vector< std::vector<float> > vvf;

int main(void) {
	FileParser* fp = new FileParser();
	DetQuadProblem * dqp = fp->parseDetModel("../benchmark/SIMPLE.txt",
			"../benchmark/SIMPLE_FE.txt");

	dqp->print();
	LinearProblem lp = dqp->getLinearProblem();
	lp.print();
	
	NaiveAlgorithm is = NaiveAlgorithm();
	Solution sol = is.getInitialSolution(lp);
	
	sol.print();
	
	return EXIT_SUCCESS;
}
