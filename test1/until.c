#include <stdio.h>

void customFunction()
{
    for (int i = 0; i < 5; i++)
    {
        printf("Loop iteration %d\n", i);
    }
    printf("End of customFunction\n");
}

int main()
{
    printf("Hello, World!\n");
    customFunction();
    return 0;
}
