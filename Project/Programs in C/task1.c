#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64

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
        char* args[MAX_ARGS];
        int arg_count = 0;
        char* token = strtok(command, " \n");
        while (token != NULL && arg_count < MAX_ARGS) {
            args[arg_count] = token;
            arg_count++;
            token = strtok(NULL, " \n");
        }
        args[arg_count] = NULL;
        if (arg_count == 0) {
            continue;
        }
        if (strcmp(args[0], "cd") == 0) {
            if (arg_count < 2) {
                chdir(getenv("HOME"));
            } else {
                chdir(args[1]);
            }
        } else {
            pid_t pid = fork();
            if (pid == 0) {
                execvp(args[0], args);
                perror("execvp");
                exit(1);
            } else if (pid < 0) {
                perror("fork");
            } else {
                waitpid(pid, NULL, 0);
            }
        }
    }
    return 0;
}
