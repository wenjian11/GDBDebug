#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_print();
int main()
{
    my_print();
    return 0;
}

int my_print()
{
    printf("hello world\n");
    return 0;
}