#ifndef CMYSTRING_H
#define CMYSTRING_H

#include "stdafx.h"

class CMyString 
{
public:

	CMyString();
	CMyString(const char *cChar);
	CMyString(const CMyString &pcOther);
	~CMyString() { if (с_string != NULL) delete[] с_string; };

	void vPrintString();

	CMyString& operator= (const CMyString& pcOther); 
	void operator= (const char *cChar);              
	void operator+=(const char *cChar);     
	CMyString& operator+ (const CMyString& pcOther); 
	friend CMyString& operator+(const char* cChar, CMyString& pcOther);

	bool isEmpty();

	string sToStandard();

private:

	char* с_string;  
	int i_length; 

	void vCopyFrom(const CMyString &pcOther);
	bool bResize(int newSize);
	int iSourceLength(const char *cChar);
	
};

#endif 
