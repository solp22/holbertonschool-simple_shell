#include "main.h"

/**
 * main - prints the command entered by user
 * Return: 0 if success -1 if fail
 */

int main()
{
	int chars_read;
	char *buffer;
	size_t bufsize = 0;
	
	while (1)
	{
		printf("$ ");
		chars_read = getline(&buffer, &bufsize, stdin);
		printf("%s", buffer);
		if (chars_read == -1)
			return(-1);
	}
	return (0);
}
