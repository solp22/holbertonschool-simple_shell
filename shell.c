#include "main.h"

/**
 * read_line - read the input given
 * Return: input
 */
char *read_line()
{
	char *buffer = NULL;
	size_t bufsize = 0;
	int chars_read = 0;

	while (1)
	{
		if (isatty(fileno(stdin)))
			printf("★ ");
		chars_read = getline(&buffer, &bufsize, stdin);
		if (chars_read == -1)
		{
			free(buffer);
			exit(0);
		}
		buffer[chars_read - 1] = '\0';
		return (buffer);
	}
}


/**
 * main - connect functions for the shell
 * Return: 0
*/
int main(void)
{
	char *line = NULL, *path = NULL, *path_string = NULL, *pathdup = NULL;
	char **command = NULL;

	while (1)
	{
		line = read_line();
		command = tokenizer(line, " \t");
		if (command[0] == NULL)
		{
			free(command);
			free(line);
			continue;
		}
		if (strcmp(command[0], "exit") == 0)
		{
			free(line);
			free_array(command);
			break;
		}
		path_string = getenv("PATH");
		if (path_string != NULL)
		{
			pathdup = strdup(path_string);
			path = _which(command[0], pathdup);
			execute_command(command, path);
			free(pathdup);
			free(path);
		}
		else
			execute_command_ap(command);
		free(line);
		free_array(command);
	}
	return (0);
}
