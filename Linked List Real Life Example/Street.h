#pragma once
#include "StreetAsset.h"
#include <iostream>
using namespace std;
class Street 
{
private:
    StreetAsset* head;     // Pointer to first asset
    StreetAsset* tail;     // Pointer to last asset

public:
    //*************** Constructors & Destructor ***************
		Street();

    //*************** Setters & Getters ***************
		void setHead(StreetAsset* head);
		StreetAsset* getHead();

		void setTail(StreetAsset* tail);
		StreetAsset* getTail();

    //*************** Utility Methods ***************
		bool isEmpty();
		int countAssets();

    //*************** Asset Operations ***************
		void addAssetAtHead(StreetAsset* asset);
		void addAssetAtTail(StreetAsset* asset);
		void addAssetAfterId(int targetId, StreetAsset* asset);

		StreetAsset* findAssetById(int assetId);
		void removeAssetById(int assetId);
		void updateAssetById(int assetId, StreetAsset* updatedAsset);

    //*************** Display ***************
		void displayAllAssets();
};
