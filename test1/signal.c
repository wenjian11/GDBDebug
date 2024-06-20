#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// �źŴ�����
void signal_handler(int signum)
{
    printf("Received signal: %d\n", signum);
    // �������źŴ���������һЩ�������¼��־���߽����ض�����
}

int main()
{
    // ע���źŴ�����
    signal(SIGINT, signal_handler);  // ���յ� SIGINT (Ctrl+C) ʱ���� signal_handler
    signal(SIGSEGV, signal_handler); // ���յ� SIGSEGV (�δ���) ʱ���� signal_handler

    // ����ѭ����ģ���������
    while (1)
    {
        printf("Program running...\n");
        sleep(1);
    }

    return 0;
}
