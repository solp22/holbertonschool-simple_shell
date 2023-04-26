#include "main.h"
/**
 * tokenizer - separates command given into tokens
 * @buffer: command given
*/

void *tokenizer(char *buffer)
{
    char *buffcopy, *token;
    char **array;
    const char *delim = " \n";
    int token_counter, i = 0;

    buffcopy = strdup(buffer);
    if (buffcopy == NULL)
    {
        free(buffcopy);
        free(buffer);
        exit(1);
    }
    token = strtok(buffer, delim);
    /*count number of tokens*/
    while (token != NULL)
    {
        token_counter++;
        token = strtok(NULL, delim);
    }
    token_counter++;
    array = malloc(sizeof(char) * token_counter);
    if (array == NULL)
    {
        free(array);
        exit(1);
    }
    token = strtok(buffcopy, delim);
    /*store tokens in array*/
    for (i = 0; token != NULL; i++)
    {
        array[i] = strdup(token);
        if (array[i] == NULL)
        {
            free(array[i]);
            free(array);
            exit(1);
        }
        token = strtok(NULL, delim);
    }
    array[i] = NULL;
    execute_command(array, token);
    free (array);
    free (buffcopy);
    return (0);
}