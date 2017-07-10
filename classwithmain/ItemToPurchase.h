#ifndef ItemToPurchase_H // in the .h, include these 
#define ItemToPurchase_H

#include <iostream> // Two files for one class
#include <cstdlib> // .h is like the interface, .cpp contains definitions.

//ClassName.h	Contains the class definition, including data members and member function declarations

using namespace std; // DECLARATION CLASS

class ItemToPurchase {
	public:
		ItemToPurchase();
		string GetName();
		void SetName(string itemName);
		int GetPrice();
		void SetPrice(int itemPrice);
		int GetQuantity();
		void SetQuantity(int itemQuantity);
		
	private:
		string itemName;
		int itemPrice;
		int itemQuantity;
};

#endif