#include <stdio.h>

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main() {
    printf(ANSI_COLOR_GREEN "Welcome to MyShell!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_GREEN "machinename@username:" ANSI_COLOR_RESET "~$ ");
    // read user input and execute commands
    return 0;
}
