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

	while (1)
	{
		if (isatty(fileno(stdin)))
			printf("★ ");
		/* chars_read -> buffer size */
		chars_read = getline(&buffer, &bufsize, stdin);
		if (chars_read == -1)
		{
			free(buffer);
			exit(0);
		}
		buffer[chars_read - 1] = '\0';
		command = tokenizer(buffer, " \t");
		if (command[0] == NULL)
		{
			free(command);
			continue;
		}
		if (strcmp(command[0], "exit") == 0)
		{
			free(buffer);
			free_array(command);
			break;
		}

		path_string = getenv("PATH");
		if (path_string != NULL)
		{
			char *pathdup = strdup(path_string);
			path = _which(command[0], pathdup);
			execute_command(command, path);
			free(pathdup);
			free(path);
		}
		else
			execute_command_ap(command);

		free_array(command);
	}
	return (0);
}
