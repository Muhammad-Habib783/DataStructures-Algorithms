#include <iostream>
using namespace std;
void insertionSort(int arr[], int n) 
{ 
    // O(n^2) time complexity
    for (int i = 1; i < n; i++)
     {
        int curr = arr[i];
        int prev = i - 1;
  // move elements greater than key one position ahead
        while (prev >= 0 && arr[prev] > curr) 
        {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}
int main() 
{
    int arr[] = {4,1,5,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}