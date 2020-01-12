#include "stdafx.h"

CMscnProblem::CMscnProblem()
{
	i_suppliers = 2;
	i_factories = 2;
	i_distributors = 3;
	i_shops = 3;

	d_sd = new double[i_suppliers];
	d_sf = new double[i_factories];
	d_sm = new double[i_distributors];
	d_ss = new double[i_shops];
	d_ps = new double[i_shops];

	d_cd = new double *[i_suppliers]; //rows
	for (int ii = 0; ii < i_suppliers; ii++)
		d_cd[ii] = new double[i_factories]; //columns

	d_cf = new double *[i_factories];
	for (int ii = 0; ii < i_factories; ii++)
		d_cf[ii] = new double[i_distributors];
	
	d_cm = new double *[i_distributors];
	for (int ii = 0; ii < i_distributors; ii++)
		d_cm[ii] = new double[i_shops];

	d_ps = new double[i_shops];
	d_ud = new double[i_suppliers];
	d_uf = new double[i_factories];
	d_um = new double[i_distributors];

	d_xd = new double *[i_suppliers];
	for (int ii = 0; ii < i_suppliers; ii++)
		d_xd[ii] = new double[i_factories];

	d_xf = new double *[i_factories];
	for (int ii = 0; ii < i_factories; ii++)
		d_xf[ii] = new double[i_distributors];

	d_xm = new double *[i_distributors];
	for (int ii = 0; ii < i_distributors; ii++)
		d_xm[ii] = new double[i_shops];
	
	i_error_code = DEFAULT_NO_ERROR;

	d_xdminmax = new double*[i_suppliers*2];
	for (int ii = 0; ii < i_suppliers*2; ii++)
		d_xdminmax[ii] = new double[i_factories];

	d_xfminmax = new double*[i_factories*2];
	for (int ii = 0; ii < i_factories*2; ii++)
		d_xfminmax[ii] = new double[i_distributors];

	d_xmminmax = new double*[i_distributors*2];
	for (int ii = 0; ii < i_distributors*2; ii++) 
		d_xmminmax[ii] = new double[i_shops];

}
//CMscnProblem::CMscnProblem(), constructor


CMscnProblem::~CMscnProblem()
{
		delete[] d_sd;
		delete[] d_sf;
		delete[] d_sm;
		delete[] d_ss;

		delete[] d_ud;
		delete[] d_uf;
		delete[] d_um;

		delete[] d_ps;

		for (int ii = 0; ii < i_suppliers; ii++)
			delete d_cd[ii];
		delete[] d_cd;
	
		for (int ii = 0; ii < i_factories; ii++)
			delete d_cf[ii];
		delete[] d_cf;
	
		for (int ii = 0; ii < i_distributors; ii++) 
			delete d_cm[ii];
		delete[] d_cm;

		for (int ii = 0; ii < i_suppliers; ii++)
			delete d_xd[ii];
		delete[] d_xd;

		for (int ii = 0; ii < i_factories; ii++)
			delete d_xf[ii];
		delete[] d_xf;

		for (int ii = 0; ii < i_distributors; ii++)
			delete d_xm[ii];
		delete[] d_xm;


		for (int ii = 0; ii < i_suppliers*2; ii++)
			delete d_xdminmax[ii];
		delete[] d_xdminmax;

		for (int ii = 0; ii < i_factories*2; ii++)
			delete d_xfminmax[ii];
		delete[] d_xfminmax;

		for (int ii = 0; ii < i_distributors*2; ii++)
			delete d_xmminmax[ii];
		delete[] d_xmminmax;
}
//CMscnProblem::~CMscnProblem(), destructor



//---------------------------------------zadanie 2-------------------------------------------------------------------

bool CMscnProblem ::b_set_suppliers(int i_s_amount)
{
	if ((i_s_amount <= 0) || (i_s_amount == i_suppliers))
		return false;

	i_suppliers = i_s_amount;

	b_resize_matrix(&d_cd, i_s_amount, i_factories);
	b_resize_table(&d_sd, i_s_amount);
	b_resize_table(&d_ud, i_s_amount);

	return true;
}
//bool CMscnProblem ::b_set_suppliers(int i_s_amount)


