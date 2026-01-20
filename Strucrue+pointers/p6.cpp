#include <iostream>
using namespace std;
int main()
{
int n1, n2;
int *ptr1 = &n1;
int *ptr2 = &n2;
n1 = 35;
n2 = 46;
ptr1 = ptr2;
*ptr1 = 78;

   cout << n1 <<" "<< n2 << endl;
   cout << *ptr1<<" "<< * ptr2 << endl;
   return 0;
}
