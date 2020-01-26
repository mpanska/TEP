// stringclass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"

int main()
{
	CMyString c32("some text to convert to string");

	CMyString c1;
	CMyString c2(" is copied");
	c1 = "something";

	CMyString c3(c1);

	c3.vPrintString();

	c3 = c1 + c2;

	c3.vPrintString();

	c3 = "this is operator= test";
	c3 = c3 + " and an op+ test";
	c3 += " with also a += test";
	c3.vPrintString();

	cout << c32.sToStandard() << endl;

	system("pause");
	return 0;
}

