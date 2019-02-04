/*******************************************************
* usage of pointers in C
This is one of the most important topics in any programming language.
Pointers are used in almost all the programming language.
In this file we will handle all the possible pointer usage
********************************************************/

#include "stdio.h"
#include "stdlib.h"

const int M = 3;
const int N = 3;

#define SIZE_N 3
#define SIZE_M 3

/* function definition to swap the values */
void swap(int *x, int *y)
{
   int temp;

   temp = *x;    /* save the value at address x */
   *x = *y;      /* put y into x */
   *y = temp;    /* put temp into y */

   return;
}

double getAverage(int arr[], int size) {

   int i;
   double avg;
   double sum = 0;

   for (i = 0; i < size; ++i)
   {
      sum += arr[i];
   }

   avg = sum / size;

   return avg;
}

void print1(int arr[M][N])
{
    int i, j;
    for (i = 0; i < M; i++)
      for (j = 0; j < N; j++)
        printf("%d ", arr[i][j]);
}

//When only second dimension is available globally (either as a macro or as a global constant).
void print2(int arr[][N], int m)
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < N; j++)
        printf("%d ", arr[i][j]);
}

//If compiler is C99 compatible
//From C99, C language supports variable sized arrays to be passed simply by specifying the variable dimensions
// n must be passed before the 2D array
void print3(int m, int n, int arr[][n])
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        printf("%d ", arr[i][j]);
}

//Using a single pointer
void print4(int *arr, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        printf("%d ", *((arr+i*n) + j));
}

void FuncD(int *x, int *y)
{
    *x = 5;   // return values
    *y = 10;
}

void FuncC(int *x, int *y)
{
    FuncD(x, y);
}

void FuncB(int *x, int *y)
{
    FuncC(x, y);
}

void FuncA()
{
    int x, y;
    FuncB(&x, &y);   // pass address of parameters
    printf("x %d y %d\n", x, y);
}


int main()
{
	int a = 10, b=100; // let us initialize two variables
	int darr2[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int darr12[][SIZE_N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m = 3, n = 3;
	char arr[4];
	int i;
	/* an int array with 5 elements */
	int balance[5] = {1000, 2, 3, 17, 50};
	double avg;
	int* normal_ptr; // usage type 1
	const int* const_ptr1;// usage type 2
	int const* const_ptr2;// usage type 3
	int* const_val_ptr;// usage type 4
	const int* const const_val_const_ptr =&b;
	// this has to be initialized because the value is constant and cant be changed during the program

	// This is the normal usage of the pointer
	normal_ptr = &a;
	printf("The address of a = %d, The value = %d\n\n", normal_ptr, *normal_ptr);

	// here the pointer can be incremented the value pointed cannot be changed
	const_ptr1 = &a;
	// *const_ptr1 = 11; //this statement should throw error as the value in it cannot be changed, uncomment and check
	printf("The address of a = %d, The value = %d\n\n", const_ptr1, *const_ptr1);
	const_ptr1++; // This operation is OK


	// looks different but it is exactly same as const_ptr1
	const_ptr2 = &a;
    	//*const_ptr2 = 11; //this statement should throw error as the value in it cannot be changed, uncomment and check
	printf("The address of a = %d, The value = %d\n\n", const_ptr2, *const_ptr2);
	const_ptr2++;// This operation is OK


	// Here it is bit tricky both the pointer and the value are constant, you cant change anything
	// const_val_const_ptr++; //throws error, uncomment and check
	//*const_val_const_ptr = 90;//throws error,uncomment and check
	printf("The address of b = %d, The value = %d\n\n", const_val_const_ptr, *const_val_const_ptr);

	printf("Before swap, value of a : %d\n", a );
	printf("Before swap, value of b : %d\n", b );

	/* calling a function to swap the values.
	* &a indicates pointer to a ie. address of variable a and
	* &b indicates pointer to b ie. address of variable b.
	*/
	swap(&a, &b);

	printf("After swap, value of a : %d\n", a );
	printf("After swap, value of b : %d\n", b );

	/*
	arr and &arr[0] points to the address of the first element.
	&arr[0] is equivalent to arr

	Since, the addresses of both are the same, the values of arr and &arr[0] are also the same.
	arr[0] is equivalent to *arr (value of an address of the pointer)

	Similarly,
	&arr[1] is equivalent to (arr + 1) AND, arr[1] is equivalent to *(arr + 1).
	&arr[2] is equivalent to (arr + 2) AND, arr[2] is equivalent to *(arr + 2).
	&arr[3] is equivalent to (arr + 3) AND, arr[3] is equivalent to *(arr + 3).
	.
	.
	&arr[i] is equivalent to (arr + i) AND, arr[i] is equivalent to *(arr + i).
	*/

	for(i = 0; i < 4; ++i)
	{
      		printf("Address of arr[%d] = %u\n", i, &arr[i]);
	}

	/* Way-1

	Formal parameters as a pointer −
	void myFunction(int *param) {
	   .
	   .
	   .
	}

	Way-2

	Formal parameters as a sized array −
	void myFunction(int param[10]) {
	   .
	   .
	   .
	}

	Way-3

	Formal parameters as an unsized array −
	void myFunction(int param[])
	{
	   .
	   .
	   .
	}

   	Pointer expression of 2-D array:
	the array name itself is a pointer to first sub array,

	arr:
	will be pointer to first sub array, not the first element of first sub
	array, according to relationship of array & pointer, it also represent
	the array itself,

	arr+1:
	will be pointer to second sub array, not the second element of first sub
	array,

	*(arr+1):
	will be pointer to first element of second sub array,
	according to relationship of array & pointer, it also represent second
	sub array, same as arr[1],

	*(arr+1)+2:
	will be pointer to third element of second sub array,

	*(*(arr+1)+2):
	will get value of third element of second sub array,
	same as arr[1][2], */

	/* pass pointer to the array as an argument */
   	avg = getAverage( balance, 5 ) ;

   	/* output the returned value */
   	printf( "Average value is: %f ", avg );

   	print2(darr2, 3);
   	print3(m, n, darr2);
   	print4((int *)darr2, m, n);
   	print1(darr12);

   	return 0;
}
