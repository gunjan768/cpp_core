#include <bits/stdc++.h>
using namespace std;

void ForEach(const vector<int> &values, void (*callback)(int))
{
  for (int value : values)
  {
    callback(value);
  }
}

// If you are capturing anything in the lamda function, then you can't use raw function pointer, you need to use function type.
// function<void(int)>: Returing type is void and taking one integer parameter. Syntax: function<return_type(arg1_type, arg2_type, ...)>
void Lambda_1(const vector<int> &values, const function<void(int)> &callback)
{
  for (int value : values)
  {
    callback(value);
  }
}

void lambdas()
{
  int a = 5;
  vector<int> values {1, 2, 3, 4, 5};

  auto lambda = [](int value)
  {
    cout << "Value: " << value << endl;
  };

  ForEach(values, lambda);

  // Weird: Though you passed 'a' by value, you can't change it (in normal function you can easily do it). To achive it, use mutable
  // keyword
  auto lambda1 = [a](int value) mutable
  {
    a = 10;
    // We want to use variable 'a' defined outside of lambda1
    cout << "Value: " << a + value << endl;
  };

  // If you are capturing anything in the lamda function, then you can't use raw function pointer, you need to use function type.
  Lambda_1(values, lambda1);
}

int main()
{

  return 0;
}