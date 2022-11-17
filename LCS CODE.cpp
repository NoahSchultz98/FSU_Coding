//#include "pch.h"
#include<iostream>

using namespace std;
#include<vector>


typedef  vector<char> row;
typedef vector<row> matrix;

void printlcs(matrix B, vector<char> X, int i, int j);


int main()
{
	vector<char> X(1, '0');
	vector<char> Y(1, '0');
	int i, j;

	char next;
	cout << "enter your first sequence. Type # when you are done" << endl;
	do
	{
		cin >> next;

		if (next != '#')
			X.push_back(next);

	} while (next != '#');
	cout << "enter your second sequence. Type # when you are done" << endl;
	do
	{
		cin >> next;
		if (next != '#')
			Y.push_back(next);

	} while (next != '#');



/* In order to implement the algorithm we need to define two matrices: B(with arrows) and C (with numbers). They have the same size. The number of columns is determined by the size of the first sequence, and the number of rows equals the size of the second sequence

*/
	const int number_of_rows = Y.size();
	const int number_of_columns = X.size();
	

/* Define matrix B with zero rows and columns and then resize accordingly*/

	matrix B;

	

	B.resize(number_of_rows);
	for (int j = 0; j < number_of_rows; j++)
		B[j].resize(number_of_columns);
/* Define matrix C with zero rows and columns and then resize accordingly*/

	matrix C;

   // this code was added	

	C.resize(number_of_rows);
	for (int j = 0; j < number_of_rows; j++)
		C[j].resize(number_of_columns);

//Dressing matrices B and C

//Let us make sure that the first row and the the //first column are filled with zeros
	for (j = 0; j < number_of_columns; j++)
	{
		B[0][j] = '0';
		C[0][j] = '0';
	}

	for (j = 0; j < number_of_rows; j++)
	{
		B[j][0] = '0';
		C[j][0] = '0';
	}

	
/* We will use ‘D’ for diagonal arrow, ‘L’ for left arrow. And ‘U’ for arrow pointing “up” */


	for (int i = 1; i < number_of_rows; i++)
		for (int j = 1; j < number_of_columns; j++)
		{
			if (X[j] == Y[i])//characters the same
			{
				C[i][j] = C[i - 1][j - 1] + 1;
				B[i][j] = 'D';
			}

			if (X[j] != Y[i]) //characters different
			{
				if (C[i][j - 1] > C[i - 1][j])
				{

					C[i][j] = C[i][j - 1];
					B[i][j] = 'L';
				}
				else
				{
					C[i][j] = C[i - 1][j];
					B[i][j] = 'U';

				}


			}
		}

	cout << "printing matrix B with arrows" << endl;
	cout << endl;

	for (int i = 1; i < number_of_rows; i++, cout << endl)
		for (int j = 1; j < number_of_columns; j++)
			cout << B[i][j] << " ";


	cout << "Here is your longest subsequence" << endl;
	printlcs(B, X, number_of_rows -1, number_of_columns-1);

	cout << endl;




	return 0;
}


void printlcs(matrix B, vector<char> X, int i, int j)
{
	if (i == 0 || j == 0){
		return;
   }
   else if(B[i][j] == 'D'){
      printlcs(B, X, i-1,j-1);
      cout << X[j];
   }
   else if(B[i][j] == 'U'){
      printlcs(B, X, i-1,j);
   }
   else if(B[i][j] == 'L'){
      printlcs(B, X, i,j-1);
   }
	return;
}


