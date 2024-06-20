#include <iostream>

void foo(int x)
{
    std::cout << "x = " << x << std::endl;
}

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        foo(i);
    }
    return 0;
}
