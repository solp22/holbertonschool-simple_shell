#include "main.h"
/**
**exit - exits the shell
**Return: void
**/

	int exitty(void)
{
	exit (-1);	
}


/**
**env - prints environment
**Return: void
**/

	void env(void)
{	
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
{
	write(STDOUT_FILENO, environ[i], strlen(environ[i]));
	write(STDOUT_FILENO, "\n", 1);
	i++;
}
}
