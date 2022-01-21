#include <bits/stdc++.h>
using namespace std;

class Move
{
public:
  int *data;

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
  Move(Move &&a) noexcept
  {
    this->data = new int;
    *this->data = *a.data;
    a.data = NULL;    // Stealing the data and making the source data NULL
    cout << "move constructor (moving resource instead of copying) called for: " << *this->data << endl;
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

  cout << "End of the program\n";
}