#include "main.h"

int main(int argc, char *argv[])
{
        char *prompt = "$ ";
        char *buffer = NULL;
        size_t buffsize = 0;
        ssize_t chars_read;
        const char *delim = " \n";
        char *buffcopy = NULL;
        char *token;
        int tokencounter = 0, i;

        (void)argc;
	/*infinite loop*/
	while (1)
        {
                printf("%s", prompt);
                chars_read = getline(&buffer, &buffsize, stdin);
                /*ask for error, EOF or user using CTRL + D*/
                if (chars_read == -1)
                        return (-1);

        buffcopy = malloc(sizeof(char) * chars_read);
        if (buffcopy == NULL)
                return (-1);

        strcpy(buffcopy, buffer);
        /*split string into array of words*/
        token = strtok(buffer, delim);
        /*calculate number of tokens*/
        while (token != NULL)
        {
                tokencounter++;
                token = strtok(NULL, delim);
        }
        tokencounter++;
        argv = malloc(sizeof(char *) * tokencounter);
        /*store tokens in argv*/
        token = strtok(buffcopy, delim);

        for (i = 0; token != NULL; i++)
        {
                argv[i] = malloc(sizeof(char) * strlen(token));
                strcpy(argv[i], token);
                token = strtok(NULL, delim);
        }
        /*terminate array*/
        argv[i] = NULL;
}
