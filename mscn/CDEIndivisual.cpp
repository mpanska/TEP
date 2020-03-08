#include "stdafx.h"

CDEIndividual::CDEIndividual(int iGenotypeSize)
{
	if (iGenotypeSize <= 0)
		i_genotype_size = DEF_GTYPE_SIZE;

	i_genotype_size = iGenotypeSize;
	pd_genotype = new double[iGenotypeSize];
}
//ctor


bool CDEIndividual::b_set_fitness(double dFitness) 
{ 
	if (dFitness < 0)
		return false;

	d_fitness = dFitness; 
	return true;
}
//bool CDEIndividual::b_set_fitness(double dFitness) 


bool CDEIndividual:: b_set_genotype_size(int i_new_size)
{
	if (i_new_size <= 0)
		return false;

	i_genotype_size = i_new_size;
	return true;
}
//bool CDEIndividual:: b_set_genotype_size(int i_new_size)


bool CDEIndividual::b_set_genotype(double* pdGenotype)
{
	if (pdGenotype == NULL)
		return false;

	pd_genotype = pdGenotype;
	return true;
}
//bool CDEIndividual::b_set_genotype(double* pdGenotype)


bool CDEIndividual::b_set_gen(int i_index, double d_gen)
{
	if (i_index < 0 && d_gen < 0)
		return false;

	pd_genotype[i_index] = d_gen;
	return true;
}
//bool CDEIndividual::b_set_gen(int i_index, double d_gen)