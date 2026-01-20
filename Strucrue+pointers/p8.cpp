#include <iostream>
using namespace std;
int main()
{

       void SortNumers(int*, int); 	//prototype
       const int N = 10; 		//NumersArray size        

       int NumersArray[N] = { 37, 84, 62, 91, 11, 65, 57, 28, 19, 49 };

       SortNumers(NumersArray, N); 	// sort the array

       for(int j=0; j<N; j++) 	            //print out sorted array
          cout << NumersArray[j] << endl;
 
      return 0;
}
//--------------------------------------------------------------
void SortNumers(int* ptr, int n)
{
       void order(int*, int*); 	// prototype
       int j, k; 		           // indexes to array

       for(j=0; j<n-1; j++) 	//outer loop
          for( k = j+1; k < n; k++) 	//inner loop starts at outer
              order(ptr+j,   ptr+k); 	//order the pointer contents
}
//--------------------------------------------------------------
void order(int* ptr1, int* ptr2) 	// orders two numbers
{
       if(*ptr1 > *ptr2) 		// if 1st larger than 2nd,
       {
              int temp = *ptr1; 		//swap them
            
              *ptr1 = *ptr2;
              *ptr2 = temp;
       }
}

