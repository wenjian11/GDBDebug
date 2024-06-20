#include <iostream>
using namespace std;

class MyClass
{
public:
    static int staticVar;
    static void staticFunc()
    {
        // some code
        std::cout << "Hello, GDB!" << std::endl;
    }
};

namespace MyNamespace
{
    int var = 5;
    void func()
    {
        std::cout << "MyNamespace::func() called. Hello, GDB!" << std::endl;
    }
}

int MyClass::staticVar = 42;

int main()
{
    MyClass::staticFunc();
    return 0;
}