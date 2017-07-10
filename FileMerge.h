#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void merge(ifstream& input1, ifstream& input2, ofstream& output) {
   int next = 0;
   int next2 = 0;
   input1 >> next;
   input2 >> next2;
   while(true) {
      if (input1.good() && input2.good()) { // checks that the previous read operation was successful
         if (next < next2) {
            output << next << " ";
            input1 >> next;
         }
         else if (next > next2) {
            output << next2 << " ";
            input2 >> next2;
         }
      }
      else if (input1.good() && !input2.good()) {
         while (!input1.eof()) {
            output << next << " ";
            input1 >> next;
         }
         return;
      }
      else if (input2.good() && !input1.good()) {
         while (!input2.eof()) {
            output << next2 << " ";
            input2 >> next2;
         }
         return;
      }
   }
}

int main()
{
   //TODO need to declare some variables
   ifstream input1;
   ifstream input2;
   ofstream output;
   string inName1;
   string inName2;
   string outName;

  cout << "Filenames are restricted to 12 characters\n";
  cout << "Enter the first of two input file names: ";
  cin >> inName1;
  cout << "Now a second input file name: ";
  cin >> inName2;
  cout << "Enter the output file name. " << endl
       << "WARNING: ANY EXISTING FILE WITH THIS NAME WILL BE ERASED."
       << endl;
  cin >> outName;
  
  //TODO open files
  input1.open(inName1);
  input2.open(inName2);
  output.open(outName);
  //TODO call merge function
  merge(input1, input2, output);
  //TODO close files
  input1.close();
  input2.close();
  output.close();
  return 0;
}