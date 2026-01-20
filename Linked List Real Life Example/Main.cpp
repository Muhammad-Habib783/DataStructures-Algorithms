#include <iostream>
#include "StreetAsset.h"
#include "Street.h"
#include "StreetLight.h"
#include "SmartBench.h"
#include "CCTV.h"
#include "Dustbin.h"
using namespace std;
int main() 
{
	Street street;
	int choice;
	do 
	{
		cout << "\n===== Smart City Street Asset Management =====\n";
		cout << "1. Add Asset\n";
		cout << "2. Remove Asset by ID\n";
		cout << "3. Display All Assets\n";
		cout << "4. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;
		cout << endl;

		if (choice == 1) 
		{
			int typeChoice;
			cout << "Select Asset Type:\n";
			cout << "1. Street Light\n";
			cout << "2. Smart Bench\n";
			cout << "3. CCTV\n";
			cout << "4. Smart Dustbin\n";
			cout << "Enter type: ";
			cin >> typeChoice;

			int id;
			string name;
			string location;
			bool status;
			cout << "\nEnter ID: "; 
			cin >> id;
			cout << "\nEnter Name: "; 
			cin >> name;
			cout << "\nEnter Location: "; 
			cin >> location;
			cout << "\nStatus (1=Active, 0=Faulty): "; 
			cin >> status;

			StreetAsset* asset = NULL;

			if (typeChoice == 1) 
			{
				int brightness; 
				bool autoMode; 
				float power;
				
				cout << "\nBrightness Level: "; 
				cin >> brightness;
				cout << "\nAutomatic (1/0): "; 
				cin >> autoMode;
				cout << "\nPower (W): "; 
				cin >> power;
				asset = new StreetLight(id, name, location, status, "StreetLight", brightness, autoMode, power);
			}
			else if (typeChoice == 2) 
			{
				bool hasCharger;
				bool hasLight;
				bool occupied;
				string chargerType;

				cout << "\nHas Charger (1/0): "; 
				cin >> hasCharger;
				cout << "\nCharger Type: "; 
				cin >> chargerType;
				cout << "\nHas Light Support (1/0): "; 
				cin >> hasLight;
				cout << "\nOccupied (1/0): "; 
				cin >> occupied;
				asset = new SmartBench(id, name, location, status, "SmartBench", hasCharger, chargerType, hasLight, occupied);
			}
			else if (typeChoice == 3) 
			{
				string resolution; 
				float fov; 
				bool rotatable; 
				int storage;

				cout << "\nResolution: "; 
				cin >> resolution;
				cout << "\nField of View: "; 
				cin >> fov;
				cout << "\nRotatable (1/0): "; 
				cin >> rotatable;
				cout << "\nStorage (GB): "; 
				cin >> storage;
				asset = new CCTV(id, name, location, status, "CCTV", resolution, fov, rotatable, storage);
			}
			else if (typeChoice == 4) 
			{
				float capacity;
				float fill;
				float temp;

				cout << "\nCapacity (liters): "; 
				cin >> capacity;
				cout << "\nFill Level (liters): "; 
				cin >> fill;
				cout << "\nTemperature (C): "; 
				cin >> temp;
				asset = new Dustbin(id, name, location, status, "Dustbin", capacity, fill, temp);
			}

			if (asset != NULL) 
			{
				street.addAssetAtTail(asset);
				cout << "\n Asset added successfully!\n";
			}
		}

		else if (choice == 2) {
			int id;
			cout << "Enter Asset ID to remove: ";
			cin >> id;
			street.removeAssetById(id);
		}

		else if (choice == 3) {
			street.displayAllAssets();
		}

	} while (choice != 4);

	cout << "\nExiting program. Goodbye!\n";
	return 0;
}