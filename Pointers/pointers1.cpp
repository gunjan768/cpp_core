#include<bits/stdc++.h>
using namespace std;

void pointerOper() {
  int a = 1025, *p = &a;
  cout << "Size of integer : " << sizeof(int) << endl;
  printf("Address: %d Value: %d\n", p, *p);

  char *cp = (char*)p; // typecasting
  cout << "Size of char : " << sizeof(char) << endl;

  // size of integer = 4 bytes (1 byte = 8 bits) and size of char = 1 byte so when type casted from integer to character, compiler
  // looks for the 1st byte (or first 8 bits) only i.e. here "00000001". Next 8 bits will be stored in a pointer whose address is
  // one more than cp i.e. (cp + 1). Hence cp1 will store "00000100". Similarly (cp + 2) will store next 8 bits.
  // 1025 in binary : 00000000 00000000 00000100 00000001
  printf("Address: %d Value: %d\n", cp, *cp);
  char *cp1 = cp + 1;
  printf("Address: %d Value: %d\n", cp1, *cp1);

  // Generic or void pointer
  void *vp = p; // no need to typecast

  // As void pointer is not mapped to any datatype hence we can't dereference it (can't check the value stored at that address)
  // Neither we can increment void pointer like (vp + 1)
  printf("Address of void pointer: %d", vp);
}


void sum(int a[]) {
  // Whenever compiler see as an array passed as an argument, it implicitly converts the variable to pointer to a variable.
  // Here we have written int a[]... but compiler will convert it to int *a and 'a' stores the base address of the original
  // array. Hence array is always pass by reference.

  // In practice, pointers will be size 2 on a 16-bit system, 4 on a 32-bit system, and 8 on a 64-bit system. In practice, pointers
  // will be size 2 on a 16-bit system, 4 on a 32-bit system, and 8 on a 64-bit system. sizeof(int*) results 8.
  printf("Inside the calling function --> Size of int: %d, size of int*: %d\n", sizeof(int), sizeof(int*));

  // As 'a' is a pointer to an integer hence we can add any constant value to it. It is a proof that 'a' is converted to pointer by compiler.
  // Remember that a[i] is interpreted as *(a + i)
  a = a + 2;
  cout << *a << endl;

  // 'sizeof' on array function parameter 'a' will return size of 'int*' as here 'a' is a pointer variable.
  printf("Inside the calling function --> Size of array: %d, size of first element: %d", sizeof(a), sizeof(a[0]));
}

void arraysAsFunctionArgs() {
  int a[] = {1, 2, 3, 4, 5};
  int i = 3;
  // If we write 'a' then it means &a[0]: the base address or address of the starting element
  printf("Addresses: %d %d\n", (a), (a + 1));
  printf("Inside the caller function --> Size of array: %d, size of first element: %d\n", sizeof(a), sizeof(a[0]));
  sum(a);
}

void printChar(char c[]) {
  // Again char c[] will be converted to char *c that stores the base address.

  printf("Inside printChar() function\n");
  int i = 0;

  // c[i] = *(c + i)
  while(*(c + i) != '\0') printf("%c", c[i]), ++i;
  printf("\n");

  while(*c != '\0') printf("%c", *c), ++c;
  printf("\n");
}

void charArrays() {
  // char c[20];
  // In these way we have to explicitly write the null character at the end.
  // c[0] = 'J', c[1] = 'O', c[2] = 'H', c[3] = 'N', c[4] = '\0';
  char c2[28] = {'j', 'o', 'h', 'n', 'y', '\0'};

  // We can use string literal and we don't need to explicitly write the null character at the end.
  char c[20] = "JOHN";    // We can't separate declaration and initialization.
  char c1[] = "JOHN";     // size will be 4 + 1 = 5

  // printf will print the characters till it find the null character (\0). strlen() will do the same.
  printf("String: %s, Length: %d, size: %d\n", c, strlen(c), sizeof(c));
  printf("String: %s, Length: %d, size: %d\n", c1, strlen(c1), sizeof(c1));
  printf("String: %s, Length: %d, size: %d\n", c2, strlen(c2), sizeof(c2));

  // ********************************************* char pointer ***********************************************

  // By using the name of the character array variable, returns the address. char *cp = c: "cp" stores the base address of the "c"
  // and not the value of variable "c". It is different from an integer pointer. In int pointer: int *p = &c (where c is an int). 
  char *cp = c;   // stores the base address of 'c' and not the actual value but the syntax is like this only.
  cout << "string using character pointer: " << cp << endl;
  printf("%c\n", cp[1]);

  printChar(c);
}

