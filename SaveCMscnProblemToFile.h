#ifndef SAVECMSCMPROBLEMTOFILE_H
#define SAVECMSCMPROBLEMTOFILE_H

#include "stdafx.h"

class CSaveProblemToFile 
{
public:

	bool v_save_problem(CMscnProblem *pcProblem, string s_file_name);
	
private:

	bool b_save_matrice(double** d_matrice, int rows, int cols);
	bool b_save_array(double* d_array, int i_size);
	bool b_save_value(double d_val);

	ofstream file;
};
#endif
