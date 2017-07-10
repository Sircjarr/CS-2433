#include <iostream>
#include <string>
using namespace std;

class Person {
   public:
      Person(string name, int CWID, int numClasses) {
         this->name = name;
         this->CWID = CWID;
         this->numClasses = numClasses;
      }
      void printPerson() {
         cout << name << " " << CWID << ", number of classes = " << numClasses << endl;
      } 
      
   protected:
      int numClasses;
      string name;
      int CWID;
};

class Student : public Person {
   public:
      Student(string name, int CWID, int numClasses, int grade)
         :Person(name, CWID, numClasses) 
         {
            this->grade = grade;
         }
      void printPerson() {
         cout << name << " " << CWID << ", number of classes = " << numClasses << ", with grade = " << calculateGrade() << endl;
      }
      double calculateGrade() { return grade*numClasses;}
      
   private:
      int grade;
};


int main() {
	Person p("Person", 1234, 1);
	p.printPerson();
	Student s("Student", 4321, 2, 100);
	s.printPerson();
	s.Person::printPerson();
}
