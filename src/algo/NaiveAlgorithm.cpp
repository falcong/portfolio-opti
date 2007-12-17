#include "NaiveAlgorithm.h"

NaiveAlgorithm::NaiveAlgorithm() {
}

NaiveAlgorithm::~NaiveAlgorithm() {
}

// FIXME : to
Solution NaiveAlgorithm::getInitialSolution(LinearProblem &pb) {
	int K = pb.getVariables().size();
	Solution sol = Solution();
	float differential = 0.0;

	for (int i = 0; i != (int)pb.getVariables().size(); ++i) {
		VariableFloat & var = *(VariableFloat*)pb.getVariables()[i];
		float var_value = 0.0;

		if (1.0/K < var.getLowerBound()) {
			var_value = var.getLowerBound();
			differential += var_value - 1.0/K;
		} else if (1.0/K > var.getUpperBound()) {
			var_value = var.getLowerBound();
			differential += var_value - 1.0/K;
		} else {
			var_value = 1.0/K;
		}

		if (differential != 0.0) {
			var_value += (differential > 0) ? var.getUpperBound() - var_value
					: var.getLowerBound() - var_value;
		}
		sol.addVariable(var_value);
	}
	return sol;
}

Solution NaiveAlgorithm::getInitialSolution(DetQuadProblem &pb, float limitRatio) {
	int stockSelSize = pb.getK();
	float differential = 0.0, totalRatio = 0.0;
	Solution sol = Solution();

	
	std::vector<Stock> tmpStocks = pb.getStocks();
	std::sort(tmpStocks.begin(), tmpStocks.end(), Stock::SortByYield());
	
	for (int i = 0; i != (int)tmpStocks.size() && totalRatio < limitRatio; ++i) {
		Stock stock = tmpStocks[i];
		float var_value = 0.0;

		if (stock.getYield() > pb.getRho() && totalRatio < 1) {
			float ratio = 1.0/stockSelSize;
			if (ratio < stock.getLowerBound()) {
				var_value = stock.getLowerBound();
				differential += var_value - ratio;
			} else if (ratio > stock.getUpperBound()) {
				var_value = stock.getUpperBound();
				differential += var_value - ratio;
			} else {
				var_value = stock.getUpperBound();
			}

			if (differential != 0.0) {
				var_value += (differential > 0) ? stock.getUpperBound()
						- var_value : stock.getLowerBound() - var_value;
			}
		}
		totalRatio += var_value;
		sol.addVariable(var_value);
	}
	return sol;
}
