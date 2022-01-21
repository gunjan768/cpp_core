#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long int;

const ll inf = 1e18;

void Enum()
{
  // We can have duplicate values for the same keys like keys B and E have same value (56) but we can't have duplicate keys.
  // enum must be integer only. But you can specify which type of integer you want enum to be like here ll
  enum Example : ll
  {
    A,
    B = 56,
    C,
    D = 98,
    E = 56,
    F = inf
  };

  enum Example1 : ll
  {
    G
  };

  Example ex = B, ex1 = F;

  cout << ex << " " << ex1 << endl;

  // If key is not present, then 0 will be returned.
  cout << "Value of D: " << Example(D) << endl;
  if (ex1 == F || ex == 56)
  {
    cout << ex1 << endl;
  }
}

void initializingVariable()
{
  int a = 5;    // C like initialization
  int b(5);     // Constructor initialization
  int c{21};    // C++11 list initialization syntax
  int d = {21}; // C++11 list initialization syntax

  int arr[8]{1, 2, 3};       // Rest elements are initialized by 0
  int arr1[10]{0};           // init all to 0
  int arr2[]{1, 2, 3, 4};    // Size automatically calculated  (C++11 list initialization syntax)
  int arr3[] = {1, 2, 3, 4}; // Size automatically calculated (C++11 list initialization syntax)

  int *p = new int[24]{1, 2, 3};
  int *p1{new int{24}};
  int *p2{};  // equivalent to int *p2 = nullptr;
  delete[] p;
  delete[] p1;
  delete p2;
  cout << a << " " << b << " " << c << endl;
}

void initializingObject()
{
  class Customer
  {
  public:
    // Default values
    int a = 10, b {45};

    // Overwrite the default value of 'a'
    Customer(int a, int b) : a{a} {}
  };

  Customer cus(2, 3.56);
  Customer cus1 = Customer(2, 3.56);
  Customer cus2{2, 3};            // C++11 value initialization syntax
  Customer cus3 = {2, 3};         // C++11 value initialization syntax
  Customer cus4 = Customer{2, 3}; // C++11 value initialization syntax
  cout << cus3.a << " " << cus3.b << endl;
}

// void listInitialization(double val, int val2)
// {
//   // Prefer {} initialization over alternatives unless you have a strong reason not to.
//   // List initialization does not allow narrowing (§iso.8.5.4). That is:
//   // An integer cannot be converted to another integer that cannot hold its value. For example, char to int is allowed, but not int to char.
//   // A floating-point value cannot be converted to another floating-point type that cannot hold its value. For example, float to double is
//   // allowed, but not double to float.
//   // A floating-point value cannot be converted to an integer type.
//   // An integer value cannot be converted to a floating-point type.
//   int x2 = val;   // if val == 7.9, x2 becomes 7 (bad)
//   char c2 = val2; // if val2 == 1025, c2 becomes 1 (bad)
//   int x3{val};    // error: possible truncation (good)
//   char c3{val2};  // error: possible narrowing (good)
//   char c4{24};    // OK: 24 can be represented exactly as a char (good)
//   char c5{264};   // error (assuming 8-bit chars): 264 cannot be represented as a char (good)
//   int x4{2.0};    // error: no double to int value conversion (good)
// }

// Delegatin means assigning work to someone else
void delegatingConstructor()
{
  // Calling constructor from another constructor to avoid writing initializer list in every constructor.
  class Player
  {
    int a, b, c;
    Player(int a, int b, int c) : a{a}, b{b}, c{c} {}
    Player(int a) : Player{a, 0, 0} {} // One arg constructor is Delegating constructor i.e. delegating to 3 args constructor
    Player() : Player{0, 0, 0} {}      // No arg constructor Delegating constructor i.e. delegating to 3 args constructor
  };
}

// We are passing as r-value
int sum(initializer_list<int> &&a) {
  int sum = 0;
  for(auto it: a) {
    sum += it;
  }
  return sum;
}

void initializer_list_dS() {
  cout << "Sum using initializer_list data structure: " << sum({1, 6, -22, 2}) << endl;
}


int main()
{
  initializer_list_dS();
}