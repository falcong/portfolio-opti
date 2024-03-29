#include "DetQuadProblem.h"

DetQuadProblem::DetQuadProblem(int nbTotalStocks, int stockSelSize, float yield) :
	n(nbTotalStocks), k(stockSelSize), rho(yield) {
	for (int i = 0; i < n; ++i) {
		epsilon.push_back(0.0);
		delta.push_back(1.0);
		sigma.push_back(*(new std::vector<float>()));
		for (int j = 0; j < n; ++j) {
			sigma[i].push_back(0.0);
		}
	}
}

DetQuadProblem::DetQuadProblem(int nbTotalStocks) :
	n(nbTotalStocks) {
	for (int i = 0; i < n; ++i) {
		epsilon.push_back(0.0);
		delta.push_back(1.0);
		sigma.push_back(*(new std::vector<float>()));
		for (int j = 0; j < n; ++j) {
			sigma[i].push_back(0.0);
		}
	}
}

void DetQuadProblem::setRho(float r) {
	this->rho = r;
}

void DetQuadProblem::setK(int k) {
	this->k = k;
}

DetQuadProblem::~DetQuadProblem() {
}

float DetQuadProblem::objectiveFunction(Solution sol) const {
	float risk = 0.0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (i == j) {
				risk += sol.getVariables()[i] * sol.getVariables()[j]* sigma[i][j];
			} else {
				risk += 2 * sol.getVariables()[i]* sol.getVariables()[j]* sigma[i][j];
			}
		}
	}
	return risk;
	//return objective.result(sol);
}

Solution DetQuadProblem::getNeighbour(Solution x, int size) const {
	// TODO change size stock in the selection
	return x;
}

void DetQuadProblem::getReglage(float temp) const {
	// TODO: I just don't remember what the Reglage is supposed to do
}

LinearProblem DetQuadProblem::getLinearProblem() const {
	LinearProblem lp = LinearProblem(n, k, rho);
	Objective obj = Objective();
	int global_pos = 1;

	// Xi sum equals to 1, and Sum of mui * Xi >= rho
	Constraint c1 = Constraint();
	Constraint c2 = Constraint();
	for (int i = 0; i < n; ++i) {
		std::ostringstream os;
		os << "X_"<< i;
		VariableFloat * var = new VariableFloat(global_pos++, os.str(), epsilon[i], delta[i]);
		lp.addVariable(var);
		c1.addTerm(*new Term(var, 1));
		c2.addTerm(*new Term(var, mu[i]));
	}
	c1.setOperator(Constraint::cEQ);
	// TODO harcoded total stock ratio
	c1.setBound(1);
	c2.setOperator(Constraint::cGE);
	c2.setBound(rho);

	lp.addConstraint(c1);
	lp.addConstraint(c2);

	// Yi sum equals to K
	Constraint c3 = Constraint();
	// epsilon * Yi <= Xi <= delta * Yi
	for (int i = 0; i < n; ++i) {
		Constraint c1 = Constraint();
		Constraint c2 = Constraint();

		std::ostringstream os;
		os << "Y_"<< i;
		VariableBool * var = new VariableBool(global_pos++, os.str());
		lp.addVariable(var);

		c1.addTerm(*new Term(var, ((VariableFloat *)lp.getVariables()[i])->getLowerBound()));
		c1.addTerm(*new Term(lp.getVariables()[i], -1));
		c1.setOperator(Constraint::cLE);
		c1.setBound(0);

		c2.addTerm(*new Term(var, ((VariableFloat *)lp.getVariables()[i])->getUpperBound()));
		c2.addTerm(*new Term(lp.getVariables()[i], -1));
		c2.setOperator(Constraint::cGE);
		c2.setBound(0);

		c3.addTerm(*new Term(var, 1));

		lp.addConstraint(c1);
		lp.addConstraint(c2);
	}
	c3.setOperator(Constraint::cEQ);
	c3.setBound(k);
	lp.addConstraint(c3);

	// Linearization constraints
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
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
			std::ostringstream os;
			os << "C_"<< i << ","<< j;
			VariableFloat * var = new VariableFloat(global_pos++, os.str(), 0, 1);
			lp.addVariable(var);
			obj.addTerm(*new Term(var, (i == j) ? sigma[i][j] : 2*sigma[i][j]));
			// cij - xi <= 0
			c1.addTerm(*new Term(var, 1.0));
			c1.addTerm(*new Term(lp.getVariables()[i], -1.0));
			c1.setOperator(Constraint::cLE);
			c1.setBound(0);
			lp.addConstraint(c1);
			// cij - cj <= 0
			if (i != j) {
				c2.addTerm(*new Term(var, 1.0));
				c2.addTerm(*new Term(lp.getVariables()[j], -1.0));
				c2.setOperator(Constraint::cLE);
				c2.setBound(0);
				lp.addConstraint(c2);
			}
			// cij - ci - cj >= -1
			c3.addTerm(*new Term(var, 1.0));
			if (i != j) {
				c3.addTerm(*new Term(lp.getVariables()[i], -1.0));
				c3.addTerm(*new Term(lp.getVariables()[j], -1.0));
			} else {
				c3.addTerm(*new Term(lp.getVariables()[i], -2.0));
			}
			c3.setOperator(Constraint::cGE);
			c3.setBound(-1);
			lp.addConstraint(c3);
		}
	}
	lp.setObjective(obj);
	return lp;
}

