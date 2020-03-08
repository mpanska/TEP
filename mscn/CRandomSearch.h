#ifndef CRANDOMSEARCH_H
#define CRANDOMSEARCH_H

#define ITERATIONS 1000 

#include "stdafx.h"
#include "COptimizer.h"

class CRandomSearch : public COptimizer
{
public:
	 
	CRandomSearch(CProblem *pcProblem) { problem = pcProblem; };
	~CRandomSearch() {};

	double* d_find_best(int i_seed);


private:

	CRandom c_random;
	double d_best_quality;

};

#endif