void diffBetweenIntAndCharPointersAndArrays() {
  // Arrays have given some functionalities of pointers.
  
  // ...............1) For integer
  // int a[]; cout << a << endl; will print the base address. We can even dereference it using *a so cout << *a << endl; will
  // print the value at the base address. We can't do a++ --> error. cout << *(a + 3) will print the value at 3rd index.

  // ................2) For character
  // char a[]; cout << a << endl; will print the whole string instead of base address. This is the difference b/w int array and
  // char array. We can even dereference it using *a so cout << *a << endl; will print the value at the base address. We can't do
  // a++ --> error. cout << *(a + 3) will print the value at 3rd index.

  // char *cp = "gunjan". cout << cp << endl; will print the whole string ("gunjan") instead of base address. cout << *cp << endl;
  //  will print the value ("g") at the base address

  char c[20] = "Hello";  // string gets stored in the space for array (stored in the stack as local variables are stored in the stack)
  
  // string gets stored as constant during the compile time, most proabably in the text segment of the memory and since constant so
  // can't be modified. So we can't do cp[1] = 'g'  // error or C++ forbids converting a string constant to 'char*'
  char *cp = c;

  // This will print the address of cp as we have used "%d". If we had used "%s", then it would have printed the whole string
  printf("%d", cp);

  // *cp prints the value at base address which is "H" (use "%c") but as we have used "%d" so print the ASCII value of it i.e. 72
  printf("%d", *cp);
}

// a[2][3]: so points to the 1D array of 3 integers. We can also write int a[][3] = int (*a)[3]
void passing2DArray(int (*a)[3]) {

}

void pointersAnd2DArray() {
  int arr[] = {1, 2, 3};
  
  // Ass array name returns the pointer and here it returns the pointer to a integer.
  int *p = arr;   // correct

  int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
  
  // As here, 'a' returns a pointer but that pointer is a pointer to 1D array of 3 integers
  // int *p1 = a;  // Error

  // We can define the pointer to 1D array of 3 integers
  int (*p1)[3] = a;

  // Similarly for 3D array
  // int a1[3][4][5], (*p2)[4][5] = a1;

  // As "a" is a 2D array ---> *a will print the value or element and here element is not an integer but 1D array of 3 integers.
  // Writing the array name = base address (address of 1st integer) so --> a = a[0] (address of 1st element) = &a[0][0] (1st integer)

  // (a + 1): 1D array --> address of 2nd element and in 1D array "a" points to integer so here element = integer
  // (a + 1): 2D array --> address of 2nd element and in 2D array "a" points to 1D array of 3 integer so here
  // element = 1D array of 3 integers. So 2nd element = 2nd 1D array i.e. a[1] (as pointer always points to the base address
  // initially so if pointer points to 1D array then base address = address of 1st integer so here 2nd element = 2nd 1D array and
  // in 2nd 1D array, pointer initially points to the 1st integer of 2nd 1D array = &a[1][0])

  // So *a = a[0] (or &a[0][0]) which is equal to the address of the 1st element of 1st 1D array.
  // In 1D array --> (a + 2) is the address of the 2nd element... similarly in 2d array ---> (a + 2) is also the address of the 2nd
  // element but here element is not an integer rather element is 1D array of 3 integers.

  // (a + 1) = address of 2nd element = address of a[1] = a[1] = base address + number of columns * sizeof(int)
  for(int i = 0; i<6; ++i) printf("%d ", (a + i));
  cout << endl;

  // a[0] is the name of the 1st 1D array and name of 1D array = base address. So (a[0] + 2) = address of 3rd integer of the
  // 1st 1D array. (a[0] + 4) ?? As we have only 3 columns (3 integers in each 1D array). (a[0] + 3) will point the 2nd element
  // of 2nd 1D array.
  for(int i = 0; i<6; ++i) printf("%d ", (a[0] + i));
  cout << endl;


  // If a = 1d array then *(a + 1) --> element at index 1 and 1D array element = integer
  // Here, a = 2D array .... *(a + 1) --> 'a' is a pointer to 1D array of 3 integers so dereferencing it gives the value to which it
  // points i.e. 'a' points to 1D array of 3 integers so we get the whole 1D array i.e. a[1] (name of the 1D array). And we know
  // that by writing the name of the 1D array gives the base address so a[1] is the base address of the a[1] (a[1] is the name).
  cout << (*(a + 1))[1] << endl;    // *(a + 1) = a[1] so (*(a + 1))[i] = a[1][i]
  printf("%d\n", *(*(a + 1))); // (*a + 1) = a[1] -> *(a[1]) = value of the 1st element (in 1D array element = integer)

  // a[i][j] = *(a[i] + j) = *(*(a + i) + j)

  passing2DArray(a);

  // Address of: a = a[0] = *a[0] = &a[0][0]
  // a[i][j][k] = *(a[i][j] + k) = *(*(a[i] + j) + k) = *(*(*(a + i) + j) + k)
}

