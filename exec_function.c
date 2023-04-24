#include "simple_shell.h"

/**
 * _exec - Executes a command
 * @av: The command and its arguments as an array of strings
 * Return: Nothing
 */
void _exec(char **av)
{
	int child_pid, status;

	child_pid = fork();

	if (child_pid == -1)
		exit (EXIT_FAILURE);

	else if (child_pid == 0)
		execve(av[0], av, environ);

	else
	{
		wait(&status);
		free(av[0]);
	}
}