bool CMscnProblem::b_set_factories(int i_f_amount)
{
	if ((i_f_amount <= 0) || (i_f_amount == i_factories))
		return false;

	i_factories = i_f_amount;

	b_resize_matrix(&d_cd, i_suppliers, i_f_amount);
	b_resize_matrix(&d_cf, i_f_amount, i_distributors);
	b_resize_table(&d_sf, i_f_amount);
	b_resize_table(&d_uf, i_f_amount);
	
	return true;
}
//bool CMscnProblem::b_set_factories(int i_f_amount)


bool CMscnProblem::b_set_distributors(int i_d_amount)
{
	if ((i_d_amount <= 0) || (i_d_amount == i_distributors))
		return false;

	i_distributors = i_d_amount;

	b_resize_matrix(&d_cf, i_factories, i_d_amount);
	b_resize_matrix(&d_cm, i_d_amount, i_shops);
	b_resize_table(&d_sm, i_d_amount);
	b_resize_table(&d_um, i_d_amount);

	return true;
}
//bool CMscnProblem::b_set_distributors(int i_d_amount)


bool CMscnProblem::b_set_shops(int i_sh_amount)
{
	if ((i_sh_amount <= 0) || (i_sh_amount == i_shops))
		return false;

	i_shops = i_sh_amount;

	b_resize_matrix(&d_cm, i_distributors, i_sh_amount);
	b_resize_table(&d_ss, i_sh_amount);
	b_resize_table(&d_ps, i_sh_amount);
	
	return true;
}
//bool CMscnProblem::b_set_shops(int i_sh_amount)



//---------------------------------------zadanie 3---------------------------------------------------------------------

bool CMscnProblem:: b_set_val_cd(double d_val, int i_row, int i_column)
{
	if (i_row >= 0 && i_column >= 0 && d_val >= 0 && i_row < i_suppliers && i_column < i_factories)
	{
		d_cd[i_row][i_column] = d_val;
		return true;
	}
	else return false;
}
//bool CMscnProblem::b_set_val_cd(double d_val, int i_row, int i_column)


bool CMscnProblem::b_set_val_cf(double d_val, int i_row, int i_column)
{
	if (i_row >= 0 && i_column >= 0 && d_val >= 0 && i_row < i_factories && i_column < i_distributors)
	{
		d_cf[i_row][i_column] = d_val;
		return true;
	}
	else return false;
}
//bool CMscnProblem::b_set_val_cf(double d_val, int i_row, int i_column)


bool CMscnProblem::b_set_val_cm(double d_val, int i_row, int i_column)
{
	if (i_row >= 0 && i_column >= 0 && d_val >= 0 && i_row < i_distributors && i_column < i_shops)
	{
		d_cm[i_row][i_column] = d_val;
		return true;
	}
	else return false;
}
//bool CMscnProblem::b_set_val_cf(double d_val, int i_row, int i_column)


bool CMscnProblem::b_set_val_sd(double d_val, int i_index)
{
	if (i_index >= 0 && i_index < i_suppliers && d_val >= 0)
	{
		d_sd[i_index] = d_val;
		return true;
	}
	else return false;
}
//bool CMscnProblem::b_set_val_sd(double d_val, int i_index)


bool CMscnProblem::b_set_val_sf(double d_val, int i_index)
{
	if (i_index >= 0 && i_index < i_factories && d_val >= 0)
	{
		d_sf[i_index] = d_val;
		return true;
	}
	else return false;
}
//bool CMscnProblem::b_set_val_sf(double d_val, int i_index)


bool CMscnProblem::b_set_val_sm(double d_val, int i_index)
{
	if (i_index >= 0 && i_index < i_distributors && d_val >= 0)
	{
		d_sm[i_index] = d_val;
		return true;
	}
	else return false;
}
//bool CMscnProblem::b_set_val_sm(double d_val, int i_index)


bool CMscnProblem::b_set_val_ss(double d_val, int i_index)
{
	if (i_index >= 0 && i_index < i_shops && d_val >= 0)
	{
		d_ss[i_index] = d_val;
		return true;
	}
	else return false;
}
//bool CMscnProblem::b_set_val_sm(double d_val, int i_index)


