#include <iostream>
using namespace std;
int calculatePower(int, int);
int main()
{
    int base, exponent, result;

    cout << "Enter base     = ";
    cin >> base;

    cout << "Enter exponent = ";
    cin >> exponent;

    result = calculatePower(base, exponent);
    cout << "           " << base << "^" << exponent << " = " << result;

    return 0;
}
int calculatePower(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    else
        return ( base * calculatePower(base, exponent-1) );
}
