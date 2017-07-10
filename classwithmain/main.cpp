#include <iostream>
#include <cstdlib>

using namespace std;
#include "ItemToPurchase.h" // must include class declaration

int main()
{
	ItemToPurchase item1, item2;

	string itemName;
	int itemPrice;
	int itemNum;
	
	cout << "Item 1" << endl << "Enter the item name:" << endl;
	getline(cin, itemName);
	item1.SetName(itemName);
	
	cout << "Enter the item price:" << endl;
	cin >> itemPrice;
	item1.SetPrice(itemPrice);
	
	cout << "Enter the item quantity:" << endl << endl;
	cin >> itemNum;
	item1.SetQuantity(itemNum);
	
	cin.ignore();
	
	cout << "Item 2" << endl << "Enter the item name:" << endl;
	getline(cin, itemName);
	item2.SetName(itemName);
	
	cout << "Enter the item price:" << endl;
	cin >> itemPrice;
	item2.SetPrice(itemPrice);
	
	cout << "Enter the item quantity:" << endl << endl;
	cin >> itemNum;
	item2.SetQuantity(itemNum);
	
	cout << "TOTAL COST" << endl;
	cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" 
		<< item1.GetPrice() * item1.GetQuantity() << endl;
	cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" 
		<< item2.GetPrice() * item2.GetQuantity() << endl << endl;
		
	cout << "Total: $" << (item1.GetQuantity() * item1.GetPrice()) + (item2.GetQuantity() * item2.GetPrice()) << endl;
	
}