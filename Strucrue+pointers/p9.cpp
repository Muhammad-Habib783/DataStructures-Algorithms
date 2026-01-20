#include <iostream>
using namespace std;
const int MAX = 5;		 //number of array elements
int main()
{
      void Centimize(double*); 		// function prototype
      double Distances[MAX] = { 10.0, 43.1, 95.9, 59.7, 87.3 };
      Centimize(Distances);        //change elements of array to centimeters

      for(int j=0; j<MAX; j++) 		//display new array values
        cout << "\n Distances[" << j << "]=" << Distances[j] << " cm" << endl; 

      return 0;
}
void Centimize(double* ptrd)
{
       for( int j=0;  j<MAX;  j++)
	      *ptrd++  *= 2.54; 		//   *(ptrd ++)  *= 2.54;
}
