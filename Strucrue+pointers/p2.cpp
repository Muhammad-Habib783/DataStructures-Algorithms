#include <iostream>
using namespace std;
int main()
{
int n1 = 50, *p1, *p2;
p1 = &n1;
p2 = p1;
*p1++ = *p2++;
  n1++;
cout<<n1 << endl;
cout<<p1 << endl;
cout<<p2 << endl;

return 0;
}
