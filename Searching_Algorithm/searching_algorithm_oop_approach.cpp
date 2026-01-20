#include<iostream>
using namespace std;
class Search
{
	private:
	//Attribute
		int size ;
		int* list ;
		int value ;
	public:
	//Constructors
		Search()
		{
			size = 3;
			list = new int[size];
			value = 0;
		}
	//Methods
		int inputData()
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
						return 0;
					}
				}
			}
			return 0;
		}
		void displayData()
		{
			for(int loop = 0; loop < value; loop++)
			{
				cout << "Value at " << loop << " index : " << list[loop]
				<< endl ;
			}
		}

		void resizeArray()
		{
			int* temp = new int [size+2] ;
			for( int loop = 0 ; loop < value ; loop++ ) 
			{ 
				temp [ loop ] = list [ loop ] ; 
			}
			delete[] list; 
			list = temp; 
		}
		void LinearSearch(int find)
		{
			for( int loop = 0 ; loop < 5 ; loop ++ )
			{
				if ( find == list [ loop ] )
				{
					cout << "Value found on "<< loop <<" index." << endl ;
				}
			}

		}
		void BinarySearch(int find)
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
};
int main()
{
	int choice = 0;
	int find = 0;
	Search obj;
	do
		{
		cout << "1:Input Data" << endl;
		cout << "2:Display Data" << endl;
		cout << "3:Resize Array" << endl;
		cout << "4:Linear Searching" << endl;
		cout << "5:Binary Searching" << endl;
		cout << "6:Exit" << endl;
		cin>> choice;
    	switch(choice)
		{
			case 1:
				obj.inputData();
			break;

			case 2:
				obj.displayData();
			break;

			case 3:
				obj.resizeArray();
			break;

			case 4:
				cout << "Enter the value you want to find : ";
				cin >> find ;
				obj.LinearSearch(find);
			break;

			case 5:
				cout << "Enter the value you want to find : ";
				cin >> find ;
				obj.BinarySearch(find);
			break;

			case 6:
				exit(0);
			break;
		}
	} while (true);
	system("pause");
	return 0;
}