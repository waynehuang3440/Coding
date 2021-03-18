/*
	Assignment 10
	Name: 黃君翰
	Student Number: 109502566
	Course 2020-CE1001
*/
#include <iostream>

using namespace std;

void insert( char* [], string, int );

int main()
{
	char *dict[ 500 ];
	int n = 0;
	string input;

	while( true )
	{
		cin >> input;
		if ( input == "-1" )
			break;
		insert( dict, input, n );
		n++;
	}

	for ( int i = 0; i < n; i++ )
		cout << "num: " << i + 1 << " word: " << dict[ i ] << endl;

	return 0;
}

void insert( char *dict[], string input, int n )
{
	char *word = new char[ 10 ];
	for ( int i = 0; i < input.length(); i++ )
	{
		word[ i ] = input[ i ];
		if ( i == input.length() - 1 )
			word[ i + 1 ] = '\0'; 
	}

	dict[ n ] = word;
	return;
}