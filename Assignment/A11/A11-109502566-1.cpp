/*
	Assignment 11
	Name: 黃君翰
	Student Number: 109502566
	Course 2020-CE1001
*/

#include <iostream>
#include <fstream>

using namespace std;

bool square_check( int [ 9 ][ 9 ] );
bool line_check( int [ 9 ][ 9 ] );
void sort( int [ 9 ] );

int main()
{
	string file = "";
	cin >> file;
	int sudo[ 9 ][ 9 ] = {};

	ifstream InFile( file, ios::in );

	string tmp = "";
	for ( int i = 0; i < 9; i++ )
		for ( int j = 0; j < 9; j++ )
		{
			InFile >> tmp;
			sudo[ i ][ j ] = int( tmp[ 0 ] ) - 48;
		}

	if ( square_check( sudo ) == false || line_check( sudo ) == false )
		cout << "N" << endl;
	else
		cout << "Y" << endl;

	InFile.close();
}

void sort( int check[ 9 ] )
{
	for ( int  i = 0; i < 9; i++ )
		for ( int j = 0; j < 9 - i; j++ )
			if ( check[ j ] > check[ j + 1 ] )
			{
				check[ j ] = check[ j ] + check[ j + 1 ];
				check[ j + 1 ] = check[ j ] - check[ j + 1 ];
				check[ j ] = check[ j ] - check[ j + 1 ];
			}
}

bool square_check( int sudo[ 9 ][ 9 ] )
{
	int check[ 9 ];
	int m = 0;

	for ( int i = 0; i < 9; i +=3 )
		for ( int j = 0; j < 9; j += 3 )
		{
			for ( int k = 0; k < 3; k++ )
				for ( int l = 0; l < 3; l++ )
				{
					check[ m ] = sudo[ i + k ][ j + l ];
					m++;
				}
			
			m = 0;
			sort( check );
			for ( int n = 1; n < 10; n++ )
				if ( check[ n - 1 ] != n )
					return false;
		}
	return true;
}

bool line_check( int sudo[ 9 ][ 9 ] )
{
	int check[ 9 ];
	int m = 0;

	for ( int i = 0; i < 9; i++ )
	{
		for ( int j = 0; j < 9; j++ )//橫線
			check[ j ] = sudo[ i ][ j ];
		sort( check );
		for ( int n = 1; n < 10; n++ )
			if ( check[ n - 1 ] != n )
				return false;

		for ( int j = 0; j < 9; j++ )//直線
			check[ j ] = sudo[ j ][ i ];
		sort( check );
		for ( int n = 1; n < 10; n++ )
			if ( check[ n - 1 ] != n )
				return false;
	}
	return true;
}