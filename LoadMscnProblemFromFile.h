#ifndef LOADMSCNPROBLEMFROMFILE_H
#define LOADMSCNPROBLEMFROMFILE_H

#include "stdafx.h"

class CLoadProblemFromFile 
{
public:

	bool v_load_problem(CMscnProblem *pcProblem, string s_file_name);

private:

	ifstream file;

	int i_get_int();
	double d_get_double();
	string s_get_string();
};

#endif