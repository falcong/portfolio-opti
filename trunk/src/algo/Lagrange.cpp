#include "Lagrange.h"

Lagrange::Lagrange() {
}

Lagrange::~Lagrange() {
}

Solution Lagrange::solve(DetQuadProblem& pb, Solver& s) const {
	LinearProblem lp = pb.getRelaxedLinearProblem(0, 0);
	// TODO
}
