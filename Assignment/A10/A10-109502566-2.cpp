/*
	Assignment 10
	Name: 黃君翰
	Student Number: 109502566
	Course 2020-CE1001
*/
#include <iostream>

using namespace std;

void insert( char* [], string, int );
void sort( char* [], int );

int main()
{
	char cmd;
	int n = 0;
	char *dict[ 500 ];
	bool p[ 500 ];
	string input;

	while ( true )
	{
		

		cout << "(a)insert (b)delete (c)print (d)exit" << endl;
		cin >> cmd;

		if ( cmd == 'a' )
		{
			cout << "Please enter a word: " << endl;
			cin >> input;
			insert( dict, input, n );
			n++;
			sort( dict, n );
		}
		else if ( cmd == 'b' )
		{
			n--;
			dict[ n ] = NULL;
		}
		else if ( cmd == 'c' )
		{
			for ( int i = 0; i < n; i++ )
				cout << "num: " << i + 1 << " word: " << dict[ i ] << endl;
		}
		else
			break;

	}
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

void sort( char *dict[], int n )
{
	bool p[ n ];
	char *temp[ n ];
	int k = 0;

	for ( int i = 0; i < n; i++ )
		p[ i ] = false;

	for ( int i = 0; i < 10; i++ )
	{
		for ( int asc = 97; asc < 123; asc++ )
		{
			for ( int j = 0; j < n; j++ )
			{
				if ( (dict[ j ])[ i ] == char( asc ) )
				{
					if ( p[ j ] == false )
					{
						temp[ k ] = dict[ j ];
						k++;
						p[ j ] = true;
					}	
				}
			}
		}
	}

	for ( int i  = 0; i < n; i++ )
		dict[ i ] = temp[ i ];

	return;
}