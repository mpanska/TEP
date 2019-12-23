#include "stdafx.h"


void test() 
{
	cout << "simple int pointer test" << endl;
	int a = 5;
	int* ptr = &a;
	CMySmartPointer<int> pc_i_smart = CMySmartPointer<int>(ptr);

	cout << "\ntest with ctable" << endl;
	CMySmartPointer<CTable> ptr_smart1 = CMySmartPointer<CTable>(new CTable);
	ptr_smart1->display();

	cout << endl;
	CMySmartPointer<CTable> ptr_smart2 = CMySmartPointer<CTable>(new CTable);
	ptr_smart2->display();
	cout << endl;

	cout << "\ntest for = operator" << endl;
	ptr_smart1 = ptr_smart2;

	cout << "\nptr_smart1" << endl;
	ptr_smart1->display();
	cout << endl;
	cout << "ptr_smart2" << endl;
	ptr_smart2->display();
}

int main()
{
	test();

	system("pause");
    return 0;
}

