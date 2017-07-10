#include <iostream>
#include <cstdlib>

using namespace std;
#include "Contacts.h" // must include class declaration

int main()
{
	string name;
	string num;
	
	cout << "Person 1" << endl;
	cout << "Enter name:" << endl;
	getline(cin, name);
	
	cout << "Enter phone number:" << endl;
	getline (cin, num);
	ContactNode c1(name, num);
	cout << "You entered: " << c1.GetName() << ", " << c1.GetPhoneNumber() << endl << endl;
	cout << "Person 2" << endl;
	cout << "Enter name:" << endl;
	getline(cin, name);
	
	cout << "Enter phone number:" << endl;
	getline (cin, num);
	ContactNode c2(name, num);
	cout << "You entered: " << c2.GetName() << ", " << c2.GetPhoneNumber() << endl << endl;
	
	cout << "Person 3" << endl;
	cout << "Enter name:" << endl;
	getline(cin, name);
	cout << "Enter phone number:" << endl;
	getline (cin, num);
	ContactNode c3(name, num);
	
	cout << "You entered: " << c3.GetName() << ", " << c3.GetPhoneNumber() << endl << endl;
	
	cout <<"CONTACT LIST" << endl;
	c1.PrintContactNode();
	cout << endl;
	c2.PrintContactNode();
	cout << endl;
	c3.PrintContactNode();
	cout << endl; 
}  
