#include "VNS.h"

VNS::VNS()
{
	iterationLimit = 0;
}

VNS::VNS( int _iterationLimit)
{
	iterationLimit = _iterationLimit;
}

VNS::~VNS()
{
	
}

Solution VNS::solve(DetQuadProblem pb, Solver * s)
{
	if (iterationLimit == 0)
		iterationLimit = pb.getK()/2;

	LinearProblem lp = pb.getSimpleLinearProblem();
	
	int i = 2, x;
	Solution sol = s->getAdmissibleSolution(&lp);
	Solution xPrim, xSecond;

	
	int max = pb.objectiveFunction(sol);

	while( i < iterationLimit)
	{
		xPrim = lp.getNeighbour(sol, i);
		lp = pb.getFixedLP(xPrim);
		xPrim = s->getAdmissibleSolution(&lp);
		xSecond = getOptimumLocal(pb, s, xPrim);

		if(pb.objectiveFunction(xSecond)>max)
		{
			sol = xSecond;
			max = pb.objectiveFunction(xSecond);
			i=2;
		}
		else i++;
	}
	return sol;
}

Solution VNS::getOptimumLocal(DetQuadProblem pb, Solver * s, const Solution& sol) const
{
	Solution res = sol;
	LinearProblem lp = pb.getFixedLP(res);
	res = s->getAdmissibleSolution(&lp);

	int maxTemp = pb.objectiveFunction(res);
	
	Solution vTemp;

	int cpt = lp.getK() * (lp.getN() - lp.getK());

	for(int j = 0 ; j< cpt ; j++)
	{
		vTemp = lp.getNeighbour(sol, 1);
		lp = pb.getFixedLP(vTemp);
		vTemp = s->getAdmissibleSolution(&lp);
		if(pb.objectiveFunction(vTemp) > maxTemp)
		{
			maxTemp = pb.objectiveFunction(vTemp);
			res = vTemp;
		}
	}
	return res;

}
