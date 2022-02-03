#include <bits/stdc++.h>
using namespace std;

// cin.get() will wait for user to press something. Backslash (\) will escape whatever comes after it, here new line (enter key).
// You you press space after baackslah, then it will escape space key instead of new line so make sure don't use space after baackslah
// by mistake unless you mean to.
#define NEW_LINE_EXAMPLE int main() \
{\
  cin.get();\
}

// Templates only get created (allocated memory) when called. See below code, we are printing the 'v' variable which is not defined
// and it compiled successfully because it is not called for once. Some compiler will throw some error like VSC's compiler so it
// is totally compiler dependent.
// template <class T>
// void P()
// {
//   cout << v << endl;
// }

template <typename T>
void Print(T value)
{
  cout << value << " ";
}

template <int N>
class Array
{
  int array[N];

public:
  int size() const { return N; }
};

template <typename T, int N>
class Generic_Array
{
  T array[N];

public:
  int size() const { return N; }
};

void templates()
{
  // We can use angular bracket before parenthesis and mention the type, but it should match (or typecasting if poosible) with the argument
  // types other error will be thrown.
  Print<int>(5);     // exactly match --> angular bracket: int, arg: int
  Print<float>(5.4); // exactly match --> angular bracket: float, arg: float
  Print<int>(5.54);  // typecast --> angular bracket: int, arg: float
  Print<float>(5);   // typecast --> angular bracket: float, arg: int

  // Compiler can even infer the type from the arguments so you don't need to pass in the angular bracket.
  Print(5);
  cout << endl;

  Array<15> a;
  cout << a.size() << endl;

  Generic_Array<string, 20> arr1;
  cout << arr1.size() << endl;
}

// Uncomment below line to see #define working
// NEW_LINE_EXAMPLE

typedef int a;

// If you don't return 0, then compiler will assume it and this is only for main() function.
int main()
{
  // int b = 10;
  // cout << b << endl;

  int Base;
}