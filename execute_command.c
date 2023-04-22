#include "main.h"

void execute_command(char **array, char *token)
{
    pid_t childpid = fork();

    if (childpid == 0)
    {
        if (execve(array[0], array, NULL) == -1)
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
