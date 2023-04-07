#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>



void basic_example() {
    pid_t pid = fork();
    if (pid == 0) {
        char* args[] = {"/bin/ls", "-la", NULL};
        execvp(args[0], args);
        perror("exec");
        exit(1);
    } else if (pid < 0) {
        perror("fork");
    } else {
        wait(NULL);
        printf("Child process finished\n");
    }
}

void intermediate_example() {
    pid_t pid = fork();
    if (pid == 0) {
        char* args[] = {"/bin/ls", "-la", NULL};
        execv(args[0], args);
        perror("exec");
        exit(1);
    } else if (pid < 0) {
        perror("fork");
    } else {
        sleep(2);
        printf("Killing child process\n");
        kill(pid, SIGKILL);
    }
}

void forkbomb() {
    while (1) {
        fork();
    }
}

int main() {
    printf("Basic example:\n");
    basic_example();
    printf("\nIntermediate example:\n");
    intermediate_example();
    printf("\nForkbomb example (use with caution):\n");
    forkbomb();
    return 0;
}
