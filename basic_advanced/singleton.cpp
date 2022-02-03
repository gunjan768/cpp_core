#include <bits/stdc++.h>
using namespace std;

class Singleton
{
private:
  static Singleton singleton;
  float temp = 5.9f;

  Singleton() {}

public:
  Singleton(const Singleton &) = delete;
  static Singleton &GetInstance()
  {
    return singleton;
  }
};

Singleton Singleton::singleton;

void singleton_class()
{
  // If we write like, then it will copy the instance of Singleton into variable 'instance' hence destroying the concept of 'Singleton'.
  // To avoid this, we need to delete the copy constructor from the class Singleton.
  // Singleton instance = Singleton::GetInstance();

  Singleton &instance = Singleton::GetInstance();
}

int main()
{
  singleton_class();
}