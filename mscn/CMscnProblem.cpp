#include "stdafx.h"
using namespace std;

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
			//cout << "values are less then zero!\n";
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

	vFixSolution(pdSolution);

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
	//cout << "Kt = " << d_Kt << endl;
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
	//cout << "Ku = " << d_Ku << endl;
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
	//cout << "p = " << d_P << endl;
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
			//cout << "values are less then zero!\n";
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

	if (bMatriceIsSmaller(d_xd, d_sd, i_suppliers, i_factories) && bMatriceIsSmaller(d_xf, d_sf, i_factories, i_distributors) 
		&& bMatriceIsSmaller(d_xm, d_sm, i_distributors, i_shops) && bMatriceIsSmaller(d_xm, d_ss, i_distributors, i_shops)
		&& bMatriceIsBigger(d_xd, d_xf, i_suppliers, i_factories, i_distributors) && bMatriceIsBigger(d_xf, d_xm, i_factories, i_distributors, i_shops)) 
	{
		//cout << "constraints are satisfied" << endl;
		return true;
	}
	else {
		//cout << "constraints are not satisfied" << endl;
		return false;
	}
}
//bool CMscnProblem::bConstraintsSatisfied(double *pdSolution, int i_solution_size)


//-------------------------------------------------------zadanie 6---------------------------------------------------------------
bool CMscnProblem::b_set_xd_minmax(double d_val, int i_row, int i_column)
{
	if (i_row >= 0 && i_column >= 0 && d_val >= 0 && i_row < i_suppliers*2 && i_column < i_factories)
	{
		d_xdminmax[i_row][i_column] = d_val;
		return true;
	}
	else return false;
}
//bool CMscnProblem::b_set_xd_minmax(double d_val, int i_row, int i_column)

bool CMscnProblem::b_set_xf_minmax(double d_val, int i_row, int i_column)
{
	if (i_row >= 0 && i_column >= 0 && d_val >= 0 && i_row < i_factories*2 && i_column < i_distributors)
	{
		d_xfminmax[i_row][i_column] = d_val;
		return true;
	}
	else return false;
}
//bool CMscnProblem::b_set_xf_minmax(double d_val, int i_row, int i_column)
	
bool CMscnProblem::b_set_xm_minmax(double d_val, int i_row, int i_column)
{
	if (i_row >= 0 && i_column >= 0 && d_val >= 0 && i_row < i_distributors*2 && i_column < i_shops)
	{
		d_xmminmax[i_row][i_column] = d_val;
		return true;
	}
	else return false;
}
//bool CMscnProblem::b_set_xm_minmax(double d_val, int i_row, int i_column)


double CMscnProblem::d_check_min(int i_index) 
{
	if (i_index < 0 || i_index >= i_required_solution_size())
	{
		cout << "given index is less the zero or greater than solution size!" << endl;
		return -1;
	}

	int i_xd_size = i_suppliers * i_factories;
	int i_xf_size = i_factories * i_distributors;

	if (i_index < i_xd_size)
		return d_xdminmax[2 * (i_index / i_factories)][i_index % i_factories];

	if (i_index < i_xd_size + i_xf_size)
	{
		int index_in_xf = i_index - i_xd_size;
		return d_xfminmax[2 * (index_in_xf / i_distributors)][index_in_xf % i_distributors];
	}

	int index_in_xm = i_index - (i_xd_size + i_xf_size);
	return d_xmminmax[2 * (index_in_xm / i_shops)][index_in_xm % i_shops];
}
//double CMscnProblem::d_check_min(int i_index) 

double CMscnProblem::d_check_max(int i_index)
{
	if (i_index < 0 || i_index >= i_required_solution_size())
	{
		cout << "given index is less the zero or greater than solution size!" << endl;
		return -1;
	}

	int i_xd_size = i_suppliers * i_factories;
	int i_xf_size = i_factories * i_distributors;

	if (i_index < i_xd_size)
		return d_xdminmax[1 + 2 * (i_index / i_factories)][i_index % i_factories];

	if (i_index < i_xd_size + i_xf_size)
	{
		int index_in_xf = i_index - i_xd_size;
		return d_xfminmax[1 + 2 * (index_in_xf / i_distributors)][index_in_xf % i_distributors];
	}
	
	int index_in_xm = i_index - (i_xd_size + i_xf_size);
	return d_xmminmax[1 + 2 * (index_in_xm / i_shops)][index_in_xm % i_shops];
}
//double CMscnProblem::d_check_max(int i_index)


