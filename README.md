#                                                                        Shell Project  
Shell project, Operating Systems IT 204, International Burch University.

## **About the project**

Task 1: In this approach, the command is executed using execvp() in a child process when the user enters input, which is parsed to extract the command and its parameters. Moreover, a built-in cd command is available for switching directories.

Task 2: This program is a simple shell implementation that continuously prompts the user for commands, forks a child process to execute the command, and waits for the child process to finish. If the command is recognized (rm, cat, clear, and cowsay), the execvp() function is called to execute it.

Task 3: This program demonstrates usage of the fork() and exec() system calls, as well as the kill() function to send signals to processes. The basic_example() function forks a child process and executes the "ls -la" command using execvp(). The intermediate_example() function is similar to the basic_example() function, but it kills the child process after waiting for 2 seconds using the kill() function with the SIGKILL signal.

Task 4: This program adds colour to shell and name

Anwers on question in task 5 are answered in answers.txt

## Compiling and using programs

To clone the repo use
``` https://github.com/mistedsait/ShellProject.git ```

All programs are already compiled with this commands.

``` gcc cfilename.c -o cfilename ```

To run program (task1 for example) use this command:
``` ./task3 ``` 

## Souces that helped us

[C file input and output](https://www.programiz.com/c-programming/c-file-input-output)
[Exec family functions](https://www.geeksforgeeks.org/exec-family-of-functions-in-c/)
[Fork system call](https://www.geeksforgeeks.org/fork-system-call/)

## Contact

**Miralem Mašić** - miralem.masic@stu.ibu.edu.ba
**Kemal Letić** - kemal.letic@stu.ibu.edu.ba


