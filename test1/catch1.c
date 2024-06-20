#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int ret = 0;
    ret = fork();
    if (ret == 0)
    {
        execv("child", NULL); // child.c编译成的可执行文件
    }
    printf("main over \n");
    return 0;
}