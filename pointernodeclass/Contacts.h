//**The variable that stores the address of another variable is what in C++ is called a POINTER**
// foo = &myBar;  where "foo" stores the address of variable myBar and is a pointer, and where & is the "address of operator"
// baz = *foo;    baz would yield the value stored at address foo, aka myBar.prepending * dereferences pointer!
// myBar = 25, &myBar = 1776, foo = address 1776, baz = 25

// http://www.cplusplus.com/doc/tutorial/pointers/

//& is the address-of operator, and can be read simply as "address of"
//* is the dereference operator, and can be read as "value pointed to by"

//EX:  (1.) int * mypointer; (2.) mypointer = &firstvalue; (3.) *mypointer = 10;  firstvalue = 10, without directly declaring it. 
//The asterisk (*) in the pointer declaration (1.) only indicates that it is a pointer, it is not the dereference operator (as in (3).)

//replacing ampersands (&) by "address of", and asterisks (*) by "value pointed to by"
// When pointers are initialized, what is initialized is the address they point to

//Pointers can be initialized either to the address of a variable, or to the value of another pointer (or array):

#ifndef ItemToPurchase_H//A common use of pointers is to create a list of 
						//items such that an item can be efficiently inserted 
						//somewhere in the middle of the list, without the shifting of later items as required for a vector
#define ItemToPurchase_H

#include <cstdlib> 
#include <iostream>

using namespace std; 

class ContactNode { //does not have to be name of the saved file!!!
	public:
		ContactNode(string contactName, string contactPhoneNum);
		void InsertAfter(ContactNode* contactsPointer);
		string GetName();
		string GetPhoneNumber();
		ContactNode* GetNext();
		void PrintContactNode();
		
	private:
		string contactName;
		string contactPhoneNum;
		ContactNode* nextNodePtr;
};

#endif