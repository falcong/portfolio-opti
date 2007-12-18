#include "DetQuadProblem.h"

DetQuadProblem::DetQuadProblem(int nbTotalStocks, int stockSelSize, float yield) :
	n(nbTotalStocks), k(stockSelSize), rho(yield) {
	for (int i = 0; i < n; ++i) {
		sigma.push_back(*(new std::vector<float>()));
		for (int j = 0; j < n; ++j) {
			sigma[i].push_back(0.0);
		}
	}
}

DetQuadProblem::~DetQuadProblem() {
}

float DetQuadProblem::objectiveFunction(Solution sol) const {
	return objective.result(sol);
}

Solution DetQuadProblem::getNeighbour(Solution x, int size) const {
	// TODO change size stock in the selection
	return x;
}

void DetQuadProblem::getReglage(float temp) const {
	// TODO: I just don't remember what the Reglage is supposed to do
}

LinearProblem DetQuadProblem::getLinearProblem() const {
	// TODO: not finished	
	LinearProblem lp;
	Objective obj = Objective();

	// Xi sum equals to 1, and Sum of mui * Xi >= rho
	const float lowerBound = 0;
	const float upperBound = 1;
	Constraint c1 = Constraint();
	Constraint c2 = Constraint();
	for (int i = 0; i < n; ++i) {
		VariableFloat * var = new VariableFloat(i, lowerBound, upperBound);
		lp.addVariable(var);
		c1.addTerm(*new Term(var, 1));
		c2.addTerm(*new Term(var, mu[i]));
	}
	c1.setOperator(Constraint::cEQ);
	c1.setBound(1);
	c2.setOperator(Constraint::cGE);
	c2.setBound(rho);

	lp.addConstraint(c1);
	lp.addConstraint(c2);

	// TODO: Yi sum equals to K

	// Linearization constraints
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			Constraint c1 = Constraint();
			Constraint c2 = Constraint();
			Constraint c3 = Constraint();
			c1.setOperator(Constraint::cLE);
			c2.setOperator(Constraint::cLE);
			c3.setOperator(Constraint::cGE);

			/* TODO: the access to the variables is higly reliable on the order
			 * the first n variables must be the x_i, beware of the y_i
			 */
			// Adding the c_ij variables
			VariableFloat * var = new VariableFloat(n+i+j, lowerBound, upperBound);
			lp.addVariable(var);
			obj.addTerm(*new Term(var, sigma[i][j]));
			// cij - xi <= 0
			c1.addTerm(*new Term(lp.getVariables()[i], -1.0));
			c1.setOperator(Constraint::cLE);
			c1.setBound(0);
			// cij - cj <= 0
			c2.addTerm(*new Term(lp.getVariables()[j], -1.0));
			c2.setOperator(Constraint::cLE);
			c2.setBound(0);
			// cij - ci - cj >= -1
			c3.addTerm(*new Term(lp.getVariables()[i], -1.0));
			c3.addTerm(*new Term(lp.getVariables()[j], -1.0));
			c3.setOperator(Constraint::cGE);
			c3.setBound(-1);

			lp.addConstraint(c1);
			lp.addConstraint(c2);
			lp.addConstraint(c3);
		}
	}
	lp.setObjective(obj);
	return lp;
}

Objective DetQuadProblem::getObjective() {
	return objective;
}

void DetQuadProblem::setObjective(Objective &objective) {
	this->objective = objective;
}

void DetQuadProblem::addVariable(Variable * var) {
	variables.push_back(var);
}

std::vector<Variable*> DetQuadProblem::getVariables() const {
	return variables;
}

void DetQuadProblem::addMeanValue(float mv) {
	mu.push_back(mv);
}

std::vector<float> DetQuadProblem::getMeanValues() const {
	return mu;
}

std::vector< std::vector<float> > & DetQuadProblem::getCovariances() {
	return sigma;
}

void DetQuadProblem::addStock(Stock stock) {
	stocks.push_back(stock);
}

std::vector<Stock> DetQuadProblem::getStocks() const {
	return stocks;
}

int DetQuadProblem::getK() const {
	return k;
}

float DetQuadProblem::getRho() const {
	return rho;
}

std::string DetQuadProblem::toString() const {
	std::ostringstream os;
	os << "DetQuad Problem:"<< std::endl;
	os << (int)stocks.size() << " Stocks:";
	for (int i = 0; i != (int)stocks.size(); ++i) {
		os << stocks[i]<< " ";
	}
	os << std::endl << objective << std::endl;
	os << (int)variables.size() << " Variables:";
	for (int i = 0; i != (int)variables.size(); ++i) {
		os << "v"<< i << "-"<< *(variables[i])<< ", ";
	}
	os << std::endl << "Mean values: ";
	for (int i = 0; i != (int)mu.size(); ++i) {
		os << getMeanValues()[i]<< " ";
	}
	os << std::endl << "Covariances: "<< std::endl;
	for (int j = 0; j < (int)sigma.size(); ++j) {
		for (int k = 0; k < (int)sigma.size(); ++k) {
			os << sigma[j][k]<< " ";
		}
		os << std::endl;
	}
	return os.str();
}

void DetQuadProblem::print() const {
	std::cout << toString() << std::endl;
}
