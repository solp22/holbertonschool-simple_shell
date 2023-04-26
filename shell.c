#include "main.h"
/**
 * main - connect functions for the shell
 * Return: 1
*/

int main(void)
{
    char *line;

    while (1)
    {
        line = read_line();
        tokenizer(line);
    }
    return (1);
}