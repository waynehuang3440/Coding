/*
	Assignment 7
	Name: 黃君翰
	Student Number: 109502566
	Course 2020-CE1001
*/

#include <iostream>

using namespace std;

int F( int N );
int prime( int A );

int main()
{
	int n, result;

	while ( true )
	{
		cin >> n;

		if ( n == 0)
		{
			break;
		}

		result = F( n );
		cout << result << endl;
	}
}

int F( int N )
{
	int count;
	
	if ( N >= 10 )
	{
		count = 1 + F( N - 22 ) + F( F( N - 30 ) - 30 );
	}
	else if ( N <= 4 )
	{
		count = 3;
	}
	else
	{
		count = 2 + F( N - 2 );
	}
	return count;
}