// TODO refactoring needed: this is copy pasted from getLinearProblem
LinearProblem DetQuadProblem::getRelaxedLinearProblem(float lambda1,
		float lambda2) const {
	// TODO add : +lambda_1 (epsilon_i * Yi + Xj - 1 - Cij)
	// TODO add : +lambda_2 (sigma[i][i] * Yi - Cij)
	LinearProblem lp = LinearProblem(n, k, rho);
	Objective obj = Objective();
	int global_pos = 1;

	// Xi sum equals to 1, and Sum of mui * Xi >= rho
	Constraint c1 = Constraint();
	Constraint c2 = Constraint();
	for (int i = 0; i < n; ++i) {
		std::ostringstream os;
		os << "X_"<< i;
		VariableFloat * var = new VariableFloat(global_pos++, os.str(), epsilon[i], delta[i]);
		lp.addVariable(var);
		c1.addTerm(*new Term(var, 1));
		c2.addTerm(*new Term(var, mu[i]));
	}
	c1.setOperator(Constraint::cEQ);
	// TODO harcoded total stock ratio
	c1.setBound(1);
	c2.setOperator(Constraint::cGE);
	c2.setBound(rho);

	lp.addConstraint(c1);
	lp.addConstraint(c2);

	// Yi sum equals to K
	Constraint c3 = Constraint();
	// epsilon_i * Yi <= Xi <= delta * Yi
	for (int i = 0; i < n; ++i) {
		Constraint c1 = Constraint();
		Constraint c2 = Constraint();

		std::ostringstream os;
		os << "Y_"<< i;
		VariableBool * var = new VariableBool(global_pos++, os.str());
		lp.addVariable(var);

		c1.addTerm(*new Term(var, ((VariableFloat *)lp.getVariables()[i])->getLowerBound()));
		c1.addTerm(*new Term(lp.getVariables()[i], -1));
		c1.setOperator(Constraint::cLE);
		c1.setBound(0);

		c2.addTerm(*new Term(var, ((VariableFloat *)lp.getVariables()[i])->getUpperBound()));
		c2.addTerm(*new Term(lp.getVariables()[i], -1));
		c2.setOperator(Constraint::cGE);
		c2.setBound(0);

		c3.addTerm(*new Term(var, 1));

		lp.addConstraint(c1);
		lp.addConstraint(c2);
	}
	c3.setOperator(Constraint::cEQ);
	c3.setBound(k);
	lp.addConstraint(c3);

	// Linearization constraints
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			Constraint c1 = Constraint(); // cij - xi <= 0
			Constraint c2 = Constraint(); // cij - cj <= 0
			Constraint c3 = Constraint();
			Constraint c4 = Constraint(); // epsilon_i * Yi + Xj - Cij <= 1
			Constraint c5 = Constraint(); // delta_i * Yi - Cij <= 0

			/* TODO: the access to the variables is higly reliable on the order
			 * the first n variables must be the x_i, beware of the y_i
			 */
			// Adding the c_ij variables
			std::ostringstream os;
			os << "C_"<< i << ","<< j;
			VariableFloat * var = new VariableFloat(global_pos++, os.str(), 0, 1);
			lp.addVariable(var);
			obj.addTerm(*new Term(var, (i == j) ? sigma[i][j] : 2*sigma[i][j]));
			// cij - xi <= 0
			c1.addTerm(*new Term(var, 1.0));
			c1.addTerm(*new Term(lp.getVariables()[i], -1.0));
			c1.setOperator(Constraint::cLE);
			c1.setBound(0);
			lp.addConstraint(c1);
			// cij - cj <= 0
			if (i != j) {
				c2.addTerm(*new Term(var, 1.0));
				c2.addTerm(*new Term(lp.getVariables()[j], -1.0));
				c2.setOperator(Constraint::cLE);
				c2.setBound(0);
				lp.addConstraint(c2);
			}
			// cij - ci - cj >= -1
			c3.addTerm(*new Term(var, 1.0));
			if (i != j) {
				c3.addTerm(*new Term(lp.getVariables()[i], -1.0));
				c3.addTerm(*new Term(lp.getVariables()[j], -1.0));
			} else {
				c3.addTerm(*new Term(lp.getVariables()[i], -2.0));
			}
			c3.setOperator(Constraint::cGE);
			c3.setBound(-1);
			lp.addConstraint(c3);

			// epsilon_i * Yi + Xj - Cij <= 1
			float epsi = ((VariableFloat *)lp.getVariables()[i])->getLowerBound();
			c4.addTerm(*new Term(lp.getVariables()[n + i], epsi));
			c4.addTerm(*new Term(lp.getVariables()[j], 1.0));
			c4.addTerm(*new Term(var, -1.0));
			c4.setOperator(Constraint::cLE);
			c4.setBound(1);
			lp.addConstraint(c4);

			// delta_i * Yi - Cij <= 0
			float delta_i = ((VariableFloat *)lp.getVariables()[i])->getUpperBound();
			c5.addTerm(*new Term(lp.getVariables()[n + i], delta_i));
			c5.addTerm(*new Term(var, -1.0));
			c5.setOperator(Constraint::cLE);
			c5.setBound(0);
			lp.addConstraint(c5);

			// +lambda_1 (epsilon_i * Yi + Xj - 1 - Cij)
			// TODO je ne sais pas faire le -1 car ca n'est pas une variable ...
			obj.addTerm(*new Term(lp.getVariables()[n+i], lambda1 * epsi));
			obj.addTerm(*new Term(lp.getVariables()[j], lambda1));
			obj.addTerm(*new Term(var, -1.0 * lambda1));

			// +lambda_2 (sigma[i][j] * Yi - Cij)
			// TODO Sandie est-ce que c'est bien sigma[i][j] dans le document technique c'est:
			// sigma_i ... donc soit c'est sigma[i][i] (mais alors attention de le faire qu'une seule fois ... sortir de la boucle sur j
			// ou alors c'est une faute de frappe et c'est sigma_ij
			obj.addTerm(*new Term(lp.getVariables()[n+i], lambda2 * sigma[i][j]));
			obj.addTerm(*new Term(var, -1.0 * lambda2));
			/* sinon c'est ca, mais ca me semble bizarre :
			 * obj.addTerm(*new Term(lp.getVariables()[n+i], lambda2 * sigma[i][i]));*/
		}
	}
	lp.setObjective(obj);
	return lp;
}

