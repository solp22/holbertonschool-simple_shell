#include "main.h"
/**
 * tokenizer - separates command given into tokens
 * @buffer: command given
 * @delim: delimiter
 *
 * Return: pointer to array of tokens
*/
char **tokenizer(char *buffer, char *delim)
{
	char *buffcopy = NULL, *token = NULL, *tokendup = NULL;
	char **array = NULL;
	int token_counter = 0, i = 0;

	buffcopy = strdup(buffer);
	if (buffcopy == NULL)
	{
		free(buffer);
		perror("Error");
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
	array = malloc(sizeof(char *) * token_counter);
	if (array == NULL)
		exit(1);
	tokendup = strtok(buffcopy, delim);
	/*store tokens in array*/
	for (i = 0; tokendup != NULL; i++)
	{
		array[i] = strdup(tokendup);
		if (array[i] == NULL)
		{
			/*make function to free array*/
			exit(1);
		}
		tokendup = strtok(NULL, delim);
	}
	array[i] = NULL;
	free(buffcopy);
	return (array);
}
