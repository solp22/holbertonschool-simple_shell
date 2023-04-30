#ifndef MAIN_H
#define MAIN_H

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
int execute_command(char **array, char *token);
int execute_command_ap(char **array);
char **tokenizer(char *buffer, char *delim);
char *_getenv(const char *name);
char *_which(char *command, char *argument);
void free_array(char **array);
void print_env(void);

/*environ*/
extern char **environ;

#endif
