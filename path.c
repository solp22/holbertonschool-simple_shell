#include "main.h"
/**
 * _getenv - get variable value from environ
 * @name: name of variable to get
 * Return: value
*/

char *_getenv(const char *name)
{
	int i = 0;
	char *value = NULL;
	int len = strlen(name);

	while (environ[i])
	{
		if (strncmp(name, environ[i], len) == 0)
		{
			value = environ[i] + len + 1;
			return (value);
		}
		i++;
	}
	return (NULL);
}
/**
 * _which - check if command exists and shwo its path
 * @command: command input
 * @path: full value of env variable PATH
 * Return: NULL if it fails, path if success
*/

char *_which(char *command, char *path)
{
	char *value = NULL;
	char **dirs = NULL;
	int i = 0;

	dirs = tokenizer(path, ":");
	value = malloc(sizeof(char) + strlen(command) + strlen(dirs[0]) + 2);
	if (value == NULL)
		exit(1);
	if (access(command, F_OK) == 0)
	{
		free(value);
		value = strdup(command);
		free_array(dirs);
		return (value);
	}
	while (dirs[i] != NULL)
	{
		sprintf(value, "%s/%s", dirs[i], command);
		if (access(value, F_OK) == 0)
		{
			free_array(dirs);
			return (value);
		}
		i++;
	}
	free(value);
	free_array(dirs);
	return (NULL);
}
