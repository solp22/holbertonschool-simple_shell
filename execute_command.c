#include "main.h"
/**
 * execute_comand - executes the command given
 * @array: array of tokens from the command
*/
void execute_command(char **array, char *token)
{
    pid_t pid;
    char *path_string = _getenv("PATH");
    char *path = _which(array[0], path_string);

    if (path != NULL)
        pid = fork();
    if (pid == 0)
    {
        if (execve(path, array, environ) == -1)
        {
            perror("Error");
        }
    }
    else if (pid < 0)
    {
        perror("Error");
    }
    else
    {
        waitpid(pid, NULL, 0);
    }
}