bool CMscnProblem::b_set_val_ud(double d_val, int i_index) { //disposable cost of using supplier d
	if (i_index >= 0 && i_index < i_suppliers && d_val >= 0)
	{
		d_ud[i_index] = d_val;
		return true;
	}
	else return false;
}
//bool CMscnProblem::b_set_val_ud(double d_val, int i_index)


bool CMscnProblem::b_set_val_uf(double d_val, int i_index) { //current cost of using the factory f
	if (i_index >= 0 && i_index < i_factories && d_val >= 0)
	{
		d_uf[i_index] = d_val;
		return true;
	}
	else return false;
}
//bool CMscnProblem::b_set_val_uf(double d_val, int i_index) 


bool CMscnProblem::b_set_val_um(double d_val, int i_index) { //current cost of using the factory f
	if (i_index >= 0 && i_index < i_distributors && d_val >= 0)
	{
		d_um[i_index] = d_val;
		return true;
	}
	else return false;
}
//bool CMscnProblem::b_set_val_um(double d_val, int i_index)


bool CMscnProblem::b_set_val_ps(double d_val, int i_index) 
{
	if (i_index >= 0 && i_index < i_shops && d_val >= 0)
	{
		d_ps[i_index] = d_val;
		return true;
	}
	else return false;
}
//bool CMscnProblem::b_set_val_ps(double d_val, int i_index) 


//---------------------------------------zadanie 4---------------------------------------------------------------------


double CMscnProblem::dGetQuality(double *pdSolution, int i_solution_size)
{
	if (pdSolution == NULL) {
		i_error_code = DOESNT_EXIST;
		cout << "solution doesn't exist!\n";
		return i_error_code;
	}

	for (int ii = 0; ii < i_solution_size; ii++)
	{
		if (pdSolution[ii] < 0) {
			i_error_code = NEGATIVE_VALUES;
			cout << "values are less then zero!\n";
			return i_error_code;
		}
	}

	int i_required_size = i_suppliers * i_factories + i_factories * i_distributors + i_distributors * i_shops;

	if (i_solution_size > i_required_size || i_solution_size < i_required_size)
	{
		i_error_code = WRONG_SOLURION_SIZE;
		if (i_solution_size > i_required_size)
			cout << "solution size is longer then required! required size is:" << i_required_size << endl;
		if (i_solution_size < i_required_size)
			cout << "solution size is shorter then required! required size is:" << i_required_size << endl;

		return i_error_code;
	}

	v_fill_x_matrices(pdSolution);
	i_error_code = DEFAULT_NO_ERROR;
	return d_count_Z();
}
//double CMscnProblem::dGetQuality(double *pdSolution, int *i_error_code)


void CMscnProblem::v_fill_x_matrices(double *pdSolution)
{
	int ii = 0;

	for (int ij = 0; ij < i_suppliers; ij++) 
	{
		for (int ik = 0; ik < i_factories; ik++, ii++)
			d_xd[ij][ik] = pdSolution[ii];
	}
	for (int ij = 0; ij < i_factories; ij++)
	{
		for (int ik = 0; ik < i_distributors; ik++, ii++)
			d_xf[ij][ik] = pdSolution[ii];
	}
	for (int ij = 0; ij < i_distributors; ij++)
	{
		for (int ik = 0; ik < i_shops; ik++, ii++)
			d_xm[ij][ik] = pdSolution[ii];
	}
}
//void CMscnProblem::v_fill_x_matrices(double *pdSolution)


double CMscnProblem::d_count_Kt() 
{
	double d_Kt = 0;

	for (int ii = 0; ii < i_suppliers; ii++) 
	{
		for (int ij = 0; ij < i_factories; ij++)
			d_Kt += (d_cd[ii][ij] * d_xd[ii][ij]);
	}
	for (int i = 0; i < i_factories; i++) 
	{
		for (int j = 0; j < i_distributors; j++) 
			d_Kt += (d_cf[i][j] * d_xf[i][j]);
	}
	for (int ii = 0; ii < i_distributors; ii++)
	{
		for (int ij = 0; ij < i_shops; ij++) 
			d_Kt += (d_cm[ii][ij] * d_xm[ii][ij]);
	}
	cout << "Kt = " << d_Kt << endl;
	return d_Kt;
}
//double CMscnProblem::d_count_Kt() 


