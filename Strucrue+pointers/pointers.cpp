// Sorting two numbers using their Pointers.
#include<iostream>
using namespace std;
void SortNumbers(int*, int*); 	//prototype
int main()
{
	int n1,n2;	// Declaration of array 'age' of 5 integers

	cout << "\n Enter first number:  ";
	cin >> n1;		// store the given number in n1 variable.

	cout << "\n Enter second number:  ";
	cin >> n2;		// store the given number in n1 variable.

	cout << "\n Before sorting, the two numbers are:" <<n1 <<" "<<n2;

	SortNumbers(&n1, &n2);

	cout << "\n After sorting, the two numbers are:" <<n1 <<" "<<n2;

	return 0;
}
void SortNumbers(int* a1, int* a2)
{
	int temp;
	
	if(*a1 > *a2)
	{
		temp = *a1;
		*a1 = *a2;
		*a2 = temp;
	}
}

