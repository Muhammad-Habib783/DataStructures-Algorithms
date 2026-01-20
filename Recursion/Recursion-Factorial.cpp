#include <iostream>
using namespace std;
int Factorial(int);
int main() 
{
    int num;
    cout<<"Enter a number to find factorial: ";
    cin >> num;
    cout << "Factorial of " << num <<" = " << Factorial(num);
    return 0;
}
int Factorial(int n) 
{
    if (n <= 1) 
    {
        return 1;
    }
    else 
    {
        return n * Factorial( n - 1 );
    }
}
