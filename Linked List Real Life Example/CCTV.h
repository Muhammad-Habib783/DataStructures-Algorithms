#pragma once
#include "StreetAsset.h"
#include <string>
#include <iostream>
using namespace std;
class CCTV : public StreetAsset
{
    private:
        string resolution;       // Resolution of the CCTV camera
        float fieldOfView;       // Field of view in degrees
        bool isRotatable;        // Can the camera rotate
        int storageCapacity;     // Storage capacity in GB

    public:
        // Default Constructor
			CCTV();

        // Parameterized Constructor
			CCTV(int, string, string, bool, string, string, float, bool, int);

        // Setters
			void setResolution(string);
			void setFieldOfView(float);
			void setIsRotatable(bool);
			void setStorageCapacity(int);

        // Getters
			string getResolution();
			float getFieldOfView();
			bool getIsRotatable();
			int getStorageCapacity();

        // Display Information
			void displayInfo();
};
