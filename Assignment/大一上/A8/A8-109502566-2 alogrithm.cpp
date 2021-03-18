#include <iostream>
#include <string>

using namespace std;

int palindrome( string str, int k );
string findbig( string str );

int main()
{
	string str, result;

	while ( true )
	{
		cin >> str;

		if ( str == "-1" )
		{
			break;
		}

		result = findbig( str );
		//cout << result << endl;

		if ( result == "-1" )
		{
			cout << "Palindrome not existed!" << endl;
		}
		else
		{
			cout << "Palindrome:" << result << "\nLength:" << result.length() << endl;
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

string findbig( string str )
{
	string split1, split2, result1, result2;
	int len;
	len = str.length();

	if ( len <= 1 )
	{
		return "-1";
	}

	if ( palindrome( str, 0 ) == 1 )
	{
		result1 = str;
		cout << result1 << endl;
		return result1;
	}
	
	if ( palindrome( str, 0 ) == 0 )
	{
		split1.assign( str, 0, len - 1 );
		split2.assign( str, 1, len - 1 );
		
		cout << split1 << ";" << split2 << endl;

		result1 = findbig( split1 );
		result2 = findbig( split2 );

		if ( result2 == "-1" )
		{
			return result1;
		}
		else if ( result2.length() > result1.length() )
		{
			return result2;
		}
		return result1;
	}
	return "-1";
}