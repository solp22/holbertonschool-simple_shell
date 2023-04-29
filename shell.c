#include "main.h"
/**
 * buf_command - connect functions for the shell
 * @chars_read: lenght of buffer
 * @buffer: input
 * Return: status
*/
int buf_command(int chars_read, char *buffer)
{
	char **command = NULL;
	char *path = NULL, *path_string = NULL;

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

	return (0);
}

/**
 * main - connect functions for the shell
 * Return: 0
*/
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	int chars_read = 0, status = 0;

	buffer = malloc(sizeof(bufsize));
	if (buffer == NULL)
	{
		perror("Error");
		exit(1);
	}
	/* non-interactive mode */
	if (!isatty(fileno(stdin)))
	{
		chars_read = read(0, buffer, sizeof(buffer));
		if (chars_read == -1)
		{
			free(buffer);
			exit(1);
		}
		if (chars_read > 0)
		{
			status = buf_command(chars_read, buffer);
			return (status);
		}
	}
	/* interactive mode */
	while (1)
	{
		printf("★ ");
		/* chars_read -> buffer size */
		chars_read = getline(&buffer, &bufsize, stdin);
		if (chars_read == -1)
		{
			free(buffer);
			exit(1);
		}
		status = buf_command(chars_read, buffer);
	}
	return (0);
}
