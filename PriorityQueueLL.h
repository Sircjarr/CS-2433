#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Node
{
public:
   Node() {}
   Node(string data, int priority, Node* link) {
      this->data = data;
      this->priority = priority;
      this->link = link;
   }
   string getData() {
      return data;
   }
   void setData(string data) {
      this->data = data;
   }
   int getPriority() {
      return priority;
   }
   void setPriority(int priority) {
      this->priority = priority;
   }
   Node* getLink() {
      return link;
   }
   void setLink(Node* link) {
      this->link = link;
   }
   
private:
	string data;
	int priority;
	Node* link;
};

class PriorityQueue
{
public:
   //define these. do NOT delete or change the names
	PriorityQueue() { 
	   head = NULL;
	}
	void add(string data, int priority){
	   Node* insert = new Node(data, priority, NULL);
      Node* temp = head;
      Node* before;
      Node* after;
      
      if (head == NULL) { 
         head = insert;
         return;
      }
      else if (temp->getPriority() > insert->getPriority()) {
         insert->setLink(temp);
         head = insert;
         return;
      }
      else { // get before and after nodes
         while (temp != NULL) {
            before = temp;
            after = temp->getLink();
            if (insert->getPriority() >= before->getPriority() && after == NULL) {
               before->setLink(insert);
               return;
            }
            else if (insert->getPriority() >= before->getPriority() && insert->getPriority() < after->getPriority()) {
               before->setLink(insert);
               insert->setLink(after);
               return;
            }
            temp = temp->getLink();
         }
      }
   }
	string remove() { // FIXME: remove the node
      if (head == NULL) {
         return "";
      }
      else {
         Node* temp = head->getLink();
         string value = head->getData();
         delete head;
         head = temp;
         return value;
      }
	}
private:
   Node* head;
	//think about what private variables you will need, maybe a pointer to the front of the queue.
};

int main()
{
   PriorityQueue* q = new PriorityQueue;
   q->add("A", 2);
   q->add("A", 2);
   cout << q->remove() << endl;
   cout << q->remove() << endl;
	return 0;
}
