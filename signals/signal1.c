#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>

int main(void) {
    int status;
    pid_t pid;

    // Create a child process
    if (!(pid = fork())) {
        // In the child process
        sleep(1);  // Wait for a second before sending a signal
        // Send a SIGKILL signal to the parent process
        kill(getppid(), SIGKILL);
        return 1;  // Terminate the child process
    }

    // In the parent process
    pid = wait(&status);  // Wait for the child process to change state
    if (pid == -1)
        perror("wait");

    printf("pid=%d\n", pid);

    // Check the status of the terminated child
    if (WIFEXITED(status))
        printf("Normal termination with exit status=%d\n", WEXITSTATUS(status));
    if (WIFSIGNALED(status))
        printf("Killed by signal=%d%s\n", WTERMSIG(status), WCOREDUMP(status) ? " (dumped core)" : "");
    if (WIFSTOPPED(status))
        printf("Stopped by signal=%d\n", WSTOPSIG(status));
    if (WIFCONTINUED(status))
        printf("Continued\n");

    return 0;
}

