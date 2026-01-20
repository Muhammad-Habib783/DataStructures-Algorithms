#pragma once
#include"StreetAsset.h"
#include <iostream>
using namespace std;
class StreetLight : public StreetAsset
{
    private:
        int brightnessLevel;     // Brightness in percentage (0�100)
        bool isAutomatic;        // Automatic ON/OFF mode
        float powerConsumption;  // Power usage in watts

    public:
        // Default Constructor
			StreetLight();

        // Parameterized Constructor
			StreetLight(int, string, string, bool, string, 
						int, bool, float);

        // Setters
			void setBrightnessLevel(int);
			void setIsAutomatic(bool);
			void setPowerConsumption(float);

        // Getters
			int getBrightnessLevel();
			bool getIsAutomatic();
			float getPowerConsumption();

        // Override displayInfo()
			void displayInfo();
};
