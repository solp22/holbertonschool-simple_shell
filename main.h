/*libraries*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/*prototypes*/
int _putchar(char c);
void execute_command(char **array, char *token);
void *tokenizer(char *buffer);
char *read_line();
