#include "simple_shell.h"

char *_gentenv(const char *name)
{
	char 
	for (int i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, 4) == 0)
		{
			strtok
			return (environ[i]);
		}
	}
	return (0);
}

char *_which(char *path, char *cmd)
{
	int nb = 0, i;
	struct stat st;
	char *path_and_cmd = NULL, *buff = NULL, COLUMN[] = ":";

	path_and_cmd = strdup(path);
	nb = nb_token(buff, COLUMN);
	buff = strtok(path_and_cmd, COLUMN);

	for (i = 0; i < nb; i++)
	{
		path_and_cmd = _strcat(buff, cmd);
		if (stat(path_and_cmd, &st) == 0)
		{
			free (buff);
			return (path_and_cmd);
		}
		buff = strtok(NULL, COLUMN);
	}

	return (NULL);
}
