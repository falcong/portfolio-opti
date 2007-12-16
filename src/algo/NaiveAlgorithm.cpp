#include "NaiveAlgorithm.h"

NaiveAlgorithm::NaiveAlgorithm() {
}

NaiveAlgorithm::~NaiveAlgorithm() {
}

Solution NaiveAlgorithm::getInitialSolution(LinearProblem &pb) {
	int K = pb.getVariables().size();
	Solution sol = Solution();
	float differential = 0.0;

	for (int i = 0; i != (int)pb.getVariables().size(); ++i) {
		VariableFloat & var = *(VariableFloat*)pb.getVariables()[i]; 
		float var_value = 0.0;
		
		if(1.0/K < var.getLowerBound()) {
			var_value = var.getLowerBound();
			differential += var_value - 1.0/K;
		} else if(1.0/K > var.getUpperBound()) {
			var_value = var.getLowerBound();
			differential += var_value - 1.0/K;
		} else {
			var_value = 1.0/K;
		}
		
		if(differential != 0.0) {
			var_value += (differential > 0) ? var.getUpperBound() - var_value : var.getLowerBound() - var_value;
		}
		sol.addVariable(var_value);
	}
	return sol;
}

Solution NaiveAlgorithm::getInitialSolution(DetQuadProblem &pb) {
	int K = pb.getK();
	Solution sol = Solution();
	//TODO
	return sol;
}
