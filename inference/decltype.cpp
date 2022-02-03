#include <bits/stdc++.h>
using namespace std;

// decltype Keyword: It inspects the declared type of an entity or the type of an expression. ‘auto’ lets you declare a variable with a
// particular type whereas decltype lets you extract the type from the variable so decltype is sort of an operator that evaluates the
// type of passed expression.

// Q) decltype vs typeid ?
// Decltype gives the type information at compile time while typeid gives at runtime.
// So, if we have a base class reference (or pointer) referring to (or pointing to) a derived class object, the decltype would give type
// as base class reference (or pointer, but typeid would give the derived type reference (or pointer).

auto add(int a, int b) { return a + b; }

// By simple writing 'auto', compiler will deduce the type of 'a' i.e. 'int' but actually it is '&a'. To return 'int ref (&int)' we
// have to explicitly mention ref after auto.
auto inc(int &a)
{
  a++;
  return a;
};

// auto becomes int type if even an integer reference is assigned to it. To make it reference type, we use auto&.
// Function that returns a ‘reference to int’ type : int& fun() {};
// m will default to int type instead of int& type : auto m = fun();
// n will be of int& type because of use of extra & with auto keyword : auto& n = fun();
auto &inc1(int &a)
{
  a++;
  return a;
};

// We can avoid writing ref after auto by using decltype(auto) --> decltype(auto) will automatically deduct the type of 'a' which is
// 'int&'.
decltype(auto) inc2(int &a)
{
  a++;
  return a;
};

int fun1() { return 10; }
char fun2() { return 'g'; }

// A generic function which finds minimum of two values return type is type of variable which is minimum
template <class A, class B>
auto findMin(A a, B b) -> decltype(a < b ? a : b)
{
  return (a < b) ? a : b;
}

// decltype checks the expression (a + b) type and returns what is returned by (a + b)
// Function with trailing return type (using decltype after the fn parenthesis) should be declared with 'auto' type specifier
template<typename T1, typename T2>
auto addition(T1 a, T2 b) -> decltype(a + b) {
  return a + b;
}

void type_deduction()
{
  // Data type of x is same as return type of fun1() and type of y is same as return type of fun2()
  decltype(fun1()) x5;
  decltype(fun2()) y5;

  cout << typeid(x5).name() << endl;
  cout << typeid(y5).name() << endl;

  int xx = 5;

  // r-value should be assignable type ex: if data type infered for 'j' (from xx) is say integer type and the
  // value we are storing (r-value) say is string then compiler will throw an error: type conversion is not possible.
  decltype(xx) j = xx + 5.54;  // j will be of type int : data type of xx no matters what is the r-value
  decltype(xx + 8.65) j1 = xx; // j1 will be of type double : data type of the expression: (xx + 8.65) i.e. double

  cout << "Type of j: " << typeid(j).name() << " and j1: " << typeid(j).name() << endl;

  // Using 'auto' return type, the compiler will deduce the type for you. auto and decltype keywords deduce the data type
  // at the compile time (since compiler do it for you).
  int p = 10;
  int r1 = inc(p);
  int &r2 = inc1(p);
  int &r3 = inc2(p);

  cout << addition(1, 1.8) << endl;
  cout << addition(1.8, 1) << endl;

  const int x = 0;
  auto x1 = x;           // int
  decltype(auto) x2 = x; // const int
  int y = 0;
  int &y1 = y;
  auto y2 = y1;           // int
  decltype(auto) y3 = y1; // int&
  int &&z = 0;
  auto z1 = move(z);           // int
  decltype(auto) z2 = move(z); // int&&

  // This call returns 3.44 of doubale type
  cout << findMin(4, 3.44) << endl;

  // This call returns 3 of double type
  cout << findMin(5.4, 3) << endl;
}

int main()
{
  type_deduction();
}