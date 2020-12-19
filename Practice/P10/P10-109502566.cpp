/*
	Practice 10
	Name: 黃君翰
	Student Number: 109502566
	Course 2020-CE1003B
*/
#include <iostream>

using namespace std;

void f( int*, int* );

int main()
{
	int a, b;
	cin >> a >> b;

	f( &a, &b );
	cout << a << endl;
	cout << b << endl;

	return 0;
}

void f( int *aptr, int *bptr )
{
	int x = *aptr;
	*aptr += *bptr;
	*bptr *= x;
	return;
}