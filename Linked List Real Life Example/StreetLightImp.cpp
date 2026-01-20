#include "StreetLight.h"
// Default Constructor
	StreetLight::StreetLight() : StreetAsset()
	{
		this->brightnessLevel = 0;
		this->isAutomatic = false;
		this->powerConsumption = 0.0;
		this->setType("StreetLight");  // Define the type for base class
	}
// Parameterized Constructor
	StreetLight::StreetLight(int givenId, string givenName, string givenLocation, bool givenStatus, string givenType,
							 int givenBrightness, bool givenAutomatic, float givenPower)
		: StreetAsset(givenId, givenName, givenLocation, givenStatus, givenType)
	{
		this->brightnessLevel = givenBrightness;
		this->isAutomatic = givenAutomatic;
		this->powerConsumption = givenPower;
	}
// Setters
	void StreetLight::setBrightnessLevel(int givenBrightness)
	{
		this->brightnessLevel = givenBrightness;
	}

	void StreetLight::setIsAutomatic(bool givenAutomatic)
	{
		this->isAutomatic = givenAutomatic;
	}

	void StreetLight::setPowerConsumption(float givenPower)
	{
		this->powerConsumption = givenPower;
	}
// Getters
	int StreetLight::getBrightnessLevel()
	{
		return this->brightnessLevel;
	}

	bool StreetLight::getIsAutomatic()
	{
		return this->isAutomatic;
	}

	float StreetLight::getPowerConsumption()
	{
		return this->powerConsumption;
	}
// Display Information
	void StreetLight::displayInfo()
	{
		cout << "----- Street Light Information -----" << endl;
		cout << "Asset ID: " << this->id << endl;
		cout << "Name: " << this->name << endl;
		cout << "Location: " << this->location << endl;
		cout << "Status: " << (this->status ? "Active" : "Faulty") << endl;
		cout << "Brightness Level: " << this->brightnessLevel << "%" << endl;
		cout << "Automatic Mode: " << (this->isAutomatic ? "Enabled" : "Disabled") << endl;
		cout << "Power Consumption: " << this->powerConsumption << " watts" << endl;
	}
