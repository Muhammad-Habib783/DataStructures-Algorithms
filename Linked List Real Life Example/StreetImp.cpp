#include "Street.h"
#include <iostream>
using namespace std;
//*************** Constructors ***************
	Street::Street()
	{
		this->head = NULL;
		this->tail = NULL;
	}
//*************** Getters & Setters ***************
	void Street::setHead(StreetAsset* head)
	{
		this->head = head;
	}
	StreetAsset* Street::getHead()
	{
		return this->head;
	}
	void Street::setTail(StreetAsset* tail)
	{
		this->tail = tail;
	}
	StreetAsset* Street::getTail()
	{
		return this->tail;
	}

//*************** Utility Methods ***************
	bool Street::isEmpty()
	{
		if (this->head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int Street::countAssets()
	{
		int count = 0;
		StreetAsset* temp = this->head;
		while (temp != NULL)
		{
			count++;
			temp = temp->getNext(); // assuming StreetAsset has a getNext() method
		}
		return count;
	}
//*************** Asset Operations ***************
	void Street::addAssetAtHead(StreetAsset* asset)
	{
		if (isEmpty())
		{
			this->head = asset;
			this->tail = asset;
		}
		else
		{
			asset->setNext(this->head);
			this->head = asset;
		}
	}
	void Street::addAssetAtTail(StreetAsset* asset)
	{
		if (isEmpty())
		{
			addAssetAtHead(asset);
		}
		else
		{
			this->tail->setNext(asset);
			this->tail = asset;
		}
	}
	StreetAsset* Street::findAssetById(int assetId)
	{
		StreetAsset* temp = this->head;
		while (temp != NULL)
		{
			if (temp->getId() == assetId)
				return temp;

			temp = temp->getNext();
		}
		return NULL;
	}
	void Street::addAssetAfterId(int targetId, StreetAsset* asset)
	{
		StreetAsset* target = findAssetById(targetId);
		if (target == NULL)
		{
			cout << "Asset with ID " << targetId << " not found." << endl;
			return;
		}

		if (target == this->head)
		{
			addAssetAtHead(asset);
		}
		else if (target == this->tail)
		{
			addAssetAtTail(asset);
		}
		else
		{
			asset->setNext(target->getNext());
			target->setNext(asset);
		}
	}
	void Street::removeAssetById(int assetId)
	{
		if (isEmpty())
		{
			cout << "No assets to remove." << endl;
			return;
		}

		StreetAsset* temp = this->head;
		StreetAsset* prev = NULL;

		while (temp != NULL && temp->getId() != assetId)
		{
			prev = temp;
			temp = temp->getNext();
		}

		if (temp == NULL)
		{
			cout << "Asset with ID " << assetId << " not found." << endl;
			return;
		}

		// Case 1: Removing head
		if (temp == this->head)
		{
			this->head = this->head->getNext();
			temp->setNext(NULL);
			delete temp;
		}
		// Case 2: Removing tail
		else if (temp == this->tail)
		{
			this->tail = prev;
			this->tail->setNext(NULL);
			delete temp;
		}
		// Case 3: Middle node
		else
		{
			prev->setNext(temp->getNext());
			temp->setNext(NULL);
			delete temp;
		}
	}
   void Street::updateAssetById(int assetId, StreetAsset* updatedAsset)
	{
		StreetAsset* target = findAssetById(assetId);
		if (target == NULL)
		{
			cout << "Asset with ID " << assetId << " not found." << endl;
			return;
		}

		// Copy fields from updated asset to the existing one
		target->setName(updatedAsset->getName());
		target->setLocation(updatedAsset->getLocation());
		target->setStatus(updatedAsset->getStatus());
		target->setType(updatedAsset->getType());
	}

	void Street::displayAllAssets()
	{
		if (isEmpty())
		{
			cout << "No assets found on this street." << endl;
			return;
		}

		StreetAsset* temp = this->head;
		while (temp != NULL)
		{
			cout << "---------------------------------" << endl;
			temp->displayInfo(); // polymorphic display
			cout << "---------------------------------" << endl;
			temp = temp->getNext();
		}
	}
