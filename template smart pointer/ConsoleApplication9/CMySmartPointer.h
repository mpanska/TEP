#ifndef _CMYSMARTPOINTER_H
#define _CMYSMARTPOINTER_H

#include "stdafx.h"


class CRefCounter
{
public:
	CRefCounter() { i_count; }
	int iAdd() { return(++i_count); }
	int iDec() { return(--i_count); };
	int iGet() { return(i_count); }
private:
	int i_count;
};//class CRefCounter



template<class T>
class CMySmartPointer
{
public:

	CMySmartPointer(T *pcPointer) 
	{ 
		pc_pointer = pcPointer;
		pc_counter = new CRefCounter();
		pc_counter->iAdd();
		cout << "utworzony wskaznik" << endl;
	}//constructor

	CMySmartPointer(const CMySmartPointer<T> &pcOther)
	{
		pc_pointer = pcOther.pc_pointer;
		pc_counter = pcOther.pc_counter;
		pc_counter->iAdd();
		cout << "copy constructor" << endl;
	}//copy constructor


	~CMySmartPointer() {
		if (pc_counter->iDec() == 0)
		{
			delete pc_pointer;
			delete pc_counter;
		}
		cout << "usuwam wskaznik" << endl;
	}//destructor


	T& operator*() { return(*pc_pointer); };
	T* operator->() { return(pc_pointer); };

	CMySmartPointer<T>& operator=(CMySmartPointer<T>& pcOther)
	{
		if (pc_counter->iDec() == 0)
		{
			delete pc_pointer;
			delete pc_counter;
		}

		pc_pointer = pcOther.pc_pointer;
		pc_counter = pcOther.pc_counter;
		pc_counter->iAdd();

		return *this;
	}

private:
	T *pc_pointer;
	CRefCounter *pc_counter;
};//class CMySmartPointer


#endif