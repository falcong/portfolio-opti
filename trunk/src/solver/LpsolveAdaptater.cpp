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

	/* to build the model faster when adding constraints one at a time */
	set_add_rowmode(lprec, TRUE);

	for (int i = 0; i < (int)(lp->getConstraints().size()); ++i) {
		Constraint c = (Constraint)(lp->getConstraints()[i]);
		TermList terms = c.getTerms();
		int col[terms.size()];
		REAL row[terms.size()];
		int j = 0;
		for (TermList::const_iterator it = terms.begin(); it != terms.end();
				++it, ++j) {
			// TODO check if this is fixed
			// getPosition is probably out of bound, should it not be j and then row[j] = getposition ?
			//col[((Term)*it).getVariable().getPosition()] = (int)std::floor((( Term )*it).getCoeff() * 100);
			col[j] = ((Term)*it).getVariable().getPosition(); 
			row[j] = (int)std::floor((( Term )*it).getCoeff() * 100);
		}
		// WARNING the Consraint uses the same operator values than in lp_lib.h
		if (!add_constraintex(lprec, i, row, col, c.getOperator(), c.getBound()
				* 100)) {
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
		// getPosition is probably out of bound
		//col[(( Term )*it).getVariable().getPosition()] = (int)std::floor((( Term )*it).getCoeff() * 100);
		col[i] = ((Term)*it).getVariable().getPosition(); 
		row[i] = (int)std::floor((( Term )*it).getCoeff() * 100);
	}
	if(!set_obj_fnex(lprec, i, row, col)) {
		// TODO raise an exception
	}
	
	if(lp->getObjective().isMinimize()) {
		set_minim(lprec);
	} else {
		set_maxim(lprec);
	}
	
	return getSolution(lprec);
}

Solution LpsolveAdaptater::getSolution(lprec * lp) {
	Solution sol = Solution();
	REAL row[get_Norig_columns(lp)];
	solve(lp);
	
	// WARNING possible conversion failure from double to float
	sol.setZ(get_objective(lp));
	get_variables(lp, row);
	
	for(int i = 0; i < get_Norig_columns(lp); ++i) {
		sol.addVariable(row[i]);
	}
	
	delete_lp(lp);
	return sol;
}
