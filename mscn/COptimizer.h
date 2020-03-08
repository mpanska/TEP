#ifndef COPTIMIZER_H
#define COPTIMIZER_H

#include "stdafx.h"

class COptimizer 
{
public:

	//what is the differene between regular methods and virtual ones <------------------ do realizacji polimorfizmu 
	virtual ~COptimizer() { delete[] d_current_best; }

	double* pdGetCurrentBest() { return d_current_best; };

	virtual double* d_find_best(int i_seed) = 0;


protected:

	CProblem * problem;
	double *d_current_best; 

};


#endif
