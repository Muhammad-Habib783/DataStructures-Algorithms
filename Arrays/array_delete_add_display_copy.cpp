#include <iostream>
using namespace std;
int main() 
{
    int size = 5;
    int* array = new int[size]; // Initial array of size 5
    int values = 0;
    // Taking initial input
    for (int i = values; i < size; i++) 
    {
        cout << "Enter value for index " << i << ": ";
        cin >> array[i];
        values++;
    }
   // Displaying initial array
    cout << "\nInitial array contents:\n";
    for (int i = 0; i < size; i++) 
    {
        cout << "Index: " << i << " | Value: " << array[i] << endl;
    }
   // Creating new array with larger size
    int* temp = new int[size + 5];
   // Copying data to new array
    for (int i = 0; i < size; i++) 
    {
        temp[i] = array[i];
    }
    // Reassigning and updating size
    delete[] array;
    array = temp;
    size += 5;
    // Taking input for new space
    for (int i = values; i < size; i++) 
    {
        cout << "Enter value for index " << i << ": ";
        cin >> array[i];
        values++;
    }
    // Displaying resized array
    cout << "\nResized array contents:\n";
    for (int i = 0; i < size; i++) 
    {
        cout << "Index: " << i << " | Value: " << array[i] << endl;
    }
    // Cleaning up
    delete[] array;
    return 0;
}