#include "main.h"
/**
 * read_line - print prompt and read line given
 * Return: line given
*/
char *read_line()
{
    char *buffer = NULL;
    size_t bufsize = 0;
    int chars_read = 0;

    buffer = malloc(sizeof(bufsize));
    if (buffer == NULL)
    {   
        free(buffer);
        exit(1);
    }
    while (1)
    {
        printf("$ ");
        chars_read = getline(&buffer, &bufsize, stdin);
        if (chars_read == -1)
        {
            free(buffer);
            exit(1);
        }
        return (buffer);
        free(buffer);
    }
    free(buffer);
}
