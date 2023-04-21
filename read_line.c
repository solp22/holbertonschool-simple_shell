#include "main.h"

char *read_line()
{
    char *buffer;
    size_t bufsize = 0;
    int chars_read = 0;

    buffer = malloc(sizeof(bufsize));
    if (buffer == NULL)
    {   free(buffer);
        exit(1);
    }
    while (1)
    {
        printf("$ ");
        chars_read = getline(&buffer, &bufsize, stdin);
        if (chars_read == -1)
        {
            printf("Exiting Shell\n");
            free(buffer);
            exit(1);
        }
        return (buffer);
    }
}
