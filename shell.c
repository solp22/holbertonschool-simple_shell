#include "main.h"

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