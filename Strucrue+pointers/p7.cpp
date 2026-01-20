#include <iostream>
using namespace std;
int main()
{

       void order(int*, int*);   // prototype

       int n1=99, n2=11;      //one pair ordered, one not
       int n3=22, n4=88;

       order( &n1, &n2 ); 	   //order each pair of numbers
       order( &n3, &n4 );

       cout << "\n Number 1 = " << n1 << endl; 
       cout << "\n Number 2 = " << n2 << endl;
       cout << "\n Number 3 = " << n3 << endl;
       cout << "\n Number 4 = " << n4 << endl;
       return 0;
}
void order(int* num1, int* num2)
{
       if(*num1 > *num2) 	// if 1st larger than 2nd,
       {
              int temp = *num1; 	//swap them
              *num1 = *num2;
              *num2 = temp;
       }
       
}	
