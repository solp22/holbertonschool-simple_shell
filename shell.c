#include "main.h"
/**
 * main - connect functions for the shell
 * Return: 0
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
		if (isatty(fileno(stdin)))
			printf("★ ");
		/* chars_read -> buffer size */
		chars_read = getline(&buffer, &bufsize, stdin);
		if (chars_read == -1)
		{
			free(buffer);
			exit(1);
		}
		buffer[chars_read - 1] = '\0';
		command = tokenizer(buffer, " \t");
		if (strcmp(command[0], "exit") == 0)
		{
			free(buffer);
			free_array(command);
			exit(0);
		}
		path_string = strdup(_getenv("PATH"));
		path = _which(command[0], path_string);
		if (path == NULL)
			perror("Error");
		execute_command(command, path);
		free_array(command);
		free(path);
		free(path_string);
	}
	return (0);
}
