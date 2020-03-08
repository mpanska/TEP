#ifndef CSOLUTIONGENERATOR_H
#define CSOLUTIONGENERATOR_H

#include "stdafx.h"

class CSolutionGenerator
{
public:

	static double* d_generate_solution(CRandom &random, CProblem* pcProblem)
	{
		int i_size = pcProblem->i_required_solution_size();

		double* pdSolution = new double[i_size];

		for (int ii = 0; ii < i_size; ii++)
		{
			double d_min = pcProblem->d_check_min(ii);
			double d_max = pcProblem->d_check_max(ii);
			pdSolution[ii] = random.dGenerateDouble(d_min, d_max);
		}

		return pdSolution;
	}
	//static double* d_generate_solution(CRandom &random, CProblem* pcProblem) 
};

#endif
