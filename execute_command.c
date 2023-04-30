#include "main.h"
/**
 * execute_command - executes the command given
 * @array: array of tokens from the command
 * @token: pointer to token
 * Return: error code
*/
int execute_command(char **array, char *token)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
		exit(execve(token, array, environ));
	else if (pid < 0)
	{
		perror("Error");
		return (1);
	}
	else
	{
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
}

/**
 * execute_command_ap - executes the command given an absolute path
 * @array: array of tokens from the command
 * Return: error code
*/
int execute_command_ap(char **array)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
		exit(execv(array[0], array));
	else if (pid < 0)
	{
		perror("Error");
		return (1);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (status != 0)
			perror("Error");
		return (WEXITSTATUS(status));
	}
}

