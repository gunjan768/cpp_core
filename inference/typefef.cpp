#include <bits/stdc++.h>
using namespace std;

// C program to demonstrate importance of typedef over #define for data types
typedef char* ptr;
#define PTR char *

void function_example() {}
#define FunctionPointer int(*p)(int, float)   // function pointer
typedef void(*function_pointer)();  // function pointer using typedef
function_pointer a = function_example;   // Declare variable of function pointer type

void diff_bet_typedef_and_define()
{
  // typedef: The typedef is used to give data type a new name whereas #define in C is a directive which is used to #define alias.
  // Below statement effectively becomes: char *a, *b, *c;
  ptr a, b, c;

  // Below statement effectively becomes: char *x, y, z;
  PTR x, y, z;

  // This makes x, y and z different, as, x is pointer-to-a char, whereas, y and z are char variables. When we declare macros with
  // pointers while defining if we declare more than one identifier then the actual definition is given to the first identifier and
  // for the rest non-pointer definition is given. In the above case x will be declared as char*, so its size is the size of a pointer,
  // whereas, y and z will be declared as char so, their size will be 1 byte.
  printf("sizeof a:%zu\n", sizeof(a));
  printf("sizeof b:%zu\n", sizeof(b));
  printf("sizeof c:%zu\n", sizeof(c));
  printf("sizeof x:%zu\n", sizeof(x));
  printf("sizeof y:%zu\n", sizeof(y));
  printf("sizeof z:%zu\n", sizeof(z));
}

int main()
{
  diff_bet_typedef_and_define();
  return 0;
}