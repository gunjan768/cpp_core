#include <bits/stdc++.h>
using namespace std;

// ************************************************* Using without virtual keyword ********************************************

class Final
{
public:
  Final() {cout << "Final \n";}
  friend class Base;  // Making Base class as a friend to Final class so that we can access any private member of Final inside Base.
};

class Base : public Final
{
public:
  Base() {cout << "Base \n";}
};

class Derived : public Base
{
public:
  Derived() {cout << "Derived \n";}
};

void simple_inheritance()
{
  // We can use virtual keyword in multi-level inheritance. Say we have three classes: A, B inherit A, C inherit B. When we create
  // an instance of C, constructor of C will be called and before running it's body, constructors for A and B will be called. Ctor of C
  // will call ctor of B and ctor of B will call ctor of A. If B inherits A virtually, then ctor of both A and B will be called by the
  // ctor of C only. 

  Derived d;    // ctor calls: Derived -> Base -> Final
}

// ************************************************* Using without virtual keyword ********************************************

class Final1
{
public:
  Final1() {cout << "Final \n";}
  friend class Base1;  // Making Base class as a friend to Final class so that we can access any private member of Final inside Base.
};

class Base1 : virtual public Final1
{
public:
  Base1() {cout << "Base \n";}
};

class Derived1 : public Base1
{
public:
  Derived1() {cout << "Derived \n";}
};

void virtual_inheritance()
{
  // virtual inheritance so ctor of Derived1 will call ctors of both Base1 and Final1. How to check this? Make ctor of Final1 private
  // and you will see the error. Becoz ctor of Final1 is private then no can call it's ctor except the friend class which is Base1.
  // Remove virtual inheritance (remove virtual keyword before Base1 is inheriting Final1 like: class Base1: public Final1). Now error
  // will go away, becoz as no virtual inheritance so ctor of Derived1 calls ctor of Base1 and ctor of Base1 will call ctor of Final1
  // as Base1 is a friend class to Final1.
  Derived1 d;    // ctor calls: Derived -> Base -> Final
}

int main()
{
  virtual_inheritance();
}