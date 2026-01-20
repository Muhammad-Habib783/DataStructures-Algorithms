#include<iostream>
using namespace std;
void SwapArrays(int* arr1,int* arr2,int size) // this is for swap two arrays
{
    for(int i=0;i<size;i++)
     {
        int temp=*(arr1+i);
        *(arr1+i)=*(arr2+i);
        *(arr2+i)=temp;
    }
}
int main()
 {
     int SIZE=5; // declare and initializ size of array 
    int NumAry1[SIZE],NumAry2[SIZE];
    cout<<"\n Enter "<<SIZE<<" elements for NumAry1 ";
    for(int i=0;i<SIZE;i++) 
    {
        cout<<"\n enter "<<i+1<<" element";
        cin>>NumAry1[i];
    }
    cout<<"\n Enter "<<SIZE<<" elements for NumAry2 ";
    for(int i=0;i<SIZE;i++) 
    {
        cout<<"\n enter "<<i+1<<" element";
        cin>>NumAry2[i];
    }
    cout<<"\n before swaping ";
    cout<<"\n NumAry1 ";
    for(int i=0;i<SIZE;i++) 
    {
        cout<<NumAry1[i];
    }
    cout<<"\n NumAry2 ";
    for(int i=0;i<SIZE;i++) 
    {
        cout<<NumAry2[i];
    }
    SwapArrays(NumAry1,NumAry2,SIZE);
    cout<<"\n After Swaping";
    cout<<"\n NumAry1 was ";
    for(int i=0;i<SIZE;i++) 
    {
        cout<<NumAry1[i];
    }
    cout<<"\n NumAry2 was ";
    for(int i=0;i<SIZE;i++) 
    {
        cout<<NumAry2[i];
    }
    return 0;
}