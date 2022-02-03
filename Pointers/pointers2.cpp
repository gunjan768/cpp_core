#include <bits/stdc++.h>
using namespace std;

int *returing_array()
{
  int a[5] = {1, 2, 3, 4, 5};
  return a;
}

void object_lifetime()
{
  // Never do this type of mistake. We are getting this array from returing_array() array and there it is created on the stack (as we
  // static initialization i.e. not used pointer) and as soon as that method ends, the array created on the stack will also be deallocated
  // i.e.e that array no longer exists. We have two options to correct it: Option 1) Pass array to the function and se dynamic allocation
  // (i.e. pointer) to allocate memory to array i.e. allocates memory on the heap.
  int *a = returing_array();
}

void pointers()
{
  // https://stackoverflow.com/questions/45388011/what-is-the-difference-between-p5-and-p5

  // int *c;      // Pointer to an integer

  // This is called Array of Pointers(Pointer Array). We can declare an array that contains pointers as its elements.Every element
  // of this array is a pointer variable that can hold address of any variable of appropriate type.
  // int *c[3];   // Same as: int *(c[3]);  Array of pointers (3 elements and each element is pointer to an integer)

  // int (*c)[x] is called a Pointer to an Array(Array Pointer). We can declare a pointer that can point to whole array instead of
  // only one element of the array. This pointer is useful when talking about multidimensional arrays.
  // int (*c)[3];     // Pointer to a 1D array of 3 elements

  // int (*c)(int, int);     // Function pointer with int arguments and return type int
  // int (*c)();  // Function pointer without any argument and return type int

  int a[] = {1, 2, 3};
  int(*p)[3] = &a;
  int *q = a;
  int *b[3];

  printf("%d %d %d", p[0], p[1], p[2]);
}

void twoD_arrays()
{
  int a[3][3] = {{1, 2, 3}, {5, 4, 12}, {15, 21, 56}};

  // If array declared on stack (statically) then all the 1D arrays are allocated memory in a row.
  printf("Address -> a[0][0]: %d, a[1][0]: %d, a[2][0]: %d", &a[0][0], &a[1][0], &a[2][0]);

  // We created a pointer (oneD_array) variable. We allocated memory for 5 integers (we get memory in a row) using new keyword and the
  // the pointer (pointing to the first integer or element) to a memory (of 5 integers) returned by new keyword is assigned to the
  // 'oneD_array' pointer variable. This is the way of creating 1D array in C++ dynamically.
  int *oneD_array = new int[5];

  // In the same way we use to create a 1D array in C++ dynamically, we use to create a 2D array. We create a pointer variable (twoD_array)
  // which is pointer to a pointer to an integer (instead of pointer to an integer). int *[5] is array of pointers where each element
  // of array is a pointer to an integer. int*[5] --> array of pointers but without name so we need something to store it and we assign
  // it to a 'twoD_array' variable. new int*[5] will create array of pointers and allocate space for them and return the pointer pointing
  // to the base address of an array i.e. pointer to a pointer (as elements of an array is pointer).
  int **twoD_array = new int *[5];

  // Till now, we have just created an array of pointers. Now we will create 5 1D arrays and assign the base address of each 1D array
  // to each of the elements (which is pointer) of an array.

  for (int i = 0; i < 5; ++i)
  {
    // Pointer each element of an array to a 1D array of 5 elements. Remember that the base address of each 1D array can be anything
    // so here 1D arrays may or may not be in a row. Maximum chance is that they will not be allocated memory in a row. This way
    // we create 2D array in C++ dynamically.
    twoD_array[i] = new int[5];
  }
}

class E
{
public:
  E() { cout << "C\n"; }
  ~E() { cout << "D\n"; }
};

void check()
{
  {
    E *e = new E();
    delete e;
  }
}

int main()
{
  twoD_arrays();
}