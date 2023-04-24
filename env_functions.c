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
			if (strncmp(environ[i], name, 4) == 0)
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
 * Return: A pointer to a string containing the full path to the command,
 * or NULL if the command is not found
 */
char *_which(char *path, char *cmd)
{
	int nb = 0, i;
	struct stat st;
	char *buff = NULL, COLUMN[] = ":";

	nb = nb_token(path, COLUMN);
	buff = strtok(path, COLUMN);

	for (i = 0; i < nb; i++)
	{
		path = _strcat(buff, cmd);
		if (path == NULL)
		{

			return (NULL);
		}
		if (stat(path, &st) == 0)
		{
			return (path);
		}
		free(path);
		buff = strtok(NULL, COLUMN);
	}
	printf("%s: not found\n", cmd);
	return (NULL);
}