//------------lab 10-----------nr 2----------------------------------------------------------------------------------------------

void CMscnProblem::vGenerateInstance(int iInstanceSeed)
{
	CRandom c_random(iInstanceSeed);

	//tablice sd,sf,sm,ss
	for (int ii = 0; ii < i_suppliers; ii++)
		b_set_val_sd(c_random.dGenerateDouble(SD_MIN, SD_MAX) , ii);
	
	for (int ii = 0; ii < i_factories; ii++)
		b_set_val_sf(c_random.dGenerateDouble(SF_MIN, SF_MAX),ii);

	for (int ii = 0; ii < i_distributors; ii++)
		b_set_val_sm(c_random.dGenerateDouble(SM_MIN, SM_MAX), ii);

	for (int ii = 0; ii < i_shops; ii++)
		b_set_val_ss(c_random.dGenerateDouble(SS_MIN, SS_MAX), ii);

	//macierze cd,cf,cm
	for (int ii = 0; ii < i_suppliers; ii++)
		for (int ij = 0; ij < i_factories; ij++)
			b_set_val_cd(c_random.dGenerateDouble(CD_MIN, CD_MAX), ii, ij);

	for (int ii = 0; ii < i_factories; ii++) 
		for (int ij = 0; ij < i_distributors; ij++) 
			b_set_val_cf(c_random.dGenerateDouble(CF_MIN, CF_MAX), ii, ij);
	
	for (int ii = 0; ii < i_distributors; ii++)
		for (int ij = 0; ij < i_shops; ij++)
			b_set_val_cm(c_random.dGenerateDouble(CM_MIN, CM_MAX), ii, ij);

	//ud,uf,um
	for (int ii = 0; ii < i_suppliers; ii++)
		b_set_val_ud(c_random.dGenerateDouble(UD_MIN, UD_MAX), ii);

	for (int ii = 0; ii < i_factories; ii++)
		b_set_val_uf(c_random.dGenerateDouble(UF_MIN, UF_MAX), ii);

	for (int ii = 0; ii < i_distributors; ii++)
		b_set_val_um(c_random.dGenerateDouble(UM_MIN, UM_MAX), ii);

	//ps
	for (int ii = 0; ii < i_shops; ii++)
		b_set_val_ps(c_random.dGenerateDouble(PS_MIN, PS_MAX), ii);
	
	//xd_minmax 
	for (int ii = 0; ii < i_suppliers * 2; ii += 2) 
	{
		for (int ij = 0; ij < i_factories; ij++) 
		{	
			b_set_xd_minmax(XDMINMAX_MIN, ii, ij);
			b_set_xd_minmax(min(d_sd[ii / 2], d_sf[ij]), ii + 1, ij);
		}
	}
	//xf_minmax
	for (int ii = 0; ii < 2 * i_factories; ii += 2) 
	{
		for (int ij = 0; ij < i_distributors; ij++) 
		{
			double d_f_max = 0;
			for (int ik = 1; ik < 2 * i_suppliers; ik += 2) 
				d_f_max += d_xdminmax[ik][ii / 2]; 
			
			double d_max = min(d_sf[ii / 2], d_sm[ij]);

			b_set_xf_minmax(XFMINMAX_MIN, ii, ij);
			b_set_xf_minmax(min(d_max, d_f_max), ii + 1, ij);
		}
	}
	//xm_minmax
	for (int ii = 0; ii < 2 * i_distributors; ii += 2) 
	{
		for (int ij = 0; ij < i_shops; ij++) 
		{
			double f_m_max = 0;
			for (int k = 1; k < 2 * i_factories; k += 2) 
				f_m_max += d_xfminmax[k][ii / 2];
			
			b_set_xm_minmax(XMMINMAX_MIN,ii, ij);
			double d_max = min(d_sm[ii / 2], d_ss[ij]);
			b_set_xm_minmax(min(d_max, f_m_max),ii + 1, ij);
		}
	}
}
//void CMscnProblem::vGenerateInstance(int iInstanceSeed)


