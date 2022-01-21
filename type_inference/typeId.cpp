#include <bits/stdc++.h>
using namespace std;

class Animal
{
};

void typeId_on_object()
{
  int i, j;
  char c;

  // Get the type info using typeid operator
  const type_info &ti1 = typeid(i);
  const type_info &ti2 = typeid(j);
  const type_info &ti3 = typeid(c);

  // Check if both types are same
  if (ti1 == ti2)
  {
    cout << "i and j are of" << " similar type" << endl;
  }
  else
  {
    cout << "i and j are of" << " different type" << endl;
  }

  // Check if both types are same
  if (ti2 == ti3)
  {
    cout << "j and c are of" << " similar type" << endl;
  }
  else
  {
    cout << "j and c are of" << " different type" << endl;
  }
}

void typeId_on_expression() 
{
  int i = 5;
  float j = 1.0;
  char c = 'a';

  // Get the type info using typeid operator
  const type_info& ti1 = typeid(i * j);
  const type_info& ti2 = typeid(i * c);
  const type_info& ti3 = typeid(c);

  // Print the types
  cout << "ti1 is of type " << ti1.name() << endl;
  cout << "ti2 is of type " << ti2.name() << endl;
  cout << "ti3 is of type " << ti3.name() << endl;
}

void typeId()
{
  // typeid is an operator in C++. typeid(type); OR typeid(expression);

  // ............................. What is typeid?
  // It is used where the dynamic type or runtime type information of an object is needed.
  // It is included in the <typeinfo> library. Hence inorder to use typeid, this library should be included in the program.
  // The typeid expression is an lvalue expression.

  // .............................. Parameters
  // type: This parameter is passed when the runtime type information of a variable or an object is needed. In this, there is no evaluation
  // that needs to be done inside type and simply the type information is to be known.
  // expression: This parameter is passed when the runtime type information of an expression is needed. In this, the expression is first
  // evaluated. Then the type information of the final result is then provided.

  // ............................ Return Value
  // This operator provides the runtime type information of the specified parameter and hence that type information is returned, as a
  // reference to an object of class type_info.

  // typeid(x).name() returns the data type of x, for example, it return ‘i’ for integers, ‘d’ for doubles, ‘Pi’ for the pointer to integer
  // etc. But the actual name returned is mostly compiler dependent.
  
  double val;
  Animal animal;
  string s;

  // Print 'd' means double (i - integer)
  cout << typeid(val).name() << endl;
  cout << typeid(animal).name() << endl;

  // Name mangling will happen which means some extra characters will be added to get more info about the class.
  cout << typeid(s).name() << endl;

  // decltype is used to declare a variable of an existing type.
  // decltype
}

int main()
{
  typeId();
}