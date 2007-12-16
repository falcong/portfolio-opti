#include "DetQuadProblem.h"

DetQuadProblem::DetQuadProblem(int nbStocks) {
	n = nbStocks;
	for (int i = 0; i < nbStocks; ++i) {
		sigma.push_back(*(new std::vector<float>()));
		for (int j = 0; j < nbStocks; ++j) {
			sigma[i].push_back(0.0);
		}
	}
}

DetQuadProblem::~DetQuadProblem() {
}

float DetQuadProblem::objectiveFunction() const {
	// TODO: not implemented
	return 0.0;
}

Solution DetQuadProblem::getNeighbour(Solution x, int size) const {
	// TODO: not implemented
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
		VariableFloat * var = new VariableFloat(lowerBound, upperBound);
		lp.addVariable(var);
		c1.addTerm(*new Term(var, 1));
		c2.addTerm(*new Term(var, mu[i]));
	}
	c1.setOperator(Constraint::EQ);
	c1.setBound(1);
	c2.setOperator(Constraint::GE);
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
			c1.setOperator(Constraint::LE);
			c2.setOperator(Constraint::LE);
			c3.setOperator(Constraint::GE);

			/* TODO: the access to the variables is higly reliable on the order
			 * the first n variables must be the x_i, beware of the y_i
			 */
			// Adding the c_ij variables
			VariableFloat * var = new VariableFloat(lowerBound, upperBound);
			lp.addVariable(var);
			obj.addTerm(*new Term(var, sigma[i][j]));
			// cij - xi <= 0
			c1.addTerm(*new Term(lp.getVariables()[i], -1.0));
			c1.setOperator(Constraint::LE);
			c1.setBound(0);
			// cij - cj <= 0
			c2.addTerm(*new Term(lp.getVariables()[j], -1.0));
			c2.setOperator(Constraint::LE);
			c2.setBound(0);
			// cij - ci - cj >= -1
			c3.addTerm(*new Term(lp.getVariables()[i], -1.0));
			c3.addTerm(*new Term(lp.getVariables()[j], -1.0));
			c3.setOperator(Constraint::GE);
			c3.setBound(-1);

			lp.addConstraint(c1);
			lp.addConstraint(c2);
			lp.addConstraint(c3);
		}
	}
	lp.setObjective(obj);
	return lp;
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

std::string DetQuadProblem::toString() const {
	std::ostringstream os;
	os << "DetQuad Problem:"<< std::endl;
	os << "Mean values: ";
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
