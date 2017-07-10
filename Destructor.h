#include <iostream>
//The second element can be accessed either with classList[1] or *(classList+1)
//http://www.cplusplus.com/doc/tutorial/dynamic/

#include <cstdlib>
#include <string>

using namespace std;

class Student {
public:
	Student() {
	   ;
	}
	~Student(); //Destructor;
	void InputData();		// Input all data from user
	void OutputData();		// Output class list to console
	void ResetClasses();		// Reset class list
	void operator=(Student second) {
	   new Student(); // declared for the purpose of calling destructor on this.classList. Necessary?
	   name = second.name;
	   numClasses = second.numClasses;
	   classList = new string[numClasses];
	   for (int i = 0; i < numClasses; i++) {
	      classList[i] = second.classList[i];
	   }
	}
private:
	string name;
	int numClasses;
	string *classList; // dynamic array of string. Recommended not to use this but vector<string> instead.
};

void Student::OutputData() {
   cout << "Name: " << name << endl;
   cout << "Number of classes: " << numClasses << endl;
   for (int i = 0; i < numClasses; i++) {
      cout << "Class " << i + 1 << ": " << classList[i] << endl;
   }
}

Student::~Student() {
      delete[] classList; // only pointers/new keyword needs deletion in destructor. Avoid "Memory leaks"
   return;
}

void Student::ResetClasses() {
   numClasses = 0;
}

void Student::InputData() {
   cout << "Enter student name:" << endl;
   cin >> name;
   cout << "Enter number of classes:" << endl;
   cin >> numClasses;
   classList = new string[numClasses];
   for (int i = 0; i < numClasses; i++) {
      cout << "Enter name of class " << i + 1 << ":" << endl;
      cin >> classList[i];
   }
}

int main()
{
  Student s1, s2;

  s1.InputData();		// Input data for student 1
  cout << "Student 1's data:" << endl;
  s1.OutputData();		// Output data for student 1

  s2 = s1;	
  cout << "Student 2's data after assignment from student 1:" << endl;
  s2.OutputData();		// Should output same data as for student 1

  s1.ResetClasses();
  cout << "Student 1's data after reset:" << endl;
  s1.OutputData();		// Should have no classes

  cout << "Student 2's data, should still have original classes:" << endl;
  s2.OutputData();		// Should still have original classes

  return 0;
}
