#include <iostream>
using namespace std;
int main()
{
int n1, n2, *ptr;
ptr = &n1;
*ptr = 4;
ptr = &n2;
*ptr = 3;
cout<< n1 << endl << n2;

return 0;
}
