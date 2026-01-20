#pragma once
#include "StreetAsset.h"
#include <string>
#include <iostream>
using namespace std;
class Dustbin : public StreetAsset
{
    private:
        float capacity;       // Total capacity in liters
        float fillLevel;      // Current fill level in liters
        float temperature;    // Current temperature inside the bin

    public:
        // Default Constructor
			Dustbin();

        // Parameterized Constructor
			Dustbin(int, string, string, bool, string, float, float, float);

        // Setters
			void setCapacity(float);
			void setFillLevel(float);
			void setTemperature(float);

        // Getters
			float getCapacity();
			float getFillLevel();
			float getTemperature();

        // Display Information
			void displayInfo();
};
