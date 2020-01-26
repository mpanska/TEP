#ifndef CMYSTRING_H
#define CMYSTRING_H

#include "stdafx.h"

class CMyString 
{
public:

	CMyString();
	CMyString(const char *cChar);
	CMyString(const CMyString &pcOther);

	~CMyString() { if (ñ_string != NULL) delete[] ñ_string; };


	void vPrintString()
	{
		for (int ii = 0; ii < i_length; ii++)
			cout << ñ_string[ii];
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
			to_string += ñ_string[ii];
		
		return to_string;
	}

private:

	char* ñ_string;  
	int i_length; 

	void vCopyFrom(const CMyString &pcOther);
	bool bResize(int newSize);
	int iSourceLength(const char *cChar);
};

#endif 
