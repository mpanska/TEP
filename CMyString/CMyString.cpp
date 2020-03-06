#include "stdafx.h"

CMyString ::CMyString()
{
	i_length = 0;
	с_string = new char[1];
	с_string[0] = '\0';
}


CMyString::CMyString(const char *cChar)
{
	i_length = iSourceLength(cChar);
	с_string = new char[i_length];

	for (int ii = 0; ii < i_length; ii++)
		с_string[ii] = cChar[ii];
}


CMyString::CMyString(const CMyString &pcOther)
{
	i_length = pcOther.i_length;
	с_string = new char[i_length];

	for (int ii = 0; ii < i_length; ii++)
		с_string[ii] = pcOther.с_string[ii];
}


void CMyString::vCopyFrom(const CMyString &pcOther)
{
	for (int ii = 0; ii < i_length; ii++)
		с_string[ii] = pcOther.с_string[ii];
}
//void CMyString::vCopyFrom(const CMyString &pcOther)


bool CMyString::bResize(int newSize) 
{
	if (newSize <= 0)
		return false;

	delete(this->с_string);

	this->с_string = new char[newSize];
	i_length = newSize;
	return true;
}
//bool CMyString::bResize(int newSize) 


int CMyString::iSourceLength(const char *cChar)
{
	int i_source_length = 0;

	while (cChar[i_source_length] != '\0')
		i_source_length++;

	return i_source_length;
}
//int CMyString::iSourceLength(const char *cChar)


void CMyString:: vPrintString()
{
	for (int ii = 0; ii < i_length; ii++)
		cout << с_string[ii];
	cout << endl;
}
//void vPrintString()


string CMyString::sToStandard()
{
	string to_string = "";
	for (int ii = 0; ii < i_length; ii++)
		to_string += с_string[ii];

	return to_string;
}
//string CMyString:: sToStandard()


CMyString& CMyString:: operator= (const CMyString& pcOther)
{
	if (this != &pcOther)  // guard against  a = a;  
	{
		delete[] с_string;              // release old memory & then allocate new memory 
		i_length = pcOther.i_length;
		с_string = new char[i_length];
		vCopyFrom(pcOther);
	}
	return *this;                  // return a reference to itself to allow a = b = c; 
}
//CMyString& CMyString:: operator= (const CMyString& pcOther)

void  CMyString:: operator= (const char *cChar)
{
	if (i_length != 0)
		delete[] с_string;

	i_length = iSourceLength(cChar);  
	с_string = new char[i_length];    

	for (int ii = 0; ii < i_length; ii++) 
		с_string[ii] = cChar[ii];
}
//void  CMyString:: operator= (const char *cChar)


CMyString& CMyString:: operator+ (const CMyString& pcOther)
{
	CMyString *c_res = new CMyString;

	if (i_length == 0 && pcOther.i_length == 0)
	{
		c_res->i_length = 0;
		c_res->с_string = NULL;
	}

	c_res->i_length = i_length + pcOther.i_length;
	c_res->с_string = new char[c_res->i_length];
	int ii;
	
	for (ii = 0; ii < i_length; ii++)
		c_res->с_string[ii] = с_string[ii];

	for (int ij = 0; ij < pcOther.i_length; ij++, ii++)
		c_res->с_string[ii] = pcOther.с_string[ij];

	return *c_res;
}
//CMyString& CMyString:: operator+ (const CMyString& pcOther)


void CMyString:: operator+=(const char *cChar)
{
	int i_source_length = iSourceLength(cChar);
	int i_new_length = i_length + i_source_length;

	char *c_new_string = new char[i_new_length];

	int ii;

	for (ii = 0; ii < i_length; ii++)
		c_new_string[ii] = с_string[ii];

	for (int ij = 0; ij < i_source_length; ij++, ii++)
		c_new_string[ii] = cChar[ij];

	delete[] с_string;

	this->i_length = i_new_length;
	this->с_string = c_new_string;
}
//void CMyString:: operator+=(const char *cChar)


CMyString& operator+(const char* cChar, CMyString& pcOther)
{
	int i_source_length = 0;

	while (cChar[i_source_length] != '\0')
		i_source_length++;

	CMyString *c_res = new CMyString;

	if (i_source_length == 0 && pcOther.i_length == 0)
	{
		c_res->i_length = 0;
		c_res->с_string = NULL;
	}

	c_res->i_length = i_source_length + pcOther.i_length;
	c_res->с_string = new char[c_res->i_length];
	int ii;

	for (ii = 0; ii < i_source_length; ii++)
		c_res->с_string[ii] = cChar[ii];

	for (int ij = 0; ij < pcOther.i_length; ij++, ii++)
		c_res->с_string[ii] = pcOther.с_string[ij];

	return *c_res;
}
//CMyString& operator+(const char* cChar, CMyString& pcOther)


bool CMyString:: isEmpty()
{
	if (strlen(с_string) == 0) 
	{
		cout << "string is empty\n";
		return false;
	}
		
	cout << "string is not empty\n";
	return true;
}

