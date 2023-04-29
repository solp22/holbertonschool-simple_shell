#include "main.h"
/**
 * execute_command - executes the command given
 * @array: array of tokens from the command
 * @token: pointer to token
*/
void execute_command(char **array, char *token)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (token == NULL)
		{
			if (execv(array[0], array) == -1)
			{
				perror("Error");
				exit(1);
			}
		}
		else
		{
			if (execve(token, array, environ) == -1)
			{
				perror("Error");
				exit(1);
			}
		}
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}
