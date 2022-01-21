#include <bits/stdc++.h>
using namespace std;

void constant_member_method()
{
  // Constant member method is used to restrict the modification of data members inside that method. We make method constant by using
  // const keyword after the method parenthesis and before curly braces. We can change data members inside the constant member method
  // if they are declared as mutable.

  // We can overload member methods on the basis of const and non-const

  class Base
  {
    int x, y;
    mutable int c;

  public:
    Base() {}
    int setX(int x) { this->x = x; }
    int getX() const
    {
      // Can't change 'x' and 'y'
      // x = 2; // Can't change x as getX() method is const.
      c = 10; // c is mutable hence can be changed
      return x;
    }
    // To call the non-const version of print() we need non-const instance
    void print() { cout << "non const print\n"; }
    // To call the const version of print() we need const instance
    void print() const { cout << "const print\n"; }
  };

  Base b1;
  const Base b2;
  b1.print(); // Can call both the versions but prefer non-const one over const
  b2.print(); // can call const version of print only
}

void mutable_keyword()
{
  int x = 8;

  auto f = [=]() mutable -> void
  {
    // We can increase the value of x only if it is captured by reference. Or use mutable keyword if using capturing by value.
    ++x;
  };

  f();
}

int main()
{

}