void memoryManagemnent() {
  // Heap is called dynamic memory and using heap is called dynamic memory memory allocation. Remember that Heap data structure
  // and this Heap memory are different and don't confuse b/w the both. Stack is also a data structure and infact Stack memory
  // is implemented using Stack DS.

  // Memory leak happens due to unused memory in the heap (unlike in stack, the memory in the heap is not automatically deallocated).
  int *am = (int*) malloc(6 * sizeof(int));  // Not initialize with zero
  int *ac = (int*) calloc(6, sizeof(int));    // Initialize all the elements with zero

  // Doubling the size of "am". It will either create the new array or if possible will extend the memory of "am" only. All the
  // elements will be copied to the new array and rest elements will be assigned a garbage value.
  int *ar1 = (int*) realloc(am, 12 * sizeof(int));
  int *ar2 = (int*) realloc(ac, 3 * sizeof(int));   // Reducing the size of "ac" to half

  // This is equal to using malloc as we have not passed any "array" as a 1st arg so all the elements will be assigned a garbage value.
  int *ar3 = (int*) realloc(NULL, 6 * sizeof(int));
}

void PRINT() {
  cout << "MICROSOFT\n";
}

int* ADD(int *a, int *b) {
  int c = *a + *b;
  return &c;
}

int* ADD1(int *a, int *b) {
  // malloc returns the void pointer which points to the address on the heap (and not on the stack)
  int *c = (int *)malloc(sizeof(int));    // dynamic memory allocation
  *c = *a + *b;
  return c;
}

void pointerAsFunctionReturns() {
  int a = 2, b = 4;
  int *p = ADD(&a, &b);   // ADD1(&a, &b);
  PRINT();
  // Assume only 4 fns are there: main(), pointerAsFunctionReturns(), ADD(), PRINT(). Memory management in the stack: push main ->
  // push pointerAsFunctionReturns -> push ADD -> pop ADD (as 'c' is local to ADD so the space will be deallocated as soon as ADD 
  // finishes it's execution) -> push PRINT (now it may happen that the space which was allocated to ADD, would be allocated to PRINT
  // hence overwriting the data stored of ADD i.e. data of 'c' will be overwritten) -> pop PRINT -> pop pointerAsFunctionReturns -> pop
  // main. Pointer 'p' points to the address of 'c' (defined in ADD) which is deallocated and might be overwritten by some other
  // function call. Hence, *p will give garbage value.

  // So it's okay to pass the address of local variable from top to bottom of the stack but it's not okay to return the address
  // of the local variable from the top to bottom in the stack.

  // We can fix the above problem by using dynamic memory allocation and we know that dynamic memory is allocated in the heap and
  // we have to explicitly deallocate (free) the memory (or when program ends). Change the code from ADD to ADD1. Instead of
  // dynamic memory allocation, we could have used global pointer.
  printf("Sum of a and b: %d", *p);
}

double cal(int a, float b) {
  return a + b;
}

int *check(int a, int b) {
  int *ptr = new int;
  *ptr = 5;
  return ptr;
}

void functionPointers() {
  // Pointer to fn that should take (int, float) as an argument and return double. We are putting the name of the pointer within the
  // parenthesis. If we would not use parenthesis: 'int *p(int, int)' --> it becomes function declaration and not fn pointer.
  double (*p)(int, float) = &cal;   // we can avoid using '&' as by directly fn name will return the address
  
  // Pointer to fn that should take (int, int) as an argument and return *int
  int *(*ptr)(int, int) = &check;   // we can avoid using '&' as by directly fn name will return the address

  // We dereference the fn pointer *p. We can avoid using dereferencing operator and achieve the same thing.
  double sum = (*p)(2, 3.56f);    // p(2, 3.56f) 
  cout << "sum using fn pointer: " << sum << endl;

  int *res = (*ptr)(2, 4);  // ptr(2, 4)
  cout << "sum using fn pointer: " << *res << endl;
}

void B(void (*ptr)()) {
  ptr();  // call-back fn that "ptr" points to 
}

void functionPointers1() {
  // Fn pointers can be passed as an argument to fns. Fn that would receive a fn pointer as an argument can callback the
  // fn that this pointer will point to. PRINT() will act as a callback fn as it is passed as an argument.
  B(PRINT);
}

int main() {

}