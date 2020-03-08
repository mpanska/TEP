#include "stdafx.h"

CDiffEvol::CDiffEvol(CProblem* pcProblem)
{
	problem = pcProblem;
	i_iterator = 0;
	d_best_quality = 0;
}
//ctor

double* CDiffEvol::d_find_best(int i_seed)
{
	v_InitPopulation(i_seed);
	while (b_CheckStopCondition())
	{
		for (int ii = 0; ii < 100; ii++)
			v_iterate();
	}


	cout << "cdiffevol best solution: " << endl;
	problem->vShowSolution(d_current_best);

	return d_current_best;
}
//double* CDiffEvol::pd_find_best(int i_seed)


void CDiffEvol::v_InitPopulation(int i_seed)  
{
	c_random = CRandom(i_seed);
	int i_size = problem->i_required_solution_size();

	i_population_size = POPULATION_SIZE;
	pc_population = new CDEIndividual[POPULATION_SIZE];
	
	for (int ii = 0; ii < POPULATION_SIZE; ii++)
	{
		pc_population[ii].b_set_genotype_size(i_size);
		pc_population[ii].b_set_genotype(CSolutionGenerator::d_generate_solution(c_random, problem));
		pc_population[ii].b_set_fitness(problem->dGetQuality(pc_population[ii].d_get_genotype(), i_size));
	}

	if (d_current_best != NULL)
		delete[] d_current_best;

	//d_current_best = new double[i_size];
	d_current_best = CSolutionGenerator::d_generate_solution(c_random, problem);
	d_best_quality = problem->dGetQuality(d_current_best, i_size);
}
//void CDiffEvol::v_InitPopulation(int i_seed)


bool CDiffEvol::b_IndividualsAreDifferent(CDEIndividual* ind, CDEIndividual* baseInd, CDEIndividual* addInd0, CDEIndividual* addInd1)
{
	int i_genotype_size = problem->i_required_solution_size();
	//if are the same:
	bool ind_1_2 = true;
	bool ind_1_3 = true;
	bool ind_1_4 = true;
	bool ind_2_3 = true;
	bool ind_2_4 = true;
	bool ind_3_4 = true;
	int i_index = 0;

	while (ind_1_2 && ind_1_3 && ind_1_4 && ind_2_3 && ind_2_4 && ind_3_4 && i_index < i_genotype_size) 
	{
		if (ind_1_2) ind_1_2 = (ind->d_get_gen(i_index) == baseInd->d_get_gen(i_index));
		if (ind_1_3) ind_1_3 = (ind->d_get_gen(i_index) == addInd0->d_get_gen(i_index));
		if (ind_1_4) ind_1_4 = (ind->d_get_gen(i_index) == addInd1->d_get_gen(i_index));
		if (ind_2_3) ind_2_3 = (baseInd->d_get_gen(i_index) == addInd0->d_get_gen(i_index));
		if (ind_2_4) ind_2_4 = (baseInd->d_get_gen(i_index) == addInd1->d_get_gen(i_index));
		if (ind_3_4) ind_3_4 = (addInd0->d_get_gen(i_index) == addInd1->d_get_gen(i_index));

		i_index++;
	}

	if (ind_1_2 || ind_1_3 || ind_1_4 || ind_2_3 || ind_2_4 || ind_3_4) return false;
	else return true;
}
//bool CDiffEvol::b_IndividualsAreDifferent(CDEIndividual* ind, CDEIndividual* baseInd, CDEIndividual* addInd0, CDEIndividual* addInd1)



void CDiffEvol::v_iterate()
{
	int i_genotype_size = problem->i_required_solution_size();
	for (int ii = 0; ii < i_population_size; ii++)
	{
		CDEIndividual* baseInd = nullptr;
		CDEIndividual* addInd0 = nullptr;
		CDEIndividual* addInd1 = nullptr;

		v_find_3_random(ii, &baseInd, &addInd0, &addInd1);

		if (b_IndividualsAreDifferent(&pc_population[ii], baseInd, addInd0, addInd1))
		{
			CDEIndividual* indNew = new CDEIndividual(i_genotype_size);

			for (int geneOffset = 0; geneOffset < i_genotype_size; geneOffset++) 
			{
				if (c_random.dGenerateDouble(0, 1) < CROSS_PROB) 
				{
					//chromosome crossover:
					//gene mutation:
					double d_mutated_gen = baseInd->d_get_gen(geneOffset) + DIFF_WEIGHT *
						(addInd0->d_get_gen(geneOffset) - addInd1->d_get_gen(geneOffset));

					double d_min = problem->d_check_min(geneOffset);
					double d_max = problem->d_check_max(geneOffset);

					if (d_mutated_gen > d_min && d_mutated_gen < d_max)
						indNew->b_set_gen(geneOffset, d_mutated_gen);

					else indNew->b_set_gen(geneOffset, baseInd->d_get_gen(geneOffset));
				}
				//jak nie to wartosc genu w osobniku kandydacie pozostaje jak w ind
				else indNew->b_set_gen(geneOffset, pc_population[ii].d_get_gen(geneOffset)); 
			}
			b_set_quality(indNew, ii);
			v_replace_if_better(indNew, ii);
		}
		else i_iterator++;
	}
}
//void CDiffEvol::v_iterate()


void CDiffEvol::v_find_3_random(int i_index, CDEIndividual** c_ind1, CDEIndividual** c_ind2, CDEIndividual** c_ind3)
{
	int i_index_base;
	int i_index_add0;
	int i_index_add1;

	do {
		i_index_base = c_random.iGenerateInt(0, i_population_size - 1);
	} while (i_index_base == i_index);
	do {
		i_index_add0 = c_random.iGenerateInt(0, i_population_size - 1);
	} while (i_index_add0 == i_index || i_index_add0 == i_index_base);
	do {
		i_index_add1 = c_random.iGenerateInt(0, i_population_size - 1);
	} while (i_index_add1 == i_index || i_index_add1 == i_index_base || i_index_add1 == i_index_add0);

	*c_ind1 = &pc_population[i_index_base];
	*c_ind2 = &pc_population[i_index_add0];
	*c_ind3 = &pc_population[i_index_add1];
}
//void CDiffEvol::v_find_3_random(int i_index, CDEIndividual** c_ind1, CDEIndividual** c_ind2, CDEIndividual** c_ind3)


bool CDiffEvol::b_set_quality(CDEIndividual* c_new_ind, int i_parent_index)
{
	if (c_new_ind == NULL || i_parent_index < 0)
		return false;

	c_new_ind->b_set_fitness(problem->dGetQuality(c_new_ind->d_get_genotype(), problem->i_required_solution_size()));
	i_iterator++;
	return true;
}
//bool CDiffEvol::b_set_quality(CDEIndividual* c_new_ind, int i_parent_index)


void CDiffEvol::v_replace_if_better(CDEIndividual* newInd, int i_ind_index)
{
	int i_size = problem->i_required_solution_size();

		//if (Fitness(indNew) ≥ Fitness(ind)):
	if (newInd->d_get_fitness() >= pc_population[i_ind_index].d_get_fitness())
	{
		pc_population[i_ind_index] = *newInd;

		if (newInd->d_get_fitness() > d_best_quality)
		{
			for (int ii = 0; ii < i_size; ii++)
				d_current_best[ii] = pc_population[i_ind_index].d_get_gen(ii);
				
			d_best_quality = newInd->d_get_fitness();
			cout << "best quality: " << d_best_quality << endl; 
		}
	}
	else delete newInd;
}
//void CDiffEvol::v_replace_if_better(CDEIndividual* newInd, int i_ind_index)

