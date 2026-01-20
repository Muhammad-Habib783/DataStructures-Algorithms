#include "CCTV.h"
// Default Constructor
	CCTV::CCTV()
		: StreetAsset()  // Calls base class default constructor
	{
		this->resolution = "Unknown";
		this->fieldOfView = 0.0;
		this->isRotatable = false;
		this->storageCapacity = 0;
	}
// Parameterized Constructor
	CCTV::CCTV(int givenId, string givenName, string givenLocation, bool givenStatus, string givenType,
			   string givenResolution, float givenFieldOfView, bool givenIsRotatable, int givenStorageCapacity)
		: StreetAsset(givenId, givenName, givenLocation, givenStatus, givenType)
	{
		this->resolution = givenResolution;
		this->fieldOfView = givenFieldOfView;
		this->isRotatable = givenIsRotatable;
		this->storageCapacity = givenStorageCapacity;
	}
// Setters
	void CCTV::setResolution(string givenResolution)
	{
		this->resolution = givenResolution;
	}

	void CCTV::setFieldOfView(float givenFieldOfView)
	{
		this->fieldOfView = givenFieldOfView;
	}

	void CCTV::setIsRotatable(bool givenIsRotatable)
	{
		this->isRotatable = givenIsRotatable;
	}

	void CCTV::setStorageCapacity(int givenStorageCapacity)
	{
		this->storageCapacity = givenStorageCapacity;
	}
// Getters
	string CCTV::getResolution()
	{
		return this->resolution;
	}

	float CCTV::getFieldOfView()
	{
		return this->fieldOfView;
	}

	bool CCTV::getIsRotatable()
	{
		return this->isRotatable;
	}

	int CCTV::getStorageCapacity()
	{
		return this->storageCapacity;
	}
// Display Information
	void CCTV::displayInfo()
	{
		StreetAsset::displayInfo();  // Call parent info
		cout << "Resolution: " << this->resolution << endl;
		cout << "Field of View: " << this->fieldOfView << "�" << endl;
		cout << "Rotatable: " << (this->isRotatable ? "Yes" : "No") << endl;
		cout << "Storage Capacity: " << this->storageCapacity << " GB" << endl;
	}
