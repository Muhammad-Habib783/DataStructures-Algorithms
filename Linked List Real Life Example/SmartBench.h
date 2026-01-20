#pragma once
#include "StreetAsset.h"
#include <string>
#include <iostream>
using namespace std;
class SmartBench : public StreetAsset
{
    private:
        bool hasCharger;        // Indicates if the bench has a charging port
        string chargerType;     // Type of charger (e.g., USB, Wireless)
        bool hasLightSupport;   // Indicates if the bench has lighting
        bool occupied;          // Indicates if someone is currently using the bench

    public:
        // Default Constructor
			SmartBench();

        // Parameterized Constructor
			SmartBench(int, string, string, bool, string, bool, string, bool, bool);

        // Setters
			void setHasCharger(bool);
			void setChargerType(string);
			void setHasLightSupport(bool);
			void setOccupied(bool);

        // Getters
			bool getHasCharger();
			string getChargerType();
			bool getHasLightSupport();
			bool getOccupied();

        // Display Information
			void displayInfo();
};
