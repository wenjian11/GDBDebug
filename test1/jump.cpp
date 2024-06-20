#include <iostream>

int main()
{
    int x = 0;
    int y = 1;
    int z = 2;
    std::cout << "Before jump: x = " << x << ", y = " << y << ", z = " << z << std::endl;
    z = x + y;
    std::cout << "After jump: x = " << x << ", y = " << y << ", z = " << z << std::endl;
    return 0;
}
