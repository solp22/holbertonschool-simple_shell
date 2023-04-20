#include "main.h"

/**
 * main - prints all arguments
 * @argv: array of strings
 * @argc: number of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int count, i;
	(void)argc;

	for (count = 0; argv[count] != NULL; count++)
	{
	}

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
