/*
	Assignment 12
	Name: 黃君翰
	Student Number: 109502566
	Course 2020-CE1001
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string filename1, filename2;
	cin >> filename1 >> filename2;

	ifstream file1( filename1, ios::in );
	ifstream file2( filename2, ios::in );
	ofstream file_out( "list-109502566.txt", ios::out );
	string arr[101][4];
	int n = 0, cmd;

	cout << "sort by (1)id (2)name (3)score"<< endl;
	cin >> cmd;

	if ( cmd != 1 && cmd != 2 && cmd != 3 )
	{
		cout << "exit" << endl;
		return 0;
	}

	string tmp1 = "", tmp2 = "", tmp3 = "";
	while( file1 >> tmp1 >> tmp2  >> tmp3 )
	{
		arr[n][1] = tmp1;
		arr[n][2] = tmp2;
		arr[n][3] = tmp3;
		n++;
	}
	while( file2 >> tmp1 >> tmp2  >> tmp3 )
	{
		arr[n][1] = tmp1;
		arr[n][2] = tmp2;
		arr[n][3] = tmp3;
		n++;
	}

	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n - i - 1; j++ )
			if ( arr[ j ][ cmd ] > arr[ j + 1 ][ cmd ] )
			{
				string copy;
				
				copy = arr[ j ][ 1 ];
				arr[ j ][ 1 ] = arr[ j + 1 ][ 1 ];
				arr[ j + 1 ][ 1 ] = copy;
				
				copy = arr[ j ][ 2 ];
				arr[ j ][ 2 ] = arr[ j + 1 ][ 2 ];
				arr[ j + 1 ][ 2 ] = copy;

				copy = arr[ j ][ 3 ];
				arr[ j ][ 3 ] = arr[ j + 1 ][ 3 ];
				arr[ j + 1 ][ 3 ] = copy;
			}

	for ( int i = 0; i < n; i++ )
	{
		cout << arr[ i ][ 1 ] << " " << arr[ i ][ 2 ] << " " << arr[ i ][ 3 ] << endl;
		file_out << arr[ i ][ 1 ] << " " << arr[ i ][ 2 ] << " " << arr[ i ][ 3 ] << endl;
	}

	return 0;
}