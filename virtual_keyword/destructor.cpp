#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
  Base() { cout << "Base constructor\n"; }
  virtual ~Base() { cout << "Base destructor\n"; }
};

class Derived : public Base
{
  int *x;
public:
  Derived() { x = new int; cout << "Derived constructor\n"; }
  ~Derived() { delete x; cout << "Derived destructor\n"; }
};

void virtual_destructor()
{
  Base *b = new Base();
  delete b;

  cout << "*********************************************************\n";

  Derived *d = new Derived();
  delete d;

  cout << "*********************************************************\n";

  // Base class pointer and Derived class address. This is dynamic polymorphism. But here, only Base class destructor will be called due to
  // run time polymorphism, which will lead to memory leak. Hence to call the Derived class destructor also, use virtual keyword before
  // Base class destructor.
  Base *polymorphism = new Derived();
  delete polymorphism;

  cout << "*********************************************************\n";
}

int main()
{
  virtual_destructor();
}