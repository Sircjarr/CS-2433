#include <iostream>
using namespace std;

class IntNode {
	public:
		IntNode() {}
		IntNode(int d, IntNode* n) {
			data = d;
			next = n;
		}
		
		int getData() {
		  return data;
		}
		IntNode* getNext() {
		  return next;
		}
		
		void setData(int d) {
		  data = d;
		}
		void setNext(IntNode* n) {
		  next = n;
		}

	private:
		int data;
		IntNode *next;
};

bool search(IntNode* head, int target) {
   IntNode* here = head;
   if (here == NULL) {
      return false;
   }
   else {
      while (here != NULL) {
         if (here->getData() == target) {
            return true;
         }
         here = here->getNext();
      }
   }
   return false;
}

void add(IntNode* &head, int value) {
   IntNode* last = new IntNode(value, NULL);
   
   if (head == NULL) {
      head = last;
      return;
   }
   else {
     IntNode* temp = new IntNode();
     temp = head;
     while (temp->getNext() != NULL) {
        temp = temp->getNext();
     }
     temp->setNext(last);
   }
} 

void add(IntNode* &head, int value) { // SORTING VERSION OF ADD METHOD
   IntNode* insert = new IntNode(value, NULL);
   IntNode* temp = head;
   IntNode* before;
   IntNode* after;
   
   if (head == NULL) { 
      head = insert;
      return;
   }
   else if (temp->getData() > insert->getData()) {
      insert->setNext(temp);
      head = insert;
      return;
   }
   else { // get before and after nodes
      while (temp != NULL) {
         before = temp;
         after = temp->getNext();
         if (insert->getData() >= before->getData() && after == NULL) {
            before->setNext(insert);
            return;
         }
         else if (insert->getData() >= before->getData() && insert->getData() < after->getData()) {
            before->setNext(insert);
            insert->setNext(after);l
            return;
         }
         temp = temp->getNext();
      }
   }
}

void deleteNode(IntNode* &head, int value) {
   IntNode* temp = head;
   IntNode* before;
   IntNode* current;
   IntNode* after;
   while(temp != NULL) {
      if(temp->getData() == value) {
         break;
      }
      temp = temp->getNext();
      if (temp == NULL) {
         return;
      }
   }
   temp = head;
   if (temp->getData() == value) { 
      head = temp->getNext();
      delete temp;
      return;
   }
   while(temp != NULL) {
      before = temp;
      current = temp->getNext();
      after = temp->getNext()->getNext();
      
      if (current->getData() == value && after != NULL) {
         before->setNext(after);
         delete current;
         return;
      }
      else if (current->getData() == value && after == NULL) {
         before->setNext(NULL);
         delete current;
         return;
      }
      temp = temp->getNext();
   }
   return;
}

void print(IntNode* head) {
   IntNode* temp = head;
   while (temp != NULL) {
      cout << temp->getData() << "         ";
      temp = temp->getNext();
   }
   cout << endl;
}

int main() {
	IntNode* head = NULL;
	char choice;
	int value;
	
	while(true){
		cout<<"Please choose to Add(A), Delete(D), "<<\
			"Search(S), Print(P), or Quit(Q): " << endl;
		cin>>choice;
		choice = tolower(choice);
		switch(choice){
			case 'a':
				cout<<"Please input the number to add: " << endl;
				cin>>value;
				add(head,value);
				break;
			case 'd':
				cout<<"Please input the number to delete: " <<endl;
				cin>>value;
				deleteNode(head,value);
				break;
			case 's':
				cout<<"Please input the number to search: ";
				cin>>value;
				cout<<"The number "<<value<<(search(head,value) ? " is " : \
						" is not ")<<"in the tree."<<endl;
				break;
			case 'p':
				print(head);
				break;
			case 'q':
				return 0;
			default:
				cout<<"Invalid input."<<endl;
				break;
		}
	}
}