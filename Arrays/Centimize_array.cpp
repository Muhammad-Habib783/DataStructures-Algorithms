#include<iostream>
using namespace std;
int Centimize(double* ptr)
{
       *ptr=(*ptr)*2.54; 		
       return *ptr;
}
int main()
{
    double length;
    cout<<"Enter the length  ";
    cin>>length;
    cout<<"\n Length before conversion is "<<length;
    Centimize(&length);
    cout<<"\n Length after conversion is "<<length;
    return 0;
}
