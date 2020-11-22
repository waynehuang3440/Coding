/*
	Assignment 6
	Name: 黃君翰
	Student Number: 109502566
	Course: 2020-CE1001
*/

#include <iostream>
#include <string> 
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
	int amount;
	cin >> amount;
	string code, chr, num;
	int i, j, k;
	int count, ascii, ascii_2;
	int times[10001];
	int num_len;

	for (i = 0; i < amount; i++)
	{ 
		cin >> code;
		count = 0;
		for (j = 0; j < code.length(); j++)
		{
			
			ascii = code[j];
			if (65 <= ascii && ascii <= 90)
			{
				chr[count] = code[j];
				count++;
			}
		}

		count = 0;
		for (j = 0; j < code.length(); j++)
		{
			ascii = code[j];
			if (ascii <= 57 && ascii >= 48)
			{
				num = "";
				num_len = 0;

				for (k = j; k < code.length(); k++)
				{
					ascii_2 = code[k];
					if (ascii_2 > 57 || ascii_2 < 48)
					{
						break;
					}

					if (ascii_2 <= 57 && ascii_2 >= 48)
					{
						num[k-j] = code[k];	
						num_len += 1;
					}
				}

				j = j + num_len -1;

				
				times[count] = 0;
				for (k = 0; k < num_len; k++)
				{
					ascii = num[k];
					times[count] += (ascii - '0') * pow(10, num_len-1-k);
				}

				for (k = 0; k < times[count]; k++)
				{
					cout << chr[count];
				}
				count++;
			}	
		}

		cout << endl;
	}
}