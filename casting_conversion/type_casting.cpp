#include <bits/stdc++.h>
using namespace std;

// In C++, RTTI (Run-time type information) is a mechanism that exposes information about an object’s data type at runtime and is 
// available only for the classes which have at least one virtual function. It allows the type of an object to be determined during 
// program execution.

void static_casting()
{
  // Static cast
  // .......1) It performs implicit conversion b/w types. We use it in implicit conversion so that we can easily find in our code where
  // are we doing the implicit conversion (by searching 'static_cast').
  float f = 3.5f;
  int a = static_cast<int>(f); // same as a = f; Happens at compile time so static cast.

  // .................. 2) We use it when conversion b/w types is provided through conversion operator or conversion constructor.
  class UserInteger
  {
    int x;

  public:
    UserInteger(int x = 0) : x{x} {}
    operator string() { return to_string(x); }
  };

  UserInteger integer(3);

  // We can't change anything in the string class so we used conversion operator in the UserInteger class to convert UserInteger to string.
  string str = integer; // Convert UserInteger to string.
  integer = 20;         // Convert int (20) to UserInteger (primitive to class)

  string str1 = static_cast<string>(integer);
  integer = static_cast<UserInteger>(30);

  // .............. 3) static cast is more restrictive than C style. For ex: char* to int* is allowed in C-style but not with static_cast.
  char c = 'a';
  char *cp = &c;
  int *ip = (int *)cp; // or (int*)&c;
  *ip = 5;             // Pass at compile time but fails at run time.

  // As char c has 1 byte (8 bits) but integer pointer points to 4 bytes (32 bits) data. cp is pointing to 1 byte but ip to 4 bytes i.e.
  // when we store '5' to the memory pointed by ip, to the first 3 bytes it stores 0 and to the last byte, it sotres 5.
  // In the binary form: 00000000 00000000 00000000 00000101
  // int *ip1 = static_cast<int*>(cp);    // Throws an error: Invalid type conversion

  // .......... 4) It won't allow cast from derived to private base pointer
  class Base
  {
  };
  class Derived : private Base
  {
  };
  Derived d1;
  Base *b1 = (Base *)&d1; // C style.... Allowed at compile time
  // Base *b2 = static_cast<Base*>(&d1);   // Error: Conversion to inaccessible base class "Base" is not allowed

  // ........... 5) It is prefered when converting to void* OR from void*
  int i = 10;
  void *v = static_cast<void *>(&i);
  int *i1 = static_cast<int *>(v);
  printf("Addresses where these pointers are pointing to (same) --> v: %d, i1: %d\n", v, i1);
  printf("Addresses of pointers (different) --> &v: %d, &i1: %d", &v, &i1);
}

void third_party_library(int *x) {}

void const_casting()
{
  // const_cast: It can be used to change the const or volatile qualifiers of pointers or references. const_cast<T> where T must
  // be pointer, reference, or pointer to member type.

  // ............. 1) When the actual referred object/variable is not const
  // Don't make 'a' const (const int a = 20)... otherwise we can't change the value of 'a' but when we change the value not
  // using 'a' but using pointer 'p2', we get the undesired result i.e. value of 'a' would still remain 20.
  int a = 20;
  const int *p1 = &a; // Pointer to a constant i.e. we can't change the value stored at the address pointed by pointer 'p1'.
  // *p1 = 30;   // Throws error
  int *p2 = const_cast<int *>(p1);
  *p2 = 30; // Valid as 'p2' is a pointer but not pointing to a constant.

  cout << &a << " " << a << " " << *p2 << " " << *p1 << endl;

  const int b = 50;
  const int *p3 = &b; // int *p3 = &b will throw an error as 'b' is const so 'p3' should point to a constant.
  int *p4 = const_cast<int *>(p3);
  *p4 = 70;

  // value of b outputs = 50 (no change). It's not like that. Compiler will do optimization i.e. when wherever you use
  // 'b', compiler will replace it with it's value (as compiler knows that b is const). Say address of' b' = 200;
  // When we do *p4 = 70, it changes the value at the address 200.
  cout << &b << " " << b << " " << *p3 << " " << *p4 << endl;

  // ..................... 2) When we need to call some fn (or 3rd party library) where it is taking variable/object as
  // non const but we have data to pass as an argument as constant.
  // third_party_library(p3);   // Error: argument of type "const int *" is incompatible with parameter of type "int *"
  third_party_library(const_cast<int *>(p3));
}