double CMscnProblem::d_count_Ku()
{
	double d_Ku = 0;
	bool b_continue = true;

	for (int ii = 0; ii < i_suppliers; ii++) {
		b_continue = true;
		for (int ij = 0; (ij < i_factories)&& b_continue; ij++)
		{
			if (d_xd[ii][ij] > 0) 
			{
				d_Ku += d_ud[ii];
				b_continue = false;
			}
				
		}
	}
	for (int ii = 0; ii < i_factories; ii++) {
		b_continue = true;
		for (int ij = 0; (ij < i_distributors)&& b_continue; ij++)
		{
			if (d_xf[ii][ij] > 0)
			{
				d_Ku += d_uf[ii];
				b_continue = false;
			}
		}
	}
	for (int ii = 0; ii < i_distributors; ii++) {
		b_continue = true;
		for (int ij = 0; (ij < i_shops)&& b_continue; ij++)
		{
			if (d_xm[ii][ij] > 0)
			{
				d_Ku += d_um[ii];
				b_continue = false;
			}
				
		}
	}
	cout << "Ku = " << d_Ku << endl;
	return d_Ku;
}
//double CMscnProblem::d_count_Ku()


double CMscnProblem::d_count_P()
{
	double d_P = 0;

	for (int ii = 0; ii < i_shops; ii++)
	{		
		for (int ij = 0; ij < i_distributors; ij++) 
			d_P += (d_xm[ij][ii] * d_ps[ii]);
	}
	cout << "p = " << d_P << endl;
	return d_P;
}
//double CMscnProblem::d_count_P()


double CMscnProblem::d_count_Z()
{
	double d_P = d_count_P();
	double d_Kt = d_count_Kt();
	double d_Ku = d_count_Ku();
	double d_Z = d_P - d_Kt - d_Ku;

	return d_Z;
}
//double CMscnProblem::d_count_Z()



//-------------------------------------------------------zadanie 5---------------------------------------------------------------

bool CMscnProblem::bConstraintsSatisfied(double *pdSolution, int i_solution_size)
{
	if (pdSolution == NULL) {
		i_error_code = DOESNT_EXIST;
		cout << "solution doesn't exist!\n";
		return false;
	}//-1

	for (int ii = 0; ii < i_solution_size; ii++)
	{
		if (pdSolution[ii] < 0) {
			i_error_code = NEGATIVE_VALUES;
			cout << "values are less then zero!\n";
			return false;
		}
	}//-2

	int i_required_size = i_suppliers * i_factories + i_factories * i_distributors + i_distributors * i_shops;
	if (i_solution_size > i_required_size || i_solution_size < i_required_size)
	{
		i_error_code = WRONG_SOLURION_SIZE;
		if (i_solution_size > i_required_size)
			cout << "solution size is longer then required! required size is:" << i_required_size << endl;
		if (i_solution_size < i_required_size)
			cout << "solution size is shorter then required! required size is:" << i_required_size << endl;

		return i_error_code;
	}//-3

	if (bMatriceIsSmaller(d_xd, d_sd, i_suppliers, i_factories) //sum ilosc surowca zamowienia u danego D nie przekracza jego mocy produkcyjnych sd
		&& bMatriceIsSmaller(d_xf, d_sf, i_factories, i_distributors) //s.i. produktow zamowienia w danej F nie przekracza mocy produkc. sf
		&& bMatriceIsSmaller(d_xm, d_sm, i_distributors, i_shops) //s.i. pr. zamow. pobierana z danego M nie przekracza jego pojemnosci sm
		&& bMatriceIsSmaller(d_xm, d_ss, i_distributors, i_shops) //s.i. pr. dostarczana do danego S nie przekracza zapotrzebowania rynkowego tego S ss
		&& bMatriceIsBigger(d_xd, d_xf, i_suppliers, i_factories, i_distributors) //
		&& bMatriceIsBigger(d_xf, d_xm, i_factories, i_distributors, i_shops)) 
	{
		cout << "constraints are satisfied" << endl;
		return true;
	}
		
	else {
		cout << "constraints are not satisfied" << endl;
		return false;
	}

}
//bool CMscnProblem::bConstraintsSatisfied(double *pdSolution, int i_solution_size)


