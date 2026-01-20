#include <iostream>
using namespace std;
int main()
{
int *p1, n1=25;
int *p2;
p1=&n1;
p2=&n1;
p1=p2;
p2=p1;
cout<<p1<<endl<<p2<<endl;
cout<<*p1<<endl<<*p2<<endl;
return 0;
}