void dynamic_casting()
{
  // dynamic_cast <new_type> (expression): dynamic_cast uses RTTI (see at the TOP for RTTI)
  // It is used at run time to find out correct down-cast. Some points to be noted:
  // . Need at least one virtual fn in base class (work only on polymorphic base class i.e. dynamic binding).
  // . If the cast is successful, dynamic_cast returns a value of type new_type.
  // . If the cast fails and new_type is a pointer type, it returns a null pointer of that type.
  // . If the cast fails and new_type is a reference type, it throws an exception that matches a handler of type bad_cast
  class Base
  {
    virtual void print() { cout << "Base\n"; }
  };
  class Derived1 : public Base
  {
    void print() { cout << "Derived1\n"; }
  };
  class Derived2 : public Base
  {
    void print() { cout << "Derived2\n"; }
  };

  Derived1 d1;
  Base *bp = dynamic_cast<Base *>(&d1);
  Derived2 *dp2 = dynamic_cast<Derived2 *>(bp); // Typecast fails and dynamic_cast returns NULL
  Derived1 *dp3 = dynamic_cast<Derived1 *>(bp); // Typecast success and dynamic_cast returns pointer of Derived1

  // We can use static_cast<> also but it won't check object types at runtime so we used dynamic_cast. dynamic_cast is slower
  // as it has runtime overhead so if we are sure that we will never cast to wrong object then we should always avoid this cast and
  // use static_cast.
  if (dp2 == NULL)
  {
    cout << "dp2 is NULL\n";
  }

  if (dp3 != NULL)
  {
    cout << &dp3 << endl;
  }

  // .......................... For reference type
  try
  {
    Derived2 &d2 = dynamic_cast<Derived2 &>(d1); // throws an error: bad_cast
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }
}

void reinterpret_casting()
{
  // reinterpret_cast: is used to typecast one pointer datatype to another pointer datatype

  // ............... 1) It can perfrom dangerous conversions becoz it can typecast any pointer to any other pointer.
  class Mango
  {
  public:
    void eatMango() { cout << "Eat Mango\n"; }
  };

  class Banana
  {
  public:
    void eatBanana(int a = 0) { cout << "Eat Banana\n"; }
  };

  Banana *b{new Banana}; // Banana *b {new Banana{}}; or Banana *b = new Banana; or Banana *b = new Banana();
  b->eatBanana();
  Mango *m{new Mango{}};
  Banana *mangoToBanana = reinterpret_cast<Banana *>(m); // Works successful but dangerous as we changed Mango to Banana

  // Compiler will make some changes here: Banana::eatBanana(&new Banana, a); i.e. as the 1st arg, pointer of Banana type will be
  // passed. Compiler will also make changes to class Banana (changes eatBanana()) --> eatBanana(const Banana *this, int a)
  mangoToBanana->eatBanana(3);

  // ..................... 2) It is used when you want to work with bits
  class MyClass
  {
  public:
    int x;  // 4 bytes
    int y;  // 4 bytes
    char c; // 1 byte
    bool b; // 1 byte

    // Total = 12 bytes (due to structural padding). Lets say 0-11 (12 bytes). x: 0 - 3, y: 4 - 7, c: 8 - 8, b: 9 - 9 and the
    // rest 2 bytes (10 and 11) will remain empty.
    MyClass(int x, int y, char c, bool b) : x{x}, y{y}, c{c}, b{b} {}
  };

  cout << "Size of MyClass: " << sizeof(bool) << endl; // Total = 12 bytes (due to structural padding)

  MyClass obj{5, 10, 'a', true};

  // When we convert MyClass type (obj) to int* type (p), integer pointer 'p' will point to the starting address i.e. to 0 (as we
  // assumed address from 0 - 11).
  int *p {reinterpret_cast<int*>(&obj)};  // same as int *p = reinterpret_cast<int*>(&obj);
  cout << *p << endl;   // As 'p' is int type pointer so print the value stored in the first 4 bytes (0 - 3)
  ++p;  // Incremenet address from 0 to 4 (as p is int type)
  cout << *p << endl;   // Print value stored in next 4 bytes
  ++p;  // Incremenet address from 4 to 8 (as p is int type)
  char *c {reinterpret_cast<char*>(p)}; 
  cout << *c << endl;   // Print next 1 byte (as char type) i.e. value at address 8 i.e. 'a' will be printed
  cout << *(reinterpret_cast<bool*>(++c)) << endl; // Print next 1 byte (as bool type) i.e. value at address 9 i.e. true (1) will be printed
}

int main()
{
  reinterpret_casting();
}