#include <bits/stdc++.h>
using namespace std;

// #pragma pack(1)  // To avoid structure padding

class Padding
{
public:
  char a;
  int b;
  char c;
};

// Chainging the order of the variable
class Padding1
{
public:
  char a; // 1 byte
  char b; // 1 byte
  int c;  // 4 bytes
};

class Padding2
{
public:
  char a;
  double b;
  int c;
};

class Packaging
{
public:
  char a;
  double b;
  int c;
} __attribute__((packed));

void structure_padding()
{
  // By default, structural padding is activated which means that the size of the class of struct will be more than or equal to the
  // actual size. Processor doesn't read 1 byte at a time from memory. It reads one word at a time. If we have 32 bits processor then
  // it means word size is 32 bits or 4 bytes and processor reads 4 bytes at a time. So processor divides the main memory into a block
  // or pages of each size 4 bytes. If we have a 64-bit processor, then the processor reads 8 bytes at a time, which means that 1
  // word is equal to 8 bytes.

  // Structure padding is a concept in C that adds the one or more empty bytes between the memory addresses to align the data in memory.

  // Actual size of Padding = 6. But sizeof(Padding) will output = 12. Why? Processor divides the memory into a size of 4 bytes each.
  // Memory --> [a - - -  b b b b  c - - -] where hyphen (-) means an empty byte.
  cout << "Size of Padding: " << sizeof(Padding) << endl;

  // The structural padding is an in-built process that is automatically done by the compiler. Sometimes it required to avoid the
  // structure padding in C as it makes the size of the structure greater than the size of the structure members. We can avoid the
  // structure padding in C in two ways: 1) Using #pragma pack(1) directive   2) Using attribute

  // *************************************************** What's the problem? ****************************************************

  // [a b - -   c c c c]
  cout << "Size of Padding1: " << sizeof(Padding1) << endl;

  // The 4-bytes can be accessed at a time as we are considering the 32-bit architecture. The problem is that in one CPU cycle, one
  // byte of char a, one byte of char b, and 2 bytes of int c can be accessed. We will not face any problem while accessing the char
  // a and char b as both the variables can be accessed in one CPU cycle, but we will face the problem when we access the int c variable
  // as 2 CPU cycles are required to access the value of the 'c' variable. In the first CPU cycle, the first two bytes are accessed,
  // and in the second cycle, the other two bytes are accessed.

  // Suppose we do not want to access the 'a' and 'b' variable, we only want to access the variable 'c', which requires two cycles.
  // The variable 'c' is of 4 bytes, so it can be accessed in one cycle also, but in this scenario, it is utilizing 2 cycles. This is
  // an unnecessary wastage of CPU cycles. Due to this reason, the structure padding concept was introduced to save the number of CPU
  // cycles. The structure padding is done automatically by the compiler. Now, we will see how structure padding is done.

  // ***********************************************************************************************************************

  // The rule for alignment (on x86 and x86_64) is generally to align a variable on it's size. In other words, 32-bit variables are
  // aligned on 4 bytes, 64-bit variables on 8 bytes, etc. On your Padding2 class, the biggest element is double, wich has a size
  // of 8 bytes. So all elements will be padded according 8 bytes. Memomry: [a - - - - - -   b b b b b b b b   c c c c - - - -]
  cout << "Size of Padding2: " << sizeof(Padding2) << endl;
}

void structure_packaging()
{
  cout << "Size of Packaging: " << sizeof(Packaging) << endl;
}

int main()
{
  structure_packaging();
}