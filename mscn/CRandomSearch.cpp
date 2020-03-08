#include "stdafx.h"

double* CRandomSearch::d_find_best(int i_seed)
{
	int i_solution_size = problem->i_required_solution_size();
	c_random = CRandom(i_seed);

	double* d_current_best = CSolutionGenerator::d_generate_solution(c_random, problem);
	double d_highest_quality = 0;
	double d_current_quality = 0;

	if (problem->bConstraintsSatisfied(d_current_best, i_solution_size))
		d_highest_quality = problem->dGetQuality(d_current_best, i_solution_size);
	
	for (int ii = 0; ii < ITERATIONS; ii++) 
	{
		double* d_current_solution = CSolutionGenerator::d_generate_solution(c_random, problem);
		d_current_quality = problem->dGetQuality(d_current_solution, i_solution_size); 

		if (d_highest_quality < d_current_quality) 
		{
			if (problem->bConstraintsSatisfied(d_current_solution, i_solution_size))
			{
				d_highest_quality = d_current_quality;
				delete d_current_best;
				d_current_best = d_current_solution;
			}
			else delete d_current_solution;
		}
	}

	cout << "crandomsearch best sol: " << endl;
	problem->vShowSolution(d_current_best);

	//CSaveProblemToFile saver;
	//saver.v_save_problem(problem, "d_best_solution_with_randomSearch.txt");

	return d_current_best;
}
//double* CRandomSearch::d_find_best(int i_seed)
