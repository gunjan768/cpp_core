#include <bits/stdc++.h>
using namespace std;

void string_literal()
{
  // "gunjan"  ---> This is string literal.

  // String literals are always stored in the constant segment i.e. in the read only memory. We can't add two string literals like:
  // "Gunjan" + "Kumar" becoz they are char arrays or char pointers so we can't just add two arrays or pointers together.
  // string name = "Gunjan" + "Kumar";

  // To make them work (add string literals), we surrounded string literals with a constructor call. We could surround only one of them
  // and that also works fine.
  string name = string("Gunjan") + string("Kumar");
  string name1 = string("Gunjan") + "Kumar";

  // Since C++14, we can add two string literals indirectly. std::string_literals will help to add two string literals. We call
  // character 's' at the end of the string literal (out of quotes) like this: "Gunjan"s. Why it works? ""s is a operator function
  // or operator overloading... inline std::string std::literals::string_literals::operator ""s(const char *__str, std::size_t __len)
  string names = "Shiwani"s + "Mehta";
}

// Global overloading of new operator
void *operator new(size_t size)
{
  cout << "Allocating " << size << " bytes\n";
  return malloc(size);
}

void allocation()
{
  // If we have string literal of length less than or equal to 15 then, there will be no dynamic allocation of memory and it will
  // be created on stack. Else string literal will be created dynamically on heap.
  string name = "Gunjan Kumar is";    // static allocation or alllocation on stack (not call new operator)
  string name1 = "Gunjan Kumar is a";  // dynamic allocation or alllocation on heap (will call new operator)
}

int main()
{
  char *c = new char[10];
  c = (char*)"Hello";
  cout << c << endl;
  int a[] = {1, 2};
  for(auto it: a) cout << it << endl;

  // allocation();
}