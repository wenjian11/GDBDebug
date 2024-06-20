#include <iostream>

int main()
{
    int i = 0;
    for (i = 0; i < 5; ++i)
    {
        std::cout << "i = " << i << std::endl;
    }
    float f = 3.14;
    char c = 'A';
    const char *str = "Hello, GDB!";
    int arr[] = {1, 2, 3, 4, 5};
    return 0;
}
