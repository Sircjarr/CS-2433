/*Write the definition for a class named Vector2D that stores information about a two-dimensional vector. The class should have methods to get and set the x component and the y component, where x and y are integers.

Next, overload the * operator so that it returns the dot product of two vectors. The dot product of two-dimensional vectors A and B is equal to

(Ax * Bx) + (Ay * By)

Next, overload the << and >> operators so that you can write the following code

Vector2D v;
cin >> v;
cout << v;
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Vector2D {
   public:
      int getX() {
         return x;
      }
      void setX(int x) {
         this->x = x;
      }
      int getY() {
         return y;
      }
      void setY(int y) {
         this->y = y;
      }
      int operator*(Vector2D second) {
         return (x * second.x) + (y * second.y);
      }
      
      friend istream &operator>>(istream &input, Vector2D &first) { // & means pass by reference. Updates the variable. 
         cout << "Input x y for the vector:" << endl;
         input >> first.x >> first.y; 
         return input; 
      }
      
      friend ostream &operator<<(ostream &output, Vector2D &first) { // friend means the data is a "friend" of the class and can reach privates.
         output << "(" << first.x << ", " << first.y << ")";         // common with stream overloads. 
         return output;  
      }
        
   private:
      int x;
      int y;
};

int main()
{
  Vector2D v1, v2;
  cin >> v1 >> v2;
  cout << v1 <<" * "<< v2<< " = " << v1*v2 << endl;

  return 0;
}
