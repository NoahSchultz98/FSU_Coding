#include <iostream>
//#include "pch.h"
using namespace std;


void array_accomodation(int *array1, int size);

void display(int *array2, int size);

void merge(int *a, int *b, int *c, int size1, int size2);
void merge_sort(int *x, int size);

int main()
{
	int *a;
	int size;

	cout << "How many numbers do you want to accommodate in a?\n " << endl;

	cin >> size;
	cout << "Enter your " << size << "  numbers to be sorted" << endl;
	a = new int[size];
	array_accomodation(a, size);
	cout << "This is your original array" << endl;
	display(a, size);
	merge_sort(a, size);
	cout << "This is your sorted array" << endl;
	display(a, size);
   
   return 0;

}

/*

  merge function merges two sorted arrays a and b into array c. We compare a[i] and b[j] and accommodate the smaller
  number into array c moving the corresponding markers. For example if a[i]<b[j], a[i] will be put into c[k]
  and we increment i and k
	 If it happens that we have accommodated the whole array a,
  we copy to c what is left of b and vice versa, if all members of b are accommodated in c, we copy
  the rest of a into c.


  */
void merge(int *a, int *b, int *c, int size1, int size2)
{
	int i = 0, j = 0, k = 0, index;

	while (i < size1 && j < size2)
	{
		if (a[i] <= b[j])
		{
			c[k] = a[i];
			i++;
			k++;
		}

		if (a[i] >= b[j])
		{
			c[k] = b[j];
			j++;
			k++;
		}



	}

	//if all memebrs of a are already in c, copy the rest of b into c
	if (i == size1)
		for (index = j; index < size2; index++)
		{
			c[k] = b[index];
			k = k + 1;
		}

	//if all memebrs of b are already in c, copy the rest of a into c

	if (j == size2)
		for (index = i; index < size1; index++)
		{
			c[k] = a[index];
			k++;
		}

}
void array_accomodation(int *array1, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		cin >> array1[i];

	}

}


//Explain in YOUR OWN WORDS how the sort works
void merge_sort(int *x, int n)
{
	int *z, *y, y_size = n / 2, z_size = n - (n / 2), i, j;
   //create two new array pointers using half the size that was passed into the function
	if (n > 1)// if the size of the array is greater than 1 then we have not split all the arrays yer
	{
		y = new int[y_size]; // allocate memory for an array reference it with the int pointer we made

		for (i = 0, j = 0; j < y_size; i++, j++)
			y[j] = x[i]; // take each of the first half of the array x and put it into out allocated array y

		
// allocate space for array z and copy the second half of x into z
//call mergesort for y and z and then merge these sorted sarrays
      
      z = new int[z_size]; //set a new array of half the size n (i dont understand how this is different than y_size)
      
      for(j = 0; j < z_size; i++, j++)
         z[j] = x[i]; // same as before, but we take from x from the same index that we left off at with the array y
      
		merge_sort(z, z_size);
		merge_sort(y, y_size);
		merge(y, z, x, y_size, z_size);
      // call the merge sort functions with the new arrays we made that are half of x
      // once we reach the bottom of the array we use the merge function on y and z into x 
      // very cool, but also very complicated.
	}

}


void display(int *a, int size)
{
	int i;

	for (i = 0; i < size; i++)
		cout << a[i] << endl;
	cout << endl;
}