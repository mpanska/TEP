#ifndef CMSCNPROBLEM_H
#define CMSCNPROBLEM_H

#define DEFAULT_NO_ERROR 0;
#define DOESNT_EXIST -1;
#define NEGATIVE_VALUES -2;
#define WRONG_SOLURION_SIZE -3;

#include "stdafx.h"

class CMscnProblem 
{
public:

	CMscnProblem();
	~CMscnProblem();

	//getters and setters:
	int i_get_error_code() const { return i_error_code; }

	int i_get_suppliers() const { return i_suppliers; };
	bool b_set_suppliers(int i_s_amount);
	int i_get_factories() const { return i_factories; };
	bool b_set_factories(int i_f_amount);
	int i_get_distributors() const { return i_distributors; };
	bool b_set_distributors(int i_d_amount);
	int i_get_shops() const { return i_shops; };
	bool b_set_shops(int i_sh_amount);
	double* d_get_sd() const { return d_sd; };
	double* d_get_sf() const { return d_sf; };
	double* d_get_sm() const { return d_sm; };
	double* d_get_ss() const { return d_ss; };
	double* d_get_ud() const { return d_ud; };
	double* d_get_uf() const { return d_uf; };
	double* d_get_um() const { return d_um; };
	double* d_get_ps() const { return d_ps; };

	double** d_get_cd() const { return d_cd; };
	double** d_get_cf() const { return d_cf; };
	double** d_get_cm() const { return d_cm; };

	double** d_get_xd() const { return d_xd; };
	double** d_get_xf() const { return d_xf; };
	double** d_get_xm() const { return d_xm; };
		

	//setting values at offsets:
	bool b_set_val_sd(double d_val, int i_index);
	bool b_set_val_sf(double d_val, int i_index);
	bool b_set_val_sm(double d_val, int i_index);
	bool b_set_val_ss(double d_val, int i_index);
	bool b_set_val_cd(double d_val, int i_row, int i_column);
	bool b_set_val_cf(double d_val, int i_row, int i_column);
	bool b_set_val_cm(double d_val, int i_row, int i_column);
	bool b_set_val_ud(double d_val, int i_index);
	bool b_set_val_uf(double d_val, int i_index);
	bool b_set_val_um(double d_val, int i_index);
	bool b_set_val_ps(double d_val, int i_index);

	double dGetQuality(double *pdSolution, int i_solution_size);
	bool bConstraintsSatisfied(double *pdSolution, int i_solution_size);
	
	void vCheckMinMax(double *pdSolution, int i_solution_size);

	void vGenerateInstance(int iInstanceSeed);

private:

	int i_error_code;

	int i_suppliers;   // D - liczba dostawcow
	int i_factories;    // F - l. fabryk
	int i_distributors; // M - l. centrow dystrybucji, magazyn
	int i_shops;        // S - l. sklepow

	//macierze:
	double** d_cd;     // D x F  // dostawca -> fabryka (koszt wytworzenia i przewiezienia surowca od D do F)
	double** d_cf;     // F x M  // fabryka -> magazyn (koszt wyprod. produktu w F i przewiezienia do M)
	double** d_cm;     // m x S  //magazyn -> sklep (k. przechowania prod. w M i przewozenia do S)
	double** d_xd;      //ilosc surowca wytwarzana u D i transportowana do F        
	double** d_xf;     //ilosc produktow wytw. w F i transp. do M             
	double** d_xm;    //ilosc produktow przechowywana w M i transportowana do S  

	//tablice
	double* d_sd;     //moc produkcyjna danego dostawcy D      
	double* d_sf;    // moc produkcyjna fabryki F              
	double* d_sm;    // pojemnosc magazynu M                 
	double* d_ss;     // zapotrzebowanie rynkowe sklepu S    
	double* d_ud;     //jednorazowy koszt korzystania z uslug dostawcy D
	double* d_uf;     // -//- z fabryki F
	double* d_um;     // -//- c magazynu M
	double* d_ps;     // przychod ze sprzedania produktu w sklepie S
	
	//zakresy dopuszczalnych wartosci dla kazdej pozycji pdSolution
	double** d_xdminmax;
	double** d_xfminmax;
	double** d_xmminmax;
	
	//obliczenie wartosci ze wzorow:
	double d_count_Kt();  //obliczenie kosztu  transportu,przechowania i wytworzenia produktu
	double d_count_Ku();  // koszt stalych umow
	double d_count_P();  //obliczenie przychodu
	double d_count_Z();  //obliczenie zysku

	//metody pomocnicze:
	bool b_resize_table(double **d_table, int i_new_size);
	bool b_resize_matrix(double ***d_matrix, int i_rows, int i_columns);
	void v_fill_x_matrices(double *pdSolution);
	bool bMatriceIsSmaller(double** d_matrice, double* d_array, int i_row, int i_column);
	bool bMatriceIsBigger(double** d_first_matrice, double** d_second_matrice, int i_row_first, int i_col_first, int i_row_second);

};

#endif