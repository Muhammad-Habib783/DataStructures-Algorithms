#include "StreetAsset.h"
// Default Constructor
	StreetAsset::StreetAsset()
	{
		this->id = 0;
		this->name = "Unknown";
		this->location = "Unspecified";
		this->status = false;
		this->type = "Generic";

		this->next = NULL;
	}
// Parameterized Constructor
	StreetAsset::StreetAsset(int givenId, string givenName, string givenLocation, bool givenStatus, string givenType)
	{
		this->id = givenId;
		this->name = givenName;
		this->location = givenLocation;
		this->status = givenStatus;
		this->type = givenType;

		this->next = NULL;
	}
// Setters
	void StreetAsset::setId(int givenId)
	{
		this->id = id;
	}

	void StreetAsset::setName(string givenName)
	{
		this->name = givenName;
	}

	void StreetAsset::setLocation(string givenLocation)
	{
		this->location = givenLocation;
	}

	void StreetAsset::setStatus(bool givenStatus)
	{
		this->status = givenStatus;
	}

	void StreetAsset::setType(string givenType)
	{
		this->type = givenType;
	}

	void StreetAsset::setNext(StreetAsset* next)
	{
		this->next = next;
	}
// Getters
	int StreetAsset::getId()
	{
		return this->id;
	}

	string StreetAsset::getName()
	{
		return this->name;
	}

	string StreetAsset::getLocation()
	{
		return this->location;
	}

	bool StreetAsset::getStatus()
	{
		return this->status;
	}

	string StreetAsset::getType()
	{
		return this->type;
	}

	StreetAsset* StreetAsset::getNext()
	{
		return this->next;
	}
// Display Information
	void StreetAsset::displayInfo()
	{
		cout << "Asset ID: " << this->id << endl;
		cout << "Name: " << this->name << endl;
		cout << "Location: " << this->location << endl;
		cout << "Status: " << (this->status ? "Active" : "Faulty") << endl;
		cout << "Type: " << this->type << endl;
	}
