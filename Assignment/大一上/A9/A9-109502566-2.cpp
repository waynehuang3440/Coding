/*
	Assignment 9
	Name: 黃君翰
	Student Number: 109502566
	Course 2020-CE1001
*/
#include <iostream>

using namespace std;

int main()
{
	char input;


	while ( true )
	{
		cin >> input;

		if ( int( input ) > 47 && int( input ) < 58 )
			cout << "number" << endl;

		else if ( int( input ) > 64 && int( input ) < 91 )
			cout << char( int( input ) + 32 ) << endl;

		else if ( int( input ) > 96 && int( input ) < 123 )
			cout << char( int( input ) - 32 ) << endl;

		else
			break;
	}

}