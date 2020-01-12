// mnsc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	//Tests test3;
	//test3.test3();
	
	
	CMscnProblem* c1 = new CMscnProblem();

	c1->b_set_suppliers(1);
	c1->b_set_factories(1);
	c1->b_set_distributors(1);
	c1->b_set_shops(2);
	CSaveProblemToFile saver;
	c1->vGenerateInstance(seed);

	saver.v_save_problem(c1, "snt7ygh.txt");
	
	system("pause");
    return 0;
}

