#include <bits/stdc++.h>
using namespace std;

// **************************************************** Type Conversion *************************************************************

void primitive_to_class()
{
  class Person
  {
  public:
    int a, b;

    Person(int a, int b) : a{a}, b{b} {}
    Person(int a) : Person{a, 0} { cout << "Called\n"; }
    Person() : Person{0, 0} {}
  };

  Person p{2, 3};
  int x = 56;
  cout << p.a << " " << p.b << endl;
  p = x; // Will call single arg constructor for type conversion from primitive to class
  cout << p.a << " " << p.b << endl;
  p = 12; // Will call single arg constructor for type conversion from primitive to class
  cout << p.a << " " << p.b << endl;
}

void class_to_primitive()
{
  // We use Casting operator to convert class to primitive type. Syntax: operator return_data_type() {.....; return data_type;}
  // This is the second use of operator keyword (fist use is in the operator overloading). This Casting operator must be a
  // part of class (member). 'return_data_type' is the data type into which we want to convert the class type.
  class Person
  {
  public:
    int a, b;

    Person(int a, int b) : a{a}, b{b} {}
    Person(int a) : Person{a, 0} { cout << "Called\n"; }
    Person() : Person{0, 0} {}
    operator int() { return 6; }
  };

  Person p{2, 3};
  int x = 56;
  cout << x << endl;
  x = p; // Will call the Casting operator for type conversion from class type to primitive type
  cout << x << endl;
}

class Animal;

class Person
{
public:
  int a, b;

  Person(int a, int b) : a{a}, b{b} {}
  Person(int a) : Person{a, 0} { cout << "Called Person\n"; }
  Person() : Person{0, 0} {}
  Person(Animal animal);
};

class Animal
{
public:
  int a, b;

  Animal(int a, int b) : a{a}, b{b} {}
  Animal(int a) : Animal{a, 0} { cout << "Called Animal\n"; }
  Animal() : Animal{0, 0} {}
};

Person::Person(Animal animal)
{
  a = animal.a;
  b = 0;
}

void oneClass_to_anotherClass()
{
  Person person{2, 3};
  Animal animal{5, 6};
  cout << "Person: " << person.a << " " << person.b << endl;
  cout << "Animal: " << animal.a << " " << animal.b << endl;
  // We could achive the same thing using the casting operator but that casting operator has to be defined in the Animal class.
  person = animal; // Animal to Person type
  cout << "Person: " << person.a << " " << person.b << endl;
  cout << "Animal: " << animal.a << " " << animal.b << endl;
}

void type_conversion()
{
  oneClass_to_anotherClass();
}

int main()
{
}