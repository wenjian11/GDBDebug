#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int signal)
{
    printf("Received signal: %d\n", signal);
}

int main()
{
    signal(SIGINT, handle_signal);
    printf("waiting for signal...\n");
    while (1)
    {
        sleep(1);
    }
    return 0;
}