// TODO refactoring needed: this is copy pasted from getLinearProblem
LinearProblem DetQuadProblem::getSimpleLinearProblem() const {
	LinearProblem lp = LinearProblem(n, k, rho);
	Objective obj = Objective();
	int global_pos = 1;

	// Xi sum equals to 1, and Sum of mui * Xi >= rho
	Constraint c1 = Constraint();
	Constraint c2 = Constraint();
	for (int i = 0; i < n; ++i) {
		std::ostringstream os;
		os << "X_"<< i;
		VariableFloat * var = new VariableFloat(global_pos++, os.str(), epsilon[i], delta[i]);
		lp.addVariable(var);
		c1.addTerm(*new Term(var, 1));
		c2.addTerm(*new Term(var, mu[i]));
	}
	c1.setOperator(Constraint::cEQ);
	// TODO harcoded total stock ratio
	c1.setBound(1);
	c2.setOperator(Constraint::cGE);
	c2.setBound(rho);

	lp.addConstraint(c1);
	lp.addConstraint(c2);

	// Yi sum equals to K
	Constraint c3 = Constraint();
	// epsilon * Yi <= Xi <= delta * Yi
	for (int i = 0; i < n; ++i) {
		Constraint c1 = Constraint();
		Constraint c2 = Constraint();

		std::ostringstream os;
		os << "Y_"<< i;
		VariableBool * var = new VariableBool(global_pos++, os.str());
		lp.addVariable(var);

		c1.addTerm(*new Term(var, ((VariableFloat *)lp.getVariables()[i])->getLowerBound()));
		c1.addTerm(*new Term(lp.getVariables()[i], -1));
		c1.setOperator(Constraint::cLE);
		c1.setBound(0);

		c2.addTerm(*new Term(var, ((VariableFloat *)lp.getVariables()[i])->getUpperBound()));
		c2.addTerm(*new Term(lp.getVariables()[i], -1));
		c2.setOperator(Constraint::cGE);
		c2.setBound(0);

		c3.addTerm(*new Term(var, 1));

		lp.addConstraint(c1);
		lp.addConstraint(c2);
	}
	c3.setOperator(Constraint::cEQ);
	c3.setBound(k);
	lp.addConstraint(c3);

	lp.setObjective(obj);
	return lp;
}

