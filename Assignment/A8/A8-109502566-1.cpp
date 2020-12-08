/*
	Assignment 8
	Name: 黃君翰
	Student Number: 109502566
	Course 2020-CE1001
*/
#include <iostream>

using namespace std;

bool symmetry( int size );

int array[10000][10000];

int main()
{
	int size;
	while ( true )
	{
		cout << "Input Size:";
		
		cin >> size;

		if ( size == -1 )
			break;

		for ( int i = 0; i < size; i++ )
			for ( int j = 0; j < size; j++ )
				cin >> array[i][j];

		if ( symmetry( size ) == true )
			cout << "Symmetric!" << endl;
		else
			cout << "Non-symmetric!" << endl;
	}

}//main

bool symmetry( int size )
{
	int n = size - 1;
	
	for ( int i = 0; i < size; i++ )
		for ( int j = 0; j < size; j++ )
			if ( array[i][j] != array[n-i][n-j] )
				return false;
	return true;
}