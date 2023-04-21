#include "main.h"

void execute_command(char **array, char *token)
{
    char *command = NULL;
    pid_t childpid = fork();

    if (childpid == 0)
    {
        printf("a");
        sprintf(command, "%s%s", "/usr/bin/", token);
        if (access(command, F_OK) == -1)
        {
            perror("Error:");
            exit(1);
        }
        if (execve(command, array, NULL) == -1)
        {
            perror("Error:");
        }
    }
    else if (childpid < 0)
    {
        perror("Error:");
    }
    else
    {
        waitpid(childpid, NULL, 0);
    }
}