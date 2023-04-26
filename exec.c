#include "simple_shell.h"

/**
 * _exec - Executes a command
 * @av: The command and its arguments as an array of strings
 *  * @exist: A flag indicating whether or not to exit the shell
 * Return: Nothing
 */
void _exec(char **av, int *exist)
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
		*exist = 1;
	}
}

/**
 * error - Print error message and exit with status 127
 * @program: The name of the program
 * @cmd: The name of the command that was not found
 * @env: The environment variable to be freed
 * Return: void
 */
int error(char *program, char *cmd, char *env)
{
	fprintf(stderr, "%s: 1: %s: not found\n", program, cmd);
	if (env)
		free(cmd);
	return (127);
}

/**
 * __exit - Exits the shell when the user enters the "exit" command.
 * @line: The command line entered by the user
 * Return: If the user enters "exit", the function exits the shell
 * with a status code of 0. Otherwise, it returns 0.
 */
int __exit(char *line)
{
	if (strcmp(line, "exit") == 0)
	{
		free(line);
		exit(2);
	}
	return (0);
}
