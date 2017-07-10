//if entered a string it will swap head and tail, unil string is reversed. 

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char *pHead;
	char *pTail;
	char str[79];

	cout << "Enter the string (Max length is 79): " << endl;
	cin >> str;
	pHead = &str[0];
	pTail = &str[strlen(str) - 1]; //sizeof(str) - 1
	int halfLen = (strlen(str) / 2);
	
	
	// swap the head and tail 
	for (int i = 0; i < halfLen; i++) {
	   char temp = *pHead; // remembers value at head;
	   *pHead = *pTail; // value of head == value of tail
	   *pTail = temp; // value at pTail = temp. 
	   pHead++;
	   pTail--;
	}
	
	cout << str << endl;

	return 0;
}