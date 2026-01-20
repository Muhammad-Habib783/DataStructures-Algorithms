#include <iostream>
using namespace std;
int main()
{
int n1 = 5 , n2;
int *p1 , *p2;
p1 = &n1;
p2 = &n2;
n2 = 5;
cout<<*p1 << endl;
cout<<*p2 << endl;

return 0;
}
