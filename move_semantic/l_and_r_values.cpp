#include <bits/stdc++.h>
using namespace std;

int sq(int a) { return a * a; }

void l_r_value()
{
  // Every expression in C++ is either l-value or r-value.
  // l-value: If you can take address of expression then it is l-value and they last extended period of time.
  // r-value: r-values are such expression which you can't take address adn they are temporary, they don't exist after 1 line.
  class Cat
  {
  };
  Cat cat1 = Cat(); // 'cat1' is l-value and Cat() is r-value

  int x = 10;
  int &l_value_reference = x;
  int &&r_value_reference = 20;
  int &&r_value_reference1 = sq(5);

  // We can bind the l-value with const and take the r-value reference (20 is r-value and we are taking the reference of 20).
  const int &p = 30; // Compiler will do: int tmp = 20; int &p = tmp;

  cout << r_value_reference1 << endl;
}

void r_and_l_values()
{
  // l-value: is a value that has name and are addressable and also modifiable (if not constant). It appears on both the sides of "=".
  // r-value: non-addressable and non-assignable. A value which is not an l-value
  // . On the right hand side of an assignment expression     . a literal     . a temporary which is intended to be non-modifiable
  int x = 100;     // x is l-value and 100 is an r-value
  int y = x + 200; // y: l-value, x + 200 (creates a temporary) is an r-value
  string name;
  name = "Gunjan"; // name: l-value, "Gunjan" is an r-value

  // mx: l-value, max(20, 30) (as it returns a result which is temporary which is non-modifiable and non addressable) is an r-value
  int mx = max(20, 30);

  // References are l-value
  int x1 = 100;
  int &ref = x1; // ref is reference to l-value as 'x' is l-value
  // int &r = 100;  // As 100 is not l-v (100 is r-v)
}

void value_reference(int &x) {}  // l-value
void value_reference(int &&x) {} // r-value

void l_r_values1()
{
  // In the context of move semantic, r-values refer to temporary objects that are created by the compiler and objects returned
  // from methods. R-value objects are the objects that move semantics addresses.

  // Move constructor moves an object rather than copying it. This is used when we have raw pointer in the class.
  // Copy elision is a compiler optimization technique that eliminates unnecessary copying.

  // R-value references:
  // . Used in moving semantics and perfect forwarding.
  // . Move semantics is all about r-value references.
  // . Used by move constructor and move assignment operator to efficiently move an object rather than copy it.
  // . R-value reference operator (&&)
  int x = 100;
  int &l_ref = x; // l-value reference
  l_ref = 10;     // change x to 10

  int &&r_ref = 200; // r-value reference
  r_ref = 300;       // change r_ref to 300
  // int &&x_ref = x;  // compilation error

  int *pv = &++x; // both pv and x are l-values so we can take the reference of l-value (&++x) in pv.

  // x++ is r-value becoz compiler creates a temp variable with value of x and returns here and increase x by 1 but reflects in the
  // next encounter of x.
  // int *pv1 = &x++;   // We can take the reference of r-value (x++) in l-value (pv)

  value_reference(x);
  value_reference(10);
}

class Base
{
};

void reference_collapsing_rule()
{
  Base b;

  // Though we have used r-value reference (&&) but this is actually l-value since on the right side of the equal to assignment is the
  // l-value. Why it worked? Due to auto keyword. During the compile time, compile will see that it is a l-value reference so it will
  // collapse the r-value reference and use the l-value reference. This is one of the reference collapsing rules.
  auto &&b1 = b;
}

int main()
{
}