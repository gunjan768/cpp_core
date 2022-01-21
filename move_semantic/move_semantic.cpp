#include <bits/stdc++.h>
using namespace std;

class Move
{
public:
  int *data;

  Move() = default;
  Move& operator=(const Move &a) = default;

  Move(int data)
  {
    this->data = new int;
    *this->data = data;
    cout << "constructor called for: " << data << endl;
  }

  // Copy constructor
  Move(const Move &a)
  {
    this->data = new int;
    *this->data = *a.data;
    cout << "copy constructor called for: " << *a.data << endl;
  }

  // Move constructor
  Move(Move &&a) noexcept // noexcept means no exception
  {
    this->data = a.data;
    a.data = NULL; // Stealing the data and making the source data NULL
    cout << "move constructor (moving resource instead of copying) called for: " << *this->data << endl;
  }

  // Move assignment operator
  Move& operator=(Move &&a) noexcept // noexcept means no exception
  {
    // We are not moving the same object i.e. obj = obj.
    if (this != &a)
    {
      // since we will overwrite the current object i.e. all the data of the current object, so we will first free the memory to avoid
      // memory leak as we can never access this memory as we will overwrite the pointer.
      delete data;
    }

    this->data = a.data;
    a.data = NULL; // Stealing the data and making the source data NULL
    cout << "Move assignment operator called for: " << *this->data << endl;

    // this is a pointer points to the address of the current object. *this means dereferencing i.e. access the value which is the
    // object. We are returning the object. But since our return type is Move& and not Move so actually we are returning the
    // reference to an object.
    return *this;
  }

  ~Move()
  {
    if (data != NULL)
    {
      cout << "Destructor called for: " << *data << endl;
    }
    else
    {
      cout << "Destructor called for nullpointer" << endl;
    }
  }
};

int main()
{
  vector<Move> v;

  // By creating the object first and then inserting them in the vector
  // {
  //   Move a1{10};
  //   Move a2{20};
  //   Move a3{30};

  //   // Compiler will copy the object and stores in the vector so equivalent code: Move obj{a1} --> calls copy constructor. When you
  //   // output the data, you will see the multiple copy constructor calls, that becoz when u insert more than one element, element arranges
  //   // itself in the vector so internally vector creates temporary object and copy the data.
  //   v.emplace_back(a1);
  //   v.emplace_back(a2);
  //   v.emplace_back(a3);

  //   cout << v.size() << endl;
  // }

  // Object is created at the time of insertion in the vector
  {
    // Object is created but without name. So first constructor will be called for the object creation and then copy constructor is called
    // for copying it to the vector and then immediately destructor for destroying the temporary object created (as no name is there so it
    // will be destroyed immediately ... it's just like creating and destroying)

    // When you uncomment the code for move constructor, then it will be called instead of copy constructor as we are using R-value.
    v.emplace_back(Move{10}); // r-value (directly passing the value)
    v.emplace_back(Move{20});
    v.emplace_back(Move{30});
  }

  Move mv1 {10}, m1{55}, m2{44};
  Move mv2 = mv1;   // call move constructor
  Move mv3, mv4, mv5;
  mv3 = mv2;

  // If default copy assignment operator is defined then use move() method or explictly convert to call move assignment. Comment the
  // default copy assignment operator and see it.
  mv4 = move(m1);   // call move assignment operator --> move() method
  mv5 = (Move&&)m2; // call move assignment operator -->  explictly convert to call move assignment

  cout << "End of the program\n";
}