#ifndef CDIFFEVOL_H
#define CDIFFEVOL_H

#include "stdafx.h"
#include "CDEIndividual.h"

#define POPULATION_SIZE 60
#define	ITERATIONS_AMOUNT 2000
#define CROSS_PROB 0.5
#define DIFF_WEIGHT 0.2

class CDiffEvol : public COptimizer
{

public:

	CDiffEvol(CProblem* pcProblem);
	~CDiffEvol() { if(pc_population!=NULL) delete[] pc_population; };

	void v_InitPopulation(int i_seed);
	void v_iterate();

	bool b_CheckStopCondition() { return  i_iterator < ITERATIONS_AMOUNT; };
	bool b_IndividualsAreDifferent(CDEIndividual* ind, CDEIndividual* baseInd, CDEIndividual* addInd0, CDEIndividual* addInd1);

	double* d_find_best(int i_seed);

private:

	CRandom c_random;
	CDEIndividual* pc_population;
	int i_population_size;

	double d_best_quality;

	int i_iterator;

	bool b_set_quality(CDEIndividual* c_new_ind, int i_parent_index);
	
	void v_find_3_random(int i_index, CDEIndividual** c_ind1, CDEIndividual** c_ind2, CDEIndividual** c_ind3);
	void v_replace_if_better(CDEIndividual* newInd, int i_ind_index);
};

#endif