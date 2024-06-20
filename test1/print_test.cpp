#include <iostream>
#include <vector>

struct Point
{
    int x, y;
};

int main()
{
    int a = 10;
    int b = 20;
    int *ptr = &a;
    Point p = {3, 4};
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::cout << "Hello, GDB!" << std::endl;
    return 0;
}
