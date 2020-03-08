#include "stdafx.h"

bool CSaveProblemToFile::v_save_problem(CMscnProblem *pcProblem, string s_file_name)
{
	file.open(s_file_name);

	if (file.is_open()) 
	{
		file << "D: ";
		b_save_value(pcProblem->i_get_suppliers());
		file << "F: ";
		b_save_value(pcProblem->i_get_factories());
		file << "M: ";
		b_save_value(pcProblem->i_get_distributors());
		file << "S: ";
		b_save_value(pcProblem->i_get_shops());

		file << "sd:\n";
		b_save_array(pcProblem->d_get_sd(), pcProblem->i_get_suppliers());
		file << "sf:\n";
		b_save_array(pcProblem->d_get_sf(), pcProblem->i_get_factories());
		file << "sm:\n";
		b_save_array(pcProblem->d_get_sm(), pcProblem->i_get_distributors());
		file << "ss:\n";
		b_save_array(pcProblem->d_get_ss(), pcProblem->i_get_shops());

		file << "ud:\n";
		b_save_array(pcProblem->d_get_ud(), pcProblem->i_get_suppliers());
		file << "uf:\n";
		b_save_array(pcProblem->d_get_uf(), pcProblem->i_get_factories());
		file << "um:\n";
		b_save_array(pcProblem->d_get_um(), pcProblem->i_get_distributors());

		file << "cd:\n";
		b_save_matrice(pcProblem->d_get_cd(), pcProblem->i_get_suppliers(), pcProblem->i_get_factories());
		file << "cf:\n";
		b_save_matrice(pcProblem->d_get_cf(), pcProblem->i_get_factories(), pcProblem->i_get_distributors());
		file << "cm:\n";
		b_save_matrice(pcProblem->d_get_cm(), pcProblem->i_get_distributors(), pcProblem->i_get_shops());

		file << "p:\n";
		b_save_array(pcProblem->d_get_ps(), pcProblem->i_get_shops());


		file << "xd:\n";
		b_save_matrice(pcProblem->d_get_xd(), pcProblem->i_get_suppliers(), pcProblem->i_get_factories());
		file << "xf:\n";
		b_save_matrice(pcProblem->d_get_xf(), pcProblem->i_get_factories(), pcProblem->i_get_distributors());
		file << "xm:\n";
		b_save_matrice(pcProblem->d_get_xm(), pcProblem->i_get_distributors(), pcProblem->i_get_shops());

		file << "xd_minmax:\n";
		b_save_matrice(pcProblem->d_get_xd_minmax(), (pcProblem->i_get_suppliers())*2, pcProblem->i_get_factories());
		file << "xf_minmax:\n";
		b_save_matrice(pcProblem->d_get_xf_minmax(),(pcProblem->i_get_factories())*2, pcProblem->i_get_distributors());
		file << "xm_minmax:\n";
		b_save_matrice(pcProblem->d_get_xm_minmax(), (pcProblem->i_get_distributors())*2, pcProblem->i_get_shops());

		file.close();
		cout << "saved successfully!" << endl;
		return true;
	}

	else 
	{
		cout << "something went wrong! Unable save to file" << endl;
		return false;
	}
}
//bool CSaveProblemToFile::b_save_problem()


bool CSaveProblemToFile::b_save_value(double d_val)
{
	if (file.is_open())
	{
		file << d_val;
		file << "\n";
		return true;
	}
	else return false;
}
//bool CSaveProblemToFile::b_save_value(double d_val)


bool CSaveProblemToFile::b_save_array(double* d_array, int i_size)
{
	if (file.is_open())
	{
		for (int ii = 0; ii < i_size; ii++) 
		{
			file << d_array[ii];
			file << " ";
		}
		file << "\n";
		return true;
	}
	else return false;
}
//bool CSaveProblemToFile::b_save_array(double* d_array, int i_size)


bool CSaveProblemToFile::b_save_matrice(double** d_matrice, int i_rows, int i_cols)
{
	if (file.is_open())
	{
		for (int ii = 0; ii < i_rows; ii++) 
		{
			for (int ij = 0; ij < i_cols; ij++)
			{
				//cout << d_matrice[ii][ij] << endl;
				file << d_matrice[ii][ij];
				file << " ";
			}
			file << "\n";
		}
		return true;
	}
	else return false;
}
//bool CSaveProblemToFile::b_save_matrice(double** d_matrice, int i_rows, int i_cols)