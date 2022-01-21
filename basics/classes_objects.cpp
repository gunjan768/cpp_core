#include <bits/stdc++.h>
using namespace std;

class Test
{
public:
  // Default values
  int a = 10, b{45};

  // Overwrite the default value of 'a'. By defining this 2 args ctor, we loose the default ctor.
  Test(int a, int b) : a{a} {}

  // We can use default keyword to define the default methods with the default implementation.
  Test() = default;                            // default ctor
  Test(const Test &test) = default;            // default copy ctor
  Test &operator=(const Test &test) = default; // default copy assignment

  // If you want to delete the default methods, use delete keyword
  Test() = delete;  // delete default ctor
};

int main()
{
}