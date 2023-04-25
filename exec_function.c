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
		exit(EXIT_FAILURE);

	else if (child_pid == 0)
		execve(av[0], av, environ);

	else
	{
		wait(&status);
	}
}
int error(char *program, char *cmd, char *env, char *line)
{
	fprintf(stderr, "%s: 1: %s: not found\n", program, cmd);
	if (env)
		free(cmd);
	free(line);
	exit(127);
}

int __exit(char *line, int exist)
{
	if (strcmp(line, "exit") == 0)
	{
		free(line);
		if (!exist)
			exit(0);
		exit(2);
	}
	return (0);
}