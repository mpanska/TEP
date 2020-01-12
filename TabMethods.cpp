#include "stdafx.h"

bool CMscnProblem::b_resize_table(double **d_table, int i_new_size)
{
	if (d_table == NULL || i_new_size <= 0)
		return false;
	else
	{
		double *d_new_table = new double[i_new_size];

		for (int ii = 0; ii < i_new_size; ii++) 
			d_new_table[ii] = (*d_table)[ii];

		delete[] *d_table;
		*d_table = d_new_table;
	}
	return true;
}
//bool CMscnProblem::v_resize_table(double **d_table, int i_new_size)


bool CMscnProblem::b_resize_matrix(double ***d_matrix, int i_rows, int i_columns)
{
	if (i_rows <= 0 || i_columns <= 0 || d_matrix == NULL)
		return false;

	double **d_new_matrix = new double*[i_rows];
	for (int ii = 0; ii < i_rows; ii++) { d_new_matrix[ii] = new double[i_columns]; }
		
	int i_old_rows = sizeof(d_matrix) / sizeof(d_matrix[0]);
	int i_old_cols = sizeof(d_matrix[0]) / sizeof(double);

	for (int ii = 0; ii < i_old_rows; ii++)
	{
		for (int ij = 0; ij < i_old_cols; ij++)
			(*d_matrix)[ii][ij] = d_new_matrix[ii][ij];
	}
	
	for (int ii = 0; ii < i_old_rows; ii++)
		delete[](*d_matrix)[ii];
	delete[](*d_matrix);

	*d_matrix = d_new_matrix;

	return true;
}
//bool CMscnProblem::b_resize_matrix(double ***d_matrix, int i_rows, int i_columns)



bool CMscnProblem::bMatriceIsSmaller(double** d_matrice, double* d_array, int i_row, int i_column)
{
	double d_sum = 0; //sum of values in given row

	for (int ii = 0; ii < i_row; ii++)
	{
		for (int ij = 0; ij < i_column; ij++) {
			if (d_matrice[ii][ij] < 0)
				return false;

			d_sum += d_matrice[ii][ij];
		}
		if (d_array[ii] < 0 || d_sum > d_array[ii])
			return false;
	}
	return true;
}
//bool CMscnProblem::bMatriceIsSmaller(double** d_matrice, double* d_array, int i_row, int i_column)


bool CMscnProblem::bMatriceIsBigger(double** d_first_matrice, double** d_second_matrice, int i_row_first, int i_col_first, int i_row_second)
{
	double d_sum_first = 0; //sumOfValsFromOneColumn
	double d_sum_second = 0; //sumOfValsFromOneRow
	for (int i = 0; i < i_col_first; i++) 
	{
		for (int j = 0; j < i_row_first; j++) 
		{
			if (d_first_matrice[j][i] < 0)
				return false;
			d_sum_first += d_first_matrice[j][i];
		}
		for (int j = 0; j < i_row_second; j++) 
		{
			if (d_second_matrice[i][j] < 0)
				return false;
			d_sum_second += d_second_matrice[i][j];
		}
	}
	if (d_sum_first < d_sum_second)
		return false;

	return true;
}
//bool CMscnProblem::bMatriceIsBigger(double** d_first_matrice, double** d_second_matrice, int i_row_first, int i_col_first, int i_row_second)