LinearProblem DetQuadProblem::getFixedLP(Solution sol) const {
	LinearProblem lp = LinearProblem(n, k, rho);
	Objective obj = Objective();
	int global_pos = 1;

	Constraint c1 = Constraint();
	Constraint c2 = Constraint();

	for (int i = 0; i < n; ++i) {
		std::ostringstream os;
		os << "X_"<< i;
		VariableFloat * var = new VariableFloat(global_pos++, os.str(), epsilon[i], delta[i]);
		lp.addVariable(var);
		c1.addTerm(*new Term(var, 1));
		c2.addTerm(*new Term(var, mu[i]));
	}
	c1.setOperator(Constraint::cEQ);
	// TODO harcoded total stock ratio
	c1.setBound(1);
	c2.setOperator(Constraint::cGE);
	c2.setBound(rho);

	lp.addConstraint(c1);
	lp.addConstraint(c2);

	// Yi sum equals to K
	Constraint c3 = Constraint();
	// epsilon * Yi <= Xi <= delta * Yi
	for (int i = 0; i < n; ++i) {
		Constraint c1 = Constraint();
		Constraint c2 = Constraint();

		std::ostringstream os;
		os << "Y_"<< i;
		VariableBool * var = new VariableBool(global_pos++, os.str());
		lp.addVariable(var);

		if (sol.getVariables()[n+i] != 0) {
			c1.addTerm(*new Term(var, ((VariableFloat *)lp.getVariables()[i])->getLowerBound()));
		} else {
			c1.addTerm(*new Term(var, 0));
		}
		c1.addTerm(*new Term(lp.getVariables()[i], -1));
		c1.setOperator(Constraint::cLE);
		c1.setBound(0);

		if (sol.getVariables()[n+i] != 0) {
			c2.addTerm(*new Term(var, ((VariableFloat *)lp.getVariables()[i])->getUpperBound()));
		} else {
			c2.addTerm(*new Term(var, 0));
		}
		c2.addTerm(*new Term(lp.getVariables()[i], -1));
		c2.setOperator(Constraint::cGE);
		c2.setBound(0);

		c3.addTerm(*new Term(var, 1));

		lp.addConstraint(c1);
		lp.addConstraint(c2);
	}
	c3.setOperator(Constraint::cEQ);
	c3.setBound(k);
	lp.addConstraint(c3);

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

int DetQuadProblem::getK() const {
	return k;
}

float DetQuadProblem::getRho() const {
	return rho;
}

int DetQuadProblem::getN() const {
	return n;
}

void DetQuadProblem::setEpsilonAt(int pos, float epsi) {
	epsilon.at(pos) = epsi;
}

void DetQuadProblem::setDeltaAt(int pos, float delt) {
	delta.at(pos) = delt;
}

void DetQuadProblem::setBounds(int pos, float lower, float upper) {
	setEpsilonAt(pos, lower);
	setDeltaAt(pos, upper);
}

std::string DetQuadProblem::toString() const {
	std::ostringstream os;
	os << "DetQuad Problem:"<< std::endl;

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
