#include "stdafx.h"

CMyString ::CMyString()
{
	i_length = 0;
	�_string = new char[1];
	�_string[0] = '\0';
}
//ctor bezparametrowy


CMyString::CMyString(const char *cChar)
{
	i_length = iSourceLength(cChar);
	�_string = new char[i_length];

	for (int ii = 0; ii < i_length; ii++)
		�_string[ii] = cChar[ii];
}
//ctor parametrowy


CMyString::CMyString(const CMyString &pcOther)
{
	i_length = pcOther.i_length;
	�_string = new char[i_length];

	for (int ii = 0; ii < i_length; ii++)
		�_string[ii] = pcOther.�_string[ii];
}
//copy ctor


//-----------helper methods-----------------------------------------------------------------------------------------
void CMyString::vCopyFrom(const CMyString &pcOther)
{
	for (int ii = 0; ii < i_length; ii++)
		�_string[ii] = pcOther.�_string[ii];
}
//void CMyString::vCopyFrom(const CMyString &pcOther)

bool CMyString::bResize(int newSize) 
{
	if (newSize <= 0)
		return false;

	delete(this->�_string);

	this->�_string = new char[newSize];
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
//------------------------------------------------------------------------------------------------------------------





//------------------------operators-----------------------------------------------------------------------------------

CMyString& CMyString:: operator= (const CMyString& pcOther)
{
	if (this != &pcOther)  // guard against  a = a;  
	{
		delete[] �_string;              // release old memory & then allocate new memory 
		i_length = pcOther.i_length;
		�_string = new char[i_length];
		vCopyFrom(pcOther);
	}
	return *this;                  // return a reference to itself to allow a = b = c; 
}
//CMyString& CMyString:: operator= (const CMyString& pcOther)

void  CMyString:: operator= (const char *cChar)
{
	if (i_length != 0)
		delete[] �_string;

	i_length = iSourceLength(cChar);  // count the length of init value
	�_string = new char[i_length];    // allocate storage 

	for (int ii = 0; ii < i_length; ii++) // copy init value into storage
		�_string[ii] = cChar[ii];
}
//void  CMyString:: operator= (const char *cChar)


CMyString& CMyString:: operator+ (const CMyString& pcOther)
{
	CMyString *c_res = new CMyString;

	if (i_length == 0 && pcOther.i_length == 0)
	{
		c_res->i_length = 0;
		c_res->�_string = NULL;
	}

	c_res->i_length = i_length + pcOther.i_length;
	c_res->�_string = new char[c_res->i_length];
	int ii;
	
	for (ii = 0; ii < i_length; ii++)
		c_res->�_string[ii] = �_string[ii];

	for (int ij = 0; ij < pcOther.i_length; ij++, ii++)
		c_res->�_string[ii] = pcOther.�_string[ij];

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
		c_new_string[ii] = �_string[ii];

	for (int ij = 0; ij < i_source_length; ij++, ii++)
		c_new_string[ii] = cChar[ij];

	delete[] �_string;

	this->i_length = i_new_length;
	this->�_string = c_new_string;
}
//void CMyString:: operator+=(const char *cChar)

