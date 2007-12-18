#include "LpsolveAdaptater.h"

LpsolveAdaptater::LpsolveAdaptater() {
}

LpsolveAdaptater::~LpsolveAdaptater() {
}

Solution LpsolveAdaptater::getSolution(LinearProblem * lp) {
	lprec *lprec;
	int nbCol = lp->getVariables().size();
	lprec = make_lp(0, nbCol);

	if (lprec == NULL) {
		// TODO raise an exception
	}

	/* set variables name to ease debugging */
	for (int i = 0; i < (int)lp->getVariables().size(); ++i) {
		Variable * var = (lp->getVariables())[i];
		set_col_name(lprec, i+1, var->getNameToChar());
		if(var->isBinary()) {
			 set_binary(lprec, i+1, TRUE);
		}
	}

	/* to build the model faster when adding constraints one at a time */
	set_add_rowmode(lprec, TRUE);

	for (int i = 0; i < (int)(lp->getConstraints().size()); ++i) {
		// FIXME there's a bug here but I can't find it
		Constraint c = (Constraint)(lp->getConstraints()[i]);
		TermList terms = c.getTerms();
		int col[terms.size()];
		REAL row[terms.size()];
		int j = 0;
		for (TermList::const_iterator it = terms.begin(); it != terms.end();
				++it, ++j) {
			// TODO check if this is fixed
			col[j] = ((Term)*it).getVariable().getPosition();
			row[j] = ((Term)*it).getCoeff();
		}
		// WARNING the Consraint uses the same operator values than in lp_lib.h
		if (!add_constraintex(lprec, j, row, col, c.getOperator(), c.getBound())) {
			// TODO raise an exception
		}
	}

	/* the objective function requires rowmode to be off */
	set_add_rowmode(lprec, FALSE);
	TermList terms = lp->getObjective().getTerms();
	int i = 0;
	int col[terms.size()];
	REAL row[terms.size()];

	for (TermList::const_iterator it = terms.begin(); it != terms.end(); ++it,
			++i) {
		col[i] = ((Term)*it).getVariable().getPosition();
		row[i] = (( Term )*it).getCoeff();
	}
	if (!set_obj_fnex(lprec, i, row, col)) {
		// TODO raise an exception
	}

	if (lp->getObjective().isMinimize()) {
		set_minim(lprec);
	} else {
		set_maxim(lprec);
	}

	return getSolution(lprec);
}

Solution LpsolveAdaptater::getSolution(lprec * lp) {
	Solution sol = Solution();
	REAL row[get_Norig_columns(lp)];
	write_LP(lp, stdout);
	solve(lp);

	// WARNING possible conversion failure from double to float
	sol.setZ(get_objective(lp));
	get_variables(lp, row);

	for (int i = 0; i < get_Norig_columns(lp); ++i) {
		sol.addVariable(row[i]);
	}

	delete_lp(lp);
	return sol;
}