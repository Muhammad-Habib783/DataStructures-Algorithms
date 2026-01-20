#include "Dustbin.h"
// Default Constructor
	Dustbin::Dustbin() 
		: StreetAsset()   // Calls base class default constructor
	{
		this->capacity = 0.0;
		this->fillLevel = 0.0;
		this->temperature = 0.0;
	}
// Parameterized Constructor
	Dustbin::Dustbin(int givenId, string givenName, string givenLocation, bool givenStatus, string givenType,
					 float givenCapacity, float givenFillLevel, float givenTemperature)
		: StreetAsset(givenId, givenName, givenLocation, givenStatus, givenType)
	{
		this->capacity = givenCapacity;
		this->fillLevel = givenFillLevel;
		this->temperature = givenTemperature;
	}
// Setters
	void Dustbin::setCapacity(float givenCapacity)
	{
		this->capacity = givenCapacity;
	}

	void Dustbin::setFillLevel(float givenFillLevel)
	{
		this->fillLevel = givenFillLevel;
	}

	void Dustbin::setTemperature(float givenTemperature)
	{
		this->temperature = givenTemperature;
	}
// Getters
	float Dustbin::getCapacity()
	{
		return this->capacity;
	}

	float Dustbin::getFillLevel()
	{
		return this->fillLevel;
	}

	float Dustbin::getTemperature()
	{
		return this->temperature;
	}
// Display Information
	void Dustbin::displayInfo()
	{
		StreetAsset::displayInfo();  // Call parent display
		cout << "Capacity: " << this->capacity << " liters" << endl;
		cout << "Current Fill Level: " << this->fillLevel << " liters" << endl;
		cout << "Temperature: " << this->temperature << " �C" << endl;
	}
