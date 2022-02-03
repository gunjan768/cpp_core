#include <bits/stdc++.h>
using namespace std;

template <typename T>
void pr(T u, char c = ' ')
{
  cout << u << " ";

  if (c == '\n')
  {
    cout << endl;
  }
}

void constAndPointers()
{
  int a = 5;
  const int *p = &a;        // pointer to a constant
  int *const p1 = &a;       // constant pointer
  const int *const p2 = &a; // constant pointet to a constant
}

void pointerPitFalls()
{
  // 1) Uninitialized pointer so *p = 100; may crash our app
  int *p;

  // 2) Dangling pointer: pointer pointing to released memory. Also called Wild or Stray pointer. Example we saw above
  // when we returned the address of a variable from a function (function ends and so the variable).
}

// ****************************************************** Smart Pointers *********************************************************

class Foo
{
public:
  int x;
  explicit Foo(int x) : x{x} {}
  int gett_x() { return x; }
  auto* gett_address_x() {return &x;}
  ~Foo() { cout << "~Foo\n"; }
};

void unique_smart_pointer()
{
  // unique_ptr<T>
  // . Points to an object of type T on the heap.
  // It is unique - there can only be one unique_ptr<T> pointing to the object on the heap.
  // . Owns what it points to.
  // . Cannot be assigned or copied hence copy constructor and copy assignment are not there.
  // . Can be moved (change the owner).
  // . When the pointer is destroyed, what it points to is automatically destroyed. When exception comes, then also it will
  // de-allocate the memory hence no memory leak.
  // . Not only object, we can create array of objects also.
  // Functions: release, reset, swap, get, get_deleter

  // You can't copy or assign one instance of unique_smart_pointer to another as copy constructor and copy assignment operator
  // are deleted from it.
   
  int *pp = new int(56);           // can also write: int *pp = new int{56};
  int *pp0{new int{78}};           // initialization list (initializing 'pp0' variable) with value initialization (passing 78 to int)
  unique_ptr<int> p(pp);           // Created pointer and then passed to the unique_ptr class constructor.
  unique_ptr<int> p0(new int(12)); // Creating pointer without name and then passing it to the unique_ptr class constructor.
  unique_ptr<int> p1{new int{20}}; // intializing using initializer list (same as above one)

  // make_unique<int>(10) will create a pointer (dynamically) with value 10; make_unique<> class was introduced in C++14.
  unique_ptr<int> p2 = make_unique<int>(10);
  // unique_ptr<int> p3(10);  // Throws an error as no overloaded constructor is there which accepts integer value.

  // * operator is overloaded in the unique_ptr class that's why it direclty works on unique_ptr instance.
  pr(*p), pr(*p0), pr(*p1), pr(*p2, '\n');

  unique_ptr<Foo> f1{new Foo{10}};
  unique_ptr<Foo> f2{make_unique<Foo>(20)};

  pr(f1->gett_x()), pr((*f2).gett_x(), '\n');

  // x = move(y) will move the ownership from f1 to f3 and f1 becomes NULL
  unique_ptr<Foo> f3{move(f1)}; // unique_ptr<Foo> f3 = move(f1);   initialization list for initializing 'f3'

  Foo *foo = f3.get();
  pr(foo->gett_x());
  Foo *foo1 = f3.release(); // will release the ownership of an object and return that object pointer so now f3 becomes NULL
  pr(foo1->gett_x(), '\n');

  // f2 was pointing to value '20' on the heap and now it will point to what 'foo1' points. We changed the managed object of
  // f2 and the previous object f2 was pointing will be deleted.
  f2.reset(foo1);

  // We can directly call any member of the object (here Foo instance) to which f2 is pointing as arrow (->) and * operators are
  // overloaded. If want to call member of unique_ptr<> class, then do directly using dot (.) operator as unique_ptr<> is a class
  // and we call members of class using dot operator.
  pr(f2->gett_x()), pr((*f2).gett_x());
}

void shared_pointer()
{
  // Shared pointer:
  // . is a smart pointer which can share the ownership of object (managed object)
  // . serveral shared_ptr can point to the same object (managed object)
  // . IF last shared_ptr goes out of scope then the managed object gets deleted.
  // . managed object is not thread safe (so we need to create object that is thread safe) but control block (or reference count)
  //    is thread safe.
  Foo *temp {new Foo{568}};
  shared_ptr<Foo> f1{temp};
  shared_ptr<Foo> f3{make_shared<Foo>(45)};
  cout << "Value: " << f1->gett_x() << " Use count: " << f1.use_count() << endl;
  shared_ptr<Foo> f2 = f1; // Will not work if uses pointer or reference (*f2 or &f2)

  // &f1 will give the address of shared_ptr class instance 'f1'. So every intance will have different address so
  // &f1 != &f2 != &f3. Managed object is shared so getting the address of managed object from any shared_ptr instance will
  // be same as we are getting the address of same managed object. 
  printf("temp --> Address: %d, Value: %d\n", &temp, (*temp).gett_x());
  printf("f1 --> Address: %d, Value: %d\n", &f1, f1->gett_x());
  printf("f2 --> Address: %d, Value: %d\n", &f2, (*f2).gett_x());
  printf("f3 --> Address: %d, Value: %d\n", &f3, f3->gett_x());
  printf("Address must be same for f1 and f2--> f1: %d, f2: %d, f3: %d\n", f1->gett_address_x(), f2->gett_address_x(), f3->gett_address_x());
  cout << "Value: " << f1->gett_x() << " Use count: " << f1.use_count() << endl;
  cout << "Value: " << f2->gett_x() << " Use count: " << f2.use_count() << endl;

  Foo *foo1 = f1.get();
  Foo *foo2 = f1.get();
  Foo *foo3 = f1.get();

  printf("Addresses should be different -> foo1: %d, foo2: %d, foo3: %d\n", &foo1, &foo2, &foo3);
}

