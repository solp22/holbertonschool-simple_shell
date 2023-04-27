#include "main.h"
/**
 * execute_comand - executes the command given
 * @array: array of tokens from the command
*/
void execute_command(char **array, char *token)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(token, array, environ) == -1)
		{
			perror("Error");
			exit(1);
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
