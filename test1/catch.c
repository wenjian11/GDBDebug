#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int ret = 0;
    ret = fork();
    if (ret == 0)
    {
        execv("child", NULL); // child.c����ɵĿ�ִ���ļ�
    }

    return 0;
}