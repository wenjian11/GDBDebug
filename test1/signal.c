#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// 信号处理函数
void signal_handler(int signum)
{
    printf("Received signal: %d\n", signum);
    // 可以在信号处理函数中做一些处理，如记录日志或者进行特定操作
}

int main()
{
    // 注册信号处理函数
    signal(SIGINT, signal_handler);  // 当收到 SIGINT (Ctrl+C) 时调用 signal_handler
    signal(SIGSEGV, signal_handler); // 当收到 SIGSEGV (段错误) 时调用 signal_handler

    // 无限循环，模拟程序运行
    while (1)
    {
        printf("Program running...\n");
        sleep(1);
    }

    return 0;
}
