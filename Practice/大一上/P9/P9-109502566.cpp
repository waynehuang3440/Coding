/*
	Practice 9
	Name: 黃君翰
	Student Number: 109502566
	Course 2020-CE1003-B
*/
#include <iostream>

using namespace std;

int main()
{
	string s;
	
	while ( true )
	{
		cin >> s;
		if ( s == "-1" )
			break;

		char a[ s.length() ];

		for ( int i = 0; i < s.length(); i++ )
			a[ i ] = int( s[ i ] );

		for ( int i = 0; i <s.length() - 1; i++ )
			for ( int j = 0; j < s.length() - 1 - i; j++ )
				if ( a[ j ] < a[ j + 1 ] )
					swap( a[ j ], a[ j + 1 ] );

		for ( int i = 0; i < s.length(); i++ )
			cout << char( a[ i ] );
		cout << endl << endl;;
	}
}