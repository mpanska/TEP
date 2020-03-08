#ifndef CPROBLEM_H
#define CPROBLEM_H

#include "stdafx.h"

class CProblem 
{
public:

	CProblem() {};
	virtual ~CProblem() {};

	virtual double d_check_min(int i_index) = 0;
	virtual double d_check_max(int i_index) = 0;
	virtual double dGetQuality(double *pdSolution, int i_sol_size) = 0;
	virtual bool bConstraintsSatisfied(double *pdSolution, int i_sol_size) = 0;
	virtual int i_required_solution_size() = 0;
	virtual void vShowSolution(double *pdSolution) = 0;

};
#endif