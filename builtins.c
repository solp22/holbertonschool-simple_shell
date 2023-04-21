#include "main.h"
/**
**exit - exits the shell
**Return: void
**/

	int exit(void)
{
	return (-1);	
}


/**
**env - prints environment
**Return: void
**/

	int env(void)
{	
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
{
	write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
	write(STDOUT_FILENO, "\n", 1);
	i++;
}
	return (0);
}