void weak_pointer()
{
  // . Weak pointer is for non-ownership smart pointer.
  // . It actually reference to an object which is managed by shared_ptr.
  // . We can't get the managed object by weak_ptr, hence weak_ptr doesn't has get() method.. We have to use the lock() method to first
  //   get the shared_ptr and then by the shared_ptr we get the managed object.
  // . A weak_ptr is created a copy of shared_ptr.
  // . We have to convert weak_ptr to shared_ptr in order to use the managed object.
  // . It is used to remove cyclic dependency b/w shared_ptr.
  shared_ptr<int> sharedPointer{make_shared<int>(45)};

  // Initializing shared_ptr to weak_ptr will not increase the count
  weak_ptr<int> weakPointer{sharedPointer};

  cout << "weakPointer.use_count(): " << weakPointer.use_count() << endl;
  cout << "sharedPointer.use_count(): " << sharedPointer.use_count() << endl; // count = 1
  cout << "weakPointer.expired(): " << weakPointer.expired() << endl;

  // weakPointer.lock() will check that shared_ptr is still alive to which it points to and return that shared_ptr.
  // Initializing weak_ptr to shared_ptr will increase the count
  if (shared_ptr<int> sharedPointer1 = weakPointer.lock())
  {
    // Remember that * and -> are overloaded so using them on smart pointers is working thme on the managed object smart pointer
    // has.
    cout << "sharedPointer address: " << &sharedPointer << endl;
    cout << "sharedPointer1 address: " << &sharedPointer1 << endl;
    cout << "weakPointer address: " << &weakPointer << endl; // weak_ptr is created a copy of shared_ptr so address will be different
    cout << "sharedPointer value: " << *sharedPointer << endl;
    cout << "sharedPointer1 value: " << *sharedPointer1 << endl;
    cout << "sharedPointer1.use_count(): " << sharedPointer1.use_count() << endl; // count = 2
  }

  weakPointer.reset();
  if (shared_ptr<int> sharedPointer1 = weakPointer.lock())
  {
  }
  else
  {
    cout << "Don't get the resource\n";
  }
}

void smartPointers()
{
  class ExampleSmartPointer
  {
    int *ptr;

  public:
    // explicit Keyword in C++ is used to mark constructors to not implicitly convert types in C++. It is optional for constructors that
    // take exactly one argument and works on constructors(with single argument) since those are the only constructors that can be used
    // in type casting.
    explicit ExampleSmartPointer() {} // 'explicit' before no arg constructor will not throw error but 'explicit' will have not effect.
    explicit ExampleSmartPointer(int *ptr = nullptr) : ptr{ptr} {}
    int &operator*() { return *ptr; };
    ~ExampleSmartPointer() { delete ptr; };
  };

  // With raw pointers we have pitfalls (see pointerPitFalls()). So Smart pointers come into play. They are implemented
  // by C++ and all the allocation and de-allocation is done automatically. They are implemented as C++ template classes
  // which we can instantiate. They can only point to heap allocated memory (dynamic allocated memory) and they automatically
  // call delete when no longer needed.

  // To use smart pointer: #include <memory>. They are wrapper classes over a raw pointer. Smart pointer classes provide overloaded
  // dereference (*) and member selection (->) operators. However, we can't do arithmetic on them like ++, --, etc.

  // There are 3 types of smart pointers:
  // 1) unique_ptr: Allows only one owner of the underlying pointer (cannot copy but move the ownernship)
  // 2) shared_ptr: Allows multiple owners of the same pointer (reference count is maintained)
  // 3) weak_ptr: It is special type of shared_ptr which doesn't count the reference

  int *p1 = new int(10); // Normal initialization
  int *p{new int{10}};   // List initilization
  ExampleSmartPointer ptr{p};
  cout << "ExampleSmartPointer: " << *ptr << endl;

  // unique_smart_pointer();
}

// ***************************************************** Smart Pointers Demo *************************************************

class Entity
{
public:
  Entity() { cout << "Entity Constructor\n"; }
  Entity(const Entity &vertex) { cout << "Entity Copy Constructor\n"; }
  ~Entity() { cout << "Entity Destructor\n"; }
};

// SmartPointer is also called Scoped pointer
class SmartPointer
{
  Entity *ptr;
public:
  SmartPointer(Entity *ptr): ptr{ptr} { cout << "SmartPointer Constructor\n"; }
  ~SmartPointer() { delete ptr; cout << "SmartPointer Destructor\n"; }
};


void smart_pointers()
{
  // Type conversion will happen, one class to another class. We have one arg constructor in the SmartPointer class for conversion.
  // We could have stored Entity instance in some variable like: Entity *entity = new Entity(); and then assign to SmartPointer
  // like: SmartPointer smartPointers = entity;

  // Here, we stored memory on the heap (new Entity()) and we have not written explictly to delete it using delete keyword as we
  // have used SmartPointer instance and not SmartPointer pointer. In this way, original SmartPointers work.
  SmartPointer smartPointers = new Entity();    // implicit type conversion. It is same as: SmartPointer smartPointers(new Entity());

  // Smartpointers like unique_ptr don't have implicity type conversion as constructors of smart pointers are marked explicit
  // i.e. no type conversion can happen.
  // unique_ptr<Entity> Entity = new Entity();  // thorws error as no implicit type conversion
  unique_ptr<Entity> entity(new Entity());  // Calling constructor
}

int main()
{
  smart_pointers();
}