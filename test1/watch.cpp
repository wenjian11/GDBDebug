#include <stdio.h>

int main()
{
    int x = 0;
    for (int i = 0; i < 10; ++i)
    {
        x += i;
        printf("x = %d\n", x);
    }
    return 0;
}
