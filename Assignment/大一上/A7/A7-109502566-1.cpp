/*
	Assignment 7
	Name: 黃君翰
	Student Number: 109502566
	Course 2020-CE1001
*/

#include <iostream>
#include <string>

using namespace std;

void guess( string str1, string str2 );

int main()
{
	string input_num, guess_num;
	int A = 0, B = 0;
	
	cout << "Input Number:";
	cin >> input_num;
	cout << "Guess:";
	cin >> guess_num;
	
	while ( true )
	{
		if ( input_num == guess_num )
		{
			break;
		}
		
		guess( input_num, guess_num );
		
		cout << "Guess:";
		cin >> guess_num;
	}

	cout << "You Win!" << endl;
}//main

void guess( string str1, string str2 )
{
	int A = 0, B = 0;
	for ( int i = 0; i < 4; i++ )
	{
		if ( str1[i] == str2[i] )
		{
			A++;
		}

		for ( int j = 0; j < 4; j++)
		{
			if ( str1[i] == str2[j] )
			{
				B++;
			}
		}
	}
	
	B = B - A;
	cout << A << "A" << B << "B" << endl;
	return;
}//guess