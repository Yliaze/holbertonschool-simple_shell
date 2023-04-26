#include "simple_shell.h"

/**
 * _exec - Executes a command
 * @av: The command and its arguments as an array of strings
<<<<<<< HEAD
 *  * @exist: A flag indicating whether or not to exit the shell
=======
 * @exist: A flag to 1 if the commande exist, 0 else
>>>>>>> refs/remotes/origin/main
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
<<<<<<< HEAD
		*exist = 1;
	}
}

=======
		free(av[0]);
		*exist = 1;
	}
}
>>>>>>> refs/remotes/origin/main
/**
 * error - Print error message and exit with status 127
 * @program: The name of the program
 * @cmd: The name of the command that was not found
 * @env: The environment variable to be freed
<<<<<<< HEAD
 * Return: void
 */
int error(char *program, char *cmd, char *env)
=======
 * @line: The command line to be freed
 * Return: void
 */
int error(char *program, char *cmd, char *env, char *line)
>>>>>>> refs/remotes/origin/main
{
	fprintf(stderr, "%s: 1: %s: not found\n", program, cmd);
	if (env)
		free(cmd);
<<<<<<< HEAD
	return (127);
}

/**
 * __exit - Exits the shell when the user enters the "exit" command.
 * @line: The command line entered by the user
 * Return: If the user enters "exit", the function exits the shell
 * with a status code of 0. Otherwise, it returns 0.
 */
int __exit(char *line)
=======
	free(line);
	exit(127);
}
/**
 * __exit - Exits the shell when the user enters the "exit" command.
 * @line: The command line entered by the user.
 */
void __exit(char *line)
>>>>>>> refs/remotes/origin/main
{
	if (strcmp(line, "exit") == 0)
	{
		free(line);
		exit(2);
	}
<<<<<<< HEAD
	return (0);
=======
}
/**
 * _env - Prints the environment variables
 * @line: The command line argument
 * @exist: A flag indicating whether or not to exit the shell.
 */
void _env(char *line, int *exist)
{
	int i = 0;

	if (strcmp(line, "env") == 0)
	{
		while (environ[i])
		{
			printf("%s\n", environ[i]);
			i++;
		}
		*exist = 1;
	}

>>>>>>> refs/remotes/origin/main
}
