#include "main.h"
/**
 * _getenv - get variable value from environ
 * @name: name of variable to get
 * Return: value
*/

const char *_getenv(const char *name)
{
    int i = 0;
    const char *value = NULL;
    int len = strlen(name);

    while (environ[i])
    {
        if (strncmp(name, environ[i], len) == 0)
        {
           value = environ[i] + len + 1;
           return (value);
        }
        i++;
    }
    return (NULL);
}

char **_which (char *command, char *argument)
{
    char *path, *dirs;
    int i = 0;

    dirs = tokenizer(command);
    while (dirs[i] != NULL)
    {
        sprintf(path, "%s/%s", dirs[i], argument);
        if (access(path, F_OK) == 0)
        {
            return (path);
        }
        i++;
    }
    perror("Error");
    return (NULL);
}