//-------------------------------------------------------zadanie 6---------------------------------------------------------------

void CMscnProblem::vCheckMinMax(double *pdSolution, int i_solution_size)
{


}



//------------lab 10-----------nr 2----------------------------------------------------------------------------------------------

void CMscnProblem::vGenerateInstance(int iInstanceSeed)
{
	CRandom c_random(iInstanceSeed);

	//tablice sd,sf,sm,ss
	for (int ii = 0; ii < i_suppliers; ii++)
	{
		b_set_val_sd(c_random.dGenerateDouble(0.0, 20.0) , ii);
		cout << d_sd[ii] << " ";
	}
	cout << endl;
	
	for (int ii = 0; ii < i_factories; ii++)
	{
		b_set_val_sf(c_random.dGenerateDouble(0.0, 200.0),ii);
		cout << d_sf[ii] << " ";
	}
	cout << endl;
	
	for (int ii = 0; ii < i_distributors; ii++)
		b_set_val_sm(c_random.dGenerateDouble(0, 20), ii);

	for (int ii = 0; ii < i_shops; ii++)
		b_set_val_ss(c_random.dGenerateDouble(0, 20), ii);

	//macierze cd,cf,cm
	for (int ii = 0; ii < i_suppliers; ii++)
		for (int ij = 0; ij < i_factories; ij++)
			b_set_val_cd(c_random.dGenerateDouble(0, 20), ii, ij);

	for (int ii = 0; ii < i_factories; ii++) 
		for (int ij = 0; ij < i_distributors; ij++) 
			b_set_val_cf(c_random.dGenerateDouble(0, 20), ii, ij);
	
	for (int ii = 0; ii < i_distributors; ii++)
		for (int ij = 0; ij < i_shops; ij++)
			b_set_val_cm(c_random.dGenerateDouble(0, 20), ii, ij);

	//ud,uf,um
	for (int ii = 0; ii < i_suppliers; ii++)
		b_set_val_ud(c_random.dGenerateDouble(0.0, 20.0), ii);

	for (int ii = 0; ii < i_factories; ii++)
		b_set_val_uf(c_random.dGenerateDouble(0.0, 20.0), ii);

	for (int ii = 0; ii < i_distributors; ii++)
		b_set_val_um(c_random.dGenerateDouble(0.0, 20.0), ii);

	//ps
	for (int ii = 0; ii < i_shops; ii++)
		b_set_val_ps(c_random.dGenerateDouble(0.0, 20.0), ii);
	
	/*
	for (int i = 0; i < i_suppliers * 2; i += 2) {
		for (int j = 0; j < i_factories; j++) {
			
			bSetValInXdminmax(i, j, 0);
			bSetValInXdminmax(i + 1, j, min(pd_sd[i / 2], pd_sf[j]));
		}
	}

	for (int i = 0; i < 2 * i_F; i += 2) {
		for (int j = 0; j < i_M; j++) {
			double d_d_to_f_max = 0;
			for (int k = 1; k < 2 * i_D; k += 2) {
				d_d_to_f_max += ppd_xdminmax[k][i / 2];
			}

			bSetValInXfminmax(i, j, 0);
			double d_max_correct_val = min(pd_sf[i / 2], pd_sm[j]);
			bSetValInXfminmax(i + 1, j, min(d_max_correct_val, d_d_to_f_max));
		}
	}
	for (int i = 0; i < 2 * i_M; i += 2) {
		for (int j = 0; j < i_S; j++) {
			double d_f_to_m_max = 0;
			for (int k = 1; k < 2 * i_F; k += 2) {
				d_f_to_m_max += ppd_xfminmax[k][i / 2];
			}

			bSetValInXmminmax(i, j, 0);
			double d_max_correct_val = min(pd_sm[i / 2], pd_ss[j]);
			bSetValInXmminmax(i + 1, j, min(d_max_correct_val, d_f_to_m_max));
		}
	}
	*/
}