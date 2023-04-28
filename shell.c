#include "main.h"
/**
 * main - connect functions for the shell
 * Return: 1
*/

int main(void)
{
	char *buffer = NULL, *path = NULL, *path_string = NULL;
	char **command = NULL;
	size_t bufsize = 0;
	int chars_read = 0;

	buffer = malloc(sizeof(bufsize));
	if (buffer == NULL)
	{
		perror("Error");
		exit(1);
	}
	while (1)
	{
		printf("$ ");
		chars_read = getline(&buffer, &bufsize, stdin); /* chars_read -> buffer size */
		if (chars_read == -1)
		{
			printf("Exiting...\n");
			free(buffer);
			exit(1);
		}
		buffer[chars_read - 1] = '\0';
		command = tokenizer(buffer, " \t");
		path_string = strdup(_getenv("PATH")); 
		path = _which(command[0], path_string);
		execute_command(command, path);
	}
}