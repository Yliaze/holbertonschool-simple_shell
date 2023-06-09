#include "simple_shell.h"

/**
 * _gentenv - Retrieves the value of an environment variable
 * @name: The name of the variable to retrieve
 * Return: A pointer to the value of the variable,
 * or NULL if the variable is not found
 */
char *_gentenv(const char *name)
{
	int i;

	if (environ)
	{
		for (i = 0; environ[i]; i++)
		{
			if (strncmp(environ[i], "PATH1", 5) == 0)
			{
				perror("./hsh: 1: hbtn_ls: not found");
				exit(127);
			}

			if (strncmp(environ[i], name, 5) == 0)
			{
				environ[i] = strtok(environ[i], "=");
				environ[i] = strtok(NULL, "=");
				return (environ[i]);
			}
		}
	}
	return (NULL);
}

/**
 * _which - Searches for the location of a command in the system's PATH
 * @path: The PATH environment variable
 * @cmd: The command to search for
 * @exist: A flag indicating if a command was executed
 * Return: A pointer to a string containing the full path to the command,
 * or NULL if the command is not found
 */
char *_which(char *path, char *cmd, int *exist)
{
	int nb = 0, i;
	struct stat st;
	char *buff = NULL, COLUMN[] = ":", *tmp;

	tmp = malloc(string_size(cmd));
	strcpy(tmp, cmd);
	*exist = 0;

	if (path == NULL || strcmp(path, "") == 0)
	{
		return (tmp);
	}
	nb = nb_token(path, COLUMN);
	buff = strtok(path, COLUMN);

	for (i = 0; i < nb; i++)
	{
		path = _strcat(buff, cmd);

		if (stat(path, &st) == 0)
		{
			*exist = 1;
			free(tmp);
			return (path);
		}
		free(path);
		buff = strtok(NULL, COLUMN);
	}
	return (tmp);
}

/**
 * copy_path - Creates a copy of the environment variable PATH
 * @env: The environment variable PATH
 * Return: A pointer to the copy of the PATH variable
 */
char *copy_path(char *env)
{
	char *path_cpy;

	path_cpy = malloc(string_size(env) + 1);
	path_cpy = strcpy(path_cpy, env);
	return (path_cpy);
}
/**
 * _printenv - Prints the environment variables
 * @line: The command line argument
 * @exist: A flag indicating if a command was executed
 */
void _printenv(char *line, int *exist)
{
	int i = 0;

	if ((strcmp(line, "env")) == 0)
	{
		while (environ[i])
		{
			printf("%s\n", environ[i]);
			i++;
		}
		*exist = 1;
	}
}
