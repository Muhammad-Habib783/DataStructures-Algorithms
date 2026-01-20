#include<iostream>
using namespace std;
int inputData(int* list, int size, int value)
{
	int ch = 0;
	for(int loop = value; loop < size; loop++)
	{
		cout << "Enter value at " << loop << " index : " ;
		cin >> list[loop];
		cout << endl ;
		value++;
		if(value!=size)
		{
			cout << "Do you want enter again (1/0) : " ;
			cin >> ch ;
			if(!ch)
			{
				return value;
			}
		}
	}
	return value;
}
void displayData(int* list, int value)
{
	for(int loop = 0; loop < value; loop++)
	{
		cout << "Value at " << loop << " index : " << list[loop]
		<< endl ;
	}
}
int* resizeArray(int* list, int size, int value)
{
	int* temp = new int [size+2] ;
	for( int loop = 0 ; loop < value ; loop++ ) 
	{ 
		temp [ loop ] = list [ loop ] ; 
	}
	delete[] list; 
	list = temp; 
	return list;
}
void LinearSearch(int* list, int value)
{
	for( int loop = 0 ; loop < 5 ; loop ++ )
	{
		if ( value == list [ loop ] )
		{
			cout << "Value found on "<< loop <<" index." << endl ;
		}
	}

}
void BinarySearch(int* list, int size, int find)
{
    int low = 0;
    int high = size - 1;
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (list[mid] == find)
        {
            cout << "Value found at " << mid << " index." << endl;
            return;
        }
        else if (list[mid] < find)
        {
            low = mid + 1;   // move right
        }
        else
        {
            high = mid - 1;  // move left
        }
    }
    cout << "Value not found!" << endl;
}
int main()
{
	int choice = 0;
	int size = 3;
	int* list = new int[size];
	int value = 0;
	int find = 0;
	do
	{
		cout << "1:Input Data" << endl;
		cout << "2:Display Data" << endl;
		cout << "3:Resize Array" << endl;
		cout << "4:Linear Searching" << endl;
		cout << "5:Binary Searching" << endl;
		cout << "6:Exit" << endl;
        cout << "Enter your choice : ";
		cin>> choice;

		switch(choice)
		{
			case 1:
				value = inputData(list, size, value);
			break;

			case 2:
				displayData(list, value);
			break;

			case 3:
				list = resizeArray(list, size, value);
				size+=2;
			break;

			case 4:
				cout << "Enter the value you want to find : ";
				cin >> find ;
				LinearSearch(list, find);
			break;

			case 5:
				cout << "Enter the value you want to find : ";
				cin >> find ;
				BinarySearch(list, size, find);
			break;

			case 6:
				exit(0);
			break;
		}
	} while (true);
	system("pause");
	return 0;
}