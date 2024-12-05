#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // Create a new process

    if (pid < 0) { // Error handling for fork
        perror("fork failed");
        exit(1);
    } else if (pid == 0) { // Child process
        char *args[] = {"/bin/ls", "ll", NULL}; // Arguments for execv
        if (execv(args[0], args) == -1) { // Execute ls -l
            perror("execv failed"); // If execv fails
            exit(1); // Exit the child process to prevent continuation
        }
    } else { // Parent process
        wait(NULL); // Wait for the child process to complete
        printf("Child process complete\n");
    }

    return 0;
}

