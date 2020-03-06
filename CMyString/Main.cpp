// stringclass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"

int main()
{
	CMyString c_str;
	c_str = "ma ";
	c_str += "kota ";
	c_str = c_str + "i psa";
	c_str = "ala " + c_str;

	c_str.vPrintString();

	cout << c_str.sToStandard() << endl;


	CMyString c_str2;

	cout << c_str.isEmpty() << endl;
	cout << c_str2.isEmpty() << endl;

	system("pause");
	return 0;
}
