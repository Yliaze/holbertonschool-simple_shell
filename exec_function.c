#include "simple_shell.h"

void _exec(char *av)
{
	int child_pid, i = 0, status;

	child_pid = fork();

	if (child_pid == -1)
		exit (EXIT_FAILURE);

	else if (child_pid == 0)
		execve(av[0], av, environ);

	else
	{
		wait(&status);
	}
}