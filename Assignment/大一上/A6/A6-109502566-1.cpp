/*
	Assignment 6
	Name: 黃君翰
	Student Number: 109502566
	Course: 2020-CE1001
*/

#include <iostream>

using namespace std;

int main()
{
	int A_x, A_y, B_x, B_y;

	cout << "Matrix A size = ";
	
	cin >> A_x; 
	cin >> A_y;

	cout << "Matrix B size = ";
	cin >> B_x;
	cin >> B_y;

	if (A_y != B_x)
		cout << "Can't be multiplied!" << endl;

	else
	{
		int matrix_A[A_x][A_y], matrix_B[B_x][B_y], mul_matrix[A_x][B_y];
		int i, j, k, l;

		cout << "Matrix A" << endl;
		for (i = 0; i < A_x; i++)
			for( j = 0; j < A_y; j++)
				cin >> matrix_A[i][j];

		cout << "Matrix B" << endl;
		for (i = 0; i < B_x; i++)
			for ( j = 0; j < B_y; j++)
				cin >> matrix_B[i][j];

		for (i = 0; i < A_x; i++)
			for (j = 0; j < B_y; j++){
				mul_matrix[i][j] = 0;
				for (k = 0; k < A_y; k++){
					mul_matrix[i][j] += matrix_A[i][k] * matrix_B[k][j]; 
				}
			}

		cout << "Multiplication" << endl;
		for (i = 0; i < A_x;i++){
			for (j = 0; j < B_y; j++)
				cout << mul_matrix[i][j] << " ";
			cout << endl;
		}
	}
}
