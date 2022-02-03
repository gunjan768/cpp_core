#include <bits/stdc++.h>
using namespace std;

bool check(string &s)
{
  return s.size() == 3;
}

class Check {
  public:
  bool operator()(string &s) {
    return s.size() == 3;
  }  
} obj;

// function<return_type(type_of_arg1, type_of_arg2, ......)> .... It is used to pass one function to other. We can use it
// if we want define recursive function inside int main() or inside any function.
void run(function<bool(string&)> check) {
  string s = "Gunjan";
  cout << check(s) << endl;
}

void function_type()
{
  vector<string> v{"one", "two", "three", "four", "six"};

  const auto lambda = [](string &s) -> bool
  {
    return s.size() == 3;
  };

  // ************************************************ Using inbuilt count_if() **************************************************

  // In the below examples, count_if() takes third parameter as anything which is callable for eg: lambda, normal function
  // or even instance of class where operator () is overloaded. It does by accepting function<> as it's 3rd arg.
  cout << count_if(v.begin(), v.end(), check) << endl;
  cout << count_if(v.begin(), v.end(), lambda) << endl;
  cout << count_if(v.begin(), v.end(), [](string &s) -> bool { return s.size() == 3; }) << endl;
  cout << count_if(v.begin(), v.end(), obj) << endl;

  // ******************************************** Using user defined run() function ***********************************************

  run(check);
  run(lambda);
  run([](string &s) -> bool { return s.size() == 3; });
  run(obj);

  // ************************************ function<return_type(type_of_arg1, type_of_arg2, ......)>******************************

  function<double(float&&, int)> add = [](float &&a, int b) -> double {
    return a + b;
  };

  cout << add(4.23, 1) << endl;
}

// https://www.geeksforgeeks.org/recursive-lambda-expressions-in-cpp/
int main()
{
  function_type();
  return 0;
}