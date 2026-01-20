#include "SmartBench.h"
// Default Constructor
	SmartBench::SmartBench()
		: StreetAsset()  // Calls base class default constructor
	{
		this->hasCharger = false;
		this->chargerType = "None";
		this->hasLightSupport = false;
		this->occupied = false;
	}
// Parameterized Constructor
	SmartBench::SmartBench(int givenId, string givenName, string givenLocation, bool givenStatus, string givenType,
						   bool givenHasCharger, string givenChargerType, bool givenHasLightSupport, bool givenOccupied)
		: StreetAsset(givenId, givenName, givenLocation, givenStatus, givenType)
	{
		this->hasCharger = givenHasCharger;
		this->chargerType = givenChargerType;
		this->hasLightSupport = givenHasLightSupport;
		this->occupied = givenOccupied;
	}
// Setters
	void SmartBench::setHasCharger(bool givenHasCharger)
	{
		this->hasCharger = givenHasCharger;
	}

	void SmartBench::setChargerType(string givenChargerType)
	{
		this->chargerType = givenChargerType;
	}

	void SmartBench::setHasLightSupport(bool givenHasLightSupport)
	{
		this->hasLightSupport = givenHasLightSupport;
	}

	void SmartBench::setOccupied(bool givenOccupied)
	{
		this->occupied = givenOccupied;
	}
// Getters
	bool SmartBench::getHasCharger()
	{
		return this->hasCharger;
	}

	string SmartBench::getChargerType()
	{
		return this->chargerType;
	}

	bool SmartBench::getHasLightSupport()
	{
		return this->hasLightSupport;
	}

	bool SmartBench::getOccupied()
	{
		return this->occupied;
	}
// Display Information
	void SmartBench::displayInfo()
	{
		StreetAsset::displayInfo();  // Call base class display
		cout << "Has Charger: " << (this->hasCharger ? "Yes" : "No") << endl;
		cout << "Charger Type: " << this->chargerType << endl;
		cout << "Has Light Support: " << (this->hasLightSupport ? "Yes" : "No") << endl;
		cout << "Occupied: " << (this->occupied ? "Yes" : "No") << endl;
	}
