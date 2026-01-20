#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	struct Student
	{
		int ID;
		char Name[25];
		float CGPA;
	};
	
	struct TopThree
	{
		Student First;  	
		Student Second;  	
		Student Third; 
	}BSCSTopper;
	//TopThree BSCSTopper;
	BSCSTopper.First.ID = 1;
	strcpy(BSCSTopper.First.Name, "Moiz Jabbar Waqar");
	BSCSTopper.First.CGPA = 4.0;
	TopThree *BSSETopper = &BSCSTopper;		// Assign structure's address to the pointer
    cout << endl << "  Character Array Display" << endl;
	cout << "-------------------------------------" << endl;
	for (int i = 0; i < strlen(BSCSTopper.First.Name); i++)
	{
		cout << "  Name[" << i << "] = " << BSCSTopper.First.Name[i] << endl;
	} 
	cout << endl << "  My Topper Student - Structure Itself"    << endl;
	cout << "---------------------------------------";
	cout << endl << "  My ID     = "   << BSCSTopper.First.ID;
	cout << endl << "  My Name   = "   << BSCSTopper.First.Name;
	cout << endl << "  My CGPA   = "   << BSCSTopper.First.CGPA;
	
	cout << endl;
	cout << endl << "  Your Topper Student - Pointer to Structure" << endl;
	cout << "---------------------------------------------";
	
	cout << endl << "  My ID     = "   << BSSETopper->First.ID;
	cout << endl << "  My Name   = "   << BSSETopper->First.Name;
	cout << endl << "  My CGPA   = "   << BSSETopper->First.CGPA;
		
	return 0;
}

