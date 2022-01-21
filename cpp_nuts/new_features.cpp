#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void digit_separator()
{
  // We use single quotation mark (') for as a digit separator. There is nor rule for using single quotation mark for digit separator i.e.
  // We can apply anywhere but it should be meaningful (readability)
  ll val = 1'048'576;
  ll val1 = 1'0'765'4'5; // not meaningful but doesn't throw any error
  cout << val << endl;
}

void binary_literals()
{
  // We can binary literals by prefixing "0b". We can use digit separator with binary literals also.
  int val = 0b1010;        // 10
  ll val1 = 0b11'10'100'1; // 233
  cout << val << " " << val1 << endl;
}

[[deprecated("This is deprecated because it will be replaced with the new generic PRINT")]] void PRINT(int a)
{
  cout << "deprecated PRINT function\n";
}

void deprecated()
{
  // We can mention any fn, class, typedef, variable, namespace, enumeration, enumerator, template specialization etc as deprecated
  // by writing: [[deprecated]] above them. Deprecated means we can still use them but they are outdated and compiler will throw an
  // error.
  PRINT(10);
}

template <typename T>
T pi = T(3.1415924443345454L);

void variable_template()
{
  cout.precision(numeric_limits<long double>::max_digits10);
  cout << "INT: " << pi<int> << endl;
  cout << "Char: " << pi<char> << endl;
  cout << "Float: " << pi<float> << endl;
  cout << "Double: " << pi<double> << endl;
  cout << "Long double: " << pi<long double> << endl;

  pi<int> = 24;   // Changing the value for INT type
  pi<char> = 'a'; // Changing the value for Char type
  cout << "INT: " << pi<int> << endl;
  cout << "Char: " << pi<char> << endl;
}

void placement_new()
{
  class Base
  {
  };

  Base a, b;

  // Though Base class is empty, size of Base class will be 1 so to differentiate b/w the instances (a, b) of Base. If sizeof
  // Base class had been 0, then no memory would be given to the instances of Base class hence we can't differentiate b/w
  // them i.e. &a print result = 0 as not memory would be allocated.
  cout << sizeof(a) << " " << sizeof(b) << " " << &a << " " << &b << endl;

  // We know that we will create 10 objects. Should be use "new" for all the 10 objects for their space (memory) allocation ?
  // It is not always advisable to use "new" to allocate memory. Whenever we use 'new', Os switches from user mode to Kernal mode
  // to serach the available space but switiching is costly. We can avoid this by using Placement New technique.

  // We created memory pool for 10 objects. We called Kernal once and told it to search 10 times of memory instead of calling
  // it 10 times. Here, new will ask the memory from the Kernal and construct the object on it.
  char *memory = new char[10 * sizeof(Base)];

  // Here, new will ask the memory only, but not from the Kernal, instead we have provided the memorty (&memory[i]). We are avoid
  // getting memory from the Kernal but we have to construct the object on the memory we already got (&memory[i]).
  Base *o1 = new (&memory[0]) Base();
  Base *o2 = new (&memory[1]) Base();
  Base *o3 = new (&memory[2]) Base();

  // As we have taken care for constructing the object, so we have to destruct the object.
  o1->~Base(); // Calling Destructor explicitly
  o2->~Base(); // Calling Destructor explicitly
  o3->~Base(); // Calling Destructor explicitly

  delete[] memory;
}

void code_bloating()
{
  // Code bloat is the production of code that is perceived as unnecessarily long, slow, or otherwise wasteful of resources.
  string s("gun"); // Unnecessary call of string constructor.
  cout << s << endl;

  // Instead, we could directly print "gun"
  cout << "gun\n";
}

int main()
{
}