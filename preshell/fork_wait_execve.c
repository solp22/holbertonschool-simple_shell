#include "main.h"

int main(void)
{
	pid_t childpid;
	pid_t parentpid;
	int status;
	int i = 0;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	parentpid = getpid();
	while (i < 5 && childpid)
	{
		childpid = fork();
		if (childpid == -1)
		{
			perror("Error:");
			return (1);
		}
		wait(&status);
		i++;
	}
	if (childpid == 0)
		printf("Child: %u\n", getpid());
	else
		printf("Parent: %u\n", parentpid);

	execve(argv[0], argv, NULL);
	if (execve(argv[0], argv, NULL) == -1)
		perror("Error:");
	return (0);
}