//------------------------------lab 12-----------------------------------------------------

void CMscnProblem::vFixSolution(double *pdSolution)
{
	double d_xd_sum = 0;
	double d_xf_sum = 0;
	double d_xm_sum = 0;
	double d_sum_d_to_f = 0;
	double d_sum_f_to_m = 0;
	double d_sum_m_to_s = 0;
	double d_total_sum_xm = 0;
	int i_index = 0; 

	//przechodzenie po macierzy xd
	for (int ii = 0; ii < i_suppliers; ii++)  //przechodzimy po D
	{
		for (int ij = 0; ij < i_factories; ij++) //przechodzimy po F
		{
			if (pdSolution[i_index] >= 0) 
			{
				d_xd_sum += pdSolution[i_index]; 
				i_index++;	//iterujemy po solution
			}
			else {
				pdSolution[i_index] = d_check_min(i_index); //inaczej sprawdzamy jaka jest naj< dopuszczalna wartosc
				d_xd_sum += pdSolution[i_index];   // i dodajemy ten minimum do sumy xd
				i_index++;
			}
		}//tu szukalismy sume wartosci w xd

		while (d_xd_sum > d_sd[ii]) //dopoki suma surowca zamowiona i danego dostawcy przekracza mocy produkcyjne - regulujemy
		{
			i_index -= i_factories; //wracamy na poczatek naszego pdSolution

			for (int ij = 0; ij < i_factories; ij++) //przechodzimy po F
			{
				if (pdSolution[i_index] * REDUCE > d_check_min(i_index)) //jezeli wartosc przez parametr REDUCE > minimuma
				{
					//suma = current suma  - to co jest w komorce pdSolution na parametr redukcji
					d_xd_sum -= pdSolution[i_index] * REDUCE; //od sumy odejmujemy wartosc pdSol (tzn zmniejszamy na 85%)
					pdSolution[i_index] *= REDUCE; //zmniejszamy na 15% wartosc w pdSol
					i_index++;
				}
				else {
					d_xd_sum -= (pdSolution[i_index] - d_check_min(i_index)); //jezeli tak wyjdzie < minimuma
					pdSolution[i_index] = d_check_min(i_index); //ustawiamy po prostu minimum
					i_index++;
				}
			}
		}
		d_xd_sum = 0; //zerujemy sume i przechodzimy do nastepnego rzedu
	}

	//przejscie po macierzy xf
	for (int ii = 0; ii < i_factories; ii++) //przejscie po rzedach
	{
		for (int ij = 0; ij < i_distributors; ij++)
		{
			if (pdSolution[i_index] >= 0) //jesli watrosc pod tym indeksem jest niezerowa
			{
				d_xf_sum += pdSolution[i_index];
				i_index++;
			}
			else {
				pdSolution[i_index] = d_check_min(i_index); //jezeli wartosc < 0 to ustawiamy jako min
				d_xf_sum += pdSolution[i_index];
				i_index++;
			}
		}//tu szukamy sumy wartosci w xf

		while (d_xf_sum > d_sf[ii]) //dopoki suma prod. zamowionych w danej F przekracza mocy produkcyjne
		{
			i_index -= i_distributors; //wracamy na poczatek

			for (int ij = 0; ij < i_distributors; ij++) //przechodzimy po D
			{
				if (pdSolution[i_index] * REDUCE > d_check_min(i_index)) //jezeli wartosc przez parametr reduce > minimalnej
				{
					d_xf_sum -= pdSolution[i_index] * REDUCE; // zmniejszamy sume na wartosc zmniejszona o 85%
					pdSolution[i_index] *= REDUCE; //zmniejszyc na 15%
					i_index++;
				}
				else {
					d_xf_sum -= (pdSolution[i_index] - d_check_min(i_index)); //inaczej zmniejszamy sume o pdSol[i] - min wart dla tego indexu
					pdSolution[i_index] = d_check_min(i_index);
					i_index++;
				}
			}
		}
		d_xf_sum = 0; //zerujemy sume i przechodzimy do nastepego rzedu
	}

	//przejscie po macierzy xm
	for (int ii = 0; ii < i_distributors; ii++)
	{
		for (int ij = 0; ij < i_shops; ij++)
		{
			if (pdSolution[i_index] >= 0)
			{
				d_xm_sum += pdSolution[i_index];
				i_index++;
			}
			else {
				pdSolution[i_index] = d_check_min(i_index);
				d_xm_sum += pdSolution[i_index];
				i_index++;
			}
		}//zsumowac xm

		while (d_xm_sum > d_sm[ii]) //dopoki przekracza pojemnosc sm
		{
			i_index -= i_shops; //wracamy na poczatek

			for (int ij = 0; ij < i_shops; ij++)
			{
				if (pdSolution[i_index] * REDUCE > d_check_min(i_index))
				{
					d_xm_sum -= pdSolution[i_index] * REDUCE;
					pdSolution[i_index] *= REDUCE;
					i_index++;
				}
				else {
					d_xm_sum -= (pdSolution[i_index] - d_check_min(i_index));
					pdSolution[i_index] = d_check_min(i_index);
					i_index++;
				}
			}
		}
		d_xm_sum = 0; //zerujemy i przechodzimy do nastepnego rzedu
	}

	//teraz bedziemy sumowac macierz xm do sprawdzenia czy nie przekracza ss
	d_xm_sum = 0; //zerujemy sume xm
	i_index = i_suppliers * i_factories + i_factories * i_distributors;

	for (int ii = 0; ii < i_shops; ii++)
	{
		for (int ij = 0; ij < i_distributors; ij++)
			d_xm_sum += pdSolution[i_index + i_shops * ij]; //sumujemy wartosci z xm

		while (d_xm_sum > d_ss[ii]) //poki przekracza zapotrzebowanie rynkowe
		{
			for (int ij = 0; ij < i_distributors; ij++)
			{
				if (pdSolution[i_index + i_distributors * ij] * REDUCE > d_check_min(i_index + i_distributors * ij)) //jezeli dla tej pozycji wiecej niz min
				{
					d_xm_sum -= pdSolution[i_index + i_distributors * ij] * REDUCE; //zmniejszamy sume
					pdSolution[i_index + i_distributors * ij] *= REDUCE;
				}
				else {//inaczej zmniejszamy sume na cos z pdSol - min wartosc dla tej pozycji
					d_xm_sum -= (pdSolution[i_index + i_distributors * ij] - d_check_min(i_index + i_distributors * ij));
					pdSolution[i_index + i_distributors * ij] = d_check_min(i_index + i_distributors * ij);
				}
			}
		}
		d_xm_sum = 0; //zerujemy i przechodzimy po nastepnym rzedzie
	}


	//xf contra xm OGARNIJ CO TU SIE DZIEJE
	for (int ii = 0; ii < i_distributors; ii++) //dla kazdego m = 1 ... M
	{
		for (int ij = 0; ij < i_factories; ij++) //suma xf
			d_sum_f_to_m += pdSolution[i_suppliers * i_factories + ii + ij * i_factories];

		for (int ij = 0; ij < i_shops; ij++)  //suma xm
			d_sum_m_to_s += pdSolution[i_suppliers * i_factories + i_factories * i_distributors + ii * i_shops + ij];

		while (d_sum_f_to_m < d_sum_m_to_s) //dopoki xf , xm (a ma byc xf >= xm)
		{
			for (int ij = 0; ij < i_factories; ij++)// zwieksza; dla xf
			{
				i_index = i_suppliers * i_factories + ii + ij * i_factories;
				if (pdSolution[i_index] == 0)
					pdSolution[i_index] = (d_check_max(i_index) - d_check_min(i_index)) / 2;

				if (pdSolution[i_index] * INCREASE < d_check_max(i_index)) //jezeli powiekszona wartosc nie przekracza dopuszczalnej wartosci
				{
					d_sum_f_to_m += pdSolution[i_index] * INCREASE; //TODO???????????????????????????
					pdSolution[i_index] *= INCREASE;
					i_index++;
				}
				else {
					d_sum_f_to_m += (d_check_max(i_index) - pdSolution[i_index]);
					pdSolution[i_index] = d_check_max(i_index);
					i_index++;
				}
			}

			if (d_sum_f_to_m < d_sum_m_to_s) //zmniejsza
			{
				for (int ij = 0; ij < i_shops; ij++)
				{
					i_index = i_suppliers * i_factories + i_factories * i_distributors + ii * i_shops + ij;
					if (pdSolution[i_index] * REDUCE > d_check_min(i_index))
					{
						d_sum_m_to_s -= pdSolution[i_index] * REDUCE;
						pdSolution[i_index] *= REDUCE;
						i_index++;
					}
					else {
						d_sum_m_to_s -= pdSolution[i_index] - d_check_min(i_index);
						pdSolution[i_index] = d_check_min(i_index);
						i_index++;
					}
				}
			}
		}
		d_sum_f_to_m = 0;
		d_sum_m_to_s = 0;
	}

	//przejscie po xd i xf
	for (int ii = 0; ii < i_factories; ii++)
	{
		for (int ij = 0; ij < i_suppliers; ij++) //sumowanie xd
			d_sum_d_to_f += pdSolution[ii + ij * i_factories];

		for (int ij = 0; ij < i_distributors; ij++) //sumowanie xf
			d_sum_f_to_m += pdSolution[i_suppliers * i_factories + ii * i_distributors + ij];

		while (d_sum_d_to_f < d_sum_f_to_m) //dopoki xd < xf (a ma byc >=)
		{
			for (int ij = 0; ij < i_suppliers; ij++) //dla xd
			{
				i_index = ii + ij * i_factories; //ii - glowna petla; -> ind = sups na facts

				if (pdSolution[i_index] == 0) //jezeli wydarzyla sie zerowa wartosc
					pdSolution[i_index] = (d_check_max(i_index) - d_check_min(i_index)) / 2; //sprawdzamy min max dla tej pozycji ?????????????

				if (pdSolution[i_index] * INCREASE < d_check_max(i_index)) //jezeli podwiekszona wart. nie przekracza dopuszczalnej wartosci
				{
					d_sum_d_to_f += pdSolution[i_index] * INCREASE; //zwiekszamy sume
					pdSolution[i_index] *= INCREASE;
					i_index++;
				}
				else {//jezeli przekracza
					d_sum_d_to_f += (d_check_max(i_index) - pdSolution[i_index]); //do sumy dodajemy maks war - watr na indeksie
					pdSolution[i_index] = d_check_max(i_index); //do solution wstawiamy maks wartosc
					i_index++;
				}
			}
		}
		d_sum_d_to_f = 0;
		d_sum_f_to_m = 0;
	}
}
//void CMscnProblem::vFixSolution(double *pdSolution)


void CMscnProblem::vShowSolution(double *pdSolution) 
{
	int i_index = 0;
	cout << "D: " << i_suppliers << endl;
	cout << "F: " << i_factories << endl;
	cout << "M: " << i_distributors << endl;
	cout << "S: " << i_shops << endl;

	cout << "xd" << endl;
	for (int ii = 0; ii < i_suppliers; ii++) 
	{
		for (int ij = 0; ij < i_factories; ij++) 
			cout << pdSolution[i_index++] << "   ";
	}

	cout << "\nxf" << endl;
	for (int ii = 0; ii < i_factories; ii++)
	{
		for (int ij = 0; ij < i_distributors; ij++) 
			cout << pdSolution[i_index++] << "   ";
	}

	cout << "\nxm" << endl;
	for (int ii = 0; ii < i_distributors; ii++) 
	{
		for (int ij = 0; ij < i_shops; ij++) 
			cout << pdSolution[i_index++] << "   ";
	}

	cout << endl;
}
//void CMscnProblem::vShowSolution(double *pdSolution) 