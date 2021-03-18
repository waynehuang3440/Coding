/*
	Assignment 8
	Name: 黃君翰
	Student Number: 109502566
	Course 2020-CE1001
*/
#include <iostream>

using namespace std;

int main()
{
	string str;
	int i;
	
	while ( true )
	{
		cin >> str;
		int ext_len = 0, max_len = 0, loc;

		if ( str == "-1" )
			break;

		for ( i = 0; i < str.length(); i++ )
		{
			ext_len = 0;
			while ( i - ext_len - 1 >= 0 && i + ext_len + 1 < str.length() && str[i - ext_len - 1] == str[i + ext_len + 1] )
				ext_len++;

			if ( ext_len > 0 && 2 * ext_len + 1 > max_len )
			{
				loc = i;
				max_len = 2 * ext_len + 1;
			}

			ext_len = 0;

			while ( i - ext_len >= 0 && i + ext_len + 1 < str.length() && str[i - ext_len] == str[i + ext_len + 1])
				ext_len++;

			if ( ext_len > 0 && 2 * ext_len > max_len )
			{
				loc = i;
				max_len = 2 * ext_len;
			}
		}

		if ( max_len > 1 )
		{
			if ( max_len % 2 == 1 )
			{
				cout << "Palindrome:";
				for ( i = loc - max_len / 2; i < loc + max_len / 2 + 1; i++ )
					cout << str[i];

				cout << "\nLength:" << max_len << endl << endl;
			}
			else
			{
				cout << "Palindrome:";
				for ( i = loc - max_len / 2 + 1; i < loc + max_len / 2 + 1; i++ )
					cout << str[i];

				cout << "\nLength:" << max_len << endl << endl;
			}
		}
		else
		{
			cout << "Palidrome not existed!" << endl << endl;
		}
	}

}