#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) // O(n^2) // time complexity
{
    for (int i = 0; i < n-1; i++) // 1*n
    {
        bool isSwap = false; // this is if array is already sorted
        for (int j = 0; j < n-i-1; j++) // n*n times run
        {
            if (arr[j] > arr[j+1]) 
            {
                // swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSwap = true; // this checks whether swap happened or not if yes then continue sorting otherwise break
            }
        }
        if(!isSwap)
        {
            return; // array is already  sorted
        }
    }
}
int main() 
{
    int arr[]={4,1,5,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,n);

    cout << "Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<< " ";
    return 0;
}