#pragma once
#include "stdafx.h"

class Tests
{
public:
	void test1()
	{
		CMscnProblem* c_mscn_problem = new CMscnProblem();

		c_mscn_problem->b_set_suppliers(2);
		c_mscn_problem->b_set_factories(2);
		c_mscn_problem->b_set_distributors(3);
		c_mscn_problem->b_set_shops(3);

		c_mscn_problem->b_set_val_sd(10, 0);
		c_mscn_problem->b_set_val_sd(10, 1);

		c_mscn_problem->b_set_val_sf(20, 0);
		c_mscn_problem->b_set_val_sf(20, 1);

		c_mscn_problem->b_set_val_sm(2, 0);
		c_mscn_problem->b_set_val_sm(2, 1);
		c_mscn_problem->b_set_val_sm(2, 2);

		c_mscn_problem->b_set_val_ss(100, 0);
		c_mscn_problem->b_set_val_ss(80, 1);
		c_mscn_problem->b_set_val_ss(50, 2);


		c_mscn_problem->b_set_val_cd(50, 0, 0);
		c_mscn_problem->b_set_val_cd(50, 0, 1);
		c_mscn_problem->b_set_val_cd(60, 1, 0);
		c_mscn_problem->b_set_val_cd(60, 1, 1);

		c_mscn_problem->b_set_val_cf(60, 0, 0);
		c_mscn_problem->b_set_val_cf(50, 0, 1);
		c_mscn_problem->b_set_val_cf(40, 0, 2);
		c_mscn_problem->b_set_val_cf(70, 1, 0);
		c_mscn_problem->b_set_val_cf(50, 1, 1);
		c_mscn_problem->b_set_val_cf(60, 1, 2);

		c_mscn_problem->b_set_val_cm(40, 0, 0);
		c_mscn_problem->b_set_val_cm(50, 0, 1);
		c_mscn_problem->b_set_val_cm(40, 0, 2);
		c_mscn_problem->b_set_val_cm(60, 1, 0);
		c_mscn_problem->b_set_val_cm(50, 1, 1);
		c_mscn_problem->b_set_val_cm(60, 1, 2);
		c_mscn_problem->b_set_val_cm(50, 2, 0);
		c_mscn_problem->b_set_val_cm(50, 2, 1);
		c_mscn_problem->b_set_val_cm(40, 2, 2);


		c_mscn_problem->b_set_val_ud(10, 0);
		c_mscn_problem->b_set_val_ud(10, 1);

		c_mscn_problem->b_set_val_uf(20, 0);
		c_mscn_problem->b_set_val_uf(20, 1);

		c_mscn_problem->b_set_val_um(10, 0);
		c_mscn_problem->b_set_val_um(10, 1);
		c_mscn_problem->b_set_val_um(10, 2);

		c_mscn_problem->b_set_val_ps(100, 0);
		c_mscn_problem->b_set_val_ps(100, 1);
		c_mscn_problem->b_set_val_ps(100, 2);


		double pdSolution[] = {
			// xd
			10, 20,
			30, 40,
			// xf
			50, 60, 70,
			80, 90, 100,
			// xm
			110, 120, 130,
			140, 150, 160,
			170, 180, 190
		};


		int size = sizeof(pdSolution) / sizeof(double);

		//cout << "size of solution table: " << size << endl;

		c_mscn_problem->bConstraintsSatisfied(pdSolution, size);

		cout << "error code value: " << c_mscn_problem->i_get_error_code() << endl;
		cout << "result: " << c_mscn_problem->dGetQuality(pdSolution, size) << endl;

		CSaveProblemToFile saver;
		saver.v_save_problem(c_mscn_problem, "CMscnProblemSaved.txt");

	}
	//void test1() 


	void test2()
	{
		CMscnProblem* c_mscn_problem2 = new CMscnProblem();

		CLoadProblemFromFile loader;
		loader.v_load_problem(c_mscn_problem2, "fileToLoad.txt");

		cout << "D: " << c_mscn_problem2->i_get_suppliers() << endl;
		cout << "F: " << c_mscn_problem2->i_get_factories() << endl;
		cout << "M: " << c_mscn_problem2->i_get_distributors() << endl;
		cout << "S: " << c_mscn_problem2->i_get_shops() << endl;

		CSaveProblemToFile saver;
		saver.v_save_problem(c_mscn_problem2, "secondSavedProblem.txt");

		delete c_mscn_problem2;
	}
	//void test2() 


	void test3()
	{
		CMscnProblem* c_mscn_problem3 = new CMscnProblem();
		CLoadProblemFromFile loader;
		loader.v_load_problem(c_mscn_problem3, "fileToLoad.txt");

		double pdSolution[] = {
			36, 82,
			32, 71,
			4.2, 54.7, 8.0, 15.5
		};

		int size = sizeof(pdSolution) / sizeof(double);
		c_mscn_problem3->bConstraintsSatisfied(pdSolution, size);

		cout << "error code value: " << c_mscn_problem3->i_get_error_code() << endl;
		cout << "result: " << c_mscn_problem3->dGetQuality(pdSolution, size) << endl;

	}
	//void test3()

	/*
	void randTest(int i_seed)
	{
		cout << "1st: \n";
		CRandom r1(i_seed);
		for (int ii = 0; ii < 20; ii++)
			cout << r1.iGenerateInt(0, 200) << endl;

		cout << "2nd: \n";
		CRandom r2(i_seed);
		for (int ii = 0; ii < 20; ii++)
			cout << r2.dGenerateDouble(0.00, 2.37) << endl;
	}
	//void randTest(int i_seed)
	*/

};
