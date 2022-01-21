#include <bits/stdc++.h>
using namespace std;

// Refer: https://stackoverflow.com/questions/14116003/difference-between-constexpr-and-const?rq=1
// https://docs.microsoft.com/en-us/cpp/cpp/constexpr-cpp?view=msvc-170

// 1) constexpr function should refer only constant global variables.

// --> constexpr vs inline functions:
// Both are for performance improvements, inline functions request compiler to expand at compile time and save time of function call
// overheads. In inline functions, expressions are always evaluated at run time. constexpr is different, here expressions are evaluated
// at compile time.

int global_var = 12;
const int const_global_var = 56;

constexpr void temp() {}

// constexpr function for product of two numbers. By specifying constexpr, we suggest compiler to evaluate value at compile time.
constexpr int product(int x, int y)
{
  // global_var = 24;   // point 1
  int a = 2;
  ++a;
  temp();
  return (x * y);
}

//  A class with constexpr constructor and function
class Rectangle
{
  int _h, _w;

public:
  // A constexpr constructor
  constexpr explicit Rectangle(int h, int w) : _h(h), _w(w) {}
  constexpr int getArea() const { return _h * _w; }
};

void constexpr_keyword()
{
  // Using constant expression (constexpr) specifier, it is possible to evaluate the value of a fn or variable at compile time.
  // constexpr specifies that the value of an object or a function can be evaluated at compile time and the expression can be used
  // in other constant expressions. The main idea is performance improvement of programs by doing computations at compile time rather
  // than run time.
  constexpr int x = product(10, 20);
  cout << x << endl;

  // Below object is initialized at compile time
  constexpr Rectangle obj(10, 20);
  constexpr int area = obj.getArea();
  cout << area << endl;
}

int main()
{
  constexpr_keyword();
}