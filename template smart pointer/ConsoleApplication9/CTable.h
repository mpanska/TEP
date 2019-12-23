#ifndef _CTABLE_H
#define _CTABLE_H

#include "stdafx.h"

class CTable
{
public:

	CTable()
	{
		c_table = new int[DEFAULT_SIZE];
		for (int ii = 0; ii < DEFAULT_SIZE; ii++)
			c_table[ii] = rand();
	}

	~CTable() { delete[] c_table; }

	void display() 
	{
		for (int ii = 0; ii < DEFAULT_SIZE; ii++)
			cout << c_table[ii] << endl;
	}

private:
	int *c_table;
	const int DEFAULT_SIZE = 5;
};

#endif
