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
	string order;
	char *s = new char;
	int i = 0;

	while ( true )
	{
		cin >> order;

		if ( order == "push" )
		{
			cin >> *( s + i );
			i++;
		}
		else if ( order == "pop" )
		{
			if ( i > 0 )
			{
				i--;
				cout << *( s + i ) << endl;
				*( s + i ) = '\0';
			}
			else
			{
				cout << "empty" << endl;
			}			
		}
		else if ( order == "list" )
		{
			for ( int j = 0; j < i; j++ )
				cout << *( s + j ) << " ";
			cout << endl;
		}
		else
		{
			break;
		}
	}

	for ( int j = 0; j <= i; j++ )
		delete *( s + i );

	return 0;
}