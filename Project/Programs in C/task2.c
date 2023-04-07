#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

void print_prompt() {
    char hostname[1024];
    gethostname(hostname, 1024);
    char username[1024];
    getlogin_r(username, 1024);
    printf("%s@%s:~$", username, hostname);
}

int main(int argc, char** argv) {
    while (1) {
        print_prompt();
        char command[MAX_COMMAND_LENGTH];
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        if (strcmp(command, "exit\n") == 0) {
            break;
        }
        pid_t pid = fork();
        if (pid == 0) {
            char* args[MAX_COMMAND_LENGTH];
            int arg_count = 0;
            char* token = strtok(command, " \n");
            while (token != NULL && arg_count < MAX_COMMAND_LENGTH) {
                args[arg_count] = token;
                arg_count++;
                token = strtok(NULL, " \n");
            }
            args[arg_count] = NULL;
            if (arg_count == 0) {
                continue;
            }
            if (strcmp(args[0], "rm") == 0 ||
                strcmp(args[0], "cat") == 0 ||
                strcmp(args[0], "clear") == 0 ||
                strcmp(args[0], "cowsay") == 0) {
                execvp(args[0], args);
                perror(args[0]);
                exit(1);
            }
            printf("Unknown command: %s\n", args[0]);
            exit(1);
        } else if (pid < 0) {
            perror("fork");
        } else {
            waitpid(pid, NULL, 0);
        }
    }
    return 0;
}
