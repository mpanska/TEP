#include "stdafx.h"


bool CLoadProblemFromFile::v_load_problem(CMscnProblem *pcProblem, string s_file_name) 
{
	file = ifstream(s_file_name, ios::in);

	if (file.is_open())
	{
		int i_value = 0;
		double d_value = 0.0;
		
		//reading suppliers
		s_get_string();
		i_value = this->i_get_int();
		pcProblem->b_set_suppliers(i_value);

		//factories
		s_get_string();
		i_value = this->i_get_int();
		pcProblem->b_set_factories(i_value);

		//distributors
		s_get_string();;
		i_value = this->i_get_int();
		pcProblem->b_set_distributors(i_value);

		//shops 
		s_get_string();
		i_value = this->i_get_int();
		pcProblem->b_set_shops(i_value);

		//reading sd
		s_get_string();
		for (int i = 0; i < pcProblem->i_get_suppliers(); i++)
		{
			d_value = this->d_get_double();
			pcProblem->b_set_val_sd(d_value, i);
		}

		// sf
		s_get_string();
		for (int j = 0; j < pcProblem->i_get_factories(); ++j)
		{
			d_value = this->d_get_double();
			pcProblem->b_set_val_sf(d_value, j);
		}

		// sm
		s_get_string();
		for (int i = 0; i < pcProblem->i_get_distributors(); i++)
		{
			d_value = this->d_get_double();
			pcProblem->b_set_val_sm(d_value, i);
		}

		// ss
		s_get_string();
		for (int i = 0; i < pcProblem->i_get_shops(); i++)
		{
			d_value = this->d_get_double();
			pcProblem->b_set_val_ss(d_value, i);
		}

		// ud
		s_get_string();
		for (int i = 0; i < pcProblem->i_get_suppliers(); i++)
		{
			d_value = this->d_get_double();
			pcProblem->b_set_val_ud(d_value, i);
		}

		// uf
		s_get_string();
		for (int i = 0; i < pcProblem->i_get_factories(); i++)
		{
			d_value = this->d_get_double();
			pcProblem->b_set_val_uf(d_value, i);
		}

		// um
		s_get_string();
		for (int i = 0; i < pcProblem->i_get_distributors(); i++)
		{
			d_value = this->d_get_double();
			pcProblem->b_set_val_um(d_value, i);
		}

		//reading the cd matrice
		s_get_string();
		for (int i = 0; i < pcProblem->i_get_suppliers(); i++)
		{
			for (int j = 0; j < pcProblem->i_get_factories(); j++) {
				d_value = this->d_get_double();
				pcProblem->b_set_val_cd(d_value, i, j);
			}
		}

		//reading the cf matrice
		s_get_string();
		for (int i = 0; i < pcProblem->i_get_factories(); i++)
		{
			for (int j = 0; j < pcProblem->i_get_distributors(); j++) {
				d_value = this->d_get_double();;
				pcProblem->b_set_val_cf(d_value, i, j);
			}
		}

		//reading the cm matrice
		s_get_string();
		for (int i = 0; i < pcProblem->i_get_distributors(); i++)
			for (int j = 0; j < pcProblem->i_get_shops(); j++) {
				d_value = this->d_get_double();
				pcProblem->b_set_val_cm(d_value, i, j);
			}

		// ps
		s_get_string();
		for (int i = 0; i < pcProblem->i_get_shops(); i++) {
			d_value = this->d_get_double();
			pcProblem->b_set_val_ps(d_value, i);
		}

		file.close();
		cout << "successfully loaded!" << endl;
		return true;
	}

	else 
	{
		cout << "something went wrong!" << endl;
		return false;
	}
}



string CLoadProblemFromFile::s_get_string() 
{
	string s_some_string;
	file >> s_some_string;
	return s_some_string;
}

double CLoadProblemFromFile::d_get_double() 
{
	double d_value;
	file >> d_value;
	return d_value;
}

int CLoadProblemFromFile::i_get_int() 
{
	int i_value;
	file >> i_value;
	return i_value;
}