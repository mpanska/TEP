#include "stdafx.h"

CMyString ::CMyString()
{
	i_length = 0;
	ñ_string = new char[1];
	ñ_string[0] = '\0';
}
//ctor bezparametrowy


CMyString::CMyString(const char *cChar)
{
	i_length = iSourceLength(cChar);
	ñ_string = new char[i_length];

	for (int ii = 0; ii < i_length; ii++)
		ñ_string[ii] = cChar[ii];
}
//ctor parametrowy


CMyString::CMyString(const CMyString &pcOther)
{
	i_length = pcOther.i_length;
	ñ_string = new char[i_length];

	for (int ii = 0; ii < i_length; ii++)
		ñ_string[ii] = pcOther.ñ_string[ii];
}
//copy ctor


//-----------helper methods-----------------------------------------------------------------------------------------
void CMyString::vCopyFrom(const CMyString &pcOther)
{
	for (int ii = 0; ii < i_length; ii++)
		ñ_string[ii] = pcOther.ñ_string[ii];
}
//void CMyString::vCopyFrom(const CMyString &pcOther)

bool CMyString::bResize(int newSize) 
{
	if (newSize <= 0)
		return false;

	delete(this->ñ_string);

	this->ñ_string = new char[newSize];
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
		delete[] ñ_string;              // release old memory & then allocate new memory 
		i_length = pcOther.i_length;
		ñ_string = new char[i_length];
		vCopyFrom(pcOther);
	}
	return *this;                  // return a reference to itself to allow a = b = c; 
}
//CMyString& CMyString:: operator= (const CMyString& pcOther)

void  CMyString:: operator= (const char *cChar)
{
	if (i_length != 0)
		delete[] ñ_string;

	i_length = iSourceLength(cChar);  // count the length of init value
	ñ_string = new char[i_length];    // allocate storage 

	for (int ii = 0; ii < i_length; ii++) // copy init value into storage
		ñ_string[ii] = cChar[ii];
}
//void  CMyString:: operator= (const char *cChar)


CMyString& CMyString:: operator+ (const CMyString& pcOther)
{
	CMyString *c_res = new CMyString;

	if (i_length == 0 && pcOther.i_length == 0)
	{
		c_res->i_length = 0;
		c_res->ñ_string = NULL;
	}

	c_res->i_length = i_length + pcOther.i_length;
	c_res->ñ_string = new char[c_res->i_length];
	int ii;
	
	for (ii = 0; ii < i_length; ii++)
		c_res->ñ_string[ii] = ñ_string[ii];

	for (int ij = 0; ij < pcOther.i_length; ij++, ii++)
		c_res->ñ_string[ii] = pcOther.ñ_string[ij];

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
		c_new_string[ii] = ñ_string[ii];

	for (int ij = 0; ij < i_source_length; ij++, ii++)
		c_new_string[ii] = cChar[ij];

	delete[] ñ_string;

	this->i_length = i_new_length;
	this->ñ_string = c_new_string;
}
//void CMyString:: operator+=(const char *cChar)

