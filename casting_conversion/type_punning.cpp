#include <bits/stdc++.h>
using namespace std;

// Can also use class instead of struct
struct Entity
{
  int x, y;
};

void type_punning()
{
  int a = 50;

  // Compiler actually converts int to double.
  double b = a;         // implicity conversion
  double c = (double)a; // explicit conversion

  // &a returns pointer to an integer. We converted into double pointer (double*) and then dereferenced the value. Actually what we did is
  // we converted integer point which points to an integer (4 bytes) to a double pointer. We know that double pointer have to point to
  // double value of 8 bytes so rest 4 bytes remain uninitialized. This is called type punning.
  double d = *(double *)&a;

  printf("Addresses --> &a: %d, (double*)&a: %d\n", &a, (double *)&a);

  cout << b << " " << d << std::endl;

  Entity entity = {1, 2};

  int *pos = (int *)&entity;

  // We can access memory freely in C++ and this is what makes C++ powerful. We can access 'y' of an Entity in different ways using type
  // punning. We converted &entity (Entity*) to char pointer (char*). We know that char* takes 1 byte. Initially char* points to the
  // base address, so to get the address of 'y' which at address 4 (say base address = 0, 'x' takes 4 bytes = 0 - 3, y = 4 - 7) we need
  // to add 4 bytes to it. We reached the address of y (4) but still it a char* so we will convert it to int* and then dereference it.
  int y = *((int *)((char *)&entity + 4));

  // pos[1] = *(pos + 1); pos is of int type pointer so incrementing it by 1 will increment 4 bytes (size of int).
  cout << pos[0] << " " << pos[1] << " " << y << endl;

  struct V1
  {
    float x, y;
  };

  struct V2
  {
    float x, y, w, z;

    V1& get()
    {
      // V1 val = *((V1*)&x); We are returning the reference of 'val'
      return *((V1*)&x);
    }
  };
}

int main()
{
  type_punning();
}