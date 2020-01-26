#ifndef CMYSTRING_H
#define CMYSTRING_H

#include "stdafx.h"

class CMyString 
{
public:

	CMyString();
	CMyString(const char *cChar);
	CMyString(const CMyString &pcOther);

	~CMyString() { if (�_string != NULL) delete[] �_string; };


	void vPrintString()
	{
		for (int ii = 0; ii < i_length; ii++)
			cout << �_string[ii];
		cout << endl;
	}
	//void vPrintString()


	CMyString& operator= (const CMyString& pcOther); 
	void operator= (const char *cChar);              
	void operator+=(const char *cChar);     
	CMyString& operator+ (const CMyString& pcOther); 


	string sToStandard() 
	{
		string to_string = "";
		for (int ii = 0; ii < i_length; ii++)
			to_string += �_string[ii];
		
		return to_string;
	}

private:

	char* �_string;  
	int i_length; 

	void vCopyFrom(const CMyString &pcOther);
	bool bResize(int newSize);
	int iSourceLength(const char *cChar);
};

#endif 
