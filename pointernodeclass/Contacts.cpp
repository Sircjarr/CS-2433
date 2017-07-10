//Tests that InsertAfter() correctly inserts Juan Alberto Jr.'s ContactNode after Roxanne 
//Hughes's ContactNode and GetNext() correctly returns Juan Alberto Jr.'s ContactNode.
#include <cstdlib>
#include <iostream>

using namespace std;

#include "Contacts.h"

ContactNode::ContactNode(string contactName, string contactPhoneNum) {
	this->contactName = contactName;
	this->contactPhoneNum = contactPhoneNum;
}


/* Insert node after this node.
 * Before: this -- next
 * After:  this -- node -- next
 */
void ContactNode::InsertAfter(ContactNode* contactsPointer) { 
	ContactNode* tmpNext;
    tmpNext = this->nextNodePtr;    // Remember next
    this->nextNodePtr = contactsPointer;    // this -- node -- ? 
    contactsPointer->nextNodePtr = tmpNext; // this -- node -- next
    return;
}

string ContactNode::GetName() {
	return contactName;
}

string ContactNode::GetPhoneNumber() {
	return contactPhoneNum;
}

ContactNode* ContactNode::GetNext() {
	return this->nextNodePtr;
}

void ContactNode::PrintContactNode() {
	cout << "Name: " << contactName << endl;
	cout << "Phone number: " << contactPhoneNum << endl;
}