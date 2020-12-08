/*
	Practice 8
	Name: 黃君翰
	Student Number: 109502566
	Course 2020-CE1003-B
*/

#include <iostream>

using namespace std;

int palindrome( string str, int k );

int main()
{
	string str;
	int len;
	int result;
	
	while ( true )
	{
		cin >> str;
		if ( str == "-1" )
		{
			break;
		}
		
		len = str.length();

		result = palindrome( str, 0 );
		if ( result == 1 )
		{
			cout << "Palindrome!" << endl;
		}
		else
		{
			cout << "Not Palindrome!" << endl;
		} 
	}
}//main

int palindrome( string str, int k )
{
	int len = str.length();
	int result;

	if ( len % 2 == 0 )
	{
		if ( str[ k ] == str[ ( len / 2 )  ] )
		{
			return 1;
		}
	}
	else if ( len % 2 == 1 )
	{
		if ( k == ( len / 2 ) + 1 || len == 1)
		{
			return 1;
		}
	}
	
	if ( str[k] != str[len - k - 1] )
	{
		return 0;
	}
	else if ( str[k] == str[len - k - 1] )
	{
		result = palindrome( str, k + 1 );
		if ( result == 1 )
		{
			return 1;
		}
	}
	return 0;
}//palindrome