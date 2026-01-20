#pragma once
#include <string>
#include <iostream>
using namespace std;
class StreetAsset
{
    protected:
        int id;                  // Unique ID
        string name;             // Name or label
        string location;         // Street name
        bool status;             // true = Active, false = Faulty
        string type;             // Type of asset (e.g., StreetLight, SmartBench)

		StreetAsset* next;

    public:
        // Default Constructor
			StreetAsset();

        // Parameterized Constructor
			StreetAsset(int, string, string, bool, string);

        // Setters
			void setId(int);
			void setName(string);
			void setLocation(string);
			void setStatus(bool);
			void setType(string);

			void setNext(StreetAsset*);

        // Getters
			int getId();
			string getName();
			string getLocation();
			bool getStatus();
			string getType();

			StreetAsset* getNext();

        // Virtual function to display information
			void displayInfo();
};