#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void size_t_dataType()
{
  // size_t is a data type:
  // . Used to represent the size of objects/variables in bytes.
  // . sizeof() returns size_t data type only. Where as malloc, new etc takes this data type only.
  // . It guarante to be big enough to contain the size of the biggest object that system can handle (for eg 64 bit compiler can hold
  // data upto unsigned long long and 32 bit upto unsigned int).
  // It is never negative.

  size_t cnt = 10;

  while (cnt--)
    cout << cnt << " ";
}

// ************************************************** Overloading new and delete *************************************************

// Overloading new and delete locally (only for Test class)
class Test
{
  int x;

public:
  Test(int x = 0) : x{x} {}

  void *operator new(size_t size)
  {
    cout << "Local Overloaded new operator, size: " << size << endl;
    void *p = malloc(size);
    return p;
  }

  void operator delete(void *p)
  {
    cout << "Local Overloaded delete operator" << endl;
    free(p);
  }
};

// Overloading new and delete globally (available for all)
void *operator new(size_t size)
{
  cout << "Global Overloaded new operator, size: " << size << endl;
  void *p = malloc(size);
  return p;
}

void operator delete(void *p)
{
  cout << "Global Overloaded delete operator" << endl;
  free(p);
}

void *operator new[](size_t size)
{
  cout << "Array Global Overloaded new operator, size: " << size << endl;
  void *p = malloc(size);
  return p;
}

void operator delete[](void *p)
{
  cout << "Array Global Overloaded delete operator" << endl;
  free(p);
}

void *operator new(size_t size, int val)
{
  printf("Global Overloaded new operator with value: %d and size: %d\n", val, size);
  void *p = malloc(size);

  if (p != NULL)
  {
    // Converting 'p' from void* to int* and then assigning value to it as we know we can't dereference void* type pointer.
    *static_cast<int *>(p) = val; // same: *(int*)p = val;
  }

  return p;
}

void new_and_delete()
{
  // new is used to get memory from the heap and delete is used to return the memory to the heap. Both new and delete operators are
  // static members functions (we don't have to write static keyword, it is automatically static), so we don't have access to this pointer
  // as this pointer is for object.
  // . We can have multiple overloaded new/delete operator functions.

  // Compiler will see the overloaded new operator and call it. Compiler will calculate the size of Test class and pass it as an
  // arg to new operator function. new will return pointer (p) and new will automatically calls the constructor on that memory (p).
  Test *t = new Test(); // Local overloaded new operator is preferred over global one
  delete t;             // Local overloaded operator delete (t is passed as an arg to operator delete function)

  int *x = new int;
  delete x;

  // If we don't have any specific new and delete operators overloading for array, then compiler will call the global ones only.
  // But if have then compiler will call the specific for array versions.
  int *arr = new int[10];
  delete[] arr;

  int *x1 = new (12) int; // As we are passing integer (12) as an arg so it will called that overloaded function only.
  cout << *x1 << endl;
  delete x1;
}

int main()
{
}