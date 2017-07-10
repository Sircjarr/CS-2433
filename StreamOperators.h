/* Sample output
Enter student's CWID, followed by grade: 
Enter student's CWID, followed by grade: 
This student has CWID 123 and grade 50                                                                                                                        
This student has CWID 234 and grade 25                                                                                                                        
This student has CWID 357 and grade 75
*/


//cin is a predefined istream

#include <iostream>
using namespace std;

class StudentRecord {
public:
	StudentRecord() : CWID(0), grade(0) {
	}
	StudentRecord(int c, double g) : CWID(c), grade(g) {
	}
	
	const StudentRecord operator +(const StudentRecord& other);
	
	bool operator ==(const StudentRecord& other);
	
	int getCWID() const {return CWID;}
	double getGrade() const {return grade;}
	void setCWID(int c) {
	   CWID = c;
	}
	void setGrade(double g) {
	   grade = g;
	}
	
	// The extraction operator >>. extract data from a data buffer and to write the data into different types of variables.
	friend istream &operator>>(istream& stream, StudentRecord& other) { // & updates variable, PASS BY REFERENCE
	   cout << "Enter student's CWID, followed by grade:" << endl;
	   cin >> other.CWID >> other.grade;
	   return stream;
	}
	
	friend ostream &operator<<(ostream& stream, StudentRecord& other) {
	   cout << "This student has CWID " << other.CWID << " and grade " << other.grade << endl;
	   return stream;
	} 
	
	//declare and overload >> and << operators
private:
	int CWID;
	double grade;
};

const StudentRecord StudentRecord::operator +(const StudentRecord& other) {
	return StudentRecord(CWID + other.getCWID(), grade + other.getGrade());
}

bool StudentRecord::operator ==(const StudentRecord& other) {
	if (CWID == other.getCWID()) {
		return true;
	}
	return false;
}

//define and overload >> and << operators

int main() {
	StudentRecord eric, nick;
	cin >> eric >> nick;
	cout << eric << nick;

	StudentRecord enik = eric + nick;
	cout << enik;
}
