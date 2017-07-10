// ClassName.cpp	Contains member function definitions.

#include <iostream> // Two files for one class
#include <cstdlib>// DEFINITION CLASS

using namespace std;

#include "ItemToPurchase.h" // implemented the .h class

ItemToPurchase::ItemToPurchase() {
	itemName = "none";
	itemPrice = 0;
	itemQuantity = 0;
}

string ItemToPurchase::GetName() {
	return itemName;
}

void ItemToPurchase::SetName(string itemName) {
	this->itemName = itemName;
}

int ItemToPurchase::GetPrice() {
	return itemPrice;
}

void ItemToPurchase::SetPrice(int itemPrice) {
	this->itemPrice = itemPrice;
}

int ItemToPurchase::GetQuantity() {
	return itemQuantity;
}

void ItemToPurchase::SetQuantity(int itemQuantity) {
	this->itemQuantity = itemQuantity;
}