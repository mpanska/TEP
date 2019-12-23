#include "stdafx.h"

CTable::CTable()
{
	c_table = new int[DEFAULT_SIZE];
	for (int ii = 0; ii < DEFAULT_SIZE; ii++)
		c_table[ii] = rand();
}


void CTable::display()
{
	for (int ii = 0; ii < DEFAULT_SIZE; ii++)
		cout << c_table[ii] << endl;
}