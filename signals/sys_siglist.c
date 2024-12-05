#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h> // For strsignal

static void sig_handler(int n)
{
    printf("The signal caught: %s\n", strsignal(n));
}

int main()
{
    if (signal(SIGINT, sig_handler) == SIG_ERR)
    {
        fprintf(stderr, "Failed to handle SIGINT\n");
        exit(EXIT_FAILURE);
    }
    if (signal(SIGCHLD, sig_handler) == SIG_ERR)
    {
        fprintf(stderr, "Failed to handle SIGCHLD\n");
        exit(EXIT_FAILURE);
    }
    if (signal(SIGALRM, sig_handler) == SIG_ERR)
    {
        fprintf(stderr, "Failed to handle SIGALRM\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        printf("Inside the main...\n");
        sleep(5);
    }

    return 0;
}

