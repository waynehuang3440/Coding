/*
	Practice 11
	Name:  黃君翰
	Student Number: 109502566
	Course 2020-CE1003B
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char ooxx[ 3 ][ 3 ];
	bool invalid[ 3 ][ 3 ];
	ofstream result( "OOXX-109502566.txt", ios::out ); 

	for (int i = 0; i < 3; i++ )
	{
		for ( int j = 0; j < 3; j++ )
		{
			invalid[ i ][ j ] = false;
			ooxx[ i ][ j ] = ' ';
		}
	}

	int x, y;
	bool o = true, win = false;

	for (int i = 0; i < 9; i++ )
	{
		cin >> x >> y;
		cout << endl;

		if ( invalid[ x ][ y ] == true || x >= 3 || y >= 3 ) //填過的位置或Out of range
		{
			cout << "Invalid place!" << endl;
			i--;

			if ( o ) //輸入失敗，抵銷後面的換邊
				o = false;
			else
				o = true;
		} 
		else
		{
			if ( o )
				ooxx[ x ][ y ] = 'O';
			else
				ooxx[ x ][ y ] = 'X';

			for ( int j = 0; j < 3; j++ ) //列印結果
			{
				cout << "|";
				for ( int k = 0; k < 3; k++ )
				{
					cout << ooxx[ j ][ k ];
					if ( k == 2 )
						cout << "|" << endl;
					else
						cout << ".";
				}
			}
			invalid[ x ][ y ] = true;
		}
		
		cout << endl;

		for ( int j = 0; j < 3; j += 2 ) //斜線
			for( int k = 0; k < 3; k += 2 )
				if ( ooxx[ 1 ][ 1 ] != ' ' && ooxx[ 1 ][ 1 ] == ooxx[ j ][ k ] && ooxx[ 1 ][ 1 ] == ooxx[ 2 - j ][ 2 - k ] )
					win = true;

		for ( int j = 0; j < 3; j++ )
		{
			if ( ooxx[ 1 ][ j ] != ' ' && ooxx[ 1 ][ j ] == ooxx[ 0 ][ j ] && ooxx[ 1 ][ j ] == ooxx[ 2 ][ j ] ) //直線
				win = true;
			if ( ooxx[ j ][ 1 ] != ' ' && ooxx[ j ][ 1 ] == ooxx[ j ][ 0 ] && ooxx[ j ][ 1 ] == ooxx[ j ][ 2 ] ) //橫線
				win = true;
		}
		
		if ( win )
			break;

		if ( o ) //換邊
			o = false;
		else
			o = true;
	}

	if ( win )
	{
		if ( o )
		{
			cout << "O Win!" << endl;
			result << "O Win!" << endl;
		}
		else
		{
			cout << "X Win!" << endl;
			result << "X Win!" << endl;
		}
	}
	else
	{
		cout << "Draw!" << endl;
		result << "Draw!" << endl;

	}

	result << endl;

	for ( int j = 0; j < 3; j++ ) //列印結果
	{
		result << "|";
		for ( int k = 0; k < 3; k++ )
		{
			result << ooxx[ j ][ k ];
			if ( k == 2 )
				result << "|" << endl;
			else
				result << ".";
		}
	}	
}