#include <bits/stdc++.h>
using namespace std;

class Vertex
{
public:
  int x, y, z;
  Vertex(int a, int b, int c) { cout << "3 args Constructor\n"; }
  Vertex(const Vertex &vertex) { cout << "Copy Constructor\n"; }
};

void vector_optimization()
{
  vector<Vertex> vertices;

  // reserve(x) assures that we have enough memory for 'x' objects. It will not construct any object beforehand. resize(x) or
  // vector<Vertex> vertices (x); will do both reserve memory for 'x' objects and construct x default objects. Using reserve()
  // we reduced the number of copies being done by the vector class internally when it needs to increase it's size (same is also
  // done using resize(x) or vector<Vertex> vertices (x) but they constructs x objects).
  vertices.reserve(5);

  // ******************************************** emplace_back ***************************************************************

  // Variadic meaning. (computing, mathematics, linguistics) Taking a variable number of arguments; especially, taking arbitrarily many
  // arguments. C's printf is one of the most widely used variadic functions.

  // emplace_back shouldn't take an argument of type vector::value_type, but instead variadic arguments that are forwarded to
  // the constructor of the appended item. template <class... Args> void emplace_back(Args&&... args);

  // Using push_back will construct the object in the main frame and then copy it to the location where vector is located. We can
  // avoid this using emplace_back(). emplace_back() tells the vector that construct the Vertex object in place in our actual vector
  // memory. We just pass the paramters without the Constructor.
  vertices.emplace_back(1, 2, 3);

  // All below ones are same and they will call constructor to first instantiate the Vertex object (in the main fream only i.e. same
  // as push_back() as we don't have Move constructor in the Vertex class otherwise it would call move constructor instead of copy 
  // ctor) and then copy it to the vector.
  // vertices.push_back({1, 2, 3});
  // vertices.push_back(Vertex{1, 2, 3});
  // vertices.push_back(Vertex(1, 2, 3));

  // Because it forwards the arguments, this means that if you don't have rvalue, this still means that the container will store a
  // "copied" copy, not a moved copy. In the below examples, even if we had the move ctor, it would call copy ctor instead.
  Vertex obj(1, 2, 3);
  vertices.emplace_back(obj);
}

int main()
{
  vector_optimization();
}