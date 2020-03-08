#ifndef CDEINDIVIDUAL_H
#define CDEINDIVIDUAL_H

#define DEF_GTYPE_SIZE 4

#include "stdafx.h"

class CDEIndividual { 

public:

	CDEIndividual() {};
	CDEIndividual(int iGenotypeSize);
	~CDEIndividual() { if(pd_genotype!=NULL) delete[] pd_genotype; }

	//getteers and setters
	double d_get_fitness() const { return d_fitness; }
	double* d_get_genotype() const { return pd_genotype; }
	double d_get_gen(int i_index) const { return pd_genotype[i_index]; }

	bool b_set_fitness(double dFitness);
	bool b_set_genotype_size(int i_new_size);
	bool b_set_genotype(double* pdGenotype);
	bool b_set_gen(int i_index, double d_gen);

private:

	double* pd_genotype;
	int i_genotype_size;
	double d_fitness;

};

#endif